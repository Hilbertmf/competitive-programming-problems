using System;

namespace _1008
{
    class Program
    {
        static void Main(string[] args)
        {
            int employeeNum, hours;
            double wage, salary;

            employeeNum = int.Parse(Console.ReadLine());
            hours = int.Parse(Console.ReadLine());
            wage = double.Parse(Console.ReadLine());

            salary = Math.Round(wage * hours,2);

            Console.WriteLine($"NUMBER = {employeeNum}");
            Console.WriteLine($"SALARY = U$ {salary.ToString("0.00")}");
        }
    }
}
