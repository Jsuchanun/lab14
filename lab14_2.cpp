#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double A[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

void findLocalMax(const double matrix[][N], bool result[][N]) {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = false;
        }
    }
    
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            double current = matrix[i][j];
            if (current >= matrix[i - 1][j] && 
                current >= matrix[i + 1][j] && 
                current >= matrix[i][j - 1] && 
                current >= matrix[i][j + 1]) { 
                result[i][j] = true;
            }
        }
    }
}

void showMatrix(const bool A[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << endl; 
    }
}

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 