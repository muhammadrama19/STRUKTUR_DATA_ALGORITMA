#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "body.cpp"

int main()
{

    printf("the original queue is:-\n");

    insert_rear(1);

    insert_front(2);

    insert_rear(3);

    printqueue(fronts, rear);

    printf("Memasukkan 4 di depan\n");

    insert_front(4);

    printqueue(fronts, rear);
    printf("Memasukkan 5 di belakang\n");

    insert_rear(5);

    printqueue(fronts, rear);
    printf("Memasukkan 6 di depan\n");

    insert_front(6);

    printqueue(fronts, rear);

    printf("Menghapus belakang\n");

    delete_rear();

    printqueue(fronts, rear);

    printf("Masukan 8 di antara fronts dan selanjutnya\n");
    insertBetween(fronts, 8);
    printqueue(fronts, rear);

    printf("Menghapus depan\n");

    delete_front();

    printqueue(fronts, rear);

    printf("Mendapatkan elemen depan\n");

    printf("%d\n", getfront());

    printf("Mendapatkan elemen belakang\n");

    printf("%d\n", getrear());

    return 0;
}