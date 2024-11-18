#pragma once
#include <iostream>
using namespace std;

template <typename T>
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

	const T** get_matr() { return matr; }
	int get_size() { return size; }

};

