#include<stdio.h>

void Nqueens(int n){
    int x[n+1];

    // current row
    int k = 1;
    for(int i = 0; i <= n; i++) {
        x[i] = 0;
    }

    while(k != 0){

        // initially x[] = 0 by incrementing by 1 we are placing queen
        x[k] = x[k] + 1;

        // if the queen cannot be placed move to next column
        while(place(x, k) != 1 && x[k] <= n) {
            x[k] = x[k] + 1;
        }


        if(x[k] <= n){
            // if k reaches the number of queens then print all queens position
            if(k == n){
                for(int j = 1; j <= n; j++){
                    printf("Queen %d Position %d\n", j, x[j]);
                }
                printf("\n");
            }

            // else increment k move to next box
            else {
                k = k + 1;
                x[k] = 0;
            }
        } else {
            // No position found to place queen so backtrack to previous row
            k = k - 1;
        }
    }
}

int place(int x[], int k){
    for(int i = 1; i < k; i++){
        if(x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
            return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Enter number of Queens to be placed: ");
    scanf("%d", &n);
    Nqueens(n);
    return 0;
}
