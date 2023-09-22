//this example demonstrate multiple ways of extracting integers from a string.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char *str = "ab234cid*(s349*(20kd", *p;
    char ch = '5';
    char moredigit[10] = "12345";
    int n;

    printf("ch is converted into integer: %d", ch-'0'); //subtracting the ascii value of 0 from the character will result in actual number
    p = moredigit;
    printf("\nMore digit %ld\n", strtol(p, &p, 10));

    sscanf(moredigit, "%d", &n);
    printf("\nMore digit2 %d\n", n);

    p = str;
    while (*p) {
        if (isdigit(*p)) {
                printf("--%c--", *p);
            long val = strtol(p, &p, 10);
            printf("%ld\n", val);
        } else {
             printf("==%c==", *p);
            p++;
        }
    }
    return 0;
}
