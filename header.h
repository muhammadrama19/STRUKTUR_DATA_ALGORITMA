#ifndef header_H
#define header_H
#include <stdlib.h>
#include <stdio.h>

typedef struct tnode *address;
typedef struct tnode
{
    int data;
    address next;
    address prev;
}nodes;

typedef struct 
{
       address front;
       address rear;
}List;

address search(List l, int key);

bool isEmpty();
/*IS : Memeriksa apakah antrian kosong atau tidak. Jika fronts dan rear adalah NULL, maka antrian kosong*/
/*FS : Menghasilkan True jika linked list kosong atau false jika list memiliki elemen*/

void insert_rear(List* l, int new_data) ;
/*IS : menambahkan elemen baru ke belakang antrian
       Jika antrian kosong, maka elemen baru akan menjadi elemen pertama dan terakhir antrian
       Jika antrian tidak kosong, maka elemen baru akan menjadi elemen terakhir antrian dan elemen sebelumnya akan menjadi elemen kedua terakhir antrian.
/*FS : Menambah elemen baru pada akhir linked list. Pointer rear akan menunjuk ke elemen baru ini*/

void insert_front(List* l, int new_data);
/*IS : menambahkan elemen baru ke depan antrian.
       Jika antrian kosong, maka elemen baru akan menjadi elemen pertama dan terakhir antrian.
       Jika antrian tidak kosong, maka elemen baru akan menjadi elemen pertama antrian dan elemen setelahnya akan menjadi elemen kedua antrian*/
/*FS : Menambah elemen baru pada awal linked list. Pointer fronts akan menunjuk ke elemen baru ini*/

void delete_front(List* l);
/*IS : Menghapus elemen pertama dari antrian
       Jika antrian tidak kosong, maka elemen kedua akan menjadi elemen pertama antrian*/
/*FS : Menghapus elemen pertama pada linked list. Pointer rear akan menunjuk ke elemen sebelum elemen pertama*/

void delete_rear(List* l);
/*IS : Menghapus elemen terakhir dari antrian
       Jika antrian tidak kosong, maka elemen kedua akan menjadi elemen terakhir antrian*/
/*FS : Menghapus elemen terakhir pada linked list. Pointer rear akan menunjuk ke elemen sebelum elemen terakhir*/

int getfront(List l);
/*IS : Mengambil elemen pertama dari antrian
       Jika antrian tidak kosong, maka elemen pertama akan dikembalikan*/
/*FS : Menghasilkan nilai elemen pertama pada linked list*/

int getrear(List l);
/*IS : Mengambil elemen terakhir dari antriian
       Jika antrian tidak kosong, maka elemen terakhir akan dikembalikan*/
/*FS : Menghasilkan nilai elemen terakhir pada linked list*/

void printqueue(List l);
/*IS : Mencetak isi antrian dari depan ke belakang. Jika antrian tidak kosong, maka isi antrian akan dicetak*/
/*FS : Menampilkan semua elemen pada linked list dari elemen pertama hingga elemen terakhir*/

void insertBetween(List& l, int prev_data, int new_data);
#endif