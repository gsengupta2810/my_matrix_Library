#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <iostream>
#include <bits/stdc++.h>

namespace matrix
{
	template <class data_type>
	class Matrix
	{
		private:
			int m;
			int n;
			std::vector<std::vector<data_type> > mat;

			//private functions
			std::vector<std::vector<data_type> > multpl(std::vector<std::vector<data_type> >); //to return the product of this->mat and some other matrix's mat
		public:
			//constructors
			Matrix(int,int);
			Matrix();
			Matrix(const Matrix &obj);
			
			//dimensional operations
			int rows() const;
			int cols() const;
			void set_dimension(int rows,int cols,data_type value=0);

			//matrix operations
			data_type at(int i,int j) const;
			int set(int i,int j, data_type value);
			void fill(data_type);
			void show() const;

			//operator overloads
			Matrix<data_type> operator+(const Matrix<data_type> &B);
			Matrix<data_type> operator-(const Matrix<data_type> &B);
			Matrix<data_type> operator*(const Matrix<data_type> &B);
			bool operator==(const Matrix<data_type> &B);

			// power, determenant and inverse operations
			Matrix<data_type> transpose();
			Matrix<data_type> multiply(Matrix<data_type>);
			Matrix<data_type> pow(int a=1);
			Matrix<data_type> pow(float a=1.0);
			Matrix<data_type> inverse();
			Matrix<data_type> sparse_multiply(Matrix<data_type> a, Matrix<data_type> b);
			float det();

			// bool functions 
			bool isSquare();
			bool isSparse();
			bool isZero();
			bool isEmpty();
			bool isUpperTriangular();
			bool isLowerTriangular();

	};
}

#endif