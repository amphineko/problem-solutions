/*
    Luna Capsule / vijos-1391

    Problem: https://vijos.org/p/1391
    Record: https://vijos.org/records/53f226d948c5fc5e2f8b4570

    - Use Dijkstra algorithm for calculating the maximum from the source to any points.
*/

#include <cstdio>

const unsigned NO_ROUTE = 0;

unsigned n, v[2001][2001], dist[2001];

void preprocess() {
    unsigned x, y, a;

    scanf("%d", &n);

    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
            v[x][y] = NO_ROUTE;

    while (true) {
        scanf("%d %d %d", &x, &y, &a);
        v[x][y] = a;
        if (x + y + a == 0) break;
    }
}

inline unsigned getmax(unsigned a, unsigned b) { return (a > b) ? a : b; }
inline unsigned getmin(unsigned a, unsigned b) { return (a > b) ? b : a; }

void process(unsigned v0) {
    /* Dijkstra Algorithm */
    bool visited[2001];
    unsigned i, j, umax, u, newdist;

    for (i = 1; i <= n; i++) {
        dist[i] = v[v0][i];
        visited[i] = false;
    }

    // Initialize source vertex
    dist[v0] = 0;
    visited[v0] = true;

    for (i = 2; i <= n; i++) {
        umax = NO_ROUTE, u = v0;

        // Select next vertex for expanding
        for (j = 1; j <= n; j++)
            if (!visited[j] && (dist[j] > umax))
                u = j, umax = dist[j];
        visited[u] = true;

        // Apply maximum
        for (j = 1; j <= n; j++)
            if (!visited[j] && (v[u][j] != NO_ROUTE)) {
                newdist = getmin(dist[u], v[u][j]);
                dist[j] = getmax(dist[j], newdist);
            }
    }
}

void postprocess() {
    unsigned i;
    for (i = 2; i <= n; i++)
        printf("%d\n", dist[i]);
}

int main() {
    preprocess();
    process(1);
    postprocess();
}
