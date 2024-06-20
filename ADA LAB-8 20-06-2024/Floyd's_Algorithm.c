#include<stdio.h>

void main()
{
    int a[4][4] = {{0, 999, 3, 999}, {2, 0, 999, 999}, {999, 7, 0, 1}, {6, 999, 999, 0}};
    int d[4][4];
    for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            d[r][c] = a[r][c];
        }
    }

    for(int k=0; k<4; k++)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4;j++)
            {
                if((d[i][k] + d[k][j]) < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    printf("All Pair Shortest paths:\n");
    for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            printf("%d\t",d[r][c]);
        }
        printf("\n");
    }
}
