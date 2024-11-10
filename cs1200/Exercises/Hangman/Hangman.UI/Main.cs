using System.ComponentModel.Design;
using Hangman.BLL;
using Hangman.BLL.Interfaces;

namespace Hangman.UI;

class Program
{
    static void Main()
    {
        Console.WriteLine("Welcome to Hangman!");
        Console.Write("\nEnter your name: ");
        string playerName = Console.ReadLine();

        int wins = 0;
        int losses = 0;

        while (true)
        {
            IWordSource wordSource = SelectWordSource();
            string wordToGuess = wordSource.GetWord();

            Game game = new Game(wordToGuess);

            while (!game.IsGameOver)
            {
                game.DisplayGameState();
                Console.Write("\nEnter Guess: ");
                string input = Console.ReadLine()?.ToLower();
                if (!string.IsNullOrWhiteSpace(input))
                {
                    game.ProcessGuess(input, playerName, ref wins, ref losses);
                }
            }

            game.EndGameMessage(playerName, ref wins, ref losses);

            Console.Write("Play another game (y/n): ");
            if (Console.ReadLine().Trim().ToLower() != "y")
            {
                break;
            }

            Console.Clear();
        }
    }

    private static IWordSource SelectWordSource()
    {
        Console.WriteLine("\nHow would you like to choose your words?");
        Console.WriteLine("\n1. Enter the word in the console window.");
        Console.WriteLine("2. Pick a random word from the dictionary for me.");
        Console.Write("\nEnter choice: ");
        string choice = Console.ReadLine();
        
        if (choice == "1")
        {
            return (IWordSource)new ConsoleWordSource();
        }
        else
        {
            return new DictionaryWordSource();
        }
    }
}