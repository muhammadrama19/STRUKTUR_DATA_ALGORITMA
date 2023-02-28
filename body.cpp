#include "header.h"

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

address search(List l, int key)
{
    address temp = l.front;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
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
        printf("Queue underflow.\n");
        return;
    }

    address temp = l->front;

    l->front = temp->next;

    if (l->front == NULL)
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
    if (l->rear == NULL)
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

int getfront(List l)
{
    return (l.front)->data;
}

int getrear(List l)
{
    return (l.rear)->data;
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
void insertBetween(List &l, int prev_data, int new_data)
{

    address prev_node = search(l, prev_data);
    if (prev_node == NULL)
    {
        printf("Data dengan %d tidak ada \n", prev_data);
        return;
    }
    else
    {
        address new_node = (address)malloc(sizeof(nodes));
        new_node->data = new_data;
        new_node->prev = prev_node;
        new_node->next = prev_node->next;

        if (prev_node->next != NULL)
        {
            prev_node->next->prev = new_node;
        }

        prev_node->next = new_node;
    }
}

void delete_by_key(List *l, int key) {
    address temp = search(*l, key);

    if (temp == NULL) {
        printf("Node tidak ada.\n");
        return;
    }

    if (temp == l->front) {
        delete_front(l);
        return;
    }

    if (temp == l->rear) {
        delete_rear(l);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
