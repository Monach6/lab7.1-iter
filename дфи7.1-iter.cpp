#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** X, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** X, const int rowCount, const int colCount);
void Change(int** X, const int row1, const int row2, const int colCount);
void Calc(int** X, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int rowCount = 7;
	int colCount = 6;

	int** X = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		X[i] = new int[colCount];

	Create(X, rowCount, colCount, Low, High);
	Print(X, rowCount, colCount);
	Sort(X, rowCount, colCount);
	Print(X, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(X, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(X, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] X[i];
	delete[] X;
	return 0;
}
void Create(int** X, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			X[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** X, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << X[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** X, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((X[i1][0] > X[i1 + 1][0])
				||
				(X[i1][0] == X[i1 + 1][0] &&
					X[i1][1] > X[i1 + 1][1])
				||
				(X[i1][0] == X[i1 + 1][0] &&
					X[i1][1] == X[i1 + 1][1] &&
					X[i1][3] < X[i1 + 1][3]))
				Change(X, i1, i1 + 1, colCount);
}
void Change(int** X, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = X[row1][j];
		X[row1][j] = X[row2][j];
		X[row2][j] = tmp;
	}
}
void Calc(int** X, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (X[i][j] % 2 != 0 || !(X[i][j] < 0))
			{
				S += X[i][j];
				k++;
				X[i][j] = 0;
			}
}