using System;

namespace SalesTaxCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the purchase price: ");
            double price = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter the tax rate: ");
            double tax = Convert.ToDouble(Console.ReadLine());

            double taxTotal = price * (tax / 100);
            double total = price + taxTotal;

            Console.WriteLine($"\nFor your {price:c} purchase, a {tax}% tax is {taxTotal:c} for a total of {total:c}.");
        }
    }
}