//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : Hans Lodewik Purba
// File Name         : layout.c
// Dependency        : stdio.h, string.h,math.h
//
// Description:
// Program untuk membaca layout manual juga untuk menampilkan
// layout
//
// Status:
// 1. Hans Lodewik Purba - 13217001    : Create the file
// 2. Hans Lodewik Purba - 13217001    : Write the comments
// 3. Hans Lodewik Purba - 13217001    : Fix the Bug
//***********************************************************//

#include<stdio.h>
#include<string.h>
#include<math.h>

//catatan :
//Untuk melakukan fitur (2) "layouting manual", panggil fungsi "manualLayout" dengan parameternya berurut adalah
//integer jumlah baris PCB, integer jumlah kolom PCB, dan array of char[baris][kolom][10] yang menyimpan masukan
//pengguna pada saat manual layouting serta telah deklarasikan terlebih dahulu pada main program.
//Untuk melakukan fitur (1) "tampilkan layout", panggil fungsi "showLayout" dengan parameternya berurut adalah
//integer jumlah baris PCB, integer jumlah kolom PCB, dan array of char[baris][kolom][10] yang sama dengan array of
//char sebelumnya.
//Fungsi-fungsi selain fungsi yang disebutkan di atas hanya fungsi yang dipakai untuk membantu.
//Jika pilihan menu awal adalah "buat proyek baru", harap deklarasikan nilai dari setiap elemen dari char[baris][kolom][10]
//adalah 0.

int cekKomponen(int x, int y, char comp[x*y][10], char input[10]){
	int cek = 0;
	for(int i=0; i<(x*y); i++){
		if (strcmp(comp[i],input)==0) {
			cek = cek + 1;
		}
	}
	return cek;
}

int jarak2Titik(int x1, int y1, int x2, int y2){
    int result;
    result = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    return result;
}

