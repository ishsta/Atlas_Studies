using System;

/* 
 * For this project I wanted to focus on breaking my code into functions.
 * This is a skill I am not great at yet.
 * It is still hard to decide what to name things.
 * I also wanted to focus on comments.
 */

namespace DiceRoller
{
    class Program
    {
        static void Main()
        {
            int[] rolls = new int[5];
            Random num = new Random();
            int rerolls = 2;
            bool isFirstRoll = true;

            // Function to roll the dice. if any flag is true it gets rerolled.
            void RollDice(int[] rolls, bool[] flags)
            {
                for (int i = 0; i <= rolls.Length - 1; i++)
                {
                    if (flags[i])
                    {
                        rolls[i] = num.Next(1, 7);
                    }
                }

            }
            // Function to display the dice. isFirstRoll determines what "roll" message gets printed.
            void DisplayDice(int[] rolls, bool isFirstRoll)
            {
                if (isFirstRoll)
                {
                    Console.WriteLine("Initial Roll:");
                }
                else
                {
                    Console.WriteLine("Updated Rolls:");
                }
                
                for (int i = 0; i < rolls.Length; i++)
                {
                    Console.WriteLine($"Die {i + 1}: {rolls[i]}");
                }
            }

            // Initial roll.
            for (int i = 0; i < rolls.Length; i++)
            {
                rolls[i] = num.Next(1, 7);
            }

            while (rerolls != 0)
            {
                // Display the initial roll.
                DisplayDice(rolls, isFirstRoll);

                // After the first display of rolls, switch the state to false.
                isFirstRoll = false;

                Console.WriteLine("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice.");
                Console.Write($"You have {rerolls} rerolls remaining): ");
                string input = Console.ReadLine();

                if (string.IsNullOrWhiteSpace(input)) break;

                // Create an array of boolean flags to track rerolls.
                bool[] flags = new bool[5] { false, false, false, false, false };

                // Parse the input to decide which dice to roll.
                string[] diceReroll = input.Split(",");
                foreach (string number in diceReroll)
                {
                    if (int.TryParse(number, out int dieNumber) && dieNumber >= 1 && dieNumber <= 5)
                    {
                        flags[dieNumber - 1] = true;
                    }
                }

                // Reroll the dice.
                RollDice(rolls, flags);
                rerolls--;
            }

            //Console.Clear();
            DisplayDice(rolls, isFirstRoll);
            Console.WriteLine();
            Console.WriteLine($"Final Score: {rolls.Sum()}");
        }
    }
}