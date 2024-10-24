using System;

namespace RPGClasses
{

    class Character
    {
        // Properties
        public string Name { get; set; } // Player will select name of character
        public int Attack { get; private set; } // Player Basic Attack
        public int Health { get; set; } // Player Health
        public int Defense { get; private set; } // Player defense

        // Constructor
        public Character(string name)
        {
            Name = name;
            Attack = 2;
            Health = 20;
            Defense = 1;
        }

        public int NormalAttack()
        {
            return Attack;
        }
    }

    class Enemy
    {
        public string Name { get; set; }
        public int Attack { get; private set; }
        public int Health { get; set; }
        public int Defense { get; private set; }

        public Enemy(string name)
        {
            Name = name;
            Attack = 2;
            Health = 15;
            Defense = 1;
        }

        public int EnemyAttack()
        {
            return Attack;
        }
    }

    class Program
    {
        static void Main()
        {
            Character player = new Character("Hero");
            Enemy villian = new Enemy("Thanos");

            Battle(player, villian);
        }

        static void Battle(Character player, Enemy enemy)
        {
            Console.WriteLine($"Battle Start: {player.Name} vs {enemy.Name}");

            while (player.Health > 0 && enemy.Health > 0)
            {
                Console.WriteLine($"{player.Name} attacks {enemy.Name}!");
                enemy.Health -= player.NormalAttack();

                if (enemy.Health <= 0)
                {
                    Console.WriteLine($"{enemy.Name} is defeated! {player.Name} wins!");
                    break;
                }

                Console.WriteLine($"{enemy.Name} has {enemy.Health} health remaining.");


                Console.WriteLine($"{enemy.Name} attacks {player.Name}!");
                player.Health -= enemy.EnemyAttack();

                if (player.Health <= 0)
                {
                    Console.WriteLine($"{player.Name} is defeated! {enemy.Name} wins!");
                }

                Console.WriteLine($"{player.Name} has {player.Health} health remaining.");

            }
        }
    }
}