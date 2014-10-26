/*
    Luna Capsule / vijos-1514

    Problem: https://vijos.org/p/1514
    Record: https://vijos.org/records/544c5c0a17f3cac60d140089

    - Used a segment tree to solve this problem.
*/

#include <cstdio>

const unsigned DATASIZE = 1000001;
const unsigned STSIZE = 10000001;

int d[DATASIZE], f[STSIZE];
unsigned n, f_l[STSIZE], f_r[STSIZE];

inline int max(int a, int b) { return a > b ? a : b; }

int buildSegmentTree(unsigned inode, unsigned a, unsigned b) {
    f_l[inode] = a, f_r[inode] = b;
    if (a == b)
        return f[inode] = d[a];
    else
        return f[inode] = max(
            buildSegmentTree(inode * 2 + 1, a, (unsigned) (a + b) / 2),
            buildSegmentTree(inode * 2 + 2, (unsigned) (a + b) / 2 + 1, b)
        );
}

int querySegmentTree(unsigned inode, unsigned a, unsigned b) {
    unsigned mid, next;

    mid = (unsigned) (f_l[inode] + f_r[inode]) / 2;
    next = inode * 2;

    //printf("Querying at #%d, [%d, %d] | mid %d, next %d, f_lr [%d, %d]\n", inode, a, b, mid, next, f_l[inode], f_r[inode]);

    if ((a == f_l[inode]) && (b == f_r[inode])) {
        //printf("* Reached leaf. [%d]\n", f[inode]);
        return f[inode];
    }

    if (b <= mid) {
        //printf("- Going down into left route.\n");
        return querySegmentTree(next + 1, a, b);
    }
    if (a > mid) {
        //printf("- Going down into right route.\n");
        return querySegmentTree(next + 2, a, b);
    }
    //printf("- Split into two routes.\n");
    return max(
        querySegmentTree(next + 1, a, mid),
        querySegmentTree(next + 2, mid + 1, b)
    );
}

void prepare() {
    unsigned i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    f[0] = buildSegmentTree(0, 1, n);
}

void processQuery() {
    unsigned m, i, a, b;

    scanf("%d", &m);
    for (i = 1; i <= m; i++)
        scanf("%d %d", &a, &b), printf("%d\n", querySegmentTree(0, a, b));
}

int main() {
    prepare();
    processQuery();
}
