using System;
namespace AdvancedAreaCalculator;

class Circle
{
    public static double radius { get; set; }

    static double CalculateArea()
    {
        double area = Math.PI * Math.Pow(radius, 2);
        return area;
    }
}