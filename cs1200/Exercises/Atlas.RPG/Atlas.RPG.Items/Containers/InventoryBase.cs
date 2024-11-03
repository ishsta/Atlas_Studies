namespace Atlas.RPG.Items;

public abstract class InventoryBase
{
    protected int _capacity;
    protected ItemBase[] _contents;

    public InventoryBase(int capacity)
    {
        _capacity = capacity;
        _contents = new ItemBase[_capacity];
    }

    public virtual bool AddItem(ItemBase item)
    {
        for (int i = 0; i < _capacity; i++)
        {
            if (_contents[i] == null)
            {
                _contents[i] = item;
                return true;
            }
        }
        return false;
    }

    public virtual ItemBase RemoveItem(int index)
    {
        if (index >= 0 && index < _capacity)
        {
            ItemBase item = _contents[index];
            if (item != null)
            {
                _contents[index] = null;
                return item;
            }
        }
        return null;
    }

    public virtual void ListContents()
    {
        Console.WriteLine("Contents");
        Console.WriteLine("=================");
        
        for (int i = 0; i < _capacity; i++)
        {
            if (_contents[i] != null)
            {
                Console.WriteLine($"{_contents[i].ItemType}\t\t| {_contents[i].Name}\t\t|\t{_contents[i].Weight}kg | $ {_contents[i].Value}");
            }
        }
    }
}
