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

void MagicSquare(int **matrix, int n) {//This magic square only makes sure that the sum of each row and each collumn is the same

	int dms = n * n;                   //But the sum of the two diagonals is not guarranteed. 
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
	CheckPerfection(matrix, n);
	//rotate it 8 times
}
void NormalMagicSquare(int **matrix, int n) {
	MagicSquare(matrix, n);
	//rotate it 10 times
}
void CheckPerfection(int **matrix, int n) {
	int sum = 0;
	int tempsum = 0;
	for (int a = 0; a < n; a++) {
		sum += matrix[a][0];
	}
	for (int b = 0; b < n; b++) {
		tempsum += matrix[0][b];
	}
	if (tempsum != sum) {
		cout << "Fuck off my work is perfect." << endl;
		return;
	}
	for (int b = 0; b < n; b++) {
		tempsum += matrix[b][b];
	}
	if (tempsum != sum) {
		cout << "Fuck off my work is perfect." << endl;
		return;
	}
	for (int b = 0; b < n; b++) {
		tempsum += matrix[n - b][n - b];
	}
	if (tempsum != sum) {
		cout << "Fuck off my work is perfect." << endl;
		return;
	}

	cout << "Told ya my work is definitely perfect." << endl;
	//FIXME: this function only checks the first column and the two diagonals.


}
/*
void PrintMagicSquare(int[15][15] &matrix, n) {

}*/