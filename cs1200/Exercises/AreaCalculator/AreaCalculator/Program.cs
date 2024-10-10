using System;

namespace AreaCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("What type of shape (R)ectangle, (T)riangle, or (C)ircle?");
            char input = Console.ReadLine().ToUpper().ToCharArray()[0];

            switch (input) {
                case 'R': {
                    Console.Write("Enter the length: ");
                    double length = Convert.ToDouble(Console.ReadLine());
                    Console.Write("Enter the width: ");
                    double width = Convert.ToDouble(Console.ReadLine());
                    double area = length * width;
                    Console.Write($"The area of this rectangle is {area:f2}.");
                    break;
                }
                case 'T': {
                    Console.Write("Enter the base: ");
                    double tBase = Convert.ToDouble(Console.ReadLine());
                    Console.Write("Enter the height: ");
                    double height = Convert.ToDouble(Console.ReadLine());
                    double area = .5 * (tBase * height);
                    Console.Write($"The area of this triangle is {area:f2}.");
                    break;
                }
                case 'C': {
                    Console.Write("Enter the radius: ");
                    double radius = Convert.ToDouble(Console.ReadLine());
                    double area = Math.PI * (radius * radius);
                    Console.Write($"The area of this circle is {area:f2}.");
                    break;
                }
                default:
                    Console.Write("Invalid shape type!");
                    break;
            }
        }
    }
}