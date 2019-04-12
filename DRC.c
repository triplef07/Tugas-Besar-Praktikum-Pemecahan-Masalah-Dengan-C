//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : Faisa Fawwaz Fauzan
// File Name         : DRC.c
// Dependency        : stdio.h, string.h,stdlib.h
//
// Description:
//     File berisi fungsi untuk melakukan operasi Design Rules
// Check, operasi tersebut dilakukan untuk mencocokan apakah ruting
// dan layout yang dibuat oleh user sudah sesuai dengan aturan.
//
// Status:
// 1. Faisa Fawwaz Fauzan - 13217014 : Create the file
// 2. Faisa Fawwaz Fauzan - 13217014 : Fix the bug
// 3. Faisa Fawwaz Fauzan - 13217014 : Write the comments
//***********************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct vektor{
	int x;
	int y;
} vektor;

typedef struct cek {
	char komponen[100];
	char node1[100];
	char node2[100];
	vektor koor1;
	vektor koor2;
	char route1;
	char route2;
} cek ;

void DRC(char komp[40][40][10], char rout[40][40]); //Melakukan Design Rule Checking

void DRC(char komp[40][40][10], char rout[40][40]){
	FILE *simpan;
	cek fileluar[100];
	int i = 0 ;
	char namafile[100];
	printf("Masukkan File DRC (dalam format .txt): ");
	scanf("%s",&namafile); //Membaca Nama File Eksternal
	simpan = fopen(namafile,"r"); //Membuka File
	while (!feof(simpan)){
	fscanf(simpan, "%s %s %s", &fileluar[i].komponen, &fileluar[i].node1, &fileluar[i].node2); //Menyimpan data dari file eksternal ke program
	i = i +1;
	}
	int hitung = i-1; // Dengan metode di atas, line terakhir yang berisi data kosong, ikut terbaca, oleh karena itu dihilangkan data tersebut dari array
	fclose(simpan);//Menutup File
	int k;
	for (k=0;k<=hitung;++k){//Algoritma untuk mencari data di array layout dan routing dan memasukannya ke data di prosedur
		int indikator = 0;//Indikator untuk menentukan apakah kaki sudah pernah terbaca atau belum
		for (i = 0; i <=39; ++i) {
			for(int j=0;j<=39;++j){
				if ((strcmp(fileluar[k].komponen,komp[i][j]) == 0) &&  (indikator == 0)){
					fileluar[k].koor1.x = i;
					fileluar[k].koor1.y = j;
					fileluar[k].route1 = rout[i][j];
					indikator = 1;
				}
				if ((strcmp(fileluar[k].komponen,komp[i][j]) == 0) &&  (indikator == 1)){
					fileluar[k].koor2.x = i;
					fileluar[k].koor2.y = j;
					fileluar[k].route2 = rout[i][j];
				}
			}
		}
	}
	int temp ;// Untuk mengecek apakah kaki komponen sudah tersambung
	int hitung_true = 0;
	for (k=0;k<=hitung;++k){//Mengecek apakah kaki sudah tersambung
		temp = 0;
		for(i=0;i<k;++i){
			if (strcmp(fileluar[k].node1,fileluar[i].node1) == 0) {
				if ((fileluar[k].route1) == (fileluar[i].route1)){
						temp = temp +1;
				}
			}
			if (strcmp(fileluar[k].node1,fileluar[i].node2) == 0){
				if ((fileluar[k].route1) == (fileluar[i].route2)){
						temp = temp +1;
				}
			}
			if (strcmp(fileluar[k].node2,fileluar[i].node1) == 0) {
				if ((fileluar[k].route2) == (fileluar[i].route1)){
						temp = temp +1;
				}
			}
			if(strcmp(fileluar[k].node2,fileluar[i].node2) == 0){
				if ((fileluar[k].route2) == (fileluar[i].route2)){
						temp = temp +1;
				}
			}
		}
		for (int j=k+1;j<=hitung;++j){
			if (strcmp(fileluar[k].node1,fileluar[j].node1) == 0) {
				if ((fileluar[k].route1) == (fileluar[j].route1)){
						temp = temp +1;
				}
			}
			if (strcmp(fileluar[k].node1,fileluar[j].node2) == 0){
				if ((fileluar[k].route1) == (fileluar[j].route2)){
						temp = temp +1;
				}
			}
			if (strcmp(fileluar[k].node2,fileluar[j].node1) == 0) {
				if ((fileluar[k].route2) == (fileluar[j].route1)){
						temp = temp +1;
				}
			}
			if(strcmp(fileluar[k].node2,fileluar[j].node2) == 0){
				if ((fileluar[k].route2) == (fileluar[j].route2)){
						temp = temp +1;
				}
			}
		}
		if (temp = 2){//Sambungan sudah benar
			hitung_true = hitung_true + 1;
		}
	}
	hitung = hitung +1;
	printf("%d/%d rule is checked \n ",hitung_true,hitung);

}
