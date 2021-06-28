#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void creat_matrix(vector< vector<int> >& mat , int n)
{
   for(int i=0; i<n; i++)
    {
       for(int j=0; j<n; j++)
           cin>>mat[i][j];

    }

}

void matrix_sum(vector< vector<int> >& a,vector< vector<int> >& b, vector< vector<int> >& c,int n)
{
	for (int i = 0; i < n;i++)
	for (int j = 0; j < n; j++){
		c[i][j] = a[i][j] + b[i][j];
	}
}
void matrix_mul(vector< vector<int> >& a, vector< vector<int> >& b, vector< vector<int> >& c, int n) // divide and conquer method
{
	if (n == 1){
		c[0][0] = a[0][0] * b[0][0];
	}
	else{
		vector<vector<int> > a11(n/2);
		vector<vector<int> > a12(n/2);
		vector<vector<int> > a21(n/2);
		vector<vector<int> > a22(n/2);

		vector<vector<int> > b11(n/2);
		vector<vector<int> > b12(n/2);
		vector<vector<int> > b21(n/2);
		vector<vector<int> > b22(n/2);

		vector<vector<int> > c11(n/2);
		vector<vector<int> > c12(n/2);
		vector<vector<int> > c21(n/2);
		vector<vector<int> > c22(n/2);

		vector<vector<int> > temp1(n/2);
		vector<vector<int> > temp2(n/2);

		for (int i = 0; i < (n/2); i++){
			a11[i].resize(n/2);
			a12[i].resize(n/2);
			a21[i].resize(n/2);
			a22[i].resize(n/2);

			b11[i].resize(n/2);
			b12[i].resize(n/2);
			b21[i].resize(n/2);
			b22[i].resize(n/2);

			c11[i].resize(n/2);
			c12[i].resize(n/2);
			c21[i].resize(n/2);
			c22[i].resize(n/2);

			temp1[i].resize(n/2);
			temp2[i].resize(n/2);

		}

		for (int i = 0; i < (n/2); i++)
		for (int j = 0; j < (n/2); j++){
			a11[i][j] = a[i][j];
			a12[i][j] = a[i][j + (n/2)];
			a21[i][j] = a[i + (n/2)][j];
			a22[i][j] = a[i + (n/2)][j + (n/2)];

			b11[i][j] = b[i][j];
			b12[i][j] = b[i][j + (n/2)];
			b21[i][j] = b[i + (n/2)][j];
			b22[i][j] = b[i + (n/2)][j + (n/2)];
		}

		matrix_mul(a11, b11, temp1, n/2);
		matrix_mul(a12, b21, temp2, n/2);
        matrix_sum(temp1, temp2, c11, (n/2));

        matrix_mul(a11, b12, temp1, (n/2));
		matrix_mul(a12, b22, temp2, (n/2));
		matrix_sum(temp1, temp2, c12, (n/2));

		matrix_mul(a21, b11, temp1, (n/2));
		matrix_mul(a22, b21, temp2, (n/2));
		matrix_sum(temp1, temp2, c21, (n/2));

		matrix_mul(a21, b12, temp1, (n/2));
		matrix_mul(a22, b22, temp2, (n/2));
		matrix_sum(temp1, temp2, c22, (n/2));

		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++){
				c[i][j] = c11[i][j];
				c[i][j + (n / 2)] = c12[i][j];
				c[i + (n / 2)][j] = c21[i][j];
				c[i + (n / 2)][j + (n / 2)] = c22[i][j];
			}

	}
}

void show_result(vector< vector<int> >& result,  int n) // to display result
{
    cout << "Result matrix is \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            {cout << result[i][j] << " ";}
            cout << "\n";
    }
}

int main()
{
    int N;
    cout<<"Enter n: dimension of matrices n x n (n is a power of 2)\n";
    cin>> N;

    vector<vector<int> > res(N); // To store result
    for ( int i = 0 ; i < N ; i++ ){
        res[i].resize(N);

    }

    vector<vector<int> > mat1(N); // initialize matrix 1
    for ( int i = 0 ; i < N ; i++ ){
        mat1[i].resize(N);

    }

    vector<vector<int> > mat2(N); // initialize matrix 2
    for ( int i = 0 ; i < N ; i++ )
    {
        mat2[i].resize(N);

    }

    cout<<"Enter elements of first matrix \n";
    creat_matrix(mat1, N);

    cout<<"Enter elements of second matrix \n";
    creat_matrix(mat2, N);

    matrix_mul(mat1, mat2, res, N);
    show_result(res, N);

    return 0;
}
