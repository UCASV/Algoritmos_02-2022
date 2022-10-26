#include <iostream>
#include <string>

using namespace std;

typedef struct{
    int max_value;
    string max_combi;
} Answer;

Answer knapsack(int K, int* V, int* W, int n){
    int M[n+1][K+1];
    string S[n+1][K+1];

    for(int i = 0; i <= n; i++){
        M[i][0] = 0;
        S[i][0] = "";
    }

    for(int j = 1; j <= K; j++){
        M[0][j] = 0;
        S[0][j] = "";
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= K; j++)
            if( j >= W[i-1] && ( V[i-1] + M[i-1][j-W[i-1]] > M[i-1][j] ) ){
                M[i][j] = V[i-1] + M[i-1][j-W[i-1]];
                S[i][j] = to_string(i) + "," + S[i-1][j-W[i-1]];
            }else{
                M[i][j] = M[i-1][j];
                S[i][j] = S[i-1][j];
            }

    Answer res;
    res.max_value = M[n][K];
    res.max_combi = S[n][K];
    return res;
}

int main(void){
    int n = 3, K = 50;
    int V[n] = {60,100,120}, W[n] = {10,20,30};

    Answer respuesta = knapsack(K, V, W, n);

    cout << "El valor máximo que se puede obtener es: " << respuesta.max_value << ", y la combinación de objetos es: [" << respuesta.max_combi << "].\n";

    return 0;
}