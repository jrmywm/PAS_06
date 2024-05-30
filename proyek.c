/*
	Proyek Akhir Semester:
	Sistem Penjualan paket internet
	Ver. 1.00
	Tanggal 23 Mei 2024
	
	Group	: 6
		1. Jeremy Wijanarko Mulyono 2306267132
		2. Reyhan Ahnaf Deannova 2306267100

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include "proyek.h"

// Main function
int main() {
    int pilihan;
    // Load data from file into linked list
    loadDataFromFile("user_data.txt", &head);

    do {
		system("cls");
        printf("\033[1;36m"); // Mengubah warna teks menjadi cyan
	    displayList(head); // Output linkedlist untuk troubleshooting
	    printf("\n====================================\n");
        printf("|  Sistem Pembelian Paket Internet |\n");
        printf("====================================\n");
        printf("\033[0m"); // Reset warna teks
        printf("\033[1;33m"); // Mengubah warna teks menjadi kuning
        printf("| 1. |	Daftar data yang tersedia  |\n");
		printf("+----+-----------------------------+\n");
        printf("| 2. |	Login data	   	   |\n");
        printf("+----+-----------------------------+\n");
        printf("| 3. |	Register nomor telefon	   |\n");
        printf("+----+-----------------------------+\n");
        printf("| 4. |	Beli token pulsa	   |\n");
        printf("+----+-----------------------------+\n");
        printf("| 5. |	Bantuan	   		   |\n");
        printf("+----+-----------------------------+\n");
        printf("| 6. |	Mode Admin	 	   |\n");
        printf("+----+-----------------------------+\n");
        printf("\033[0;31m");
        printf("| 0. |	Keluar dari program	   |\n");
        printf("+----+-----------------------------+\n\n");
        printf("\033[0m"); // Reset warna teks
         
        printf("Masukkan pilihan menu: ");
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1:
            	system("cls");
                pilihan1();
                break;
            case 2:
            	system("cls");
                pilihan2();
                break;
            case 3:
            	system("cls");
                pilihan3();
			    #pragma omp parallel
			    {
			        #pragma omp single nowait
			        {
			            head = mergeSort(head);
			        }
			    }
                break;
            case 4:
            	system("cls");
            	pilihan4();
            	break;
            case 5:
            	system("cls");
            	pilihan5();
            	break;
            case 6:
            	system("cls");
            	displayList(head);
            	adminMode();
            	break;
            case 0:
            	printf("\033[0;31m");
                printf("Keluar dari program...\n");
                printf("\033[0m");
                break;
            default:
            	printf("\033[0;31m");
                printf("Pilihan tidak valid. Silahkan coba lagi.\n");
                printf("\033[0m");
                system("pause");
                break;	
        }
    } while (pilihan != 0);
    updateUserDataFile(head, "user_data.txt");

    return 0;
}

