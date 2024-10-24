using System;
namespace AdvancedAreaCalculator;

class ConsoleIO
{
    public static void DisplayMenu()
    {
        Console.WriteLine("Area Calculator");
        Console.WriteLine("=================");
        Console.WriteLine("1. Rectangle");
        Console.WriteLine("2. Circle");
        Console.WriteLine("3. Triangle");
        Console.WriteLine("4. Quit");
    }

    public static int GetMenuChoice()
    {
        int choice;
        do
        {

            DisplayMenu();
            Console.Write("Enter choice: ");
            choice = Convert.ToInt32(Console.ReadLine());

        } while (choice != 4);
        return choice;
    }

    public static double GetPositiveDouble(string prompt)
    {
        double value;
        bool isValid;
        do
        {
            Console.Write(prompt);
            string input = Console.ReadLine();
            isValid = double.TryParse(input, out value) && value > 0;

            if (!isValid)
            {
                Console.WriteLine("Invalid input. Please enter a positive number.");
            }
        } while (!isValid);

        return value;
    }
}