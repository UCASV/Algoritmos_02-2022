#include <iostream>

using namespace std;

typedef struct{
    int max_length;
    string max_seq;
} Answer;

Answer LCS(string A, string B){ 
    int nA = A.length(), nB = B.length();
    int M[nA+1][nB+1];
    string R[nA+1][nB+1];

    for(int i = 0; i <= nA; i++){
        M[i][0] = 0;
        R[i][0] = "";
    }
    for(int j = 1; j <= nB; j++){
        M[0][j] = 0;
        R[0][j] = "";
    }

    for(int i = 1; i <= nA; i++)
        for(int j = 1; j <= nB; j++)
            if( A[i-1] == B[j-1] ){
                M[i][j] = 1 + M[i-1][j-1];
                R[i][j] = R[i-1][j-1] + A[i-1] + " ";
            }else{
                M[i][j] = max( M[i-1][j] , M[i][j-1] );
                if( M[i-1][j] > M[i][j-1] )
                    R[i][j] = R[i-1][j];
                else
                    R[i][j] = R[i][j-1];
            }

    Answer res;
    res.max_length = M[nA][nB];
    res.max_seq = R[nA][nB];
    return res;
}

int main(void){
    string S1 = "stone", S2 = "longest";

    Answer respuesta = LCS(S1, S2);
    cout << "La longitud de la Longest Common Subsequence es: " << respuesta.max_length << ", y la secuencia correspondiente es: [ "<< respuesta.max_seq <<"].\n";

    return 0;
}