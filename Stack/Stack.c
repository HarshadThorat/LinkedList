#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Push(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn; 
    }
}


void Pop(PPNODE First)
{
    PNODE temp = *First;

    (*First) = (*First)->next;
    free(temp);
}

void Display(PNODE First)
{
    printf("Elements of the Stack are : \n");

    PNODE temp = First;

    while(temp != NULL)
    {
        printf(" | %d |->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int Count(PNODE First)
{
    int iCnt = 0;

    PNODE temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    int ret = 0;

    Push(&Head,101);
    Push(&Head,51);
    Push(&Head,21);
    Push(&Head,11);
    Display(Head);
    ret = Count(Head);
    printf("Number of elements are : %d\n",ret);

    Pop(&Head);
    Display(Head);
    ret = Count(Head);
    printf("Number of elements are : %d\n",ret);

    return 0;
}

