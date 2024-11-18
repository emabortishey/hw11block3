#include "matrix.h"

int main()
{
	int** matr = new int* [2];
	for (int i = 0; i < 2; i++) { matr[i] = new int[2]; }
	matr[0][0] = 1;
	matr[0][1] = 2;
	matr[1][0] = 3;
	matr[1][1] = 4;

	int** matr2 = new int* [2];
	for (int i = 0; i < 2; i++) { matr2[i] = new int[2]; }
	matr2[0][0] = 5;
	matr2[0][1] = 6;
	matr2[1][0] = 7;
	matr2[1][1] = 8;

	matrix<int, 2> obj1{};
	matrix<int, 2> obj2{};

	obj1.set_matrix(matr);
	obj2.set_matrix(matr2);

	obj1 * obj2;

	int** result = new int* [2];
	for (int i = 0; i < 2; i++) { result[i] = new int[2]; }
	result = obj1 * obj2;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << result[i][j] << '\t';
		}
		cout << '\n';
	}

	return 0;
}