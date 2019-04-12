//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : Faisa Fawwaz Fauzan
// File Name         : Main.c
// Dependency        : stdio.h, string.h,stdlib.h
//
// Description:
//     File ini berisi program utama dari program yang dikerjakan
//
// Status:
// 1. Faisa Fawwaz Fauzan - 13217014 : Create the file
// 2. Faisa Fawwaz Fauzan - 13217014 : Fix the bug
//***********************************************************//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DRC.c"
#include "layout.c"
#include "routing.c"
#include "saveAndLoad.c"


int main(){
	int input,mode;
	int baris,kolom;
	char namaFile[100];
	char rLayout[40][40][10];
	char rRouting[40][40];
	printf("Menu:\n" );
	printf("   1. Buat Proyek Baru\n");
	printf("   2. Muat Proyek dari Berkas\n");
	printf("   3. Keluar\n");
	printf("Masukan: ");
	scanf("%d",&input);
	while ((input>3) ||(input < 1)){
		printf("Masukan Salah");
		printf("Menu :\n" );
		printf("   1. Buat Proyek Baru \n");
		printf("   2. Muat Proyek dari Berkas \n");
		printf("   3. Keluar \n");
		printf("Masukan : ");
		scanf("%d",&input);
	}
	printf("\n");
do{
	if (input == 1){
		printf("====== Membuat Proyek Baru ======\n");
		printf("Masukkan nama proyek: ");
		scanf("%s",&namaFile);
		printf("Masukkan ukuran PCB NxM (N,M<40): ");
		scanf("%d %d",&kolom,&baris);
		for(int i=0;i<baris;i++){
        	for(int j=0;j<kolom;j++){
            	for(int k=0;k<10;k++){
                	rLayout[i][j][k]=0;
            	}
        	}
    	}
    	for(int f=0;f<baris;f++){
        	for(int g=0;g<kolom;g++){
          	  rRouting[f][g] = ' ';
        	}
    	}
    	printf("\n");
		do{
			printf("[Menu Utama]\n");
    		printf("Pilih Mode:\n");
    		printf("   1. Tampilkan Layout\n");
    		printf("   2. Layouting Manual\n");
    		printf("   3. Tampilkan Routing\n");
    		printf("   4. Routing Manual\n");
    		printf("   5. Design Rule Checker\n");
    		printf("   6. Simpan Proyek dan Keluar\n");
    		printf("Pilih Mode: ");
    		scanf("%d",&mode);
    		getchar();
			if (mode == 1){
				showLayout(baris,kolom,rLayout);
			}
			else if (mode == 2){
				manualLayout(baris,kolom,rLayout);
			}
			else if (mode == 3){
				showRouting(kolom,baris,rRouting);
			}
			else if (mode == 4){
				routing(kolom,baris,rRouting);
			}
			else if (mode == 5){
				DRC(rLayout,rRouting);
			}
		} while (mode !=6);
		save(rLayout,rRouting,baris,kolom,namaFile);
		printf("Menu :\n" );
		printf("   1. Buat Proyek Baru \n");
		printf("   2. Muat Proyek dari Berkas \n");
		printf("   3. Keluar \n");
		printf("Masukan : ");
		scanf("%d",&input);
	}
	if (input == 2){
		load(rLayout,rRouting);
		do{
			printf("[Menu Utama]\n");
    		printf("Pilih Mode: \n");
    		printf("   1. Tampilkan Layout\n");
    		printf("   2. Layouting Manual\n");
    		printf("   3. Tampilkan Routing\n");
    		printf("   4. Routing Manual\n");
    		printf("   5. DRC\n");
    		printf("   6. Keluar\n");
    		scanf("%d",&mode);
    		getchar();
			if (mode == 1){
				showLayout(baris,kolom,rLayout);
			}
			else if (mode == 2){
				manualLayout(baris,kolom,rLayout);
			}
			else if (mode == 3){
				showRouting(kolom,baris,rRouting);
			}
			else if (mode == 4){
				routing(baris,kolom,rRouting);
			}
			else if (mode == 5){
				DRC(rLayout,rRouting);
			}
		} while (mode !=6);
		save(rLayout,rRouting,baris,kolom,namaFile);
		printf("Menu :\n" );
		printf("   1. Buat Proyek Baru \n");
		printf("   2. Muat Proyek dari Berkas \n");
		printf("   3. Keluar \n");
		printf("Masukan : ");
		scanf("%d",&input);
	}
	}while (input !=3);
	return 0;
}
