#include<stdio.h>

int c[6][6] = {{0, 15, 10, 999, 45, 999}, {999, 0, 15, 999, 20, 999},{20, 999, 0, 20, 999, 999}, {999, 10, 999, 0, 35, 999}, {999, 999, 999, 30, 0, 999}, {999, 999, 999, 4, 999, 0}};

void main()
{
    int d[6], v[6], min, u;
    int source = 5;
    for(int j=1;j<6;j++)
    {
        d[j] = c[source][j];
        v[j] = 0;
    }

    d[source] = 0;
    v[source] = 1;
    int count = 1;

    while(count != 6)
    {
        min = 9999;
        for(int j = 1;j<6;j++)
        {
            if(d[j] < min && v[j] != 1)
            {
                min = d[j];
                u = j;
            }
        }
        v[u] = 1;
        count = count + 1;
        for(int j = 1;j<6;j++){
            if(min+c[u][j] < d[j] && v[j] != 1)
                d[j] = min + c[u][j];
        }
    }

    printf("Shortest distance is:\n");
    printf("Source\tDestination\tMinCost\n");
    for(int j = 1;j<6;j++){
        printf("\n%d\t%d\t\t %d\n", source, j, d[j]);
    }
}