void manualLayout(int baris, int kolom, char layout[baris][kolom][10]){
    //"baris" adalah variabel M(pada main program), sedangkan "kolom" adalah variabel N(pada main program)
    //*berdasarkan contoh yang diberikan
    char input[10];
    char comp[baris*kolom][10];
    int a, b, c, d, e, f;
    int i=0;
    printf("\n[Mode Layout]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    printf("Pilih Komponen (R,C,T,J): ");
    scanf("%s", input);
    while(input[0]!='q'&&input[0]!='Q'){
        if (input[0] != 'R' && input[0] != 'C' && input[0] != 'T' && input[0] != 'J') {
            printf("Masukan harus sesuai kode komponen [R,C,T,J]!\n");
        }
        else if(input[0]=='R'){
            printf("Koordinat Kaki 1: ");
            scanf("%d,%d", &a, &b);
            printf("Koordinat Kaki 2: ");
            scanf("%d,%d", &c, &d);
            printf("\n");
            while(a>baris||c>baris||b>kolom||d>kolom){
                printf("Koordinat melebihi ukuran PCB.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki 1: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki 2: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            while(layout[a-1][b-1][0]!=0||layout[c-1][d-1][0]!=0){
                printf("Koordinat yang anda masukkan telah digunakan untuk komponen lain.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki 1: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki 2: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            while(jarak2Titik(a,b,c,d)<=3){
                printf("Jarak minimal antar kaki resistor adalah 3 satuan.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki 1: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki 2: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            strcpy(comp[i],input);
            strcpy(layout[a-1][b-1],comp[i]);
            strcpy(layout[c-1][d-1],comp[i]);
            i++;
        }else if(input[0]=='C'){
            printf("Koordinat Kaki 1: ");
            scanf("%d,%d", &a, &b);
            printf("Koordinat Kaki 2: ");
            scanf("%d,%d", &c, &d);
            printf("\n");
            while(a>baris||c>baris||b>kolom||d>kolom){
                printf("Koordinat melebihi ukuran PCB.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki 1: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki 2: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            while(layout[a-1][b-1][0]!=0||layout[c-1][d][0-1]!=0){
                printf("Koordinat yang anda masukkan telah digunakan untuk komponen lain.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki 1: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki 2: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            while(jarak2Titik(a,b,c,d)<=1){
                printf("Jarak minimal antar kaki kapasitor adalah 1 satuan.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki 1: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki 2: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            strcpy(comp[i],input);
            strcpy(layout[a-1][b-1],comp[i]);
            strcpy(layout[c-1][d-1],comp[i]);
            i++;
        }else if(input[0]=='T'){
            printf("Koordinat Kaki Emiter: ");
            scanf("%d,%d", &a, &b);
            printf("Koordinat Kaki Collector: ");
            scanf("%d,%d", &c, &d);
            printf("Koordinat Kaki Basis: ");
            scanf("%d,%d", &e, &f);
            printf("\n");
            while(a>baris||c>baris||e>baris||b>kolom||d>kolom||f>kolom){
                printf("Koordinat melebihi ukuran PCB.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki Emiter: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki Collector: ");
                scanf("%d,%d", &c, &d);
                printf("Koordinat Kaki Basis: ");
                scanf("%d,%d", &e, &f);
                printf("\n");
            }
            while(layout[a-1][b-1][0]!=0||layout[c-1][d-1][0]!=0||layout[e-1][f-1][0]!=0){
                printf("Koordinat yang anda masukkan telah digunakan untuk komponen lain.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki Emiter: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki Collector: ");
                scanf("%d,%d", &c, &d);
                printf("Koordinat Kaki Basis: ");
                scanf("%d,%d", &e, &f);
                printf("\n");
            }
            while(jarak2Titik(a,b,c,d)<=1||jarak2Titik(a,b,e,f)<=1||jarak2Titik(c,d,e,f)<=1){
                printf("Jarak minimal antar kaki transistor adalah 1 satuan.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki Emiter: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki Collector: ");
                scanf("%d,%d", &c, &d);
                printf("Koordinat Kaki Basis: ");
                scanf("%d,%d", &e, &f);
                printf("\n");
            }
            strcpy(comp[i],input);
            strcpy(layout[a-1][b-1],comp[i]);
            strcpy(layout[c-1][d-1],comp[i]);
            strcpy(layout[e-1][f-1],comp[i]);
            strcat(layout[a-1][b-1],"e");
            strcat(layout[c-1][d-1],"c");
            strcat(layout[e-1][f-1],"b");
            i++;
        }else if(input[0]=='J'){
            printf("Koordinat Kaki Positif: ");
            scanf("%d,%d", &a, &b);
            printf("Koordinat Kaki Negatif: ");
            scanf("%d,%d", &c, &d);
            printf("\n");
            while(a>baris||c>baris||b>kolom||d>kolom){
                printf("Koordinat melebihi ukuran PCB.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki Positif: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki Negatif: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            while(layout[a-1][b-1][0]!=0||layout[c-1][d-1][0]!=0){
                printf("Koordinat yang anda masukkan telah digunakan untuk komponen lain.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki Positif: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki Negatif: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            while(jarak2Titik(a,b,c,d)<=0){
                printf("Kedua kaki jumper tidak boleh berada pada tempat yang sama.\n");
                printf("Silakan memasukkan ulang koordinat kaki komponen.\n\n");
                printf("Koordinat Kaki Positif: ");
                scanf("%d,%d", &a, &b);
                printf("Koordinat Kaki Negatif: ");
                scanf("%d,%d", &c, &d);
                printf("\n");
            }
            strcpy(comp[i],input);
            strcpy(layout[a-1][b-1],comp[i]);
            strcpy(layout[c-1][d-1],comp[i]);
            strcat(layout[a-1][b-1],"+");
            strcat(layout[c-1][d-1],"-");
            i++;
        }
        printf("Pilih Komponen (R,C,T,J): ");
        scanf("%s", input);
        while(cekKomponen(baris, kolom, comp, input)>=1) {
            printf ("\nKomponen sudah dipakai, masukkan komponen yang berbeda\n\n");
            printf("Pilih Komponen (R,C,T,J): ");
            scanf("%s", input);
        }
    }
}

void showLayout(int baris, int kolom, char layout[baris][kolom][10]){
    printf("\n[Layout Rangkaian pada PCB Dot Matriks]\n");

    printf("    ");
    for(int j=0;j<kolom;j++){
        printf("%4d", j+1);
    }
    printf("\n");
    for(int i=0;i<baris;i++){
        printf("%4d", i+1);
        for(int j=0;j<kolom;j++){
            printf("%4s", layout[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
