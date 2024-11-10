namespace Atlas.RPG.Items.Containers;

public class ClothBag : WeightRestrictedInventory
{
    public ClothBag(int capacity) : base(capacity, maxWeight: 5)
    {
        
    }
}