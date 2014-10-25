/*
    Luna Capsule / vijos-1407

    Problem: https://vijos.org/p/1407
    Record: https://vijos.org/records/544bccb417f3ca382e140073

    - 語文題 + 背包
*/

#include <cstdio>

const unsigned ATTR_SIZE = 3;
const unsigned DP_SIZE = 8001;

unsigned z[ATTR_SIZE], c[ATTR_SIZE], v[ATTR_SIZE];
unsigned f[DP_SIZE];

inline unsigned lookup(unsigned id) { for (unsigned i = 0; i < ATTR_SIZE; i++) if (z[i] == id) return i; return 0; }

int main() {
    unsigned n, m;
    unsigned i, j, k;
    unsigned b, cz, a, _;

    scanf("%d %d", &n, &m);

    /* Initialize 0/1 Package */
    for (i = 0; i <= m; i++)
        f[i] = 0;

    /* Initialize texture info */
    for (i = 0; i < ATTR_SIZE; i++)
        scanf("%d %d %d", &z[i], &c[i], &v[i]);

    /* Dynamic Programming */
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &b, &cz);
        k = lookup(cz);
        a = b * c[k], b += b * v[k];
        for (j = m; j >= b; j--) {
            _ = f[j - b] + a;
            if (_ > f[j])
                f[j] = _;
        }
    }

    /* Postprocess */
    printf("%d", f[m]);
    return 0;
}
