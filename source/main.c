#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Użycie: interpreter [plik_z_kodem_python]\n");
        return 1;
    }
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku %s\n", filename);
        return 1;
    }
    char code[1024];
    while (fgets(code, sizeof(code), file)) {
        printf("Wykonuję kod...\n");
        if (strstr(code, "print(") != NULL) {
            char *start = strstr(code, "(");
            char *end = strstr(code, ")");
            if (start != NULL && end != NULL) {
                start++;
                *end = '\0';
                printf("%s\n", start);
            }
        } else {
            printf("Nieznana komenda.\n");
        }
    }
    fclose(file);
    return 0;
}
