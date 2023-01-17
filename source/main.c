#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    // Check if there are arguments
    if (argc < 2){
        printf("Użycie: interpreter [plik_z_kodem_python]\n");
        return 1;
    }
    // Filename will be second argument
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    // If can not open file:
    if (file == NULL) {
        printf("Nie można otworzyć pliku %s\n", filename);
        return 1;
    }
    // Array code
    char code[1024];
    // fgets is getting one line of file
    // It saves text to code
    // Maximum number of chars is sizeof(code)
    while (fgets(code, sizeof(code), file)) {
        printf("Wykonuję kod... \n");
        puts(code);
        // If "print(" will be found
        if (strstr(code, "print('") != NULL) {
            char *start = strstr(code, "(");
            char *end = strstr(code, ")");
            if (start != NULL && end != NULL) {
                start++;
                *end = '\0';
                printf("%s\n", start);
            }
        }
        // if (strstr(code, "+") != NULL || strstr(code, "-") != NULL || strstr(code, "*") != NULL || 
        //     strstr(code, "/") != NULL ) {
        //     char *result;
        //     double final_result = strtod(code, &result);

        //     if (*result) {
        //         printf("Invalid input");
        //     }
        //     else {
        //         printf("Wynik: %f\n", final_result);
        //     }
        //     } 
        //     else {
        //         printf("Nieznana komenda.\n");
        //     }
    }

    fclose(file);
    return 0;
}
