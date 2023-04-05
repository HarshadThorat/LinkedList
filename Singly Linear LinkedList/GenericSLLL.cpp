#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
        struct node<T> * First;

        SinglyLL();
        void InsertFirst(T No);
        void InsertLast(T no);
        void InsertAtPosition(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);


        void Display();
        int Count();
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T No)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template<class T>
void SinglyLL<T>:: InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

template<class T>
void SinglyLL<T> :: Display()
{
    struct node<T> *temp = First;
    cout<<"Elements of the Linked List are : "<<"\n";

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |-> ";
        temp = temp->next;
    } 
    cout<<"NULL\n";
}

template<class T>
int SinglyLL<T> :: Count()
{
    struct node<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    } 
    return iCnt;;
}

template<class T>
void SinglyLL<T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T> * temp = First;

        First = First->next;
        delete temp;
    }
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template<class T>
void SinglyLL<T> :: InsertAtPosition(T no, int ipos)
{
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        struct node<T> * temp = First;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyLL<T> :: DeleteAtPosition(int ipos)
{
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp1 = First;
        struct node<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        } 
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}



int main()
{
    int iRet = 0;

    SinglyLL <int>iobj;

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
