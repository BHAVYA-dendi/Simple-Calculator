#include <stdio.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void calculator();

int main() {
    printf("Simple Calculator\n");
    calculator();
    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

// Calculator function
void calculator() {
    int choice;
    double num1, num2, result;
    double (*operation)(double, double);  // Function pointer

    while (1) {
        // Menu
        printf("\nSelect an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Input numbers
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        // Assign operation based on choice
        switch (choice) {
            case 1: operation = add; break;
            case 2: operation = subtract; break;
            case 3: operation = multiply; break;
            case 4: operation = divide; break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        // Perform and display result
        result = operation(num1, num2);
        printf("Result: %.2lf\n", result);
    }
}
