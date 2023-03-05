#include <stdlib.h>
#include <stdio.h>
#include "body.cpp"

int main()
{
    int input = 0;
    int tempDelOpt = 0;
    int tempBetween = 0;
    int tempVal = 0;
    int opsiBetween = 0;
    bool running = true;

    List l;

    createList(&l);

    insert_rear(&l, 1);
    insert_front(&l, 2);
    insert_rear(&l, 3);

    printf("Kondisi awal node:-\n");
    printqueue(l);

    while (running)
    {
        printf("\n1.Insert\n2.Delete\n3.Keluar\n");
        printf("Masukan pilihan anda: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("\n1.Insert Depan.\n2.Insert Belakang\n ");
            printf("\nMasukan pilihan anda: ");
            scanf("%d", &opsiBetween);
            switch (opsiBetween)
            {
            case 1:
                printf("Masukkan angka untuk insert di depan: ");
                scanf("%d", &input);
                insert_front(&l, input);
                printqueue(l);
                break;
            case 2:
                printf("\nMasukkan angka untuk insert di belakang: ");
                scanf("%d", &input);
                insert_rear(&l, input);
                printqueue(l);
                break;
            default:
                printf("Masukan pilihan yang benar.\n");
                break;
            }
            break;
        case 2:
            {
            printf("\n1.Delete Depan.\n2.Delete Belakang\n");
            printf("\nMasukan pilihan anda:");
            scanf("%d", &tempDelOpt);
            switch (tempDelOpt)
            {
            case 1:
                {
                delete_front(&l);
                printf("Menghapus elemen depan\n");
                printqueue(l);
                break;
                }
            case 2:
                {
                delete_rear(&l);
                printf("Menghapus elemen belakang\n");
                printqueue(l);
                break;
                }
            default:
                {
                printf("Masukan pilihan yang benar.\n");
                break;
                }
            }
            }
            break;
        case 3:
        {
            running = false;
            break;
        }
        default:
            printf("Masukan pilihan yang benar.\n");
            break;
        }
    }

    return 0;
}
