namespace Atlas.RPG.Items.Armors;

public class LeatherArmor : ArmorBase
{
    public LeatherArmor(string itemType, int defense, string name, string description, int weight, int value){
        ItemType = itemType;
        Defense = defense;
        Name = name;
        Description = description;
        Weight = weight;
        Value = value;
    }
}