using System;
using System.Formats.Asn1;
namespace AdvancedAreaCalculator;

class App
{
    public void Run()
    {
        //ConsoleIO.DisplayMenu();
        switch(ConsoleIO.GetMenuChoice())
        {
            case 1:
                CalculateRectangle();
                break;
        }
    }

    private void CalculateRectangle()
    {

    }

    private void CalculateCircle()
    {

    }

    private void CalculateTriangle()
    {

    }
}