#include <iostream>

using namespace std;

typedef struct{
    int i;
    int j;
    int res;
} Answer;

int summation(int* A, int i, int j){
    int acum = 0;
    for(int k = i; k <= j; k++)
        acum += A[k];
    return acum;
}

Answer max_1d_range_sum(int* A, int n){
    Answer result;
    result.res = -999;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int sum = summation(A,i,j);
            if(sum > result.res){
                result.i = i;
                result.j = j;
                result.res = sum;
            }
        }

    return result;
}

int main(void){
    int n = 8;
    int A[n] = {-2,1,-3,4,-1,2,1,-5,4};

    Answer example = max_1d_range_sum(A, n);

    cout << "El resultado máximo se obtiene en el rango [ " << example.i << " , " << example.j << " ], y es igual a " << example.res << ".\n";

    return 0;
}