#include <iostream>

using namespace std;

int knapsack(int K, int* V, int* W, int n){
    int M[n+1][K+1];

    for(int i = 0; i <= n; i++)
        M[i][0] = 0;

    for(int j = 1; j <= K; j++)
        M[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= K; j++)
            if( j >= W[i-1] )
                 M[i][j] = max( V[i-1] + M[i-1][j-W[i-1]], M[i-1][j]);
            else M[i][j] = M[i-1][j];

    return M[n][K];
}

int main(void){
    int n = 3, K = 50;
    int V[n] = {60,100,120}, W[n] = {10,20,30};

    cout << "El valor máximo que se puede obtener es: " << knapsack(K, V, W, n) << ".\n";

    return 0;
}