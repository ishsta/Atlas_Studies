namespace Hangman.BLL.Interfaces;

public class DictionaryWordSource : IWordSource
{
    private readonly string[] words;

    public DictionaryWordSource()
    {
        if (File.Exists("dictionary.txt"))
        {
            words = File.ReadAllLines("dictionary.txt");
        }
        else
        {
            words = new string[] { "default", "words", "for", "testing" };
        }
    }

    public string GetWord()
    {
        Random num = new Random();
        int index = num.Next(words.Length);
        string randWord = words[index];

        Console.WriteLine($"A random word has been selected from the dictionary, it is {randWord.Length} letters long");
        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
        Console.Clear();

        return randWord;
    }
}