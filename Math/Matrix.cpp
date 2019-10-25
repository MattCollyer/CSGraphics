#include "Matrix.h"

Matrix::Matrix(int y, int x){
	rows = y;
	columns = x;
	size = x * y;
	matrix = std::vector<std::vector<double>>(rows,  std::vector<double>(columns,0.0));
}

int Matrix::getRows() const{
	return this->rows;
}

int Matrix::getColumns() const{
	return this->columns;
}

int Matrix::getSize() const{
	return this->size;
}

double Matrix::getValue(int y, int x) const{
	return this->matrix[y][x];
}

void Matrix::setValue(int y, int x, double val){
	this->matrix[y][x] = val;
}

void Matrix::fromArray(double* arr){
	int x = 0;
	while (x < this->size){
		for (int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				this->matrix[i][j] = arr[x];
				x++;
			}
		}
	}
}

bool Matrix::operator==(const Matrix& other) const{
	if(this->rows != other.getRows() && this->columns != other.getColumns()){
		return false;
	}
	else{
		double epsilon = 0.00001;
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				if(abs(this->matrix[i][j] - other.getValue(i, j)) > epsilon){
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other) const{
	return !(*this == other);
}

Matrix Matrix::operator*(const Matrix& other) const{
	Matrix returnMatrix(this->rows, this->columns);
	if(this->size != 16 && other.getSize() != 16){
		std::runtime_error("Can't multiply these matrices together");
	}
	else{
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				returnMatrix.setValue(i, j, (this->matrix[i][0] * other.getValue(0, j)) + (this->matrix[i][1] * other.getValue(1, j)) + (this->matrix[i][2] * other.getValue(2, j)) + (this->matrix[i][3] * other.getValue(3, j)));
			}
		}
	}
	return returnMatrix;
}

Tuple Matrix::operator*(const Tuple& other) const{
	double tupleArr[4] = {other.getX(), other.getY(), other.getZ(), other.getW()};
	double returnArr[4] = {0,0,0,0};
	for(int i = 0; i < this->rows; i++){
		for(int j = 0; j < this->columns; j++){
			returnArr[i] += this->matrix[i][j] * tupleArr[j];
		}
	}
	Tuple returnTuple(returnArr[0], returnArr[1], returnArr[2], returnArr[3]);
	return returnTuple;
}

Matrix Matrix::identity(int dimmension){
	Matrix identity(dimmension, dimmension);
	for(int i = 0; i < dimmension; i++){
		identity.setValue(i, i, 1);
	}
	return identity;
}

double Matrix::determinant(){
	double determinant = 0;
	if (this->size == 4){
		determinant = this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
	}
	else{
		for(int j = 0; j < this->columns; j++){
			determinant += this->matrix[0][j] * this->cofactor(0, j);
		}
	}
	return determinant;
}

Matrix Matrix::submatrix(int row, int column){
	//input is zero based
	Matrix returnMatrix (this->rows - 1, this->columns - 1);
	int outsideCounter = 0;
	for(int i = 0; i < this->rows; i++){
		if(i != row){
			int insideCounter = 0;
			for(int j = 0; j < this->columns; j++){
				if(j != column){
					returnMatrix.setValue(outsideCounter, insideCounter, this->matrix[i][j]);
					insideCounter++;
				}
			}
			outsideCounter++;
		}
	}
	return returnMatrix;
}

double Matrix::minor(int row, int column){
	return this->submatrix(row, column).determinant();
}
double Matrix::cofactor(int row, int column){
	double minor = this->minor(row, column);
	if((row + column) % 2 == 0){
		return minor;
	}
	else{
		return -minor;
	}
}

bool Matrix::isInvertible(){
	return this->determinant();
}

Matrix Matrix::inverse(){
	Matrix returnMatrix(this->rows, this->columns);
	if(!isInvertible()){
		std::runtime_error("Matrix not invertible");
	}
	else{
		double determinant = this->determinant();
		for(int i = 0; i < this->rows; i++){
			for(int j = 0; j < this->columns; j++){
				double cofactor = this->cofactor(i, j);
				returnMatrix.setValue(j, i, cofactor / determinant);
			}
		}
	}
	return returnMatrix;
}
