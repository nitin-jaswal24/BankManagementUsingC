#include <stdio.h>
#include <time.h>
char name[20];
int amt = 10000;
int dip_amt;
int with_amt;
int accNo;
int transAmt;
void menu() {
    printf("Main Menu\n");
    printf("1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money\n");
    printf("4. Transfer Details\n");
    printf("5. Transaction Details\n");
}

void depositMoney(){
    time_t t;
    time(&t);
    FILE *ptr=fopen("Account.txt","a");
    printf("Enter the amount to be deposited: ");
    scanf("%d",&dip_amt);
    amt += dip_amt;
    printf("Depositing the Money\n");
    printf("Current Balance: %d\n", amt); // Add %d to print the balance
    fprintf(ptr,"Money has been deposited on %s", ctime(&t)); // Correct the format string here
    fclose(ptr); // Close the file after writing
}

void withdrawMoney() {
    printf("Enter Money to withdraw: ");
    FILE *ptr = fopen("Account.txt", "a"); // Open the file in append mode

    if (ptr == NULL) {
        printf("Error opening file.\n");
        return; // Exit the function if the file couldn't be opened
    }

    scanf("%d", &with_amt);
    if (with_amt > amt) {
        printf("Insufficient balance.\n");
        fclose(ptr); // Close the file before returning
        return; // Exit the function if the withdrawal amount is more than the balance
    }

    amt -= with_amt;
    printf("Money withdrew\n");
    printf("Current Balance: %d\n", amt);
    fprintf(ptr, "rs %d has been withdrawn from the account\n", with_amt); // Use with_amt instead of dip_amt
    fclose(ptr);
}


void transferMoney(){
    int ac;
    printf("Transfering the money\n");
    printf("Enter the amount\n");
    scanf("%d",&transAmt);
    printf("enter the account number to which money is to be transferred\n");
    if(amt<transAmt){
        printf("you dont have suffiecient  balance\n");
        return;
    }
    // else{
    //     printf("")
    // }
}

int main() {
    int choice;
    printf("Enter your Name Sir/Madam: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your acc. no.: ");
    scanf("%d", &accNo);
    menu();

    printf("enter your choice");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        depositMoney();
        break;
    case 2:
        withdrawMoney();
        break;
    // case 3:
    //     TransferMoney();
    //     break;
    // case 4:
    //     TransferDetails();
    //     break;
    // case 5:
    //     TransactionDetails();
    //     break;
    default:
        printf("Invalid Choice");
        break;
    }
   
}
