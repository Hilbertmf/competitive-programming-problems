using System;

namespace _1013
{
    class Program
    {
        static int bigger(int n1, int n2) {
            if (n1>n2) {
                return n1;
            } 
            else {
                return n2;
            }
        }
        static int biggerOptimized(int n1, int n2) {
            return (n1 + n2 + Math.Abs(n1-n2))/2;
        }
        static void Main(string[] args)
        {
            var line = Console.ReadLine();
            var nums = line.Split(' ');

            int n1,n2,n3;
            n1 = int.Parse(nums[0]);
            n2 = int.Parse(nums[1]);
            n3 = int.Parse(nums[2]);

            int answer = bigger(n3, bigger(n1,n2));
            answer = biggerOptimized(n3,biggerOptimized(n1,n2));
            Console.WriteLine($"{answer} eh o maior");
        }
    }
}
