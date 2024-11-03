namespace Atlas.RPG.Items.Weapons;

public class Sword : WeaponBase
{
    public Sword()
    {
        ItemType = ItemType.Weapon;
        Damage = 5;
        Name = "Iron Sword";
        Description = "A standard Iron Sword";
        Weight = 4;
        Value = 100;
    }
}