using Atlas.RPG.Items;
using Atlas.RPG.Items.Armors;
using Atlas.RPG.Items.Containers;
using Atlas.RPG.Items.Potions;
using Atlas.RPG.Items.Weapons;

namespace Atlas.RPG.UI;

public class Tests
{
    public static void RunBaseTests()
    {
        // create container with 2 slots
        var container = new Chest(2);

        var item1 = new LeatherArmor
        {
            //Name = "Item 1"
        };

        var item2 = new HealthPotion
        {
            //Name = "Item 2"
        };

<<<<<<< Updated upstream
        var item3 = new LeatherArmor
=======
        var item3 = new Sword
>>>>>>> Stashed changes
        {
            //Name = "Item 3"
        };

        Console.WriteLine("Add Items Tests");
        Console.WriteLine($"Can add first item: {container.AddItem(item1)}");
        Console.WriteLine($"Can add second item: {container.AddItem(item2)}");
<<<<<<< Updated upstream
        Console.WriteLine($"Cannot add third item: {!container.AddItem(item3)}");
        Console.WriteLine("List contents test: ");
=======
        Console.WriteLine($"Cannot add third item: {container.AddItem(item3)}");
>>>>>>> Stashed changes
        container.ListContents();

        Console.WriteLine("\nRemove Items Tests");
        var removed = container.RemoveItem(1);
        Console.WriteLine($"Can remove item: {removed != null}");
        Console.WriteLine($"Removed expected item: {removed == item2}");
        Console.WriteLine($"Removed slot is now null: {container.RemoveItem(1) == null}");
    }

    public static void WeightRestrictedTests()
    {
        var container = new ClothBag(5);

        var item1 = new Sword
        {

        };

        var item2 = new HealthPotion
        {

        };

        var item3 = new LeatherArmor
        {

        };

        Console.WriteLine("Weight Restricted Tests");
        Console.WriteLine($"Can add sword: {container.AddItem(item1)}");
        Console.WriteLine($"Can add potion: {container.AddItem(item2)}");
        Console.WriteLine($"Cannot add armor: {!container.AddItem(item3)}");
    }

    public static void TypeRestrictedTests()
    {
        var container = new PotionCase(5);

        var item1 = new Sword
        {

        };

        var item2 = new HealthPotion
        {

        };

        Console.WriteLine("Type Restricted Tests");
        Console.WriteLine($"Cannot add sword: {!container.AddItem(item1)}");
        Console.WriteLine($"Can add potion: {container.AddItem(item2)}");
        //Console.WriteLine($"Cannot add armor: {!container.AddItem(item3)}");
    }
}
