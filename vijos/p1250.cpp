/*
    Luna Capsule / vijos-1250

    Problem: https://vijos.org/p/1250
    Record: https://vijos.org/records/5451155917f3ca6472ffbe8b

    - 并查集 + 分组动态规划
*/

#include <cstdio>

const unsigned MAXSIZE = 1001;
const unsigned MAXWEIGHT = 100001;

unsigned n, p[MAXSIZE], w[MAXSIZE], wmax;

bool gmark[MAXSIZE];
unsigned f[MAXWEIGHT], mg[MAXSIZE];

void createmg(unsigned k) {
    unsigned i, j, a, b, c, d;

    for (i = 1; i <= n; i++)
        mg[i] = i, gmark[i] = false;
    for (i = 1; i <= k; i++) {
        scanf("%d %d", &a, &b), c = mg[a], d = mg[b];
        for (j = 1; j <= n; j++)
            if (mg[j] == c)
                mg[j] = d;
    }
    for (i = 1; i <= n; i++)
        gmark[mg[i]] = true;
}

void init() {
    unsigned i, k;

    scanf("%d %d %d", &n, &wmax, &k);
    for (i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &w[i]), mg[i] = i;
    createmg(k);
}

inline unsigned max(unsigned a, unsigned b) { return a > b ? a : b; }

void process() {
    unsigned i, j, k;

    for (k = 1; k <= n; k++)
        if (gmark[k])
            for (j = wmax; j > 0; j--)
                for (i = 1; i <= n; i++)
                    if ((mg[i] == k) && (w[i] <= j))
                        f[j] = max(f[j], f[j-w[i]] + p[i]);
    printf("%d", f[wmax]);
}

int main() {
    init();
    process();
}
