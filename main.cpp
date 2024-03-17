#include<iostream>
#include<vector>
#include<cmath>
#include"matrice.h"

int main() {

	int r1, c1, r2, c2;                       //r is for rows and c is for columns

	std::cout << "Enter the value of rows of Matrix 1-->" << std::endl;
	std::cin >> r1;

	std::cout << "Enter the value of columns of Matrix 1-->" << std::endl;
	std::cin >> c1;

	Matrice matrix_1(r1, c1);
	std::cout << "Enter the elements of Matrix 1:" << std::endl;
	matrix_1.set_value();
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	matrix_1.print_it();

	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Enter the value of rows of Matrix 2-->" << std::endl;
	std::cin >> r2;

	std::cout << "Enter the value of columns of Matrix 2-->" << std::endl;
	std::cin >> c2;

	Matrice matrix_2(r2, c2);
	std::cout << "Enter the elements of Matrix 2:" << std::endl;
	matrix_2.set_value();
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

	Matrice transposed_matrix1(r1, c1);
	transposed_matrix1 = matrix_1.transpose(matrix_1);
	transposed_matrix1.print_it();

	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Transpose of the Matrix 2:" << std::endl;

	Matrice transposed_matrix(r2, c2);
	transposed_matrix = matrix_2.transpose(matrix_2);
	transposed_matrix.print_it();

	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "Rotation of the Matrix 2:" << std::endl;
	matrix_2.rotate(matrix_2);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;


	getchar();
	getchar();

	return 0;
}