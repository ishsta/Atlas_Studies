namespace Atlas.RPG.Items.Potions;

public class HealthPotion : PotionBase
{
    public override void Drink()
    {
        Console.Write("Glug, glug, glug! You feel better!");
    }
}