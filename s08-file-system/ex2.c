#include <stdio.h>
#include <unistd.h>

int main () {
    while(1) {
        fprintf(stdout, "hey!\n");
        sleep(1);
        fprintf(stderr, "ho!\n");
        sleep(1);
    }
}
