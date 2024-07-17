#include<stdio.h>

void calculateIndegrees(int indegree[], int a[][5], int n) {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[j][i];
        }
        indegree[i] = sum;
    }
}

void dfs(int res[], int v[], int a[][5], int sp, int *index) {
    v[sp] = 1;
    for (int i = 0; i < 5; i++) {
        if (a[sp][i] == 1 && v[i] == 0) {
            dfs(res, v, a, i, index);
        }
    }
    res[(*index)++] = sp;
}

int main() {
    int res[5], v[5], indegree[5];
    int a[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    // Initialize arrays
    for (int i = 0; i < 5; i++) {
        res[i] = -1; // Using -1 to indicate uninitialized values
        v[i] = 0;
    }

    calculateIndegrees(indegree, a, 5);

    // Start DFS from all vertices with 0 indegrees
    int index = 0;
    for (int i = 0; i < 5; i++) {
        if (indegree[i] == 0 && v[i] == 0) {
            dfs(res, v, a, i, &index);
        }
    }

    // Output result
    printf("Order of vertices visited (topological sort):\n");
    for (int i = 4; i >= 0; i--) {
        if (res[i] != -1) // Only print initialized values
            printf("%d\t", res[i] + 1);
    }
    printf("\n");

    return 0;
}
