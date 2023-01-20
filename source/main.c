#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double num1, num2, result = 0;
    double variables[26];
    double value;
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

        else if (strstr(code, "=") != NULL) {
            char variableName = code[0];
            if (variableName >= 'a' && variableName <= 'z') {
                sscanf(code, "%c = %lf", &variableName, &value);
                variables[variableName - 'a'] = value;
            }
        }

        else if (strstr(code, "print(") != NULL)
        {
            char *start = strstr(code, "(");
            char *end = strstr(code, ")");
            if (start != NULL && end != NULL)
            {
                start++;
                *end = '\0';
                for (int i = 0; i < 26; i++) {
                    char var_char = i + 'a';
                    if (var_char == *start){
                        printf("%lf\n", variables[i]);
                    }
                }
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
            default:
                printf("Nieznany operator: %c\n", operator);
                continue;
            }
        }
    }
    // printf("%f\n", result);

    fclose(file);
    return 0;
}
