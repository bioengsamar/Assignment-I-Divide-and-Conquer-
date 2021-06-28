#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void creat_matrix(int **mat , int n)
{
   for(int i=0; i<n; i++)
    {
       for(int j=0; j<n; j++)
           cin>>mat[i][j];
    }
}

void matrix_sum(int **a, int **b, int **c, int n){
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++){
		c[i][j] = a[i][j] + b[i][j];
	}
}

void matrix_sub(int **a, int **b, int **c, int n){
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++){
		c[i][j] = a[i][j] - b[i][j];
	}
}
void matrix_mul(int **a, int **b, int **c, int n){
	if (n == 1){
		c[0][0] = a[0][0] * b[0][0];
	}
	else{
		int **a11 = new int*[(n / 2)];
		int **a12 = new int*[(n / 2)];
		int **a21 = new int*[(n / 2)];
		int **a22 = new int*[(n / 2)];

		int **b11 = new int*[(n / 2)];
		int **b12 = new int*[(n / 2)];
		int **b21 = new int*[(n / 2)];
		int **b22 = new int*[(n / 2)];

		int **c11 = new int*[(n / 2)];
		int **c12 = new int*[(n / 2)];
		int **c21 = new int*[(n / 2)];
		int **c22 = new int*[(n / 2)];

		int **temp1 = new int*[(n / 2)];
		int **temp2 = new int*[(n / 2)];

		int **m1 = new int*[(n / 2)];
		int **m2 = new int*[(n / 2)];
		int **m3 = new int*[(n / 2)];
		int **m4 = new int*[(n / 2)];
		int **m5 = new int*[(n / 2)];
		int **m6 = new int*[(n / 2)];
		int **m7 = new int*[(n / 2)];

		for (int i = 0; i < (n / 2); i++){
			a11[i] = new int[(n / 2)];
			a12[i] = new int[(n / 2)];
			a21[i] = new int[(n / 2)];
			a22[i] = new int[(n / 2)];

			b11[i] = new int[(n / 2)];
			b12[i] = new int[(n / 2)];
			b21[i] = new int[(n / 2)];
			b22[i] = new int[(n / 2)];

			c11[i] = new int[(n / 2)];
			c12[i] = new int[(n / 2)];
			c21[i] = new int[(n / 2)];
			c22[i] = new int[(n / 2)];

			temp1[i] = new int[(n / 2)];
			temp2[i] = new int[(n / 2)];

			m1[i] = new int[n / 2];
			m2[i] = new int[n / 2];
			m3[i] = new int[n / 2];
			m4[i] = new int[n / 2];
			m5[i] = new int[n / 2];
			m6[i] = new int[n / 2];
			m7[i] = new int[n / 2];
		}

		for (int i = 0; i < (n / 2); i++)
		for (int j = 0; j < (n / 2); j++){
			a11[i][j] = a[i][j];
			a12[i][j] = a[i][j + (n / 2)];
			a21[i][j] = a[i + (n / 2)][j];
			a22[i][j] = a[i + (n / 2)][j + (n / 2)];

			b11[i][j] = b[i][j];
			b12[i][j] = b[i][j + (n / 2)];
			b21[i][j] = b[i + (n / 2)][j];
			b22[i][j] = b[i + (n / 2)][j + (n / 2)];
		}


		matrix_sum(a11, a22, temp1, (n / 2)); // a11 + a22
		matrix_sum(b11, b22, temp2, (n / 2)); // b11 + b22
		matrix_mul(temp1, temp2, m1, (n / 2)); //m1 = (a11 + a22) (b11 + b22)

		matrix_sum(a21, a22, temp1, (n / 2)); // a21 + a22
		matrix_mul(temp1, b11, m2, (n / 2)); //m2 = (a21 + a22) b11

		matrix_sub(b12, b22, temp1, (n / 2)); // b12 - b22
		matrix_mul(a11, temp1, m3, (n / 2)); //m3 = a11 (b12 - b22)

		matrix_sub(b21, b11, temp1, (n / 2)); // b21 - b11
		matrix_mul(a22, temp1, m4, (n / 2)); //m4 = a22 (b21 - b11)

		matrix_sum(a11, a12, temp1, (n / 2)); // a11 + a12
		matrix_mul(temp1, b22, m5, (n / 2)); //m5 = (a11 + a12) b22

		matrix_sub(a21, a11, temp1, (n / 2)); // a21 - a11
		matrix_sum(b11, b12, temp2, (n / 2)); // b11 + b12
		matrix_mul(temp1, temp2, m6, (n / 2)); //m6 = (a21 - a11) (b11 + b12)

		matrix_sub(a12, a22, temp1, (n / 2)); // a12 - a22
		matrix_sum(b21, b22, temp2, (n / 2)); // b21 + b22
		matrix_mul(temp1, temp2, m7, (n / 2)); //m7 = (a12 - a22) (b21 + b22)

		matrix_sum(m1, m4, temp1, n / 2); // m1 + m4
		matrix_sum(temp1, m7,temp2, n / 2); // m1 + m4 + m7
		matrix_sub(temp2, m5, c11, n / 2);// c11 = m1 + m4 - m5 + m7

		matrix_sum(m3, m5, c12, n / 2); // c12 = m3 + m5

		matrix_sum(m2, m4, c21, n / 2); // c21 = m2 + m4

		matrix_sum(m1, m3, temp1, n / 2); // m1 + m3
		matrix_sum(temp1, m6, temp2, n / 2); //m1 + m3 + m6
		matrix_sub(temp2, m2, c22, n / 2); // c22 = m1 - m2 + m3 + m6

		for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++){
			c[i][j] = c11[i][j];
			c[i][j + (n / 2)] = c12[i][j];
			c[i + (n / 2)][j] = c21[i][j];
			c[i + (n / 2)][j + (n / 2)] = c22[i][j];
		}

	}
}

void show_result(int **result,  int n) // to display result
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

    int** res = new int*[N]; // To store result
    for(int i=0; i<N; i++)
    {
        res[i] = new int[N];
    }

    int **mat1;  // initialize matrix 1
    mat1 = new int *[N];
    for(int i=0; i<N; i++)
    {
    mat1[i] = new int[N];
    }

    int **mat2;  // initialize matrix 2
    mat2 = new int *[N];
    for(int i=0; i<N; i++)
    {
        mat2[i] = new int[N];
    }

    cout<<"Enter elements of first matrix \n";
    creat_matrix(mat1, N);

    cout<<"Enter elements of second matrix \n";
    creat_matrix(mat2, N);

    matrix_mul(mat1, mat2, res, N);
    show_result(res, N);

    return 0;
}


