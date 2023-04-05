#include<iostream>
using namespace std;
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

class DoublyLL
{
    public:
        PNODE First;
        int iCount;

        DoublyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

DoublyLL :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        (First)->prev= newn;
        First = newn;
        iCount++;
    }
}
void DoublyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

void DoublyLL :: Display()
{
    cout<<"Elements of the Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void DoublyLL :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        First = First->next; 
        delete First->prev;
        First->prev = NULL;
        iCount--; 
    }
}

void DoublyLL :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }   
        delete temp->next;
        temp->next = NULL;
        iCount--;
    }
}

void DoublyLL :: InsertAtPosition(int no,int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
        
        iCount++;
    }
}

void DoublyLL :: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        
        PNODE temp2 = temp1->next;

        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;

        iCount--;
    }

}

int main()
{
    DoublyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.iCount<<"\n";
      
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.iCount<<"\n";
    
    obj.InsertAtPosition(105,5);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.iCount<<"\n";
    
    obj.DeleteAtPosition(5);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.iCount<<"\n";
    
    obj.DeleteFirst();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.iCount<<"\n";
    
    obj.DeleteLast();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.iCount<<"\n";
    

}


