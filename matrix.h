#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

template <class T>
class Matrix {
  private:
  protected:
  public:
	T *A;
	int m, n;

	Matrix(const int m, const int n);
	Matrix(const int m, const int n, const T temp[]);

	~Matrix();

	Matrix<T>& set(const T temp[]);
	Matrix<T>& zero();
	Matrix<T> transpose();
	Matrix<T>  operator*(const Matrix<T>& B);
	Matrix<T>  operator*(const T s);
	Matrix<T>  operator+(const Matrix<T>& B);
	Matrix<T>  operator-(const Matrix<T>& B);
	Matrix<T>& operator=(const Matrix<T>& B);
	void householderDecomposition(Matrix<T>& Q, Matrix<T>& R);
	void lu(Matrix<T>& L, Matrix<T>& U);
	T determinant();
	void output();
};


#endif

