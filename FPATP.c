#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FINAL PROJECT ATP PHONE BOOK KELOMPOK 9

#define n 1000

typedef struct contacts
{
    char nama[50];
    long long int nomor;
} contact;

int contact_count = 0;
contact newContact[n], temp, del;
int del_count = 0;

void buffer(int X)
{
    scanf("\n%d", &X);
    if (X == 1)
    {
        menu();
    }
    else
    {
        printf("Coba tekan 1 dulu pls <3\n");
        buffer(X);
    }
}

void add_contact()
{
    printf("\n\n\n\t\t\tNEW CONTACT\t\t\t\n");
    printf("Nama : ");
    getchar();
    fgets(newContact[contact_count].nama, sizeof(newContact[contact_count].nama), stdin);
    newContact[contact_count].nama[strcspn(newContact[contact_count].nama, "\n")] = '\0';
    strupr(newContact[contact_count].nama);
    printf("\nNo Handphone: ");
    scanf("\n%lld", &newContact[contact_count].nomor);
    contact_count++;

    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    while (x != 1)
    {
        scanf("\n%d", &x);
        if (x == 1)
        {
            menu();
        }
        else
        {
            printf("Coba tekan 1 dulu pls <3\n");
        }
    }
}

void list()
{
    printf("\n\n\n\t\t\tLIST\t\t\t\n");
    printf("\n%-20s %s\n", "Nama", "No Handphone");
    for (int j = 0; j < contact_count; j++)
    {
        if (newContact[j].nomor > 0)
            printf("%-20s %lld\n", newContact[j].nama, newContact[j].nomor);
    }

    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    buffer(x);
}

void bubble () {
    int sort_counts = 0;
    printf("\n\n\n\t\t\tSORT\t");
    for (int j = 0; j < contact_count - 1 - del_count; j++)
    {
        for (int j = 0; j < contact_count - j - 1 - del_count; j++)
        {
            if (strcmp(newContact[j].nama, newContact[j + 1].nama) > 0)
            {
                temp = newContact[j];
                newContact[j] = newContact[j + 1];
                newContact[j + 1] = temp;
                sort_counts++;
            }
        }
    }
    printf("\nSorting telah di lakukan dengan %d steps", sort_counts);
    printf("\n%-20s %s\n", "Nama", "No Handphone");
    for (int j = 0; j < contact_count; j++)
    {
        if (newContact[j].nomor > 0)
            printf("%-20s %lld\n", newContact[j].nama, newContact[j].nomor);
    }

    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    buffer(x);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void select () {
    int sort_counts = 0;
    for (int i = 0; i < contact_count - 1 - del_count; i++) {
    int min_idx = i;
    for (int j = i + 1; j < contact_count - del_count; j++) {
      if (strcmp(newContact[j].nama, newContact[min_idx].nama) > 0)
        min_idx = j;
        sort_counts++;
    }
    swap(&newContact[min_idx], &newContact[i]);
  }

  printf("\nSorting telah di lakukan dengan %d steps", sort_counts);
    printf("\n%-20s %s\n", "Nama", "No Handphone");
    for (int j = 0; j < contact_count; j++)
    {
        if (newContact[j].nomor > 0)
            printf("%-20s %lld\n", newContact[j].nama, newContact[j].nomor);
    }

    printf("\n\t\tTekan 1 untuk lanjut\n");
    int x = 0;
    buffer(x);
}

void sort()
{
    int x = 0;
    printf("\n\n\n\t\t\tSORT\t\n");
    printf("1. Bubble Sort || A - Z\n");
    printf("2. Selection Sort || Z - A\n");
    while (x != 1 || x != 2)
    {
        printf("Tekan 1 / 2 untuk memilih ->");
        scanf("%d", &x);
            switch (x)
            {
            case 1:
                bubble ();
                break;
            case 2:
                select ();
                break;
            default:
                printf("\nMasukkan angka yang benar!\n");
                break;
            }
    }
}

void search()
{
    // Implement search functionality
    int x;
    char f_name[50];
    printf("\n\n\n\t\t\tSEARCH\t\t\t\n");
    printf("1. Cari Nama\n");
    printf("2. Cari Nomor Handphone\n");
    printf("Tekan 1 / 2 untuk memilih ->");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Nama yang ingin dicari : ");
        getchar();
        fgets(f_name, sizeof(f_name), stdin);
        f_name[strcspn(f_name, "\n")] = '\0';
        strupr(f_name);
        for (int j = 0; j < contact_count; j++)
        {
            if (strcmp(newContact[j].nama, f_name) == 0)
            {
                printf("\n%-20s %s\n", "Nama", "No Handphone");
                printf("%-20s %lld\n", newContact[j].nama, newContact[j].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer(x);
                break;
            }
        }
        int x = 0;
        printf("Contact tidak ditemukan!\n");
        printf("Tekan 1.Menu\t\t2.Coba lagi");
        while (x != 1 || x != 2)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                menu();
            }
            else if (x == 2)
            {
                search();
            }
            else
            {
                printf("\nMasukkan angka yang benar!\n");
            }
        }
    }
    else if (x == 2)
    {
        long long int f_number;
        printf("Nomor yang ingin dicari : ");
        scanf("%lld", &f_number);
        for (int j = 0; j < contact_count; j++)
        {
            if (newContact[j].nomor == f_number)
            {
                printf("\n%-20s %s\n", "Nama", "No Handphone");
                printf("%-20s %lld\n", newContact[j].nama, newContact[j].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer(x);
                break;
            }
        }
        int x = 0;
        printf("Contact tidak ditemukan!\n");
        printf("Tekan 1.Menu\t\t2.Coba lagi");
        while (x != 1 || x != 2)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                menu();
            }
            else if (x == 2)
            {
                search();
            }
            else
            {
                printf("\nMasukkan angka yang benar!\n");
            }
        }
    }
}

