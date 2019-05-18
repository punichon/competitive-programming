using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SelfCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var a = int.Parse(input[0]);
            var b = int.Parse(input[1]);
            var ans = Math.Max(2 * a - 1, Math.Max(2 * b - 1, a + b));
            Console.WriteLine(ans);
        }
    }
}
