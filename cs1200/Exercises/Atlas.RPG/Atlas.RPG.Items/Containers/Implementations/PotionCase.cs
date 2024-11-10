namespace Atlas.RPG.Items.Containers;

public class PotionCase : TypeRestrictedInventory
{
    public PotionCase(int capacity) : base(capacity, requiredType: ItemType.Potion)
    {
        
    }
}