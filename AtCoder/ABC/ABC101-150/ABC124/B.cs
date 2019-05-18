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
            var n = int.Parse(Console.ReadLine());

            var array = Console.ReadLine().Split(' ');

            var array2 = array.Select(int.Parse).ToArray();

            var maxi = array2[0];
            var cnt = 0;

            for (int i = 0; i < n; i++)
            {
                if (maxi <= array2[i])
                {
                    maxi = array2[i];
                    cnt++;
                }
            }
            Console.WriteLine(cnt);
        }
    }
}
