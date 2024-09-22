#include <stdio.h>
#include <string.h>

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
    char userInput[10];
    char shipDestination[10];
    char shipMethod[10];
    int shirtQuantity = 0;
    int shoeQuantity = 0;
    int pantsQuantity = 0;
    float shipCost;
    float tax;
    char *destination[10];
    char *method[20];

    do {

        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");

        scanf("%s", &userInput);

        if (strcmp(userInput, "shirt") == 0) {

            printf("Enter the quantity of shirts needed: ");
            scanf("%d", &shirtQuantity);

        } else if (strcmp(userInput, "shoes") == 0) {

            printf("Enter the quantity of shoes needed: ");
            scanf("%d", &shoeQuantity);

        } else if (strcmp(userInput, "pants") == 0) {

            printf("Enter the quantity of pants needed: ");
            scanf("%d", &pantsQuantity);
            
        } else if (strcmp(userInput, "exit") != 0) {

            printf("Invalid clothing type. Please enter 'shirt', 'shoes', 'pants'.\n");
            continue;
        }

        if (strcmp(userInput, "exit") != 0) {

            printf("Clothing item '%s' successfully added to your cart.\n", userInput);

        }
        

    } while (strcmp(userInput, "exit") != 0);

    printf("\nEnter the shipping destination (USA, Mexico, Canada): ");
    scanf("%s", &shipDestination);

    printf("Enter the shipping method (standard, expedited): ");
    scanf("%s", &shipMethod);

    if (strcmp(shipDestination, "usa") == 0) {

        tax = USA_TAX;
        destination[10] = "USA";

        if (strcmp(shipMethod, "standard") == 0) {
            shipCost = USA_STANDARD;
            method[20] = "Standard to USA";
        } else if (strcmp(shipMethod, "expedited") == 0) {
            shipCost = USA_EXPEDITED;
            method[20] = "Expedited to USA";
        }

    } /* else if (strcmp(shipDestination, "mexico") == 0) {

        tax = MEX_TAX;
        destination[10] = "Mexico";

        if (strcmp(shipMethod, "standard") == 0) {
            shipCost = MEX_STANDARD;
            method[20] = "Standard to Mexico";
        } else if (strcmp(shipMethod, "expedited") == 0) {
            shipCost = MEX_EXPEDITED;
            method[20] = "Expedited to Mexico";
        }

    } else if (strcmp(shipDestination, "canada") == 0) {

        tax = CAN_TAX;
        destination[10] = "Canada";

        if (strcmp(shipMethod, "standard") == 0) {
            shipCost = CAN_STANDARD;
            method[20] = "Standard to Canada";
        } else if (strcmp(shipMethod, "expedited") == 0) {
            shipCost = CAN_EXPEDITED;
            method[20] = "Expedited to Canada";
        }

    } */



    float subTotal = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);
    float totalCost = subTotal + shipCost + tax;
    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subTotal);
    printf("Shipping Destination: %s\n", destination[10]);
    printf("Shipping Method: %s\n", method[20]);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shipCost);
    printf("Tax (%.2f%%):\t\t\t\t\t$%.2f\n", (tax * 100) , (tax * subTotal));
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f", totalCost);

    return 0;  // Indicate successful program execution

}