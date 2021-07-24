using System;
using System.Diagnostics;

namespace _1015
{
    class Program
    {
        static void Main(string[] args)
        {
            double x1,x2,y1,y2,dist;
                
            // reading variables
            var line = Console.ReadLine();
            var nums = line.Split(' ');
            x1 = double.Parse(nums[0]);
            y1 = double.Parse(nums[1]);
            
            line = Console.ReadLine();
            nums = line.Split(' ');
            x2 = double.Parse(nums[0]);
            y2 = double.Parse(nums[1]);

            // benchmarking Math.Pow vs just mutiplying
            var watch = new Stopwatch();
            watch.Start();
            dist = Math.Sqrt(Math.Pow((x2-x1),2)  + Math.Pow((y2-y1),2));
            watch.Stop();
            Console.WriteLine($"using Math.Pow: {watch.Elapsed.TotalMilliseconds} ms elapsed");
            watch.Reset();
            watch.Start();
            dist = Math.Sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
            watch.Stop();
            Console.WriteLine($"not using Math.Pow: {watch.Elapsed.TotalMilliseconds} ms elapsed");
            Console.WriteLine($"{Math.Round(dist,4).ToString("0.0000")}");
        }
    }
}
