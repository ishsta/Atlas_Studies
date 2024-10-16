using System;

namespace MultiplicationTable
{
    class Program
    {
        static void Main()
        {
            // Get row and column info from user
            Console.Write("Enter starting value for rows: ");
            int startRow = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter ending value for rows: ");
            int endRow = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter starting value for columns: ");
            int startCol = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter ending value for columns: ");
            int endCol = Convert.ToInt32(Console.ReadLine());

            Console.Write("\t"); // Initial tab in headers
            
            // Cycle through header numbers and print them
            for(int col = startCol; col <= endCol; col++)
            {
                Console.Write($"{col}\t");
            }
            Console.WriteLine(); // Move to next line

            // Seperator
            Console.WriteLine("============================================================");

            for(int row = startRow; row <= endRow; row++)
            {
                //Console.Write("\t"); // Clean up code, Align middle
                Console.Write($"{row}\t"); // print row number
                for(int col = startCol; col <= endCol; col++)
                {
                    Console.Write($"{row * col}\t");
                }
                Console.WriteLine();
            }
        }
    }
}