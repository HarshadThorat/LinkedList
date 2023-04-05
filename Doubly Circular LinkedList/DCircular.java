import java.util.*;

class Node
{
    public int data;
    public Node next;
    public Node prev;

    public Node(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}


class LinkList
{
    public Node First;
    public Node Last;
    
    public LinkList()
    {
        First = null;
        Last = null;
    } 

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);
        
        if(First == null  && Last == null)
        {
            First = Last = newn;
        }
        else
        {
            newn.next = First;
            First.prev = newn;
            First = newn;
        }
        First.prev = Last;
        Last.next = First;
    }

    public void InsertLast(int no)
    {
        Node newn = new Node(no);
        
        if(First == null  && Last == null)
        {
            First = Last = newn; 
        }
        else
        {
            Last.next = newn;
            newn.prev = Last;
            Last = newn;
        }
        First.prev = Last;
        Last.next = First;
    }

    public void Display()
    {
        Node temp = First;

        System.out.println("Elements of the linked list are : ");

        do
        {
            System.out.print(" | "+temp.data+" |(=) ");
            temp = temp.next;
        }while(temp != Last.next);
        System.out.println("null");
    }

    public int Count()
    {
        int iCnt = 0;

        Node temp = First;

        do
        {
            iCnt++;
            temp = temp.next;
        }while(temp != Last.next);
        return iCnt;
    }

    public void DeleteFirst()
    {
        if(First == null && Last == null)
        {
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            First = First.next;
            First.prev = Last;
            Last.next = First;
        }
    }
    public void DeleteLast()
    {
        if(First == null && Last == null)
        {
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            Node temp = First;

            while(temp.next != Last)
            {
                temp = temp.next;
            }
            Last = temp;
            First.prev = Last;
            Last.next = First;
        }
    }

    public void InsertAtPosition(int no, int ipos)
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

class DCircular
{
    public static void main(String arg[])
    {
        LinkList obj = new LinkList();

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