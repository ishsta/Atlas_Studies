using System.Runtime.CompilerServices;
using System;

namespace Hangman.BLL;

public class Game
{
    private readonly string wordToGuess;
    private readonly char[] currentGuess;
    private int strikesRemaining;
    private const int maxStrikes = 5;
    private readonly bool enableConsoleRead;

    public Game(string word, bool enableConsoleRead = true)
    {
        wordToGuess = word;
        currentGuess = new string('_', word.Length).ToCharArray();
        strikesRemaining = maxStrikes;
        this.enableConsoleRead = enableConsoleRead;
    }

    public int StrikesRemaining => strikesRemaining;
    public string CurrentGuess => string.Join(" ", currentGuess);
    public bool IsGameOver => strikesRemaining <= 0 || IsWordGuessed();

    public void DisplayGameState()
    {
        Console.WriteLine($"\nStrikes Remaining: {strikesRemaining}");
        Console.WriteLine("\nWord: " + string.Join(" ", currentGuess));
    }

    public void ProcessGuess(string guess, string playerName, ref int wins, ref int losses)
    {
        Console.WriteLine();

        if (guess.Length == 1)
        {
            char letter = guess[0];
            if (wordToGuess.Contains(letter))
            {
                UpdateCurrentGuess(letter);
                if (IsWordGuessed())
                {
                    wins++;
                    Console.WriteLine($"{playerName} guessed the word. They win!");
                    Console.WriteLine("Press any key to continue...");
                    if (enableConsoleRead) Console.ReadLine();
                    return;
                }
                else
                {
                    int occurences = UpdateCurrentGuess(letter);
                    Console.WriteLine($"We found {occurences} of those!");
                }
            }
            else
            {
                strikesRemaining--;
                Console.WriteLine("Sorry, that was not found!");

                if (strikesRemaining <= 0)
                {
                    losses++;
                    Console.WriteLine($"{playerName} is out of strikes. They lose!");
                    Console.WriteLine($"{playerName}'s record is {wins}W-{losses}L.");
                    Console.WriteLine("Press any key to continue...");
                    if (enableConsoleRead) Console.ReadLine();
                    return;
                }
            }
        }
        else if (guess.Equals(wordToGuess, StringComparison.OrdinalIgnoreCase))
        {
            for (int i = 0; i < wordToGuess.Length; i++)
            {
                currentGuess[i] = wordToGuess[i];
            }
            Console.WriteLine($"{playerName} guessed the word. They win!");
            Console.WriteLine("Press and key to continue...");
            wins++;
            if (enableConsoleRead) Console.ReadLine();
            if (enableConsoleRead) Console.Clear();
            return;
        }
        else
        {
            strikesRemaining--;
            Console.WriteLine("Incorrect word guess!");
        }

        Console.WriteLine("Press any key to continue...");
        if (enableConsoleRead) Console.ReadLine();
        if (enableConsoleRead) Console.Clear();
    }

    private int UpdateCurrentGuess(char letter)
    {
        int count = 0;
        for (int i = 0; i < wordToGuess.Length; i++)
        {
            if (wordToGuess[i] == letter)
            {
                currentGuess[i] = letter;
                count++;
            }
        }
        return count;
    }

    public bool IsWordGuessed() => !currentGuess.Contains('_');

    public void EndGameMessage(string playerName, ref int wins, ref int losses)
    {
        // if (IsWordGuessed())
        // {
        //     Console.WriteLine($"{playerName} guesses the word. They win!");
        //     wins++;
        // }
        // else
        // {
        //     Console.WriteLine($"{playerName} is out of strikes. They lose!");
        //     losses++;
        // }
        Console.WriteLine($"{playerName}'s record is {wins}W-{losses}L.");
    }
}