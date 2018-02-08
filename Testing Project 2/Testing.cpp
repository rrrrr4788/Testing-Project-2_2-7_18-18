#include<iostream>
#include<array>
using namespace std;
void MagicSquare(int **matrix, int n);
void TbtMagicSquare(int **matrix, int n);
void NormalMagicSquare(int **matrix, int n);
void CheckPerfection(int **matrix, int n);
//void PrintMagicSquare (int &matrix, n);
int main() {
	int n = 0;
	cout << "Enter an odd number that is larger than 2 and smaller than 15:";

	

	do {
		cin >> n;
		// exception handling for when user enters even number
		if ((n < 3) || (n % 2 == 0) || (n > 15)) {
			cout << "Be serious." << endl;
		}
	} while ((n < 3) || (n % 2 == 0) || (n > 15));
	int** matrix;
	matrix = new int*[n];
	//allocate memory for each of of 2D array
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

	if (n != 3) { NormalMagicSquare(matrix, n); }
	else { TbtMagicSquare(matrix, n); }

	system("pause");
	return 0;
}

void MagicSquare(int **matrix, int n) {
	int dms = n * n;
	int i = n / 2;
	int	j = n / 2;     // Matrix construction starts in the middle

	for (int k = 1; k <= dms; ++k) {
		matrix[i][j] = k;

		i++;
		j--;//The numbers are filled in in the derection of bottomleft

		if (k % n == 0) { //Immediate adjustments
			i -= 2;
			++j;
			if (i<0) {
				i += n;
			}
		}
		else {
			if (i == n)
				i -= n;
			if (j < 0)
				j += n;
		}

	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			cout << matrix[a][b] << " ";
		}
		cout << endl;

	}
}

void TbtMagicSquare(int **matrix, int n){
	MagicSquare(matrix, n);
	//rotate it 8 times
}
void NormalMagicSquare(int **matrix, int n) {
	MagicSquare(matrix, n);
	//rotate it 10 times
}
void CheckPerfection(int **matrix, int n) {

}
/*
void PrintMagicSquare(int[15][15] &matrix, n) {

}*/