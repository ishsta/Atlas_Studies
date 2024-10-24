using System;
using System.Formats.Asn1;
namespace AdvancedAreaCalculator;

class Rectangle
{
    public static double Length { get; set; }
    public static double Width { get; set; }

    static double CalculateArea()
    {
        double area = Length * Width;
        return area; 
    }
}