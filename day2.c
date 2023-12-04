#include <stdio.h>
#include <ctype.h>

#define R_MAX 12
#define B_MAX 13
#define G_MAX 14
#define R_SKIP 3
#define G_SKIP 5
#define B_SKIP 4

#define SET_COLOR(x) {fseek(f, x##_SKIP, SEEK_CUR); max = x##_MAX;}

int fgetnumber(FILE* f) {
    int number = 0;
    for (int c=fgetc(f);isdigit(c);c=fgetc(f)) {
        number *= 10;
        number += c-'0';
    }
    return number;
}

int main(void) {
    FILE* f = fopen("../day2.txt","r");

    int sum = 0, id;
    outer_continue: while (!feof(f)) {
        fseek(f, 5, SEEK_CUR);
        id = fgetnumber(f);

        while (!feof(f) && fgetc(f) != '\n') {
            int amount = fgetnumber(f),
                max = 0,
                color = fgetc(f);
            if      (color == 'r') SET_COLOR(R)
            else if (color == 'g') SET_COLOR(G)
            else if (color == 'b') SET_COLOR(B)

            if (amount > max) {
                while (!feof(f) && fgetc(f) != '\n'); // Ignore other conditions
                goto outer_continue;
            }
        }
        sum += id;
    }
    fclose(f);
    printf("Result: %d\n", sum);
}
