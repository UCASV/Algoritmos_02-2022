#include <iostream>

using namespace std;

int knapsack(int K, int* V, int* W, int n, int cont){
    if(cont == n) return 0;
    
    int res1, res2;
    
    res1 = knapsack(K, V, W, n, cont+1);
    
    if(W[cont] <= K)
        res2 = V[cont] + knapsack(K-W[cont], V, W, n, cont+1);
    else res2 = 0;

    return max(res1, res2);
}

int main(void){
    int n = 3, K = 50;
    int V[n] = {60,100,120}, W[n] = {10,20,30};

    cout << "El valor máximo que se puede obtener es: " << knapsack(K, V, W, n, 0) << ".\n";

    return 0;
}