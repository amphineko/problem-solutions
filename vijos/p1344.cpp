/*
    Luna Capsule / vijos-1344

    Problem: https://vijos.org/p/1344
    Record: https://vijos.org/records/53eabfb248c5fc75748b4573
*/

#include <cstdio>
#include <cstdlib>

unsigned parsetype(char a) {
    if ((48 <= a) && (a <= 57))
        return 1;
    if ((97 <= a) && (a <= 122))
        return 2;
    switch (a) {
        case '+': return 3;
        case '-': return 4;
        case '=': return 5;
        case EOF: return 5;
    }
    return 0;
}

void parse() {
    char c, a = 'a';
    bool preflag = 0;
    signed cparam = 0, pf = 1, minus = 1, pre = 0, con = 0;
    double ret;

    while (true) {
        if (scanf("%c", &c) == EOF)
            c = EOF;
        //printf("%c\: ", c);
        switch (parsetype(c)) {
            case 1: {
                cparam = cparam * 10 + (c - 48);
                //printf("number \> cparam = %d\n", cparam);
            } break;

            case 2: {
                preflag = true;
                a = c;
                //printf("object \> preflag = %d\n", preflag);
            } break;

            case 3: case 4: case 5: {
                //printf("operator \> pf = %d, minus = %d, pre = %d, con = %d, cparam = %d\n", pf, minus, pre, con, cparam);
                if (preflag)
                    pre += cparam * pf * minus;
                else
                    con += cparam * pf * minus;
                preflag = false;
                cparam = 0;
                minus = 1;
                //printf("              pf = %d, minus = %d, pre = %d, con = %d, cparam = %d\n", pf, minus, pre, con, cparam);

                if (c == '-')
                    minus = -1;
                if (c == '=')
                    pf = -1;
            } break;
        }
        if (c == EOF) {
            break;
        }
    }

    ret = double(-con) / double(pre);
    printf("%c=%.3f", a, ret);
}

int main() {
    parse();
    return 0;
}
