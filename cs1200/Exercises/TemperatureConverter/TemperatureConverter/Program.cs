using System;
namespace TemperatureConverter;

class Program
{
    static void Main()
    {
        Temperature t1 = new Temperature();

        Console.Write("Enter temperature (K): ");
        t1.Kelvin = double.Parse(Console.ReadLine());

        Console.WriteLine($"The temperature is {t1.Kelvin}K, {t1.Celsius}C, {t1.Fahrenheit}F.");

    }
}

class Temperature
{
    private double _kelvin; // backing field

    public double Kelvin
    {
        get { return _kelvin; }
        set { _kelvin = value; }
    }
    public double Celsius
    {
        get
        {
            return Kelvin - 273.15;
        }
    }
    public double Fahrenheit
    {
        get
        {
            return Celsius * 9 / 5 + 32;
        }
    }

}