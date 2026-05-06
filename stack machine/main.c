#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf(" -> Pushed: %d\n", value);
    }
}

// Pop
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        return stack[top--];
    }
}

// Display stack with Index Numbers
void display() {
    if (top == -1) {
        printf("[ Stack is empty ]\n");
    } else {
        printf("\n--- Current Stack ---\n");
        for (int i = 0; i <= top; i++) {
            printf(" Index [%d] : %d\n", i, stack[i]);
        }
        printf("---------------------\n");
    }
}

int main() {
    int choice, value, a, b, num_values;
    int idx1, idx2;

    printf("===== Stack Machine =====\n");

    while (1) {
        printf("\n------------------------------------------------");
        printf("\n1. Push Value(s)     5. Multiply (Custom) 9. Logical NOT (Custom)\n");
        printf("2. Pop Top Value     6. Divide (Custom)   10. Print Top\n");
        printf("3. Add (Custom)      7. AND (Custom)      11. Display Stack\n");
        printf("4. Subtract (Custom) 8. OR (Custom)       12. Exit\n");
        printf("------------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many values do you want to push? ");
                scanf("%d", &num_values);
                if (num_values > 0) {
                    printf("Enter %d value(s) separated by spaces: ", num_values);
                    for (int i = 0; i < num_values; i++) {
                        scanf("%d", &value);
                        push(value);
                    }
                } else {
                    printf("Invalid number of values.\n");
                }
                break;

            case 2:
                if (top != -1) {
                    value = pop();
                    printf(" -> Popped value: %d\n", value);
                } else {
                    printf("Error: Stack is empty.\n");
                }
                break;

            case 3: // Custom Add
                if (top < 1) {
                    printf("Error: Need at least 2 values to add.\n");
                } else {
                    printf("Enter INDEX for First Value: ");
                    scanf("%d", &idx1);
                    printf("Enter INDEX for Second Value: ");
                    scanf("%d", &idx2);

                    if (idx1 >= 0 && idx1 <= top && idx2 >= 0 && idx2 <= top) {
                        a = stack[idx1];
                        b = stack[idx2];
                        printf(" -> Operation: %d + %d\n", a, b);
                        push(a + b);
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 4: // Custom Subtract
                if (top < 1) {
                    printf("Error: Need at least 2 values to subtract.\n");
                } else {
                    printf("Enter INDEX to subtract FROM: ");
                    scanf("%d", &idx1);
                    printf("Enter INDEX to subtract: ");
                    scanf("%d", &idx2);

                    if (idx1 >= 0 && idx1 <= top && idx2 >= 0 && idx2 <= top) {
                        a = stack[idx1];
                        b = stack[idx2];
                        printf(" -> Operation: %d - %d\n", a, b);
                        push(a - b);
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 5: // Custom Multiply
                if (top < 1) {
                    printf("Error: Need at least 2 values to multiply.\n");
                } else {
                    printf("Enter INDEX for First Value: ");
                    scanf("%d", &idx1);
                    printf("Enter INDEX for Second Value: ");
                    scanf("%d", &idx2);

                    if (idx1 >= 0 && idx1 <= top && idx2 >= 0 && idx2 <= top) {
                        a = stack[idx1];
                        b = stack[idx2];
                        printf(" -> Operation: %d * %d\n", a, b);
                        push(a * b);
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 6: // Custom Divide
                if (top < 1) {
                    printf("Error: Need at least 2 values to divide.\n");
                } else {
                    printf("Enter INDEX for the Numerator (Top): ");
                    scanf("%d", &idx1);
                    printf("Enter INDEX for the Denominator (Bottom): ");
                    scanf("%d", &idx2);

                    if (idx1 >= 0 && idx1 <= top && idx2 >= 0 && idx2 <= top) {
                        a = stack[idx1];
                        b = stack[idx2];
                        if (b != 0) {
                            printf(" -> Operation: %d / %d\n", a, b);
                            push(a / b);
                        } else {
                            printf("Error: Division by zero.\n");
                        }
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 7: // Custom Logical AND
                if (top < 1) {
                    printf("Error: Need at least 2 values for Logical AND.\n");
                } else {
                    printf("Enter INDEX for First Value: ");
                    scanf("%d", &idx1);
                    printf("Enter INDEX for Second Value: ");
                    scanf("%d", &idx2);

                    if (idx1 >= 0 && idx1 <= top && idx2 >= 0 && idx2 <= top) {
                        a = stack[idx1];
                        b = stack[idx2];
                        printf(" -> Operation: %d && %d\n", a, b);
                        push(a && b); // Will push 1 or 0
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 8: // Custom Logical OR
                if (top < 1) {
                    printf("Error: Need at least 2 values for Logical OR.\n");
                } else {
                    printf("Enter INDEX for First Value: ");
                    scanf("%d", &idx1);
                    printf("Enter INDEX for Second Value: ");
                    scanf("%d", &idx2);

                    if (idx1 >= 0 && idx1 <= top && idx2 >= 0 && idx2 <= top) {
                        a = stack[idx1];
                        b = stack[idx2];
                        printf(" -> Operation: %d || %d\n", a, b);
                        push(a || b); // Will push 1 or 0
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 9: // Custom Logical NOT
                if (top < 0) {
                    printf("Error: Stack is empty.\n");
                } else {
                    printf("Enter INDEX of the value to flip (NOT): ");
                    scanf("%d", &idx1);

                    if (idx1 >= 0 && idx1 <= top) {
                        a = stack[idx1];
                        printf(" -> Operation: NOT %d (!%d)\n", a, a);
                        push(!a); // Will push 1 or 0
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;

            case 10:
                if (top != -1)
                    printf(" -> Top value: %d\n", stack[top]);
                else
                    printf("Stack is empty\n");
                break;

            case 11:
                // Falls through to auto-display
                break;

            case 12:
                printf("Program ended\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Auto-display
        if (choice != 12) {
            display();
        }
    }
}
