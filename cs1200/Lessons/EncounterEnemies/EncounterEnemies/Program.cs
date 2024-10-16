using System;

namespace EncounterEnemies
{
    class Program
    {
        static void Main()
        {
            int characterHP = 100;
            int characterAttack = 20;
            int characterDefense = 10;
            //bool alive = true;

            int[] enemyHP = { 30, 40, 50 };
            int[] enemyAttack = { 10, 15, 20 };
            int[] enemyDefense = { 5, 7, 10 };

            for (int i = 0; i < 3; i++)
            {
                while (enemyHP[i] > 0 && characterHP > 0)
                {
                    enemyHP[i] -= (characterAttack - enemyDefense[i]);
                    characterHP -= (enemyAttack[i] - characterDefense);
                }

                if (enemyHP[i] <= 0)
                {
                    Console.WriteLine($"Enemy {i} defeated!");
                }
                else if (characterHP <= 0)
                {
                    Console.WriteLine("Your character has been defeated!");
                }
            }
        }
    }
}