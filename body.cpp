#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

using namespace std;

bool isEmpty()
{
    if (fronts == NULL && rear == NULL)
    {
        return true;
    }
    return false;
}

void insert_rear(int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (isEmpty())
    {
        fronts = new_node;
        rear = new_node;
    }

    else
    {
        rear->next = new_node;
        new_node->prev = rear;
        rear = new_node;
    }
}

void insert_front(int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (isEmpty())
    {
        fronts = new_node;
        rear = new_node;
    }

    else
    {
        new_node->next = fronts;
        fronts->prev = new_node->next;
        fronts = new_node;
    }
}

void delete_front()
{
    if (isEmpty())
    {
        printf("the queue is empty");
        return;
    }

    struct node *temp = fronts;

    fronts = temp->next;

    if (fronts == NULL)
    {
        rear = NULL;
    }
    else
    {
        fronts->prev = NULL;
    }

    delete (temp);
}

void delete_rear()
{
    if (isEmpty())
    {
        printf("the queue is empty");
        return;
    }

    struct node *temp = rear;
    rear = temp->prev;
    if (rear == NULL)
    {
        fronts = NULL;
    }
    else
    {
        rear->next = NULL;
    }
    temp->prev = NULL;

    delete (temp);
}

int getfront()
{
    return fronts->data;
}

int getrear()
{
    return rear->data;
}

void printqueue(struct node *fronts, struct node *rear)
{
    while (fronts != rear)
    {
        printf("%d ", fronts->data);

        fronts = fronts->next;
    }

    printf("%d\n", rear->data);
}

void insertBetween(struct node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}