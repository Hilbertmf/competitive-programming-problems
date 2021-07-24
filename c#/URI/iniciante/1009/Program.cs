using System;

namespace _1009
{
    class Program
    {
        static void readBool(ref bool foo) {
            foo = bool.Parse(Console.ReadLine());
            return;
        }
        static void readDouble(ref double foo) {
            foo = double.Parse(Console.ReadLine());
            return;
        }
        static void readInt(ref int foo) {
            foo = int.Parse(Console.ReadLine());
            return;
        }
        static void readStr(ref string foo) {
            foo = Console.ReadLine();
            return;
        }
        
        static void Main(string[] args)
        {
            string name=" ";
            double salary=0, sales=0, commission=0, total=0;

            readStr(ref name);
            readDouble(ref salary);
            readDouble(ref sales);

            commission = sales * 0.15;
            total = Math.Round(salary + commission, 2);
            Console.WriteLine($"TOTAL = R$ {total.ToString("0.00")}");
        }
    }
}
