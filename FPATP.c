#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 1000

typedef struct contacts {
    char nama[50];
    long long int nomor;
} contact;

int contact_count = 0;
contact newContact[n], temp, del;

void buffer (int X) {
    scanf("\n%d", &X);
    if (X == 1) {
        menu();
    } else {
        printf("Coba tekan 1 dulu pls <3");
        buffer (X);
    }
}

void add_contact() {
    printf("\n\n\n\t\t\tNEW CONTACT\t\t\t\n");
    printf("Nama : ");
    // fgets(newContact[contact_count].nama, sizeof(newContact[contact_count].nama), stdin);
    // newContact[contact_count].nama[strcspn(newContact[contact_count].nama, "\n")] = '\0';
    scanf("%s", newContact[contact_count].nama);
    getchar();
    strupr(newContact[contact_count].nama);
    printf("\nNo Handphone: ");
    scanf("\n%lld", &newContact[contact_count].nomor);
    contact_count++;

    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    while (x != 1)
    {
    scanf("\n%d", &x);
    if (x == 1) {
        menu();
    } else {
        printf("Coba tekan 1 dulu pls <3");
    }  
    }
}

void list() {
    printf("\n\n\n\t\t\tLIST\t\t\t\n");
    printf("\n%-20s %s\n", "Nama", "No Handphone");
    for (int i = 0; i < contact_count; i++) {
        if (newContact[i].nomor > 0) printf("%-20s %lld\n", newContact[i].nama, newContact[i].nomor);
    }
    
    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    buffer (x);
}

void sort() {
    printf("\n\n\n\t\t\tSORT\t");
    for(int i = 0; i < contact_count - 1; i++){
        for(int j = 0; j < contact_count - i - 1; j++){
            if(strcmp(newContact[j].nama, newContact[j + 1].nama) > 0){
                temp = newContact[j];
                newContact[j] = newContact[j + 1];
                newContact[j + 1] = temp;
            }
        }
    }
    printf("\n%-20s %s\n", "Nama", "No Handphone");
    for (int i = 0; i < contact_count; i++) {
        if (newContact[i].nomor > 0) printf("%-20s %lld\n", newContact[i].nama, newContact[i].nomor);
    }
    
    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    buffer (x);
}

