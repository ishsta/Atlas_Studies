namespace Atlas.RPG.Items;

public class WeightRestrictedInventory : InventoryBase
{
    protected double _currentWeight;
    protected double _maxWeight;
    public WeightRestrictedInventory(int capacity, double maxWeight) : base(capacity)
    {
        _maxWeight = maxWeight;
        _currentWeight = 0;
    }

    public override bool AddItem(ItemBase item)
    {
        if (_currentWeight + item.Weight > _maxWeight)
        {
            return false;
        }

        bool wasAdded = base.AddItem(item);
        if (wasAdded)
        {
            _currentWeight += item.Weight;
        }
        return wasAdded;
    }

    public override ItemBase RemoveItem(int index)
    {
        ItemBase removedItem = base.RemoveItem(index);
        if (removedItem != null)
        {
            _currentWeight -= removedItem.Weight;
        }
        return removedItem;
    }
}