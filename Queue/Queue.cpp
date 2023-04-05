#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class Queue
{
    public:
        PNODE First;

        Queue();

        void EnQueue(int no);  //InsertLast
        int DeQueue();         //DeleteFirst
        void Display();
        int Count();
};

Queue :: Queue()
{
    First = NULL;
}

void Queue :: EnQueue(int no)
{

    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }     
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }         
        temp->next = newn;
    }
}

int Queue :: DeQueue()
{
    if(First == NULL)
    {
        cout<<"Unable to Pop the elements as stack is empty\n";
        return -1;
    }
    else
    {
        PNODE temp = First;

        First = First->next;
        delete temp;
    }
}

void Queue :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        cout<<"Elements of the stack are : "<<"\n";

        PNODE temp = First;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" |-> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}


int Queue :: Count()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
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
}

int main()
{
    Queue obj;
    int ret = 0;

    obj.EnQueue(101);
    obj.EnQueue(51);
    obj.EnQueue(21);
    obj.EnQueue(11);
    obj.Display();
    ret = obj.Count();
    cout<<"DeQueue element is : "<<ret<<"\n";
    
    obj.DeQueue();
    obj.Display();
    ret = obj.Count();
    cout<<"DeQueue element is : "<<ret<<"\n";
    
    return 0;
}

