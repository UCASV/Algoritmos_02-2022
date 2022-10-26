#include <iostream>
#include <string>

using namespace std;

typedef struct{
    int max_sum;
    string max_range;
} Answer;

Answer max_1d_range_sum(int* A, int n){
    int M[n+1], S = 0;
    string R[n+1], cad = "";

    M[0] = 0;
    R[0] = "";
    for(int i = 1; i <= n; i++){
        S += A[i-1];

        if( S > A[i-1] ) cad += "-"+to_string(i-1);
        else cad = to_string(i-1);
        S = max(S, A[i-1]);

        if( S > M[i-1] ) R[i] = cad;
        else R[i] = R[i-1];
        M[i] = max(S, M[i-1]);
    }

    Answer res;
    res.max_sum = M[n];
    res.max_range = R[n];
    return res;
}

int main(void){
    int n = 8;
    int A[n] = {-2,1,-3,4,-1,2,1,-5,4};

    Answer respuesta = max_1d_range_sum(A, n);

    cout << "El resultado máximo es: " << respuesta.max_sum << ", y ocurre en el rango: " << respuesta.max_range << ".\n";

    return 0;
}