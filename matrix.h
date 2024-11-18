#pragma once
#include <iostream>
using namespace std;

template <typename T, int>
class matrix
{
	T** matr;
	int size;

public:

	void set_matrix(const T** obj) { for (int i = 0; i < size; i++) { delete[] matr[i]; }
		delete[] matr;
		size = strlen(matr);
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

	T** operator+(const matrix<T, int>** obj)
	{
		T** matr_buff;

		for (int i = 0; i < size; i++) { matr_buff[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matr_buff[i][j] = matr[i][j] + obj.matr[i][j];
			}
		}

		return matr_buff;
	}

	T** operator-(const matrix<T, int>** obj)
	{
		T** matr_buff;

		for (int i = 0; i < size; i++) { matr_buff[i] = new T[size]; }

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matr_buff[i][j] = matr[i][j] - obj.matr[i][j];
			}
		}

		return matr_buff;
	}


	const T** get_matr() { return matr; }

	T** get_size() { return size; }

};

