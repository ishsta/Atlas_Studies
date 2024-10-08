// Write a message without a newline at the end
using System.Runtime.InteropServices;

Console.Write("Enter your name: ");

// Read the user's name and store it in a variable
string name = Console.ReadLine();

// Greet the user with their name
Console.WriteLine("Hello, " + name + "!");

// Prompt the user to press a key to continue
Console.WriteLine("Press any key to continue...");

// Wait for the user to press a key
Console.ReadKey();

// Clear the contents of the console window
Console.Clear();

// Demonstrate the Read() method
Console.WriteLine("\nEnter a single character: ");

// Read a single character input from the user
int inputChar = Console.Read();

// Display the character as a number (ASCII value)
Console.WriteLine("ASCII value: " + inputChar);