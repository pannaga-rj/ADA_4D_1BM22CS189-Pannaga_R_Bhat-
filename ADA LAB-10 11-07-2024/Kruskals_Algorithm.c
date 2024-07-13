#include <stdio.h>

void main() {
    int n;
    printf("Enter number of vertices\n");
    scanf("%d", &n);

    int c[n][n];
    printf("Enter cost adjacency matrix\n");
    for (int r = 0; r < n; r++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[r][j]);
        }
        printf("\n");
    }

    int ne = 0, parent[n];
    int mincost = 0, min, u, v, a, b;

    for (int i = 0; i < n; i++) { // Initialize parent array starting from 0
        parent[i] = 0;
    }

    while (ne != n - 1) {
        min = 9999; // Use a large number as initial min
        for (int i = 0; i < n; i++) { // Loop starting from 0
            for (int j = 0; j < n; j++) { // Loop starting from 0
                if (c[i][j] < min && c[i][j] != 0) { // Ensure 0 is not considered as a valid edge
                    min = c[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        while (parent[u] != 0) {
            u = parent[u];
        }
        while (parent[v] != 0) {
            v = parent[v];
        }

        if (u != v) {
            printf("A = %d, B = %d, Min = %d\n", a + 1, b + 1, min); // Print 1-based index
            parent[v] = u;
            ne = ne + 1;
            mincost += min;
        }

        c[a][b] = c[b][a] = 9999; // Mark the edge as visited
    }
    printf("Minimum Cost = %d\n", mincost);
}




