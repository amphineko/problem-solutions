/*
    Luna Capsule / vijos-1635

    Problem: https://vijos.org/p/1635
    Record: https://vijos.org/records/544bc9e317f3ca522b140075

    - 一道求單源點最短路徑的題目
      使用path[ ]記錄某節點的上一個節點(來源節點), 再使用棧即可完成路徑輸出
*/

#include <cstdio>

const unsigned MAXNODE = 1001;
const unsigned NO_CONN = 0x3f3f3f;

unsigned a[MAXNODE][MAXNODE], n;

void init() {
    unsigned i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = NO_CONN;
        }
}

void process(unsigned v0) {
    bool visited[MAXNODE];
    unsigned f[MAXNODE], prev[MAXNODE], path[MAXNODE], i, j, u = 0, ul, c;

    for (i = 1; i <= n; i++)
        f[i] = (a[v0][i] == NO_CONN) ? NO_CONN : a[v0][i], prev[i] = v0, visited[i] = false;
    visited[v0] = true;

    for (i = 2; i <= n; i++) {
        ul = NO_CONN;
        for (j = 1; j <= n; j++)
            if (!visited[j] && (f[j] < ul))
                u = j, ul = f[j];
        visited[u] = true;
        for (j = 1; j <= n; j++)
            if (!visited[j]) {
                c = f[u] + a[u][j];
                if (f[j] > c)
                    f[j] = c, prev[j] = u;
            }
    }

    j = 0;
    for (i = n; i != 1; i = prev[i])
        path[++j] = i;
    printf("%d ", v0);
    for (i = j; i >= 1; i--)
        printf("%d ", path[i]);
    printf("\n%d", f[n]);
}

int main() {
    init();
    process(1);
}
