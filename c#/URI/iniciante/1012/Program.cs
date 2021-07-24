using System;

namespace _1012
{
    class Program
    {
        static string formatter(double n) {
            return Math.Round(n,3).ToString("0.000");
        }
        static void Main(string[] args)
        {
            double a,b,c;
            var line = Console.ReadLine();
            var nums = line.Split(' ');
            a=double.Parse(nums[0]);
            b=double.Parse(nums[1]);
            c=double.Parse(nums[2]);

            double triangleArea, circleArea, trapezoidArea, squareArea, rectangleArea;
            triangleArea = (a*c)/2;
            circleArea = 3.14159 * c * c;
            trapezoidArea = ((a+b)/2)*c;
            squareArea = b*b;
            rectangleArea = a*b;

            Console.WriteLine($"TRIANGULO: {(formatter(triangleArea))}\nCIRCULO: {formatter(circleArea)}\nTRAPEZIO: {formatter(trapezoidArea)}\nQUADRADO: {formatter(squareArea)}\nRETANGULO: {formatter(rectangleArea)}");
        }
    }
}
