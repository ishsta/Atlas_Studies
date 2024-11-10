namespace Atlas.RPG.Items;

public class TypeRestrictedInventory : InventoryBase
{
    protected ItemType _requiredType;
    public TypeRestrictedInventory(int capacity, ItemType requiredType) : base(capacity)
    {
        _requiredType = requiredType;
    }

    public override bool AddItem(ItemBase item)
    {
        
        if (item.ItemType != _requiredType)
        {
            return false; 
        }

        bool wasAdded = base.AddItem(item);
        return wasAdded ? true : false;
    }
}