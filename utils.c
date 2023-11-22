#include "main.h"
#include <stdio.h>

char *intToString(int n) {
    char *str = malloc(12 * sizeof(char));
    if (str == NULL) {
        return NULL;
    }
    sprintf(str, "%d", n);
    return str;
}

