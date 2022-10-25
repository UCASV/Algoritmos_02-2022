#include <iostream>

using namespace std;

int max_1d_range_sum(int* A, int n){
    int M[n+1], S = 0;

    M[0] = 0;
    for(int i = 1; i <= n; i++){
        S += A[i-1];
        S = max(S, A[i-1]);
        M[i] = max(S, M[i-1]);
    }

    return M[n];
}

int main(void){
    int n = 8;
    int A[n] = {-2,1,-3,4,-1,2,1,-5,4};

    cout << "El resultado máximo es: " << max_1d_range_sum(A, n) << ".\n";

    return 0;
}