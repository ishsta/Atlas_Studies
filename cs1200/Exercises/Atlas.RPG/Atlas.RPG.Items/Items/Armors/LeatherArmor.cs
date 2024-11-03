namespace Atlas.RPG.Items.Armors;

public class LeatherArmor : ArmorBase
{
    public LeatherArmor(){
        ItemType = ItemType.Armor;
        Defense = 2;
        Name = "Leather Armor";
        Description = "Basic Leather Armor";
        Weight = 3;
        Value = 100;
    }
}