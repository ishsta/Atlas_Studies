using System.Security.Cryptography.X509Certificates;

namespace Atlas.RPG.Items.Potions;

public class HealthPotion : PotionBase
{
    public override void Drink()
    {
        Console.Write("Glug, glug, glug! You feel better!");

    }

    public HealthPotion()
    {
        ItemType = ItemType.Potion;
        Name = "Health Potion";
        Description = "A potion for healing";
        Weight = 1;
        Value = 10;
    }
}