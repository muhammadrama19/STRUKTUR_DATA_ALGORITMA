#include "header.h"

infotype scanfChar()
{
    char *Temp = (char *)malloc(sizeof(infotype) * 100);
Start:
    scanf("%s", Temp);

    if (strlen(Temp) > 1 || strlen(Temp) < 1)
    {
        printf("input tidak valid, masukan value baru: ");
        goto Start;
    }
    return Temp[0];
}

void printDetail(nodes Elemen)
{
    if (Elemen.next != NULL && Elemen.prev != NULL)
    {
        printf("Elemen [%c] terhubung dengan [%c] dan [%c]", Elemen.data, Elemen.next->data, Elemen.prev->data);
    }
    else if (Elemen.next == NULL)
    {
        printf("Elemen [%c] terhubung dengan [%c]", Elemen.data, Elemen.prev->data);
    }
    else if (Elemen.prev == NULL)
    {
        printf("Elemen [%c] terhubung dengan [%c]", Elemen.data, Elemen.next->data);
    }

    printf("\n\nGambaran RAM :\n[%c] -> [%c] -> [%c]\n[%c] <- [%c] <- [%c]\n\n", Elemen.prev->data, Elemen.data, Elemen.next->data, Elemen.prev->data, Elemen.data, Elemen.next->data);
}

void caseInsert(List *Data)
{
    infotype temp = 0;
    printf("Masukan value yang diinginkan: ");
    temp = scanfChar();
    insert_front(&(*Data), temp);
}

void caseDelete(List *Data)
{

    delete_rear(&(*Data));
}

void createList(List *Data)
/*Melakukan initialisasi terhadap pointer yang menunjuk list*/
{
    (*Data).front = NULL;
}

bool isEmpty(List Penunjuk)
/*Melakukan pengecekan terhadap jumlah data yang dimiliki list, return true jika kosong*/
{
    // Khusus untuk circular karena hanya memiliki front
    if (Penunjuk.front == NULL)
    {
        return true;
    }
    return false;
}
void printAll(List Data)
/*Melakukan print index 1-n*/
{
    if (!isEmpty(Data))
    {
        // temp sebagai travelsal
        address temp = Data.front;

        int i = 0;
        // Selama temp bukanlah data awal
        while (temp != Data.front || i == 0)
        {
            printf("%c ", toupper(temp->data));
            temp = temp->next;
            i++;
        }
    }
    else
    {
        printf("List kosong");
    }
    printf("\n");
}
void printAllReverse(List Data)
/*Melakukan print index n-1*/

{

    if (!isEmpty(Data))
    {
        // temp untuk traversal
        address temp = Rear(Data);

        int i = 0;
        // stop saat ada di rear
        while (temp != Rear(Data) || i == 0)
        {
            printf("%c ", toupper(temp->data));
            // Menggeser travelsal ke elemen sebelumnya (gerak mundur)
            temp = temp->prev;
            i++;
        }
    }
    else
    {
        printf("List kosong");
    }
    printf("\n");
}

address Alokasi(infotype X)
{
    // alokasi assign data
    address P;
    /* Algoritma */
    P = (address)malloc(sizeof(nodes));
    if (P != NULL) /* Alokasi berhasil */
    {

        P->data = X;
        // default circular akan mengisi next dan prev nya dengan dirinya sendiri saat pertama kali pemesanan
        P->next = P;
        P->prev = P;
    }
    else // Ketika alokasi gagal, program akan berhenti
    {
        printf("ALOKASI GAGAL, TIDAK ADA MEMORI TERSISA!\nPROGRAM KELUAR....\n");
        getch();
        exit(0);
    }
    return (P);
}

