// Generic Singly Circular Linked List in C++

#include<iostream>
using namespace std;
#pragma pack(1)

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyCL
{
    public:
        struct node<T> * First;
        struct node<T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
}; 

template<class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;

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

template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;

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

template<class T>
void SinglyCL<T> :: Display()
{
    cout<<"Elements of Linked list are : "<<"\n";
    struct node<T> * temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
    struct node<T> * temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
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

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> * temp = First;

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

template<class T>
void SinglyCL<T> :: InsertAtPosition(T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

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
        newn = new struct node<T>;

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

template<class T>
void SinglyCL<T> :: DeleteAtPosition(int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct node<T> * temp1 = NULL;
    struct node<T> * temp2 = NULL;

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
    int iRet = 0;

    SinglyCL <int>iobj;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.InsertAtPosition(105,5);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteAtPosition(5);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    iobj.DeleteFirst();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


    return 0;
}