void delete_contact()
{
    int x;
    char f_name[50];
    printf("\n\n\n\t\t\tDELETE\t\t\t\n");
    printf("1. Cari Nama\n");
    printf("2. Cari Nomor Handphone\n");
    printf("Tekan 1 / 2 untuk memilih -> ");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Nama yang ingin di hapus : ");
        getchar();
        fgets(f_name, sizeof(f_name), stdin);
        f_name[strcspn(f_name, "\n")] = '\0';
        strupr(f_name);
        for (int j = 0; j < contact_count; j++)
        {
            if (strcmp(newContact[j].nama, f_name) == 0)
            {
                for (int j = j; j < contact_count; j++)
                {
                    newContact[j] = newContact[j + 1];
                }
                del_count++;

                printf("\nContact %s telah di hapus", f_name);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer(x);
                break;
            }
        }
        int x = 0;
        printf("Contact tidak ditemukan!\n");
        printf("Tekan 1.Menu\t\t2.Coba lagi");
        while (x != 1 || x != 2)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                menu();
            }
            else if (x == 2)
            {
                search();
            }
            else
            {
                printf("\nMasukkan angka yang benar!\n");
            }
        }
    }
    else if (x == 2)
    {
        long long int f_number;
        printf("Nomor yang ingin di hapus : ");
        scanf("%lld", &f_number);
        for (int j = 0; j < contact_count; j++)
        {
            if (newContact[j].nomor == f_number)
            {
                newContact[j] = del;
                printf("\nContact %lld telah di hapus", f_number);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer(x);
                break;
            }
        }
        int x = 0;
        printf("Contact tidak ditemukan!\n");
        printf("Tekan 1.Menu\t\t2.Coba lagi");
        while (x != 1 || x != 2)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                menu();
            }
            else if (x == 2)
            {
                search();
            }
            else
            {
                printf("\nMasukkan angka yang benar!\n");
            }
        }
    }
}

void edit_contact()
{
    int x;
    char f_name[50];
    printf("\n\n\n\t\t\tEDIT\t\t\t\n");
    printf("1. Cari Nama\n");
    printf("2. Cari Nomor Handphone\n");
    printf("Tekan 1 / 2 untuk memilih ->");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Nama yang ingin di ubah : ");
        getchar();
        fgets(f_name, sizeof(f_name), stdin);
        f_name[strcspn(f_name, "\n")] = '\0';
        strupr(f_name);
        for (int j = 0; j < contact_count; j++)
        {
            if (strcmp(newContact[j].nama, f_name) == 0)
            {
                printf("Nama baru : ");
                scanf("%s", newContact[j].nama);
                strupr(newContact[j].nama);
                printf("No Handphone baru : ");
                scanf("%lld", &newContact[j].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer(x);
                break;
            }
        }
        int x = 0;
        printf("Contact tidak ditemukan!\n");
        printf("Tekan 1.Menu\t\t2.Coba lagi");
        while (x != 1 || x != 2)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                menu();
            }
            else if (x == 2)
            {
                search();
            }
            else
            {
                printf("\nMasukkan angka yang benar!\n");
            }
        }
    }
    else if (x == 2)
    {
        long long int f_number;
        printf("Nomor yang ingin di ubah : ");
        scanf("%lld", &f_number);
        for (int j = 0; j < contact_count; j++)
        {
            if (newContact[j].nomor == f_number)
            {
                printf("Nama baru : ");
                scanf("%s", newContact[j].nama);
                strupr(newContact[j].nama);
                printf("No Handphone baru : ");
                scanf("%lld", &newContact[j].nomor);

                printf("\n\t\tTekan 1 untuk lanjut\n");
                int x = 0;
                buffer(x);
                break;
            }
        }
        int x = 0;
        printf("Contact tidak ditemukan!\n");
        printf("Tekan 1.Menu\t\t2.Coba lagi");
        while (x != 1 || x != 2)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                menu();
            }
            else if (x == 2)
            {
                search();
            }
            else
            {
                printf("\nMasukkan angka yang benar!\n");
            }
        }
    }
}

void menu()
{
    int X;

    printf("\n\n\n\t\t\tMENU\t\t\t\n");
    printf("1. Tambah contact Baru\t\t2. List contact\t\t3. Sort contact\n");
    printf("4. Cari contact\t\t\t5. Hapus\t\t\t6. Edit\t\t\t\n7. Exit\n");

    scanf("%d", &X);

    switch (X)
    {
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

int main()
{
    menu();
    return 0;
}
