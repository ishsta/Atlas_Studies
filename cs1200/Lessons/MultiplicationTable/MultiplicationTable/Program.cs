using System;

namespace MultiplicationTable
{
    class Program
    {
        static void Main()
        {
            int startRow;

            Console.Write("Enter starting value for rows: ");
            int.TryParse(Console.ReadLine(), out startRow);

            Console.Write("Enter ending value for rows: ");
            int endRow = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter starting value for columns: ");
            int startCol = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter ending value for columns: ");
            int endCol = Convert.ToInt32(Console.ReadLine());

            Console.Write("\t");

            for(int col = startCol; col <= endCol; col++)
            {
                Console.Write($"{col}\t");
            }
            Console.WriteLine();

            Console.WriteLine("============================================================");

            for(int row = startRow; row <= endRow; row++)
            {
                Console.Write("\t"); // Clean up code, Align middle
                for(int col = startCol; col <= endCol; col++)
                {
                    Console.Write($"{row * col}\t");
                }
                Console.WriteLine();
            }
        }
    }
}