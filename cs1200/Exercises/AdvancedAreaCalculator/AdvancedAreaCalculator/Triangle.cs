using System;
namespace AdvancedAreaCalculator;

class Triangle
{
    public static double Base { get; set; }
    public static double Height { get; set; }

    static double CalculateArea()
    {
        double area = .5 * Base * Height;
        return area;
    }
}