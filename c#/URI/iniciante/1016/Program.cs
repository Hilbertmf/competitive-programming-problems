using System;

namespace _1016
{
    class Program
    {
        static void readInt(ref int foo) {
            foo = int.Parse(Console.ReadLine());
            return;
        }
        static void Main(string[] args)
        {
            int dist=0;
            readInt(ref dist);

            // relative velocity between Y car and X car is 30km/h = 0.5km/min
            // so given distance print time in minutes

            Console.WriteLine($"{dist*2} minutos");
        }
    }
}
