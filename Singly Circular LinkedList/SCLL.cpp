// Singly Circular Linked List in C++

#include<iostream>
using namespace std;
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
    public:
        PNODE First;
        PNODE Last;

        SinglyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
}; 

SinglyCL :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

void SinglyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

void SinglyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

void SinglyCL :: Display()
{
    cout<<"Elements of Linked list are : "<<"\n";
    PNODE temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

int SinglyCL :: Count()
{
    PNODE temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

void SinglyCL :: DeleteFirst()
{

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;   //*Last = NULL;  
    }
    else
    {
        (First) = (First)->next;
        delete((Last)->next);
        (Last)->next = First;
    }
}

void SinglyCL :: DeleteLast()
{
    PNODE temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;     
    }
    else
    {
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete(Last);  //free(temp->next)
        (Last) = temp;
        (Last)->next = First;
    }
}

void SinglyCL :: InsertAtPosition(int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        temp =First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }

}

void SinglyCL :: DeleteAtPosition(int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }
}

int main()
{
    SinglyCL obj; 
    int iRet = 0;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.InsertAtPosition(105,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteAtPosition(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    return 0;
}