void search() {
    // Implement search functionality
    int x;
    char f_name[50];
    printf("\n\n\n\t\t\tSEARCH\t\t\t\n");
    printf("1. Cari Nama\n");
    printf("2. Cari Nomor Handphone\n");
    printf("Tekan 1 / 2 untuk memilih ->");
    scanf("%d", &x);
    if (x == 1){
        printf("Nama yang ingin dicari : ");
        scanf("%s", &f_name);
        strupr(f_name);
         for(int i = 0; i < contact_count; i++){
            if(strcmp(newContact[i].nama, f_name) == 0){
                printf("\n%-20s %s\n", "Nama", "No Handphone");
                printf("%-20s %lld\n", newContact[i].nama, newContact[i].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer (x); 
                break;
            }
        } 
            int x = 0;
            printf("Contact tidak ditemukan!\n");
            printf("Tekan 1.Menu\t\t2.Coba lagi");
            while (x != 1 || x != 2){
                scanf("%d", &x);
            if (x == 1){
                menu();
            } else if (x == 2){
                search();
            } else {
                printf("\nMasukkan angka yang benar!\n");
            }
            }
        
    } else if (x == 2){
        long long int f_number;
        printf("Nomor yang ingin dicari : ");
        scanf("%lld", &f_number);
        for(int i = 0; i < contact_count; i++){
            if(newContact[i].nomor == f_number){
                printf("\n%-20s %s\n", "Nama", "No Handphone");
                printf("%-20s %lld\n", newContact[i].nama, newContact[i].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer (x);
                break;
            }  
        }
            int x = 0;
            printf("Contact tidak ditemukan!\n");
            printf("Tekan 1.Menu\t\t2.Coba lagi");
            while (x != 1 || x != 2){
                scanf("%d", &x);
            if (x == 1){
                menu();
            } else if (x == 2){
                search();
            } else {
                printf("\nMasukkan angka yang benar!\n");
            }
    }
}
}


void delete_contact() {
    // Implement contact deletion functionality
    int x;
    char f_name[50];
    printf("\n\n\n\t\t\tDELETE\t\t\t\n");
    printf("1. Cari Nama\n");
    printf("2. Cari Nomor Handphone\n");
    printf("Tekan 1 / 2 untuk memilih -> ");
    scanf("%d", &x);
    if (x == 1){
    printf("Nama yang ingin di hapus : ");
    scanf("%s", &f_name);
    strupr(f_name);
         for(int i = 0; i < contact_count; i++){
            if(strcmp(newContact[i].nama, f_name) == 0){
                for (int j = i; j < contact_count; j++)
                {
                    newContact[j] = newContact[j + 1];
                }
                
                
                printf("\nContact %s telah di hapus", f_name);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer (x);
                break;
            } 
         }
                int x = 0;
                printf("Contact tidak ditemukan!\n");
                printf("Tekan 1.Menu\t\t2.Coba lagi");
                    while (x != 1 || x != 2){
                        scanf("%d", &x);
                    if (x == 1){
                        menu();
                    } else if (x == 2){
                        search();
                    } else {
                        printf("\nMasukkan angka yang benar!\n");
                    }
                 }
            
        
    } else if (x == 2){
        long long int f_number;
        printf("Nomor yang ingin di hapus : ");
        scanf("%lld", &f_number);
        for(int i = 0; i < contact_count; i++){
            if(newContact[i].nomor == f_number){
                newContact[i] = del;
                printf("\nContact %lld telah di hapus", f_number);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer (x);
                break;
            }
        }
                int x = 0;
                printf("Contact tidak ditemukan!\n");
                printf("Tekan 1.Menu\t\t2.Coba lagi");
                    while (x != 1 || x != 2){
                        scanf("%d", &x);
                    if (x == 1){
                        menu();
                    } else if (x == 2){
                        search();
                    } else {
                        printf("\nMasukkan angka yang benar!\n");
                    }
                 }
           
        }
    }

void edit_contact (){
    int x;
    char f_name[50];
    printf("\n\n\n\t\t\tEDIT\t\t\t\n");
    printf("1. Cari Nama\n");
    printf("2. Cari Nomor Handphone\n");
    printf("Tekan 1 / 2 untuk memilih ->");
    scanf("%d", &x);
    if (x == 1){
    printf("Nama yang ingin di ubah : ");
    scanf("%s", &f_name);
    strupr(f_name);
        for(int i = 0; i < contact_count; i++){
            if(strcmp(newContact[i].nama, f_name) == 0){
                printf("Nama baru : ");
                scanf("%s", newContact[i].nama);
                strupr(newContact[i].nama);
                printf("No Handphone baru : ");
                scanf("%lld", &newContact[i].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer (x);
                break;
            }
        }
    } else if (x == 2){
        long long int f_number;
        printf("Nomor yang ingin di ubah : ");
        scanf("%lld", &f_number);
        for(int i = 0; i < contact_count; i++){
            if(newContact[i].nomor == f_number){
                printf("Nama baru : ");
                scanf("%s", newContact[i].nama);
                strupr(newContact[i].nama);
                printf("No Handphone baru : ");
                scanf("%lld", &newContact[i].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer (x);
                break;
            }
        }
                int x = 0;
                printf("Contact tidak ditemukan!\n");
                printf("Tekan 1.Menu\t\t2.Coba lagi");
                    while (x != 1 || x != 2){
                        scanf("%d", &x);
                    if (x == 1){
                        menu();
                    } else if (x == 2){
                        search();
                    } else {
                        printf("\nMasukkan angka yang benar!\n");
                    }
                 }
           
        }
}


void menu() {
    int X;

    printf("\n\n\n\t\t\tMENU\t\t\t\n");
    printf("1. Tambah contact Baru\t\t2. List contact\t\t3. Sort contact\n");
    printf("4. Cari contact\t\t\t5. Hapus\t\t\t6. Edit\t\t\t\n7. Exit\n");

    scanf("%d", &X);

    switch (X) {
        case 1:
            add_contact();
            break;
        case 2:
            list();
            break;
        case 3:
            sort();
            break;
        case 4:
            search();
            break;
        case 5:
            delete_contact();
            break;
        case 6:
            edit_contact();
            break;
        case 7:
            return;
            break;
        default:
            printf("Masukkan angka yang benar!\n");
            menu();
    }
}

int main() {
    menu();
    return 0;
}
