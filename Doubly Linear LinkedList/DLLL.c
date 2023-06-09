#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}
void InsertLast(PPNODE First,int no)
{
    PNODE newn  = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }    
        temp->next = newn;
        newn->prev = temp;
    }
}

void Display(PNODE First)
{
	printf("Elements of Linked List are\n");

	while(First != NULL)
	{
		printf(" | %d |<=> ",First->data);
		First = First->next;
	}
	printf("NULL\n");
}

int Count(PNODE First)
{
	int iCnt = 0;

	while(First != NULL)
	{
		iCnt++;
		First = First->next;
	}
	return iCnt;
}

void DeleteFirst(PPNODE First)
{
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        (*First) = (*First)->next;
        free((*First)->prev);
        (*First)->prev = NULL;
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPosition(PPNODE First,int ipos,int no)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        printf("invalid Position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

        temp = *First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }        
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteAtPosition(PPNODE First,int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        printf("invalid Position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == NodeCnt+1)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }    
        temp2 = temp1->next;

        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    InsertAtPosition(&Head,5,105);
	Display(Head);
	iRet = Count(Head);
	printf("Number of elements are : %d\n ",iRet);

	DeleteAtPosition(&Head,5);
	Display(Head);
	iRet = Count(Head);
	printf("Number of elements are : %d\n ",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    return 0;
}