
class Node
{
    public int data;
    public Node next;

    public Node(int No)
    {
        data = No;
        next = null;
    }
}

class LinkList
{
    public Node First;

    public LinkList()
    {
        First = null;   
    } 

    public void EnQueue(int no)           //InsertLast
    {
        Node newn = new Node(no);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            Node temp = First;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
    }

    public void DeQueue()           //DeleteFirst
    {
        if(First == null)
        {
            System.out.println("Unable DeQueue elements as Queue is empty");
            return;
        }
        else
        {
            First = First.next;
        }
    }

    public void Display()
    {
        if(First == null)
        {
            System.out.println("Queue is empty");
        }
        else
        {
            System.out.println("Elements of the Queue are : ");
            Node temp = First;

            while(temp != null)
            {
                System.out.print(" | "+temp.data+" |-> "); 
                temp = temp.next;
            }
            System.out.println("null");
        }
    }

    public int Count()
    {
        int iCnt = 0;

        Node temp = First;

        while(temp != null)
        {
            iCnt++;
            temp = temp.next;
        }
        return iCnt;
    }
}



class Queue
{
    public static void main(String arg[])
    {
        LinkList obj = new LinkList();

        obj.EnQueue(101);
        obj.EnQueue(51);
        obj.EnQueue(21);
        obj.EnQueue(11);
        obj.Display();
        int ret = obj.Count();
        System.out.println("Number of elements are :  "+ret);

        obj.DeQueue();
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are :  "+ret);

    }
}