void insert_front(List *Penunjuk, infotype new_data)
{
    address new_node = Alokasi(new_data);
    if (isEmpty(*Penunjuk))
    {
        // kondisi masih kosong maka front dan rear menunjuk node yang sama
        (*Penunjuk).front = new_node;
        Rear(*Penunjuk) = new_node;
    }
    else // Jika terdapat elemen pada list, perlu adanya pengubahan hubungan
    {

        // A B C
        // mau masukin X
        // awalnya X -> X <- X

        // Next dari elemen baru dihubungkan dengan front
        // diubah X -> A //next dari X
        new_node->next = (*Penunjuk).front;

        // diubah C <- X // prev dari X
        // prev x akan menunjuk ke c
        new_node->prev = Rear(*Penunjuk);

        // Semula elemen akhir menujuk ke A, diubah menjadi menunjuk ke X
        Rear((*Penunjuk))->next = new_node;

        // A bagian prev menjadi ke x
        (*Penunjuk).front->prev = new_node;

        // Mengubah front menjadi menunjuk X
        (*Penunjuk).front = new_node;
    }
}

void insert_rear(List *Penunjuk, infotype new_data)
{
    address new_node = Alokasi(new_data);

    if (isEmpty(*Penunjuk))
    {
        // Jika empty, gunakan algoritma pada front untuk menambah 1 elemen
        insert_front(Penunjuk, new_data);
        free(new_node);
    }
    else
    {
        // A B C
        // mau masukin X
        // extected = A B C X
        // awalnya X -> X <- X

        // X bagian next nya nyambung ke A
        new_node->next = (*Penunjuk).front;

        // x bagian prev ke C
        new_node->prev = Rear(*Penunjuk);

        // c next ke X
        Rear((*Penunjuk))->next = new_node;

        // subvar A menunjuk ke X
        (*Penunjuk).front->prev = new_node;
    }
}

address search(List *Penunjuk, infotype key)
/*Mencari elemen dan mereturn alamat dari elemen yang dicari tersebut*/
{
    address temp = (*Penunjuk).front;

    int i = 0;
    while (temp != (*Penunjuk).front || i == 0) // Perulangan hingga akhir data
    {
        if (toupper(temp->data) == toupper(key)) // not case sensitive
        {
            return temp;
        }
        temp = temp->next;
        i++;
    }

    return NULL;
}

void delete_front(List *Penunjuk)
{
    if ((*Penunjuk).front == NULL)
    {
        printf("DELETE GAGAL, LIST KOSONG !");
    }
    else
    {
        // A B C
        // temp = A
        // front = A
        address temp = (*Penunjuk).front;

        // front = B
        (*Penunjuk).front = temp->next;

        // Menghubungkan prev B ke address C
        (*Penunjuk).front->prev = temp->prev;
        // Menghubungkan next C ke address B
        temp->prev->next = (*Penunjuk).front;

        temp->next = NULL;
        temp->prev = NULL;

        free(temp);
    }
}

void delete_rear(List *Penunjuk)
{
    if (isEmpty(*Penunjuk)) // kondisi saat masih kosong
    {
        printf("DELETE GAGAL, LIST KOSONG !");
    }
    else
    {
        // A B C
        // delete C
        // expected = A B
        // front = A
        // rear = C
        // temp = C

        address temp = Rear(*Penunjuk); // temp diisi elemen akhir
        // rear = B
        Rear(*Penunjuk) = temp->prev;                     // pref dari elemen awal menunjuk ke elemen sebelum temp
        if (Rear((*Penunjuk))->next == (*Penunjuk).front) // Jika hanya 1 data
        {
            (*Penunjuk).front = NULL;
        }
        else
        {
            // B -> C
            // B NEXT konek ke A
            // menjadi B -> A
            Rear((*Penunjuk))->next = (*Penunjuk).front;
            // KONEK subvar prev dari A JADI KE B
            (*Penunjuk).front->prev = Rear(*Penunjuk);
        }
        // NULL C sebelum dihapus
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

infotype getfront(List Penunjuk)
{
    return toupper(Penunjuk.front->data);
}

infotype getrear(List Penunjuk)
{
    return toupper(Rear(Penunjuk)->data);
}