#ifndef Matrix_H
#define Matrix_H
#include <stdio.h>
#include <vector>
#include <fstream>
#include <math.h>
#include "Tuple.h"
class Matrix{
	private:
		int rows;
		int columns;
		int size;
		std::vector <std::vector<double>> matrix;
	public:
		Matrix(int y, int x);
		int getRows() const;
		int getColumns() const;
		int getSize() const;
		double getValue(int y, int x) const;
		void setValue(int y, int x, double val);
		void fromArray(double* arr);
		bool operator==(const Matrix& other) const;
		bool operator!=(const Matrix& other) const;
		Matrix operator*(const Matrix& other) const;
		Tuple operator*(const Tuple& other) const;
		static Matrix identity(int dimmension);
		double determinant();
		Matrix submatrix(int row, int column);
		double minor(int row, int column);
		double cofactor(int row, int column);
		bool isInvertible();
		Matrix inverse();
		Matrix transpose();
		static Matrix translation(double x, double y, double z);
		static Matrix scaling(double x, double y, double z);

};

//For catch2
std::ostream& operator << ( std::ostream& os, Matrix const& obj );


#endif
