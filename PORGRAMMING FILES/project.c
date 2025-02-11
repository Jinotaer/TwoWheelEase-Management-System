#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a customer
struct Customer
{
    char name[25];
    char address[25];
    int customerNo, age;
    char contactNumber[12];
    char bikeModel[25];
    float downPayment;
    float balance;
    float monthlypay;
    float price;
    int term;
    int month, day, year;

};

// function declaration
void addCustomer();
void viewCustomerRecords();
void editCustomerRecord();
void deletecustomerrecord();
void listAvailableMotorcycles();
void manageMonthlyPayments();
void searchCustomerRecord();

// The main function
int main()
{

    struct Customer customer;
    int choice;

    do
    {
        // Clear screen
        system("cls");

        // display Menu
        printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t|\t\t\t\t\t\t |\n");
        printf("    \t\t\t\t\t\t\t|  WELCOME TO TWOWHEELEASE MANAGEMENT SYSTEM     |\n");
        printf("    \t\t\t\t\t\t\t|\t\t\t\t\t\t |\n");
        printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n");

        printf("\t\t\t\t1. Add Customer \t\t2. View Customer Records \t3. List Available Motorcycles\n\n");
        printf("\t\t\t\t4. Manage Monthly Payments\t5. Search Customer Records \t6. Exit\n\n\n");

        printf("\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);



        // Switch case to execute corresponding function based on user input
        switch (choice)
        {
        case 1:
            addCustomer(); // Function call to  Add customer record
            break;
        case 2:
            viewCustomerRecords(); // Function call to View customer records
            break;
        case 3:
            listAvailableMotorcycles(); // Function call to List available motorcycle models
            break;
        case 4:
            manageMonthlyPayments(); // Function call to Manage monthly payments
            break;
        case 5:
            searchCustomerRecord(); // Function call to Search for a customer record
            break;
        case 6:
            getchar();
            system("cls");

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  EXITING THE PROGRAM.....\n\n\n\n\n\n"); // Exit the program
            exit(0);
            break;

        default:
            printf("\n\t\t\t\tInvalid choice. Please try again.\n"); // Invalid choice
            getchar();
            getchar();
        }
    }
    while(choice != 6);

    return 0;

}

// Function to add a new customer record
void addCustomer()
{
    // Open file to append mode
    FILE *fptr = fopen("storedData.txt", "a");

    // Error message if file cannot be opened
    if (fptr == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // Declare and initialize variables
    int choice = 1;
    int choice2 = 0;
    do
    {
        // Clear screen
        system("cls");
        printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
        printf("    \t\t\t\t\t\t\t|\t\t    ADD CUSTOMER\t\t |\n");
        printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n\n");


        // Declare a structure variable to store customer data
        struct Customer customer;

        // Clear input buffer
        getchar();
        printf("\t\t\t\t\tEnter the Date Today: ");
        scanf("%d/%d/%d", &customer.month, &customer.day, &customer.year);
        getchar();

        // Get the customer information
        printf("\n\n\t\t\t\t\tEnter customer Name: ");
        fgets(customer.name, sizeof(customer.name), stdin); // read or stored customer name
        customer.name[strcspn(customer.name, "\n")] = '\0';// Remove trailing newline character

        printf("\t\t\t\t\tEnter customer Age: ");
        scanf("%d", &customer.age);
        getchar(); // Clear the newline character from the input buffer

        printf("\t\t\t\t\tEnter customer address: ");
        fgets(customer.address, sizeof(customer.address), stdin);
        customer.address[strcspn(customer.address, "\n")] = '\0';

        printf("\t\t\t\t\tEnter customer contact number: ");
        scanf("%s", &customer.contactNumber);
        getchar();

        // Display available motorcycle models
        printf("\n\t\t\t\t\tMotorcycle Model:\t\tPrice: \n");
        printf("\t\t\t\t\t(1).  RUSI-MP-110\t\tPhp 88,000.00\n\t\t\t\t\t(2).  RUSI-PASSION-125\t\tPhp 47,000\n\t\t\t\t\t(3).  RUSI-GALA-125\t\tPhp 42,000\n\t\t\t\t\t(4).  RUSI-RAPID-150\t\tPhp 65,000.00\n\t\t\t\t\t(5).  RUSI-Rfi-175\t\tPhp94,000.00\n");
        printf("\t\t\t\t\t(6).  RUSI-CLASSIC-250\t\tPhp 100,000.00\n\t\t\t\t\t(7).  RUSI-KR-125\t\tPhp 60,000\n\t\t\t\t\t(8).  RUSI-TC-150\t\tPhp 50,000\n\t\t\t\t\t(9).  RUSI-DL-150\t\tPhp 70,000.00\n\t\t\t\t\t(10). RUSI-SC-125\t\tPhp80,000.00\n\n");

invalid:
        // Input motorcycle choice
        printf("\t\t\t\t\tEnter motorcycle choice (index): ");
        scanf("%d", &choice2);
        getchar();

// function declaration
        // Switch case to calculate balance and monthly payment based on motorcycle choice
        switch(choice2)
        {
        case 1:
            customer.price = 88000;
            strcpy(customer.bikeModel, "RUSI-MP-110");

            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 2:
            customer.price = 47000;
            strcpy(customer.bikeModel, "RUSI-PASSION-125");

            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);
            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 3:
            customer.price = 42000;
            strcpy(customer.bikeModel, "RUSI-GALA-125");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);


            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 4:
            customer.price = 65000;
            strcpy(customer.bikeModel, "RUSI-RAPID-150");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 5:
            customer.price = 94000;
            strcpy(customer.bikeModel, "RUSI-Rfi-175");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 6:
            customer.price = 100000;
            strcpy(customer.bikeModel, "RUSI-CLASSIC-250");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 7:
            customer.price = 60000;
            strcpy(customer.bikeModel, "RUSI-KR-125");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 8:
            customer.price = 50000;
            strcpy(customer.bikeModel, "RUSI-TC-150");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 9:
            customer.price = 70000;
            strcpy(customer.bikeModel, "RUSI-DL-150");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        case 10:
            customer.price = 80000;
            strcpy(customer.bikeModel, "RUSI-SC-125");
            printf("\t\t\t\t\tEnter down payment: ");
            scanf("%f", &customer.downPayment);

            printf("\t\t\t\t\tEnter loan term (in months): ");
            scanf("%d", &customer.term);

            customer.balance = customer.price - customer.downPayment;
            customer.monthlypay = customer.balance / customer.term;
            break;
        default:
            printf("\n\t\t\t\t\tInvalid choice.\n");
            fclose(fptr);
            goto invalid;
        }

        printf("\n\t\t\t\t\tcustomer Record Successfully\n");


        // Write customer data to file
        fprintf(fptr,"%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);

        // Ask user if they want to add another record
        printf("\n\t\t\t\t\tPress 0 to return to main and 1 to add other record:");
        scanf("%d", &choice);

        if (choice == 0) // Check if choice is 1, if yes, exit the loop
        {

            break;
        }
    }
    while (choice == 1);

    fclose(fptr); // Close file
}

// Function to view a  customer record
void viewCustomerRecords()
{
    system("cls"); // system clear
    getchar();

    printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
    printf("    \t\t\t\t\t\t\t|\t\t  CUSTOMER RECORDS\t\t |\n");
    printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n\n\n");

    // open file in read mode
    FILE *fptr = fopen("storedData.txt", "r");
    // if the file cannot bih open
    if (fptr == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }


    printf("Name\t\t   Age\t    Address\t   Contact Number   Motorcycle\t     Total Price    Down Payment       Balance\t   Monthly\tTerm\tDate\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    // buffer is temporary memory
    char buffer[1000];
    // Read data from file and print customer records
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        // display the input data from file
        printf("%s", buffer);
        printf("\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(fptr); // Close the file

    // Prompt user for action
    int action;
invalid:
    printf("\nEnter (1 to Edit Record), or (0 back to Main): ");
    scanf("%d", &action);

    // switch condition if the user want to edit customer information or back
    switch (action)
    {
    case 1:
        editCustomerRecord();// Edit customer record
        break;
    case 0:
        main();// Return to main menu
        break;
    default:
        printf("\tInvalid Choice.\n\n");
        goto invalid;
    }

}

// Function to edit a customer record
void editCustomerRecord()
{
    system("cls");
    getchar();// consume newline
    // Variable to store the name of the customer to edit
    struct Customer customer;
    char edit[25];
    // open file old and newrec in read and write mode
    FILE *old, *newrec;
    old = fopen("storedData.txt", "r");
    newrec = fopen("newrec.txt", "w");

    int found = 0; // Variable to track if the customer is found in the file
    int choice2; // Variable to store the user's choice of motorcycle

    printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
    printf("    \t\t\t\t\t\t\t|\t\t EDIT CUSTOMER RECORD\t\t |\n");
    printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n");


start:
    printf("\nEnter the name of the customer whose info you want to change: "); // enter customer name you want to change
    fgets(edit, sizeof(edit), stdin);
    edit[strcspn(edit, "\n")] = '\0'; // remove newline



    // Loop through the file until the end, reading customer records
    while (fscanf(old, "%[^\t] %d %[^\t] %s %s %f %f %f %f %d %d/%d/%d\n", customer.name,
                  &customer.age, customer.address, &customer.contactNumber, customer.bikeModel, &customer.price,
                  &customer.downPayment, &customer.balance, &customer.monthlypay, &customer.term, &customer.month, &customer.day, &customer.year)!= EOF)// EOF (End of File) indicates the end of the file being read
    {

        if (strcmp(customer.name, edit) == 0) // string compare function if customer.name and variable edit is matched
        {
            found = 1; // if the record is found
            // display if the record is found
            printf("\n\nName\t\t   Age\t    Address\t   Contact Number   Motorcycle\t     Total Price    Down Payment       Balance\t   Monthly\tTerm\tDate\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                   customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                   customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


            printf("\n\n\tEnter the Date Today: ");
            scanf("%d/%d/%d", &customer.month, &customer.day, &customer.year);
            getchar();

            // Input new customer details
            printf("\n\n\tEnter New customer Name: ");
            fgets(customer.name, sizeof(customer.name), stdin); // read or stored customer name
            customer.name[strcspn(customer.name, "\n")] = '\0';// Remove trailing newline character

            printf("\tEnter New customer Age: ");
            scanf("%d", &customer.age);
            getchar(); // Clear the newline character from the input buffer

            printf("\tEnter New customer address: ");
            fgets(customer.address, sizeof(customer.address), stdin);
            customer.address[strcspn(customer.address, "\n")] = '\0';

            printf("\tEnter New customer contact number: ");
            scanf("%s", &customer.contactNumber);
            getchar();

            // Display available motorcycle models
            printf("\n\tMotorcycle Model:\t\tPrice: \n");
            printf("\t(1).  RUSI-MP-110\t\tPhp88,000.00\n\t(2).  RUSI-PASSION-125\t\tPhp47,000\n\t(3).  RUSI-GALA-125\t\tPhp42,000\n\t(4).  RUSI-RAPID-150\t\tPhp65,000.00\n\t(5).  RUSI-Rfi-175\t\tPhp94,000.00\n");
            printf("\t(6).  RUSI-CLASSIC-250\t\tPhp100,000.00\n\t(7).  RUSI-KR-125\t\tPhp60,000\n\t(8).  RUSI-TC-150\t\tPhp50,000\n\t(9).  RUSI-DL-150\t\tPhp70,000.00\n\t(10). RUSI-SC-125\t\tPhp80,000.00\n\n");

invalid:
            // Input motorcycle choice
            printf("\tEnter New motorcycle choice (index): ");
            scanf("%d", &choice2);
            getchar();

            // Switch case to calculate balance and monthly payment based on motorcycle choice
            switch(choice2)
            {
            case 1:

                customer.price = 88000;
                strcpy(customer.bikeModel, "RUSI-MP-110");

                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 2:
                customer.price = 47000;
                strcpy(customer.bikeModel, "RUSI-PASSION-125");

                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);
                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 3:
                customer.price = 42000;
                strcpy(customer.bikeModel, "RUSI-GALA-125");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);


                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 4:
                customer.price = 65000;
                strcpy(customer.bikeModel, "RUSI-RAPID-150");
                printf("\t\t\t\t\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 5:
                customer.price = 94000;
                strcpy(customer.bikeModel, "RUSI-Rfi-175");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\ttEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 6:
                customer.price = 100000;
                strcpy(customer.bikeModel, "RUSI-CLASSIC-250");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 7:
                customer.price = 60000;
                strcpy(customer.bikeModel, "RUSI-KR-125");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 8:
                customer.price = 50000;
                strcpy(customer.bikeModel, "RUSI-TC-150");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 9:
                customer.price = 70000;
                strcpy(customer.bikeModel, "RUSI-DL-150");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            case 10:
                customer.price = 80000;
                strcpy(customer.bikeModel, "RUSI-SC-125");
                printf("\tEnter down payment: ");
                scanf("%f", &customer.downPayment);

                printf("\tEnter loan term (in months): ");
                scanf("%d", &customer.term);

                customer.balance = customer.price - customer.downPayment;
                customer.monthlypay = customer.balance / customer.term;
                break;
            default:
                printf("\n\tInvalid choice.\n");
                fclose(old);
                fclose(newrec);
                goto invalid;
            }


            printf("\n\tCustomer Record Successfully\n");


        }

        // Write customer data to new file
        fprintf(newrec,"%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);

    }

    // if condition to customer not found
    if (!found)
    {
        printf("Customer not found.\n\n");// display if the customer not found
        fclose(old); // close the file
        int choice3;
erase_invalid: // back here if in valid choice

        // display user choice
        printf("\n\tEnter 0 to try again,1 to return to main menu: ");
        scanf("%d",&choice3);

        // if condition to return to main or try agian
        if (choice3 == 1)
        {
            fclose(old); // close the file
            fclose(newrec); // close the file
            main();
        }
        else if (choice3 == 0)
        {
            fclose(old); // close the file
            fclose(newrec); // close the file
            editCustomerRecord();
        }
        else
        {
            printf("\n\tInvalid!\a");// display if invalid choice
            fclose(old); // close the file
            fclose(newrec); // close the file
            goto erase_invalid;// go to choices
        }
    }

    fclose(old); // Close the old file
    fclose(newrec); // Close the new file
    remove("storedData.txt"); // Remove the old data file
    rename("newrec.txt", "storedData.txt"); // Rename the new file to replace the old one

    printf("\tPress any key to return to main.....");
    getchar();
    getchar();
    main(); // Return to main menu
}

// Function to list available motorcycle models
void listAvailableMotorcycles()
{
    system("cls");// system clear
    getchar();// consume the newline

    printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
    printf("    \t\t\t\t\t\t\t|\t    LIST AVAILABLE MOTORCYCLES \t\t |\n");
    printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n");

    // display the available motorcycles and it price
    printf("\n\t\t\t\t\t\t\tMotorcycle Model:\t\tPrice: \n\n");
    printf("\t\t\t\t\t\t\t(1).  RUSI-MP-110\t\tPhp 88,000.00\n\n\t\t\t\t\t\t\t(2).  RUSI-PASSION-125\t\tPhp 47,000\n\n\t\t\t\t\t\t\t(3).  RUSI-GALA-125\t\tPhp 42,000\n\n\t\t\t\t\t\t\t(4).  RUSI-RAPID-150\t\tPhp 65,000.00\n\n\t\t\t\t\t\t\t(5).  RUSI-Rfi-175\t\tPhp 94,000.00\n\n");
    printf("\t\t\t\t\t\t\t(6).  RUSI-CLASSIC-250\t\tPhp 100,000.00\n\n\t\t\t\t\t\t\t(7).  RUSI-KR-125\t\tPhp 60,000\n\n\t\t\t\t\t\t\t(8).  RUSI-TC-150\t\tPhp 50,000\n\n\t\t\t\t\t\t\t(9).  RUSI-DL-150\t\tPhp 70,000.00\n\n\t\t\t\t\t\t\t(10). RUSI-SC-125\t\tPhp 80,000.00\n\n");

    int choice4;// variable choice
choice4_invalid:  // back here if in valid choice

    // display choices
    printf("\t\t\t\t\t\t\tEnter 0 to return to main menu: ");
    scanf("%d", &choice4);

    // if condition to return to main
    if(choice4 == 0)
    {
        main();
    }
    else
    {
        printf("Invalid Input\n\n");// display if invalid choices
        goto choice4_invalid; // back to display choices
    }

}

// Function to manage monthly payments
void manageMonthlyPayments()
{
    system("cls"); // system clear
    getchar();// cunsume newline

    struct Customer customer;
    char name[25];// varaiable name to compare customer.name
    int month, date, year;// variable to input month, date, year
    int found = 0;
    float payment;

    // open file in read and write
    FILE *old = fopen("storedData.txt", "r+");
    FILE *newrec = fopen("newrec.txt", "w+");

    printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
    printf("    \t\t\t\t\t\t\t|\t       MANAGE MONTHLY PAYMENT \t\t |\n");
    printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n");


    printf("\nEnter the name of the Customer: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    // Loop through the file until the end, reading customer records
    while (fscanf(old, "%[^\t] %d %[^\t] %s %s %f %f %f %f %d %d/%d/%d\n", customer.name,
                  &customer.age, customer.address, &customer.contactNumber, customer.bikeModel, &customer.price,
                  &customer.downPayment, &customer.balance, &customer.monthlypay, &customer.term, &customer.month, &customer.day, &customer.year)!= EOF)// EOF (End of File) indicates the end of the file being read
    {

        if (strcmp(customer.name, name) == 0)// string compare function if customer.name and variable edit is matched
        {
            found = 1; // if the record is found
            // display customer record if found in the file
            printf("\n\nName\t\t   Age\t    Address\t   Contact Number   Motorcycle\t     Total Price    Down Payment       Balance\t   Monthly\tTerm\tDate\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                   customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                   customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


            // input date
            printf("\nDate Today ex.(mm/dd/yyyy): ");
            scanf("%d/%d/%d", &month, &date, &year);
invalid:// back here if payment is exceed customer balance
            // input monthly payment
            printf("\nEnter Monthly Payment: ");
            scanf("%f", &payment);
            getchar();


            // condition if payment is exceed customer balance
            if(payment > customer.balance)
            {
                printf("\nPayment exceeds the balance. Please enter a valid amount.\n\n");// display if payment is exceeds
                fclose(old);// close file old
                fclose(newrec);// close file new
                remove("newrec.txt");
                goto invalid;
            }

            // Update the balance
            // formula customer balance minus payment
            customer.balance = customer.balance - payment;

            system("cls");// system clear
            printf("\n\n");// newline
            // display reciept
            printf("\n\t\t\t\t\t\t|====================================================|\n");
            printf("\t\t\t\t\t\t|\t\t   TWOWHEELEASE\t\t\t     |\n");
            printf("\t\t\t\t\t\t| Purok - 7, Sayre Hwy, Don Carlos, Bukidnon, 8712   |\n");
            printf("\t\t\t\t\t\t| Contact: 09955230525\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t|----------------------------------------------------|\n");
            printf("\t\t\t\t\t\t| Receipt\t\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t| \t\t\t\t  Date: %d/%d/%d   |\n", month, date, year);
            printf("\t\t\t\t\t\t|\t\t\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t| RECEIVED from: %s     with TIN: 721-432-123 |\n",customer.name);
            printf("\t\t\t\t\t\t| and address at:    %s    engaged in the    |\n",customer.address);
            printf("\t\t\t\t\t\t| Business style of: \tN/A \t   the sum pesos     |\n",customer.name);
            printf("\t\t\t\t\t\t| (P: %.f) in partial/full payment for Motorcycle   |\n",payment);
            printf("\t\t\t\t\t\t| \t\t\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t|\t\t\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t| Item Description:\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t| Motorcycle Model: %s\t\t\t     |\n",customer.bikeModel);
            printf("\t\t\t\t\t\t| Remaining Balance: %.2f\t\t\t     |\n",customer.balance);
            printf("\t\t\t\t\t\t|----------------------------------------------------|\n");
            printf("\t\t\t\t\t\t| NOTE:\t\t\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t| No account will be recognized as all paid, without |\n");
            printf("\t\t\t\t\t\t| the Original signed by the company's authorized    |\n");
            printf("\t\t\t\t\t\t| Officer\t\t\t\t\t     |\n");
            printf("\t\t\t\t\t\t|----------------------------------------------------|\n");
            printf("\t\t\t\t\t\t| \t\t       \t\t\t\t     |\n");
            printf("\t\t\t\t\t\t| \t\t      ------------\t\t     |\n");
            printf("\t\t\t\t\t\t| \t\t         Signed\t\t\t     |\n");
            printf("\t\t\t\t\t\t|====================================================|\n");


            // Write customer data to new file
            fprintf(newrec,"%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                    customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                    customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);
        }
        else
        {
            // Write customer data to new file
            fprintf(newrec,"%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                    customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                    customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);
        }

    }

    // if not found display the following
    if (!found)
    {
        printf("\nCustomer not found.\n");
    }

    fclose(old); // Close the old file
    fclose(newrec); // Close the new file
    remove("storedData.txt"); // Remove the old data file
    rename("newrec.txt", "storedData.txt"); // Rename the new file to replace the old one


    // if condition to return to mai
    int choice5;// variable choice
choice4_invalid: // back here if in valid choice
    // display choices
    printf("\n\t\t\t\t\t\tEnter 0 to Pay Again, or 1 to return to the main menu: ");
    scanf("%d", &choice5);

    // if condition if the user want to return to main or pay again
    if(choice5 == 1)
    {
        main();
    }
    else if(choice5 == 0 )
    {
        manageMonthlyPayments();
    }
    else
    {
        printf("Invalid Input\n\n");
        goto choice4_invalid;
    }
}


// Function to search for a customer record
void searchCustomerRecord()
{
    system("cls");// system clear
    getchar();// consume the newline

    struct Customer customer; // Variable to store the name of the customer to search
    char search[25];// variable search
    int found = 0;// Variable to track if the customer is found in the file
    // open file in read mode
    FILE *fptr = fopen("storedData.txt", "r");
    // if file cannot be open
    if (fptr == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\n\t\t\t\t\t\t\t--------------------------------------------------\n");
    printf("    \t\t\t\t\t\t\t|\t       SEARCH CUSTOMER RECORD \t\t |\n");
    printf("    \t\t\t\t\t\t\t--------------------------------------------------\n\n\n\n");

    // input customer name you want to search
    printf("\nEnter the name of the customer you want to search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0'; // Remove trailing newline character


    // Loop through the file until the end, reading customer records
    while (fscanf(fptr, "%[^\t] %d %[^\t] %s %s %f %f %f %f %d %d/%d/%d\n", customer.name,
                  &customer.age, customer.address, &customer.contactNumber, customer.bikeModel, &customer.price,
                  &customer.downPayment, &customer.balance, &customer.monthlypay, &customer.term, &customer.month, &customer.day, &customer.year)!= EOF)//EOF (End of File) indicates the end of the file being read
    {

        if (strcmp(customer.name, search) == 0)// string compare if the customer name and search variable is matched
        {
            // display if the record is found
            printf("\n\nName\t\t   Age\t    Address\t   Contact Number   Motorcycle\t     Total Price    Down Payment       Balance\t   Monthly\tTerm\tDate\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("%s\t   %d\t    %s\t    %s\t    %s\t     %.2f\t    %.2f\t       %.2f\t   %.2f\t%d\t%d/%d/%d\n", customer.name,
                   customer.age, customer.address, customer.contactNumber, customer.bikeModel, customer.price, customer.downPayment,
                   customer.balance, customer.monthlypay, customer.term, customer.month, customer.day, customer.year);
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }
    // if the record not found
    if (!found)
    {
        printf("Customer record not found.\n\n");// display if record not found
    }

    int choice5;// variable choice5
choice4_invalid:// back here if the user input invalid
    // display the choices
    printf("\nEnter 1 to Search Again, or 0 to return to main menu: ");
    scanf("%d", &choice5);

    // if condition if user want to return main or search agian
    if(choice5 == 0)
    {
        main();
    }
    else if(choice5 == 1 )
    {
        searchCustomerRecord();
    }
    else
    {
        printf("Invalid Input\n\n");
        goto choice4_invalid;
    }

    fclose(fptr);// close file
}
