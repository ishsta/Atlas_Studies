#include <stdio.h>
#include <string.h>

/*****************************************************************************
******************************************************************************
Filename: taxonomy.c
Requirements:
1) prompt the user for the number of animals they want to store in a database.
2) have them enter each animal's taxonomy per the following attributes:
1. Animal Name (e.g. Bear)
2. Animal Type (Mammal, Bird, Reptile, Amphibian, Fish)
3. Diet (Herbivore, Carnivore, Omnivore)
4. Habitat (Terrestrial, Aquatic, Arboreal)
5. Average Lifespan (in years)
3) allow them to quit using 'q' at any time
4) print the data in this format when the number of animals have been entered:
+--------------+------------+-------------+--------------+-------------------+
| Animal Name  | Animal Type|    Diet     |   Habitat    | Average Lifespan  |
+--------------+------------+-------------+--------------+-------------------+
| Lion         | Mammal     | Carnivore   | Terrestrial  |        15         |
| Penguin      | Bird       | Carnivore   | Aquatic      |        20         |
| Elephant     | Mammal     | Herbivore   | Terrestrial  |        70         |
| Crocodile    | Reptile    | Carnivore   | Aquatic      |        70         |
| Chimpanzee   | Mammal     | Omnivore    | Arboreal     |        40         |
+--------------+------------+-------------+--------------+-------------------+
*****************************************************************************
*****************************************************************************/

#define MAX_ANIMALS 100
#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 20
#define MAX_DIET_LENGTH 20
#define MAX_HABITAT_LENGTH 20

int main() {
    char animalNames[MAX_ANIMALS][MAX_NAME_LENGTH];
    char animalTypes[MAX_ANIMALS][MAX_TYPE_LENGTH];
    char animalDiets[MAX_ANIMALS][MAX_DIET_LENGTH];
    char animalHabitats[MAX_ANIMALS][MAX_HABITAT_LENGTH];
    int animalLifespan[MAX_ANIMALS];
    int numAnimals, i;

    printf("Enter the number of animals: ");
    scanf("%d", &numAnimals);

    for (i = 0; i < numAnimals; i++) {
        printf("\nAnimal %d:\n", i + 1);

        printf("Enter the animal name (e.g. Bear): ");
        scanf("%s", animalNames[i]);

        printf("Enter the animal type (Mammal, Bird, Reptile, Amphibian, Fish): ");
        scanf("%s", animalTypes[i]);

        printf("Enter the animal diet (Herbivore, Carnivore, Omnivore): ");
        scanf("%s", animalDiets[i]);

        printf("Enter the animal habitat (Terrestrial, Aquatic, Arboreal): ");
        scanf("%s", animalHabitats[i]);

        printf("Enter the average lifespan (in years): ");
        scanf("%d", &animalLifespan[i]);
    }

    printf("\n+--------------+------------+-------------+--------------+-------------------+\n");
    printf("| Animal Name  | Animal Type|    Diet     |   Habitat    | Average Lifespan  |\n");
    printf("+--------------+------------+-------------+--------------+-------------------+\n");

    for (i = 0; i <numAnimals; i++) {
        printf("| %-12s | %-10s | %-11s | %-12s | %-17d |\n",
            animalNames[i], animalTypes[i], animalDiets[i], animalHabitats[i], animalLifespan[i]);
    }
    
    printf("+--------------+------------+-------------+--------------+-------------------+\n");
    
    return 0;
}