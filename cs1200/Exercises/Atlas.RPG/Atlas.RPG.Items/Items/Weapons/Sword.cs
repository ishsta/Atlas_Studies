namespace Atlas.RPG.Items.Weapons;

public class Sword : WeaponBase
{
    public Sword(string itemType, int damage, string name, string description, int weight, int value)
    {
        ItemType = itemType;
        Damage = damage;
        Name = name;
        Description = description;
        Weight = weight;
        Value = value;
    }
}