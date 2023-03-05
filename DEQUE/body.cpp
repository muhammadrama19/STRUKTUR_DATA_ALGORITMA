#include "header.h"

void createList(List *list){
    (*list).front=NULL;
    (*list).rear=NULL;
}

bool isEmpty(List l)
{
    if (l.front == NULL && l.rear == NULL)
    {
        return true;
    }
    return false;
}

void insert_rear(List *l, int new_data)
{

    address new_node = (address)malloc(sizeof(nodes));

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (isEmpty(*l))
    {
        l->front = new_node;
        l->rear = new_node;
    }
    else
    {
        (l->rear)->next = new_node;
        new_node->prev = l->rear;
        l->rear = new_node;
    }
}
void insert_front(List *l, int new_data)
{
    address new_node = (address)malloc(sizeof(nodes));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (isEmpty(*l))
    {
        l->front = new_node;
        l->rear = new_node;
    }
    else
    {
        new_node->next = l->front;
        (l->front)->prev = new_node;
        l->front = new_node;
    }
}

void delete_front(List *l)
{
    if (isEmpty(*l))
    {
        printf("Linked List Kosong.\n");
        return;
    }

    address temp = l->front;

    l->front = temp->next;

    if (l->front == NULL) //kasus satu elemen
    {
        l->rear = NULL;
    }
    else
    {
        (l->front)->prev = NULL;
    }

    free(temp);
}

void delete_rear(List *l)
{
    if (isEmpty(*l))
    {
        printf("Queue underflow.\n");
        return;
    }

    address temp = l->rear;
    l->rear = temp->prev;
    if (l->rear == NULL) //kasus satu elemen
    {
        l->front = NULL;
    }
    else
    {
        (l->rear)->next = NULL;
    }
    temp->prev = NULL;

    free(temp);
}

void printqueue(List l)
{
    address temp = l.front;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
