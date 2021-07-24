using System;

namespace _1011
{
    class Program
    {
        static void readDouble(ref double foo) {
            foo = double.Parse(Console.ReadLine());
            return;
        }
    
        static void Main(string[] args)
        {
            double pi = 3.14159, cte=(4.0/3),radius=0;
            readDouble(ref radius);
            double ans = Math.Round(cte*pi*(radius*radius*radius),3);
            Console.WriteLine($"VOLUME = {ans.ToString("0.000")}");
        }
    }
}
