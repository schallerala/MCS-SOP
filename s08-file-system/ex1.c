#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * lib_upper (char * string) {
    int len = strlen(string);
    char * new_string = malloc(len);

    for (int i = 0; i < len; i++) {
        new_string[i] = toupper(string[i]);
    }

    return new_string;
}

char * own_upper (char * string) {
    int len = strlen(string);
    char * new_string = malloc(len);

    for (int i = 0; i < len; i++) {
        char c = string[i];
        new_string[i] = c;
        if (c >= 'a' && c <= 'z') {
            new_string[i] += 'A' - 'a';
        }
    }

    return new_string;
}

int main () {
    char s1[] = "Français";
    char s2[] = "spaß";
    printf("%s -> lib upper: %s\n", s1, lib_upper(s1));
    printf("%s -> lib upper: %s\n", s2, lib_upper(s2));

    printf("%s -> own upper: %s\n", s1, own_upper(s1));
    printf("%s -> own upper: %s\n", s2, own_upper(s2));

    return 1;
}