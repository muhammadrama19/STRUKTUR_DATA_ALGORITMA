#include "header.h"

int main()
{
    List Data;
    int choice = 0;

    createList(&Data);

    insert_front(&Data, 'A');
    insert_front(&Data, 'B');
    insert_front(&Data, 'C');
    insert_front(&Data, 'D');
    insert_front(&Data, 'E');

Start:
    system("cls");
    printf("=======================================\n");
    printf("Kondisi Data:\n");
    printAll(Data);
    printAllReverse(Data);
    // printf("Data Awal : %c\n", getfront(Data));
    // printf("Data akhir : %c\n", getrear(Data));
    printf("=======================================\n");
    printf("Pilih Aksi:\n  1.Insert\n  2.Delete\n  3.Search\n  4.exit\n: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        caseInsert(&Data);
        printf("Proses insert berhasil\nTekan ENTER untuk melanjutkan...\n");
        getch();
        break;
    }
    case 2:
    {
        caseDelete(&Data);
        printf("Proses delete berhasil\nTekan ENTER untuk melanjutkan...\n");
        getch();
        break;
    }
    case 3:
    {
        printf("Masukan data yang ingin dicari: ");
        char temp = scanfChar();
        if (search(&Data, temp))
        {
            printDetail(*search(&Data, temp));
        }
        else
        {
            printf("Data tidak ditemukan!...\n");
        }
        printf("Tekan ENTER untuk melanjutkan...\n");
        getch();
        break;
    }
    default:
    {
        printf("Program keluar, Tekan ENTER untuk melanjutkan...");
        getch();
        exit(1);
        break;
    }
    }
    goto Start;
    return 0;
}
#include "body.cpp"
