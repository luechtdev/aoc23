#pragma clang diagnostic ignored "-Wformat-security"

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

const char* digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char cmpbuf[5];

int main(void) {
    FILE* f = fopen("day1.txt","r"); assert(f);
    int ch, sum = 0, last = 0;
    while (!feof(f) && (ch = fgetc(f))!= EOF)
        if (ch == '\n') {
            sum += last; last = 0;
        } else if (isdigit(ch)) {
            sum += (ch-'0') * 10 * !last;
            last = (ch-'0');
        } else {
            *cmpbuf = (char)ch;
            for (long i=0, pos=ftell(f);i<9;++i) {
                fgets(&cmpbuf[1], (int)strlen(digits[i])-1,f);
                if (!strncmp(cmpbuf, digits[i], strlen(digits[i]))) {
                    sum += (i+1) * 10 * !last;
                    last = (i+1);
                    break;
                } else fseek(f, pos, SEEK_SET);
            }
        }
    fclose(f);
    sum += last;
    printf("Result: %d\n", sum);
}
