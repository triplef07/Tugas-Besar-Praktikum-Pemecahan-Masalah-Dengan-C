//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : Muhammad Iqbal Akbari
// File Name         : saveAndLoad.c
// Dependency        : stdio.h, string.h
//
// Description:
// Program untuk membaca file eksternal dan menyimpan kedalam
// array serta untuk menyimpan array dalam file eksternal.
//
// Status:
// 1. M. Iqbal A. - 13217020    : Create the file
// 2. M. Iqbal A. - 13217020    : Debugging
//***********************************************************//
// Code version / Update : 5.5 / 11/04/2019
//***********************************************************//

#include <stdio.h>
#include <string.h>

void save(char layout[40][40][2], char routing[40][40], int panjang, int lebar, char fName[100]){
    char fNameL[100],fNameR[100];
//Membuka file berdasar nama yang diinput user
    printf("\n_______Menyimpan Proyek_______\n");
    strcpy(fNameL,fName); strcpy(fNameR,fName);
    strcat(fNameL,"_Layout.csv"); strcat(fNameL,"_Routing.csv");
    FILE*foutL = fopen(fNameL, "w");
    FILE*foutR = fopen(fNameR, "w");
//Proses menyimpan
    printf("\n\nLoading...\n\n");
    for(int i=0; i<=lebar; i++){
        for(int j=0; j<=panjang; j++){
            fprintf(foutL, "%s,", layout[i][j]);
        }
        fprintf(foutL, "\n");
    }
    for(int i=0; i<=lebar; i++){
        for(int j=0; j<=panjang; j++){
            fprintf(foutR, "%c,", routing[i][j]);
        }
        fprintf(foutR, "\n");
    }
    printf("Layout disimpan dalam berkas %s\n",fNameL);
    printf("Routing disimpan dalam berkas %s\n",fNameR);
//Proses menyimpan diakhiri dengan menutup file
    fclose(foutL); fclose(foutR);
    return 0;
}

void load(char layout[40][40][2], char routing[40][40]){
    char dummy[40][120];
    char fName[100],fNameL[100],fNameR[100];
    int i,j,z,x,l,p;
//Meminta nama file
    printf("\n_______Membuka Proyek_______\n");
    printf("Masukkan nama file : ");scanf("%s",fName);
    strcpy(fNameL,fName); strcpy(fNameR,fName);
    strcat(fNameL,"_Layout.csv"); strcat(fNameL,"_Routing.csv");
    FILE*finL = fopen(fNameL, "r");
    FILE*finR = fopen(fNameR, "r");
//Mulai membaca file
    if((finL==NULL)&&(finR==NULL)){
        printf("Load file gagal\n");
    }else{
//Membaca Layout
        i=0;
        while(fgets(dummy[i],120,finL) != NULL){
            i++;
        }
        l=i; i=0;
        while(i<=l){
            j=0; x=0; z=0;
            while(dummy[i][z]!='\n'){
                if(dummy[i][z]!=','){
                    layout[i][j][x]=dummy[i][z];
                    x++;
                }else if(dummy[i][z]==','){
                    x=0;
                    j++;
                }
                z++;
            }
            i++;
        }
        p=j;
        printf("\nLoad file layout berhasil");
    }
//Membaca Routing
        i=0;
        while(fgets(dummy[i],120,finR) != NULL){
            i++;
        }
        l=i; i=0;
        while(i<=l){
            j=0;
            for(z=0;z<=strlen(dummy[i]);z++){
                if(dummy[i][z]!=','){
                    routing[i][j]=dummy[i][z];
                    j++;
                }
            }
            i++;
        }
        printf("\nLoad file routing berhasil\n");
    }
    p=j;
    fclose(finL); fclose(finR);
    return 0;
}
