#include<iostream>
using namespace std;

template<class T> 
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Queue
{
    public:
        struct node<T> * First;

        Queue();

        void EnQueue(int no);  //InsertLast
        int DeQueue();         //DeleteFirst
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    First = NULL;
}

template<class T>
void Queue<T> :: EnQueue(int no)
{

    struct node<T> * newn = new struct node<T>;
    struct node<T> *  temp = First;

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

template<class T>
int Queue<T> :: DeQueue()
{
    if(First == NULL)
    {
        cout<<"Unable to Pop the elements as stack is empty\n";
        return -1;
    }
    else
    {
        struct node<T> * temp = First;

        First = First->next;
        delete temp;
    }
}

template<class T>
void Queue<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        cout<<"Elements of the stack are : "<<"\n";

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
int Queue<T> :: Count()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        int iCnt = 0;

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
    Queue <int>obj;
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

