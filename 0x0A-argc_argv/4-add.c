#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("0\n");
        return 0;
    }

    int sum = 0;
    int error = 0;

    for (int i = 1; i < argc; i++) {
        char *end;
        long number = strtol(argv[i], &end, 10);

        if (number <= 0 || *end != '\0') {
            error = 1;
            break;
        }

        sum += number;
    }

    if (error) {
        printf("Error\n");
        return 1;
    }

    printf("%d\n", sum);
    return 0;
}