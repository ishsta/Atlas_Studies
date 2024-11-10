namespace Hangman.BLL.Interfaces;

public class ConsoleWordSource : IWordSource
{
    public string GetWord()
    {
        Console.Write("Enter the first word to guess: ");
        string word = Console.ReadLine();
        Console.Clear();
        return word;
    }
}