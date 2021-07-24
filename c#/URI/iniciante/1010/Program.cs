using System;

namespace _1010
{
    class Program
    {
        static void Main(string[] args)
        {
            int numParts1=0, numParts2=0;
            double value1=0, value2=0, answer=0;

            var line = Console.ReadLine();
            var nums = line.Split(' ');
            
            numParts1 = int.Parse(nums[1]);
            value1 = double.Parse(nums[2]);
            
            line = Console.ReadLine();
            nums = line.Split(' ');

            numParts2 = int.Parse(nums[1]);
            value2 = double.Parse(nums[2]);

            answer = Math.Round(numParts1*value1 + numParts2*value2,2);
            Console.WriteLine($"VALOR A PAGAR: R$ {answer.ToString("0.00")}");
        }
    }
}
