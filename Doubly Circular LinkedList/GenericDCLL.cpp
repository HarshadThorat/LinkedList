#include<iostream>
using namespace std;
#pragma pack(1)

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    public:
        struct node<T> * First;
        struct node<T> * Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
};

template<class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void DoublyCL<T> ::  InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = Last =  newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;

    }
    (First)->prev = Last;
    (Last)->next = First;

}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = Last =  newn;

    }
    else
    {
        (Last)->next = newn;
        newn->prev = Last;
        Last = newn;

    }
    (First)->prev = Last;
    (Last)->next = First;

}

template<class T>
void DoublyCL<T> :: Display()
{
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of linked list are : "<<"\n"; 

    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;

    }while( temp != Last->next );
    cout<<"NULL\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while((temp != Last->next));
    return iCnt;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL  && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = (First)->next;
        delete First->prev;       //free((Last)->next); 
        (First)->prev = Last;
        (Last)->next = First;
    }
    
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{

    if(First == NULL  && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = (Last)->prev;
        delete First->prev;      //free((*Last)->next);
        (First)->prev = Last;
        (Last)->next = First;
    }   
}

template<class T>
void DoublyCL<T> :: InsertAtPosition(T no,int ipos)
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

    if(ipos < 1)
    {
        InsertFirst(no);
    }
    else if(ipos > NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(iCnt = 1; iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev= newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void DoublyCL<T> :: DeleteAtPosition(int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct node<T> * temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos < 1)
    {
        DeleteFirst();
    }
    else if(ipos > NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(iCnt = 1; iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    int iRet = 0;

    DoublyCL <int>iobj;

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