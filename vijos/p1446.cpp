/*
    Luna Capsule / vijos-1446

    Problem: https://vijos.org/p/1446
    Record: https://vijos.org/records/544bcc1d17f3ca162e140074

    - 資料規模很小, 使用Prim即可解
      枚舉與a直接連接的節點k, 若f[a][k] == f[k][b]的話通過k由a達到b的路徑一定在最短路徑集中
*/

#include <cstdio>

const unsigned NO_CONN = 0x3f3f3f;
const unsigned VERTEX_MAX = 101;

unsigned f[VERTEX_MAX][VERTEX_MAX], n;

void preprocess() {
    unsigned m, i, j, u, v;

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f[i][j] = NO_CONN;
    for (i = 1; i <= m; i++)
        scanf("%d %d", &u, &v), f[u][v] = f[v][u] = 1;
}

void process() {
    unsigned k, i, j, c;

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                c = f[i][k] + f[k][j];
                if (f[i][j] > c)
                    f[i][j] = c;
            }
}

inline unsigned query(unsigned u, unsigned v) {
    unsigned i, t = 2;

    for (i = 1; i <= n; i++)
        if (f[u][i] + f[i][v] == f[u][v])
            t++;
    return t;
}

void postprocess() {
    unsigned p, i, u, v;

    scanf("%d", &p);
    for (i = 1; i <= p; i++)
        scanf("%d %d", &u, &v), printf("%d\n", query(u, v));
}

int main() {
    preprocess();
    process();
    postprocess();
}
