#include "header.h"

int main()
{
    List Data;
    int option = 0;
    createList(&Data);

start:
    system("cls");
    printf("Kondisi data : \n");
    printAll(Data);

    printf("Masukan Aksi :\n1. push (tambah)\n2. pop (hapus)\n3. exit\n: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        char charInput;
        printf("Masukan karakter : ");
        scanf("\n%c", &charInput);
        printf("Proses push dengan value: %c berhasil\n", charInput);
        push(&Data, charInput);
        break;
    }
    case 2:
    {
        printf("Proses pop dengan value: %c berhasil\n", Data.top);
        pop(&Data);
        break;
    }
    case 3:
    {
        printf("Program keluar...\n");
        getch();
        exit(1);
        break;
    }
    }
    printf("Tekan ENTER untuk melanjutkan...\n");
    getch();
    goto start;
    return 0;
}

#include "body.cpp"