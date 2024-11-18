#pragma once
#include <iostream>
using namespace std;

// также на параметры типов даны значения по умолчанию
template <typename T = int, int size = 2>
class matrix
{
	T** matr;
	int size;

public:

	// конструкторы
	matrix() : matrix(nullptr, 2) { }
	matrix(const T** obj) : matrix(obj, strlen(obj)) { }
	matrix(const T** obj, int size_P) : size{size_P}
	{
		matr = new T * [size];
		for (int i = 0; i < size; i++) { matr[i] = new T[size]; }
	}
	matrix(const matrix& obj) : size{ obj.size }
	{
		matr = new T * [size];
		for (int i = 0; i < size; i++) { matr[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matr[i][j] = obj.matr[i][j];
			}
		}
	}

	// при присоении матрице нового значения размер тоже меняется

	void set_matrix(T** obj) { for (int i = 0; i < size; i++) { delete[] matr[i]; }
		delete[] matr;
		size = sizeof(obj)/4;
		matr = new T * [size];
		for (int i = 0; i < size; i++) { matr[i] = new T[size]; }
		for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { matr[i][j] = obj[i][j]; } } }

	void set_size(int size_P) { size = size_P; }


	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matr[i][j] << '\t'; 
			} 
			cout << '\n';
		}
	}

	void fill_by_user()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin << matr[i][j];
			} 
		}
	}

	void fill_random()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matr[i][j] = rand() % 100;
			}
		}
	}

	T find_max()
	{
		T max = matr[0][0];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (matr[i][j] > max)
				{
					max = matr[i][j];
				}
			}
		}

		return max;
	}

	T find_min()
	{
		T min = matr[0][0];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (matr[i][j] < min)
				{
					min = matr[i][j];
				}
			}
		}

		return min;
	}

	// как я поняла вычитание и сложение выполняются просто путём вычитания из ячейки матрицы 1 под индексами и ж ячейки 2 матрицы под индексом и ж

	T** operator+(const matrix& obj)
	{
		// буфферная матрица которая будет содержать результат
		T** matr_buff = new T * [size];
		for (int i = 0; i < size; i++) { matr_buff[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				// сложение двух ячеек матриц под одинаковыми индексами
				matr_buff[i][j] = matr[i][j] + obj.matr[i][j];
			}
		}

		return matr_buff;
	}

	T** operator-(const matrix& obj)
	{
		// буфферная матрица которая будет содержать результат
		T** matr_buff = new T * [size];
		for (int i = 0; i < size; i++) { matr_buff[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				// вычитание двух ячеек матриц под одинаковыми индексами
				matr_buff[i][j] = matr[i][j] - obj.matr[i][j];
			}
		}

		return matr_buff;
	}

	T** operator*(const matrix& obj)
	{
		// буфферная матрица которая будет содержать результат
		T** matr_buff = new T * [size];
		for (int i = 0; i < size; i++) { matr_buff[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				// так как у нас идет не приравнивание а добавление к существующему значению 
				// с каждым обходом цикла, в самом начале мы должны присвоить текущей ячейке матрицы результата
				// нулевое значение, т.к. сейчас в ней находятся мусорные значения

				matr_buff[i][j] = 0;

				for (int k = 0; k < size; k++)
				{
					// тут цикл я комментировать не буду, потому что сама еле как понимаю как оно работает

					matr_buff[i][j] += matr[i][k] * obj.matr[k][j];
				}
			}
		}

		return matr_buff;
	}

	// так как из того, что я прочитала, я поняла что деление матриц невозможно или для него требуется
	// доп значения, я сделала перегрузку оператора деления самой примитивной

	T** operator/(const matrix& obj)
	{
		T** matr_buff = new T * [size];
		for (int i = 0; i < size; i++) { matr_buff[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matr_buff[i][j] = matr[i][j] / obj.matr[i][j];
			}
		}

		return matr_buff;
	}


	const T** get_matr() { return matr; }

	T** get_size() { return size; }

	~matrix()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matr[i];
		}

		delete[] matr;
	}

};

