//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : Daffa Zaidan Nabil
// File Name         : routing.c
// Dependency        : stdio.h, string.h
//
// Description:
//     File berisi fungsi untuk routing yang dapat melakukan
// routing pada koordinat PCB yang diinput menggunakan simbol
// yang dipilih. Selain itu, file juga berisi fungsi untuk me-
// nampilkan hasil routing yang disimpan pada program utama.
//
// Status:
// 1. Daffa Zaidan Nabil - 13217008 : Create the file
// 2. Daffa Zaidan Nabil - 13217008 : Fix the bug
// 3. Daffa Zaidan Nabil - 13217008 : Write the comments
//***********************************************************//

#include<stdio.h>
#include<string.h>

int min(int p, int q); //Return nilai terkecil antara p dan q
int max(int p, int q); //Return nilai terbesar antara p dan q
void showRouting(int col, int row, char rout[40][40]); //Menampilkan hasil routing yang disimpan pada program utama
void routing(int col, int row, char routArray[40][40]); //Melakukan routing pada koordinat-koordinat di PCB menggunakan simbol

void routing(int col, int row, char routArray[40][40]){
    int status = 0, i, y, x, yPrev, xPrev;
    char simbol[1], input[6]; //Input dapar berupa koordinat atau pilihan menu
    printf("\n[Mode Routing]\nIsi 'q' atau 'Q' untuk kembali ke menu\nIsi 'n' atau 'N' untuk memulai pada simpul (node) baru");

    do{ //Dijalankan berulang sampai user memilih ganti mode
        do{ //Dijalankan berulang sampai input simbol benar atau memilih ganti mode
            printf("\nPilih Simbol (!,@,#,$,%,^,&,*,(,)): ");
            gets(simbol);
            if((strlen(simbol)==1)&&(simbol[0]=='!'||simbol[0]=='@'||simbol[0]=='#'||simbol[0]=='$'||simbol[0]=='%'||simbol[0]=='^'||simbol[0]=='&'||simbol[0]=='*'||simbol[0]==',')){
                status = 3; //Lanjut
            }else if((strlen(simbol)==1)&&(simbol[0] == 'q' || simbol[0] == 'Q')){
                status = 2; //Ganti Mode
            }else if((strlen(simbol)==1)&&(simbol[0] == 'n' || simbol[0] == 'N')){
                //Ganti Simbol (walaupun tidak perlu)
            }else{ //Input simbol salah atau tidak sesuai format
                printf("Simbol tidak tersedia!\n");
            }
        }while(status==0);

        i = 1;
        yPrev = 0;
        xPrev = 0;

        while(status==3){ //Dijalankan apabila input simbol benar, berulang sampai user memilih ganti simbol
            do{ //Dijalankan berulang sampai input koordinat benar
                status = 0;
                int n = 0, nKoma = 0;

                printf("Koordinat %d: ", i);
                gets(input); //Input koordinat atau pilihan menu

                for(int k=0;k<strlen(input);k++){ //Pengecekan jumlah koma dan karakter lain
                    if((input[k]<'0')||(input[k]>'9')){
                        n++;
                    }
                    if(input[k]==','){
                        nKoma++;
                    }
                }

                if(n==1 && nKoma==0){ //Input berupa pilihan menu
                    if(input[0] == 'n' || input[0] == 'N'){
                        status = 1; //Ganti Simbol
                    }else if(input[0] == 'q' || input[0] == 'Q'){
                        status = 2; //Ganti Mode
                    }else{
                        printf("Input salah, ikuti format yang ada!\n");
                    }
                }else if(n==1 && nKoma==1){ //Input berupa koordinat
                    y = atoi(strtok(input, ","));
                    x = atoi(strtok(NULL, ","));
                    if(y>row || x>col || y<1 || x<1){ //Input koordinat melebihi ukuran PCB
                        printf("Input salah, ukuran PCB adalah NxM = %dx%d sehingga koordinat maksimal adalah (%d,%d)!\n", col, row, row, col);
                    }else{ //Input koordinat benar
                        if(yPrev==0 && xPrev==0){ //Routing koordinat pertama untuk simbol terpilih
                            routArray[y-1][x-1] = simbol[0];
                            status = 3; //Koordinat Selanjutnya
                        }else if(yPrev==y){ //Routing horizontal ke koordinat selanjutnya
                            for(int f=min(x,xPrev);f<=max(x,xPrev);f++){
                                routArray[y-1][f-1] = simbol[0];
                            }
                            status = 3; //Koordinat Selanjutnya
                        }else if(xPrev==x){ //Routing vertikal ke koordinat selanjutnya
                            for(int f=min(y,yPrev);f<=max(y,yPrev);f++){
                                routArray[f-1][x-1] = simbol[0];
                            }
                            status = 3; //Koordinat Selanjutnya
                        }else{ //Routing ke koordinat selanjutnya yang tidak sebaris/sekolom
                            for(int f=min(x,xPrev);f<=max(x,xPrev);f++){ //Routing horizontal
                                routArray[yPrev-1][f-1] = simbol[0];
                            }
                            for(int f=min(y,yPrev);f<=max(y,yPrev);f++){ //Routing vertikal
                                routArray[f-1][x-1] = simbol[0];
                            }
                            status = 3; //Koordinat Selanjutnya
                        }
                    }
                }else{ //Input koordinat atau pilihan menu tidak sesuai format
                    printf("Input salah, ikuti format yang ada!\n");
                }
            }while(status==0);
            i++;
            yPrev = y;
            xPrev = x;
        }
    }while(status==1);
}

void showRouting(int col, int row, char rout[40][40]){
    printf("\n[Routing Rangkaian pada PCB Dot Matriks]\n");
    printf("    ");
    for(int x=0;x<col;x++){
        printf("%4d", x+1); //Menampilkan jumlah koordinat N di atas gambar routing
    }

    for(int y=0;y<row;y++){
        printf("\n%4d", y+1); //Menampilkan jumlah koordinat M di kiri gambar routing
        for(int x=0;x<col;x++){ //Menampilkan gambar routing
            printf("   %c", rout[y][x]);
        }
    }
    printf("\n\n");
}

int min(int p, int q){
    if(p<=q){
        return p;
    }else{
        return q;
    }
}

int max(int p, int q){
    if(p>=q){
        return p;
    }else{
        return q;
    }
}
