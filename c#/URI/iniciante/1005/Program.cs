using System;

namespace _1005
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = double.Parse(Console.ReadLine());
            double b = double.Parse(Console.ReadLine());
            double avg = ((a * 3.5)+ (b * 7.5))/11.0;
            double roundedAvg = Math.Round(avg,5);
            Console.WriteLine($"MEDIA = {roundedAvg.ToString("0.00000")}");
        }
    }
}
