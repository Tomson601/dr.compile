#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double num1, num2, result = 0;
    char operator;

    // Check if there are arguments
    if (argc < 2)
    {
        printf("Użycie: interpreter [plik_z_kodem_python]\n");
        return 1;
    }
    // Filename will be second argument
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    // If can not open file:
    if (file == NULL)
    {
        printf("Nie można otworzyć pliku %s\n", filename);
        return 1;
    }
    // Array code
    char code[1024];

    while (fgets(code, sizeof(code), file))
    {
        if (strstr(code, "print('") != NULL)
        {
            char *start = strstr(code, "(");
            char *end = strstr(code, ")");
            if (start != NULL && end != NULL)
            {
                start++;
                *end = '\0';
                printf("%s\n", start);
            }
        }

        else if (sscanf(code, "%lf %c %lf", &num1, &operator, & num2) == 3)
        {
            switch (operator)
            {
            case '+':
                result = num1 + num2;
                printf("%f\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("%f\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("%f\n", result);
                break;
            case '/':
                result = num1 / num2;
                printf("%f\n", result);
                break;
            }
        }
    }
    // printf("%f\n", result);

    fclose(file);
    return 0;
}
