using System;

namespace _1006
{
    class Program
    {
        static void Main(string[] args)
        {            
            double a = double.Parse(Console.ReadLine());
            double b = double.Parse(Console.ReadLine());
            double c = double.Parse(Console.ReadLine());
            double avg = Math.Round( ( (a*2)+(b*3)+(c*5) )/10 , 2);
            Console.WriteLine($"MEDIA = {avg.ToString("0.0")}");
        }
    }
}
