#include <stdio.h>
#include <math.h>

int main(void)
{
    long long a, b, result;
    int choice;

    while (1)
    {
        printf("\n============================\n");
        printf("       C CALCULATOR\n");
        printf("============================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");
        printf("============================\n");
        printf("Choose: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 8)
            break;

        if (choice >= 1 && choice <= 5)
        {
            printf("Enter two numbers (up to 1,000,000,000): ");

            if (scanf("%lld %lld", &a, &b) != 2)
            {
                printf("Invalid input.\n");
                while (getchar() != '\n');
                continue;
            }

            if (a > 1000000000LL || a < -1000000000LL ||
                b > 1000000000LL || b < -1000000000LL)
            {
                printf("Error: Number must be between -1,000,000,000 and 1,000,000,000.\n");
                continue;
            }

            switch (choice)
            {
                case 1:
                    result = a + b;
                    printf("Result: %lld\n", result);
                    break;

                case 2:
                    result = a - b;
                    printf("Result: %lld\n", result);
                    break;

                case 3:
                    result = a * b;
                    printf("Result: %lld\n", result);
                    break;

                case 4:
                    if (b == 0)
                        printf("Error: Cannot divide by zero.\n");
                    else
                        printf("Result: %lld\n", a / b);
                    break;

                case 5:
                    if (b == 0)
                        printf("Error: Cannot use modulus by zero.\n");
                    else
                        printf("Result: %lld\n", a % b);
                    break;
            }
        }
        else if (choice == 6)
        {
            double x, y;

            printf("Enter base and exponent: ");
            scanf("%lf %lf", &x, &y);

            printf("Result: %.10g\n", pow(x, y));
        }
        else if (choice == 7)
        {
            double x;

            printf("Enter number: ");
            scanf("%lf", &x);

            if (x < 0)
                printf("Error: Negative number.\n");
            else
                printf("Result: %.10g\n", sqrt(x));
        }
        else
        {
            printf("Invalid option.\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}
