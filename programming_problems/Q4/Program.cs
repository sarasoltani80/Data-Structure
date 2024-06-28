using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp67
{


    class Program
    {

		static void countSort(int[] arr)
		{
			int max = arr.Max();
			int min = arr.Min();
			int range = max - min + 1;
			int[] count = new int[range];
			int[] output = new int[arr.Length];
			for (int i = 0; i < arr.Length; i++)
			{
				count[arr[i] - min]++;
			}
			for (int i = 1; i < count.Length; i++)
			{
				count[i] += count[i - 1];
			}
			for (int i = arr.Length - 1; i >= 0; i--)
			{
				output[count[arr[i] - min] - 1] = arr[i];
				count[arr[i] - min]--;
			}
			for (int i = 0; i < arr.Length; i++)
			{
				arr[i] = output[i];
			}
		}
		static void printArray(int[] arr)
		{
			for (int i = 0; i < arr.Length; i++)
			{
				Console.Write(arr[i] + " ");
			}
			Console.WriteLine("");
		}
		static void Main(string[] args)
        {
			int n = Convert.ToInt32(Console.ReadLine());
			int[] array = new int[n];
			string[] tokens = Console.ReadLine().Split();
			for (int i = 0; i < n; i++)
			{
				array[i] = Convert.ToInt32(tokens[i]);
			}
			countSort(array);

			for (int i = 0; i < array.Length; ++i)
				Console.Write(array[i]+ " ");
		}
    }
}
