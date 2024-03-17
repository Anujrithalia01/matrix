#include<vector>
#pragma once

class Matrice
{
private:
	int rows;
	int cols;
	std::vector<std::vector<int>>mat;

public:

	Matrice(int numRow, int numCol);

	void set_value();

	void print_it();

	Matrice operator+(const Matrice& other) const;
	Matrice operator-(const Matrice& other) const;
	Matrice operator*(const Matrice& other) const;
	Matrice operator *(int number) const;
	Matrice transpose(const Matrice& matrix) const;
	Matrice rotate(const Matrice& matrix) const;
};

