#include <iostream>

using namespace std;

int LCS(string A, string B){ 
    int nA = A.length(), nB = B.length();
    int M[nA+1][nB+1];

    for(int i = 0; i <= nA; i++)
        M[i][0] = 0;
    for(int j = 1; j <= nB; j++)
        M[0][j] = 0;

    for(int i = 1; i <= nA; i++)
        for(int j = 1; j <= nB; j++)
            if( A[i-1] == B[j-1] )
                M[i][j] = 1 + M[i-1][j-1];
            else
                M[i][j] = max( M[i-1][j] , M[i][j-1] );

    return M[nA][nB];
}

int main(void){
    string S1 = "stone", S2 = "longest";

    cout << "La longitud de la Longest Common Subsequence es: " << LCS(S1, S2) << ".\n";

    return 0;
}