// ;;;
// Insert your code here.
#include <stdio.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

// Arrays for storing contact data
char names[MAX_CONTACTS][MAX_CONTACT_NAME_LENGTH];
char phones[MAX_CONTACTS][MAX_PHONE_NUMBER_LENGTH];
char emails[MAX_CONTACTS][MAX_EMAIL_ADDRESS_LENGTH];

// Function prototypes
void displayMenu();
void listContacts(char names[][MAX_CONTACT_NAME_LENGTH], char phones[][MAX_PHONE_NUMBER_LENGTH], char emails[][MAX_EMAIL_ADDRESS_LENGTH], int count);
void callContact(char name[]);
void emailContact(char emails[]);

int readContacts(char names[][MAX_CONTACT_NAME_LENGTH], char phones[][MAX_PHONE_NUMBER_LENGTH], char emails[][MAX_EMAIL_ADDRESS_LENGTH], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    // Read each contact until we reach the end of the file
    while (fscanf(file, "%49[^,],%14[^,],%49[^\n]\n", names[count], phones[count], emails[count]) == 3) {
        count++;
        if (count >= MAX_CONTACTS) {
            printf("Contact list is full!\n");
            break;
        }
    }

    fclose(file);
    return count;
}

int main() {
    int contactCount = readContacts(names, phones, emails, "phone_contacts.csv");
    
    if (contactCount <= 0) {
        printf("No contacts loaded.\n");
        return 1;
    }

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listContacts(names, phones, emails, contactCount);
                printf("\n");
                break;
            case 2: {
                int contactIndex;
                printf("Enter the contact index: ");
                scanf("%d", &contactIndex);

                if (contactIndex > 0 && contactIndex <= contactCount) {
                    contactIndex--;  // Adjust to 0-based index
        
                    // Display the selected contact's information
                    printf("Selected Contact:\n");
                    printf("Name: %s\n", names[contactIndex]);
                    printf("Phone: %s\n", phones[contactIndex]);
                    printf("Email: %s\n", emails[contactIndex]);

                    // Ask the user for the action to perform
                    int action;
                    printf("What would you like to do?\n");
                    printf("1. Call\n");
                    printf("2. Send Email\n");
                    printf("Enter your choice: ");
                    scanf("%d", &action);

                    if (action == 1) {
                        callContact(names[contactIndex]);
                    } else if (action == 2) {
                        emailContact(emails[contactIndex]);
                    } else {
                        printf("Invalid action.\n");
                    }
                } else {
                    printf("Invalid contact index.\n\n");
                }
                break;
            }
            case 3:
                printf("Exiting the Smartphone Contact Hub.\n");
                printf("\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                printf("\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("Smartphone Contact Hub\n");
    printf("1. List Contacts\n");
    printf("2. Select Contact\n");
    printf("3. Exit\n");
}

// Function to list all contacts
void listContacts(char names[][MAX_CONTACT_NAME_LENGTH], char phones[][MAX_PHONE_NUMBER_LENGTH], char email[][MAX_EMAIL_ADDRESS_LENGTH], int count) {
    printf("Phone Contacts:\n");
    for (int i = 0; i < count; i++) {
        //printf("%d. %s - %s\n", i + 1, names[i], phones[i]);
        printf("%d. Name: %s\n", i + 1, names[i]);
        printf("   Phone: %s\n", phones[i]);
        printf("   Email: %s\n\n", emails[i]);
    }
}

// Function to simulate calling a contact
void callContact(char name[]) {
    printf("Calling %s...\n\n", name);
}

// Function to simulate emailing a contact
void emailContact(char email[]) {
    printf("Sending email to %s...\n\n", email);
}