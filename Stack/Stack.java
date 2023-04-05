
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

    public void Push(int no)
    {
        Node newn = new Node(no);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            newn.next = First;
            First = newn;
        }
    }

    public void Pop()
    {
        if(First == null)
        {
            System.out.println("Unable Poped elements as stack is empty");
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
            System.out.println("stack is empty");
        }
        else
        {
            System.out.println("Elements of the Stack are : ");
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



class Stack
{
    public static void main(String arg[])
    {
        LinkList obj = new LinkList();

        obj.Push(101);
        obj.Push(51);
        obj.Push(21);
        obj.Push(11);
        obj.Display();
        int ret = obj.Count();
        System.out.println("Number of elements are :  "+ret);

        obj.Pop();
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are :  "+ret);

    }
}