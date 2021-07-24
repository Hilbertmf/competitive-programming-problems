using System;

namespace _1014
{
    class Program
    {
        static void readDouble(ref double foo) {
            foo = double.Parse(Console.ReadLine());
            return;
        }
        static void readInt(ref int foo) {
            foo = int.Parse(Console.ReadLine());
            return;
        }

        static void Main(string[] args)
        {
            int dist=0;
            double liters=0;

            readInt(ref dist);
            readDouble(ref liters);

            Console.WriteLine($"{Math.Round(dist/liters,3).ToString("0.000")} km/l");
        }
    }
}
