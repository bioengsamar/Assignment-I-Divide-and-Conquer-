#include <iostream>

using namespace std;

#define N 4

void creat_matrix(int mat[][N] , int n)
{
   for(int i=0; i<n; i++)
    {
       for(int j=0; j<n; j++)
           cin>>mat[i][j];

    }

}

// This function multiplies
// mat1[][] and mat2[][], and
// stores the result in res[][]
void multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}
int show_result(int c[][N])
{
   cout<<"\n result Matrix is:\n";
   for(int i=0; i<N; i++)
   {
       for(int j=0; j<N; j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

// Driver Code
int main()
{
    int res[N][N]; // To store result
    int mat1[N][N];

    int mat2[N][N];

    cout<<"Enter elements of first matrix \n";
    creat_matrix(mat1, N);

    cout<<"Enter elements of second matrix \n";
    creat_matrix(mat2, N);

    multiply(mat1, mat2, res);

    show_result(res);
    return 0;
}


