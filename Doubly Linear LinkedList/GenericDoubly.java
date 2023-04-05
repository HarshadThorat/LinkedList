import java.util.*;

class Node<T>
{
    public T data;
    public Node next;
    public Node prev;

    public Node(T no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class LinkList<T>
{
    public Node First;

    public LinkList()
    {
        First = null;
    }

    public void InsertFirst(T no)
    {
        Node newn = new Node(no);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            newn.next = First;
            First.prev = newn;
            First = newn;
        }
    }
    public void InsertLast(T no)
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
            newn.prev = temp;
        }
    }
    public void Display()
    {
        Node temp = First;

        System.out.println("Elements of the linked list are : ");

        while(temp != null)
        {
            System.out.print(" | "+temp.data+" |<=> ");
            temp = temp.next;
        }
        System.out.println("null");
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

    public void DeleteFirst()
    {
        if(First == null)
        {
            return;
        }
        else if(First.next == null)
        {
            First = null;
        }
        else
        {
            First = First.next;
            First.prev = null;
        }
    }
    public void DeleteLast()
    {
        if(First == null)
        {
            return;
        }
        else if(First.next == null)
        {
            First = null;
        }
        else
        {
            Node temp = First;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
    }

    public void InsertAtPosition(T no, int ipos)
    {
        int NodeCnt = 0;

        NodeCnt = Count();

        if((ipos < 1) || (ipos > NodeCnt+1))
        {
            System.out.println("Invalid Position");
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
            Node newn = new Node(no);

            Node temp = First;

            for(int iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp.next;
            } 
            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;
        }
    }
    public void DeleteAtPosition(int ipos)
    {
        int NodeCnt = 0;

        NodeCnt = Count();

        if((ipos < 1) || (ipos > NodeCnt))
        {
            System.out.println("Invalid Position");
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
            Node temp = First;

            for(int iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp.next;
            } 
            temp.next = temp.next.next;
            temp.next.prev = temp;
        }
    }
}

class GenericDoubly
{
    public static void main(String arg[])
    {
        LinkList <Integer>obj = new LinkList<Integer>();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();
        int ret = obj.Count();
        System.out.println("Number of elements are : "+ret);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are : "+ret);

        obj.InsertAtPosition(105,5);
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are : "+ret);

        obj.DeleteAtPosition(5);
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are : "+ret);

        obj.DeleteFirst();
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are : "+ret);

        obj.DeleteLast();
        obj.Display();
        ret = obj.Count();
        System.out.println("Number of elements are : "+ret);

    } 
}