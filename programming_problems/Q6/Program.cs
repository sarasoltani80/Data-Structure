using System;

namespace ConsoleApp72
{
    public class Node
    {
        public long number { set; get; }
        public Node next { set; get; }
        public Node(long num)
        {
            number = num;
            next = null;
        }
    }

    public class shomaredahi
    {
        private Node head;
        private long[] searcharray = new long[100000];
        public shomaredahi()
        {
            head = null;
            for (long i = 0; i < 100000; i++)
                searcharray[i] = 0;
        }

        public void AddLeft(long num)
        {
            Node new_node = new Node(num);
            new_node.next = head;
            head = new_node;
            searcharray[num] = 0;
        }

        public long removeFirstNode()
        {
            if (head == null)
                return -1;
            long shomare = head.number;
            Node temp = head;
            head = head.next;
            searcharray[shomare] = 1;
            return shomare;
        }

        public string searchIfbusy(long num)
        {
            if (searcharray[num] == 1)
                return "busy number";
            else
                return "free number";
        }


    }
    class Program
    {
        static void Main(string[] args)
        {
            shomaredahi Number = new shomaredahi();

            //create the list of phonenumbers
            for(long i=0;i<100000;i++)
            {
                Number.AddLeft(i);
            }

            Console.WriteLine("if you want to get new number enter 1");
            Console.WriteLine("if you want to search if a number is busy or not enter 2");
            Console.WriteLine("if you want to free a number enter 3");
            Console.WriteLine("if you dont want non of them enter 4");
            int n = 1;

            while (n != 4)
            {


                n = Convert.ToInt32(Console.ReadLine());

                if (n == 1)
                {
                    long phonenumber = Number.removeFirstNode();
                    Console.Write("your number would be:");
                    Console.WriteLine(phonenumber);
                }

                if (n == 2)
                {
                    Console.WriteLine("enter the number you want to check");
                    Console.WriteLine(Number.searchIfbusy(Convert.ToInt32(Console.ReadLine())));

                }

                if (n == 3)
                {
                    Console.WriteLine("enter the number you want to free");
                    Number.AddLeft(Convert.ToInt32(Console.ReadLine()));
                }
            }
        }
    }
}
