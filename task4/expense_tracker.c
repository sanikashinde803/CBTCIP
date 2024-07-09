#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char category[MAX_LENGTH];
    float amount;
    char date[MAX_LENGTH];
} Expense;

void addExpense(Expense *expenses, int *count);
void viewExpenses(const Expense *expenses, int count);
void generateReport(const Expense *expenses, int count);
void saveExpensesToFile(const Expense *expenses, int count);
void loadExpensesFromFile(Expense *expenses, int *count);

int main() {
    Expense expenses[100];
    int count = 0;
    int choice;

    loadExpensesFromFile(expenses, &count);

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Generate Report\n");
        printf("4. Save Expenses\n");
        printf("5. Load Expenses\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                generateReport(expenses, count);
                break;
            case 4:
                saveExpensesToFile(expenses, count);
                break;
            case 5:
                loadExpensesFromFile(expenses, &count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addExpense(Expense *expenses, int *count) {
    printf("Enter category: ");
    scanf("%s", expenses[*count].category);
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expenses[*count].date);

    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const Expense *expenses, int count) {
    printf("\nAll Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("Category: %s, Amount: %.2f, Date: %s\n",
               expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void generateReport(const Expense *expenses, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal Expenses: %.2f\n", total);

    printf("\nExpenses by Category:\n");
    for (int i = 0; i < count; i++) {
        float categoryTotal = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(expenses[i].category, expenses[j].category) == 0) {
                categoryTotal += expenses[j].amount;
            }
        }
        printf("Category: %s, Total: %.2f\n", expenses[i].category, categoryTotal);
    }
}

void saveExpensesToFile(const Expense *expenses, int count) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
    fclose(file);
    printf("Expenses saved to file successfully!\n");
}

void loadExpensesFromFile(Expense *expenses, int *count) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "%s %f %s", expenses[*count].category, &expenses[*count].amount, expenses[*count].date) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Expenses loaded from file successfully!\n");
}
