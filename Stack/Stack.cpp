#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Stack
{
    public:
        struct node * First;

        Stack();

        void Push(int no);   //InsertFirst
        int Pop();           //DeleteFirst
        void Display();
        int Count();
};



Stack :: Stack()
{
    First = NULL;
}

void Stack :: Push(int no)
{
    struct node * newn = new struct node;

    newn->data= no;
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

int Stack :: Pop()
{
    if(First == NULL)
    {
        cout<<"Unable Poped elements as stack is empty\n";
        return -1;
    }
    else
    {
        struct node * temp = First;

        First = First->next;
        delete temp;     
    }
}

void Stack :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        cout<<"Elements of the Stack are : \n";
        struct node * temp = First;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" |-> "; 
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

int Stack :: Count()
{
    int iCnt = 0;

    if(First == NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        struct node * temp = First;

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
    Stack obj;
    int ret = 0;

    obj.Push(101);
    obj.Push(51);
    obj.Push(21);
    obj.Push(11);
    obj.Display();
    ret = obj.Count();
    cout<<"Number of elements are : "<<ret<<"\n";

    obj.Pop();
    obj.Display();
    ret = obj.Count();
    cout<<"Number of elements are : "<<ret<<"\n";

    return 0;
}

