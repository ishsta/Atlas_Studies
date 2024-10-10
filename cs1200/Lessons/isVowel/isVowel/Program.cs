using System;

namespace isVowel
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a letter: ");
            char input = Convert.ToChar(Console.ReadLine().ToUpper());

            switch (input) {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    Console.WriteLine("Vowel");
                    break;
                case 'Y':
                    Console.WriteLine("Maybe");
                    break;
                default:
                    Console.WriteLine("Not a Vowel");
                    break;
            }
        }
    }
}