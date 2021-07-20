using System;

namespace _1002
{
    class Program
    {
        static void Main(string[] args)
        {
            double pi = 3.14159;
            double radius = double.Parse(Console.ReadLine());
            double answer = Math.Round(pi * (radius * radius),4);

            Console.WriteLine($"A={answer.ToString("0.0000")}");
        }
    }
}
