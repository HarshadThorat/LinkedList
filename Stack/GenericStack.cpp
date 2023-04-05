#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
        struct node<T> * First;

        Stack();

        void Push(T no);   //InsertFirst
        T Pop();           //DeleteFirst
        void Display();
        int Count();
};


template<class T>
Stack<T> :: Stack()
{
    First = NULL;
}

template<class T>
void Stack<T> :: Push(T no)
{
    struct node<T> * newn = new struct node<T>;

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

template<class T>
T Stack<T> :: Pop()
{
    if(First == NULL)
    {
        cout<<"Unable Poped elements as stack is empty\n";
        return (T)-1;
    }
    else
    {
        struct node<T> * temp = First;

        First = First->next;
        delete temp;     
    }
}

template<class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        cout<<"Elements of the Stack are : \n";
        struct node<T> * temp = First;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" |-> "; 
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

template<class T>
int Stack<T> :: Count()
{
    int iCnt = 0;

    if(First == NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        struct node<T> * temp = First;

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
    Stack <int>obj;
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

