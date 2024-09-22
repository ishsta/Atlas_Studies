#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

#define USA_STANDARD 5.99
#define USA_EXPEDITED 9.99
#define MEX_STANDARD 7.99
#define MEX_EXPEDITED 12.99
#define CAN_STANDARD 6.99
#define CAN_EXPEDITED 11.99

#define USA_TAX 0.08
#define MEX_TAX 0.16
#define CAN_TAX 0.12



int main(void) {
    char clothingType[30]; // Array to store user input for clothing type
    char destination[30];
    char method[30];
    int shirtQuantity = 0;
    int shoeQuantity = 0;
    int pantsQuantity = 0;
    float shipCost;
    float tax;
    float totalCost;
    
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");

        // Read user input for clothing type
        scanf("%s", &clothingType);

        // Check user ipnut and prompt for quantity based on clothing type
        if (strcmp(clothingType, "shirt") == 0) {
            printf("Enter the quantity of shirts needed: ");
            scanf("%d",&shirtQuantity);
        } else if (strcmp(clothingType, "shoes") == 0) {
            printf("Enter the quantity of shoes needed: ");
            scanf("%d",&shoeQuantity);
        } else if (strcmp(clothingType, "pants") == 0) {
            printf("Enter the quantity of pants needed: ");
            scanf("%d",&pantsQuantity);
        } else if (strcmp(clothingType, "exit") != 0) {
            printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            continue;
        }

        // If user input is not 'exit', display a success message for adding the clothing item
        if (strcmp(clothingType, "exit") != 0) {
            printf("Clothing item '%s' successfully added to your cart.\n", clothingType);
        }
    }while (strcmp(clothingType, "exit") != 0); // Repeat the loop until user enters 'exit'

    printf("\nEnter the shipping destination (USA, Mexico, Canada): ");
    scanf("%s", &destination);

    printf("Enter the shipping method (standard, expedited): ");
    scanf("%s", &method);

    for(int i = 0; destination[i]; i++) {
        destination[i] = tolower(destination[i]);
    }

    for(int i = 0; method[i]; i++) {
        method[i] = tolower(method[i]);
    }

    if (strcmp(destination, "usa") == 0) {
        strcpy(destination, "USA");
        tax = USA_TAX;
        if (strcmp(method, "standard") == 0) {
            strcpy(method, "Standard to USA");
            shipCost = USA_STANDARD;
        } else if (strcmp(method, "expedited") == 0) {
            strcpy(method, "Expedited to USA");
            shipCost = USA_EXPEDITED;
        }
    }else if (strcmp(destination, "mexico") == 0) {
        strcpy(destination, "Mexico");
        tax = MEX_TAX;
        if (strcmp(method, "standard") == 0) {
            strcpy(method, "Standard to Mexico");
            shipCost = MEX_STANDARD;
        } else if (strcmp(method, "expedited") == 0) {
            strcpy(method, "Expedited to Mexico");
            shipCost = MEX_EXPEDITED;
        }
    }else if (strcmp(destination, "canada") == 0) {
        strcpy(destination, "Canada");
        tax = CAN_TAX;
        if (strcmp(method, "standard") == 0) {
            strcpy(method, "Standard to Canada");
            shipCost = CAN_STANDARD;
        } else if (strcmp(method, "expedited") == 0) {
            strcpy(method, "Expedited to Canada");
            shipCost = CAN_EXPEDITED;
        }
    } else {
        printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
        strcpy(destination, "USA");
        tax = USA_TAX;
        strcpy(method, "Standard to USA");
        shipCost = USA_STANDARD;
    }
    
    // Calculate the total cost based on quantities and prices of each clothing item
    float subTotal = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);
    totalCost = subTotal + shipCost + (tax * subTotal);

    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subTotal);
    printf("Shipping Destination: %s\n", destination);
    printf("Shipping Method: %s\n", method);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shipCost);
    printf("Tax (%.2f%%):\t\t\t\t\t$%.2f\n", tax * 100, tax * subTotal);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f\n", totalCost);

    return 0;  // Indicate successful program execution

}
