#include <stdio.h>

// https://stackoverflow.com/a/4415646/3771148
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))


void original_for (int n) {
    for (int i = 0; i < n; i++) {
        // do some actions
        printf("Do stuff\n");
    }
}


void for_with_goto (int n) {
loopstart:;

    if (n-- <= 0)
        goto loopend;

    // do some actions
    printf("Do stuff\n");
    goto loopstart;

loopend:;
}

void original_for_break (int n) {
    for (int i = 0; i < n; i++) {
        // do some actions 1
        printf("Action 1\n");

        if (i % 4 == 3) break;
        // do some actions 2
        printf("Action 2\n");
    }
}

void for_break_with_goto (int n) {
    int i = 0;
loopstart:;

    if (i >= n)
        goto loopend;

    printf("Action 1\n");

    if (i % 4 == 3)
        goto loopend;

    printf("Action 2\n");

    i++;
    goto loopstart;

loopend:;
}

void original_for_continue (int n) {
    for (int i = 0; i < n; i++) {
        // do some actions 1
        printf("Action 1\n");
        if (i % 4 == 3) continue;
        // do some actions 2
        printf("Action 2\n");
    }
}

void for_continue_with_goto (int n) {
    int i = 0;
loopstart:;

    if (i >= n)
        goto loopend;

    printf("Action 1\n");

    if (i % 4 == 3) {
        i++;
        goto loopstart;
    }

    printf("Action 2\n");

    i++;
    goto loopstart;

loopend:;
}

void original_switch (int i) {
    switch (i) {
        case 1:
            printf("case 1\n");
            break;
        case 2:
            printf("case 2\n"); // Beware: no break !!!
        default:
            printf("default case\n");
            break;
    }
}

void switch_goto (int i) {
    void *switch_gotos[] = {&&CASE1, &&CASE2};

    if (i < 1 || i > 2)
        goto DEFAULTCASE;

    goto *switch_gotos[i - 1];

CASE1:;
    printf("case 1\n");
    goto SWITCHOUT;
CASE2:;
    printf("case 2\n");

DEFAULTCASE:;
    printf("default case\n");
    // to do the same, here, goto SWITCHOUT too, but not necessary
    // to get the same result

SWITCHOUT:;
}

void call_original_and_alternative (void (* original)(int), void (* alternative)(int), char* name, int n) {
    printf("# Calling %s with n=%d\n", name, n);
    printf("## original:\n");
    original(n);
    printf("## alternative:\n");
    alternative(n);
}

void call_original_and_alternative_array (void (* original)(int), void (* alternative)(int), char* name, int n_s[], int n_s_size) {
    for (int i = 0; i < n_s_size; i++) {
        int n = n_s[i];
        printf("\n");
        call_original_and_alternative(original, alternative, name, n);
    }
}


int main () {
    int n_s[] = {0, 2, 4, 6};
    int n_s_size = COUNT_OF(n_s);

    call_original_and_alternative_array(&original_for, &for_with_goto, "for loop", n_s, n_s_size);

    printf("\n");
    call_original_and_alternative_array(&original_for_break, &for_break_with_goto, "for break loop", n_s, n_s_size);

    printf("\n");
    call_original_and_alternative_array(&original_for_continue, &for_continue_with_goto, "for continue loop", n_s, n_s_size);


    int n_s_2[] = {-2, 0, 1, 2, 15};
    int n_s_size_2 = COUNT_OF(n_s_2);

    printf("\n");
    call_original_and_alternative_array(&original_switch, &switch_goto, "switch statement", n_s_2, n_s_size_2);
}