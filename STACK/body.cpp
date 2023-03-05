#include "header.h"

void createList(List *Data)
/*Melakukan initialisasi terhadap pointer yang menunjuk list*/
{
    (*Data).top = NULL;
    (*Data).bottom = NULL;
}
address Alokasi(infotype X)
{
    address P;
    /* Algoritma */
    P = (address)malloc(sizeof(nodes));
    if (P != NULL) /* Alokasi berhasil */
    {
        P->data = X;
        // default adalah NULL, tidak koneksi ke manapun
        P->next = NULL;
    }
    else
    {
        printf("ALOKASI GAGAL, TIDAK ADA MEMORI TERSISA!\nPROGRAM KELUAR....\n");
        getch();
        exit(0);
    }
    return (P);
}

bool isEmpty(List Penunjuk)
/*Melakukan pengecekan terhadap jumlah data yang dimiliki list, return true jika kosong*/
{
    // Jika front dan rear NULL, artinya list kosong
    if (Penunjuk.top == NULL && Penunjuk.bottom == NULL)
    {
        return true;
    }
    return false;
}

void push(List *Penunjuk, infotype new_data)
{
    address new_node = Alokasi(new_data);
    if (isEmpty(*Penunjuk))
    { // kondisi satu node
        (*Penunjuk).top = new_node;
        (*Penunjuk).bottom = new_node;
    }
    else
    {
        // A B C
        // push X
        // F.S: X A B C

        // x subvar next sambungkan ke A
        // X --> A
        new_node->next = (*Penunjuk).top;

        // mengubah front menjadi menujuk ke X
        (*Penunjuk).top = new_node;
    }
}

void pop(List *Penunjuk)
{
    if (isEmpty(*Penunjuk))
    {
        printf("POP GAGAL, LIST KOSONG !");
    }
    else
    {

        // A B C
        // F.S = B C

        address temp = (*Penunjuk).top;

        // FRONT MAJU SATU NODE
        (*Penunjuk).top = temp->next;

        if ((*Penunjuk).top == NULL) // membuat kedua penjunjuk menjadi NULL agar list kosong jika sebelumnya hanya memiliki 1 elemen
        {
            (*Penunjuk).bottom = NULL;
        }
        else
        {
            // mengubah next dari A menjadi NULL sebelum dilakukan dealokasi
            temp->next = NULL;
        }

        free(temp);
    }
}

void printAll(List Data)
/*Melakukan print index 1-n*/
{
    if (!isEmpty(Data))
    {
        // temp sebagai travelsal
        address temp = Data.top;
        while (temp != NULL)
        {
            printf("%c ", toupper(temp->data));
            temp = temp->next;
        }
    }
    else
    {
        printf("List kosong");
    }
    printf("\n");
}