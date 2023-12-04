#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE* f = fopen("../day1.txt","r");
    int ch, sum = 0, last = 0;
    while ((ch = fgetc(f))!= EOF)
        if (ch == '\n') {
            sum += last; last = 0;
        } else if (isdigit(ch)) {
            sum += (ch-'0') * 10 * !last;
            last = (ch-'0');
        }
    fclose(f);
    sum += last;
    printf("Result: %d\n", sum);
}