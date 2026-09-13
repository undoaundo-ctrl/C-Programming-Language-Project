#include <stdio.h>
#include <math.h>

int main(void)
{
    int choice;
    double a, b, result;

    while (1)
    {
        printf("\n==============================\n");
        printf("       C CALCULATOR\n");
        printf("==============================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");
        printf("==============================\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 8)
        {
            printf("Goodbye!\n");
            break;
        }

        switch (choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = a + b;
                printf("Result: %.10g\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = a - b;
                printf("Result: %.10g\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                result = a * b;
                printf("Result: %.10g\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);

                if (b == 0)
                    printf("Error: Cannot divide by zero.\n");
                else
                {
                    result = a / b;
                    printf("Result: %.10g\n", result);
                }
                break;

            case 5:
                printf("Enter two integers: ");

                {
                    long long x, y;

                    if (scanf("%lld %lld", &x, &y) != 2)
                    {
                        printf("Invalid input.\n");
                        while (getchar() != '\n');
                        break;
                    }

                    if (y == 0)
                        printf("Error: Cannot use modulus by zero.\n");
                    else
                        printf("Result: %lld\n", x % y);
                }
                break;

            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &a, &b);
                result = pow(a, b);
                printf("Result: %.10g\n", result);
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%lf", &a);

                if (a < 0)
                    printf("Error: Cannot calculate the square root of a negative number.\n");
                else
                {
                    result = sqrt(a);
                    printf("Result: %.10g\n", result);
                }
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}
