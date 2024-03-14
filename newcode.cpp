#include <iostream>
#include <vector>

//Assignment 14th March 2024

template<typename T>
class Matrix {
private: 
	int rows;
	int cols;
	std::vector<std::vector<T>> mat;

public:

	Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
		mat.resize(numRows, std::vector<T>(numCols, 0));
	}

	void set_value(int row, int col) {                             //The value of Matrix is set by this function
		int value;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cin >> value;
				mat[i][j] = value;
			}
		}
	}

	int get_value(int row, int col) const {
		if (row >= 0 && row < rows && col >= 0 && col < cols)
			return mat[row][col];

		return 0;
	}

	Matrix operator +(const Matrix& other) const {                              //Operator overloading is done to make the program more readable and clear
		if (rows != other.rows || cols != other.cols) {

			std::cerr << "This is invalid because the dimesions of the 2 matrix should be same";
			return *this;
		}
		Matrix result(rows, cols);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.mat[i][j] = mat[i][j] + other.mat[i][j];
			}
		}
		return result;
	}

	Matrix operator -(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols) {

			std::cerr << "This is invalid because the dimesions of the 2 matrix should be same";
			return *this;
		}
		Matrix result(rows, cols);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.mat[i][j] = mat[i][j] - other.mat[i][j];
			}
		}
		return result;
	}

	Matrix operator *(Matrix& other) const {

		if (cols != other.rows) {
			std::cerr << "This is invalid because the column of first matrix should be equal to the rows of the other matrix";
			return *this;
		}

		Matrix computed(rows, other.cols);

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < other.cols; j++) {

				for (int k = 0; k < cols; k++) {

					computed.mat[i][j] += mat[i][k] * other.mat[k][j];
				}
			}
		}

		return computed;

	}

	Matrix operator *(int number) const {                             // This is for scaler multiplication of matrix

		Matrix matrice(rows, cols);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols;j++) {
				matrice.mat[i][j] = mat[i][j] * number;
			}
		}
		return matrice;
	}

	Matrix transpose(const Matrix& matrix) const {                     //This is a function made to Transpose and then print a matrix 
		Matrix transposed_mat(matrix.cols, matrix.rows);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				transposed_mat.mat[j][i] = matrix.mat[i][j];
			}
		}
		transposed_mat.print_it();
		return transposed_mat;
	}

	void print_it() {                                                  //The matrix is printed by this function call

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cout << this->mat[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

};

int main() {
	int r1, c1, r2, c2;                       //r is for rows and c is for columns

	std::cout << "Enter the value of rows of Matrix 1-->" << std::endl;
	std::cin >> r1;

	std::cout << "Enter the value of columns of Matrix 1-->" << std::endl;
	std::cin >> c1;

	Matrix<int> matrix_1(r1, c1);
	std::cout << "Enter the elements of Matrix 1:" << std::endl;
	matrix_1.set_value(r1, c1);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "Matrix 1:" << std::endl;

	matrix_1.print_it();

	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Enter the value of rows of Matrix 2-->" << std::endl;
	std::cin >> r2;

	std::cout << "Enter the value of columns of Matrix 2-->" << std::endl;
	std::cin >> c2;

	Matrix<int> matrix_2(r2, c2);
	std::cout << "Enter the elements of Matrix 2:" << std::endl;
	matrix_2.set_value(r2, c2);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "Matrix 2:" << std::endl;

	matrix_2.print_it();

	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;


	std::cout << "Addition of the Matrices:" << std::endl;
	(matrix_1 + matrix_2).print_it();
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "Subtraction of the Matrices:" << std::endl;
	(matrix_1 - matrix_2).print_it();
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Multiplication of the Matrices:" << std::endl;
	(matrix_1 * matrix_2).print_it();
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "Transpose of the Matrix 1:" << std::endl;
	matrix_1.transpose(matrix_1);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Transpose of the Matrix 2:" << std::endl;
	matrix_2.transpose(matrix_2);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	getchar();
	getchar();

	return 0;
}
