#include "my_matrix.h"

using namespace std;

namespace matrix
{
//#######################################################################################
//	        						Private Functions
// ######################################################################################

	template <class data_type>
	std::vector<std::vector<data_type> > Matrix<data_type>::multpl(std::vector<std::vector<data_type> > b)
	{
		std::vector<std::vector<data_type> > temp;
		for (int i = 0; i < m; ++i)
		{
			std::vector<data_type> v(n,0);
			temp.push_back(v);
		}
		if(n==b[0].size() && b.empty()!=true)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					data_type sum=0;
					for (int k = 0; k < n; ++k)
					{
						sum+=mat[i][k]*b[k][j];
					}
					temp[i][j]=sum;
				}
			}
		}
		else 
		{
			cout<<"the dimensions of mats for multiplication is not valid"<<endl;
		}
		return temp;
	}

//#######################################################################################
//	        						Constructors
// ######################################################################################
	template <class data_type>
	Matrix<data_type>::Matrix(int i,int j)
	{	
		m=i;
		n=j;
		data_type temp=0;
		for (int i = 0; i <m ; ++i)
		{
			std::vector<data_type> v(n,0);
			mat.push_back(v);
		}	
	}//constructor 1

	template <class data_type>
	Matrix<data_type>::Matrix()
	{
		m=0;
		n=0;
	}

	template <class data_type>
	Matrix<data_type>::Matrix(const Matrix &obj)
	{
		m=obj.m;
		n=obj.n;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				mat[i][j]=(obj.mat)[i][j];
			}
		}
	}//copy constructor

//#######################################################################################
//  								Basic Operations
// ######################################################################################
	template <class data_type>
	int Matrix<data_type>::rows() const
	{
		return m;
	}//rows

	template <class data_type>
	int Matrix<data_type>::cols() const
	{
		return n;
	}//cols

	template <class data_type>
	void Matrix<data_type>::set_dimension(int rows,int cols, data_type value) 
	{
		m=rows;
		n=cols;
		if(m!=0 && n!=0)
		{
			for (int i = 0; i <m ; ++i)
			{
				std::vector<data_type> v(n,value);
				mat.push_back(v);
			}	
		}
	}//set rows

	template <class data_type>
	data_type Matrix<data_type>::at(int i,int j) const
	{
		return mat[i][j];
	}//at

	template <class data_type>
	void Matrix<data_type>::show() const
	{
		try
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		catch(...)
		{
			cout<<"error ocurring in showing matrix"<<endl;
		}
	}//show

	template <class data_type>
	int Matrix<data_type>::set(int i,int j,data_type value)
	{
		if(!mat.empty())
		{	
			try
			{
				mat[i][j]=value;
				return 1;
			}
			catch(...)
			{
				cout<<"error in setting value"<<endl;
				return -1;
			}
		}
		else if(m!=0 && n!=0)
		{
			cout<<"entering"<<endl;
			for (int i = 0; i <m ; ++i)
			{
				std::vector<data_type> v(n,0);
				mat.push_back(v);
			}	
			try
			{
				mat[i][j]=value;
				return 1;
			}
			catch(...)
			{
				cout<<"error in setting value"<<endl;
				return -1;
			}
		}
		else
		{
			cout<<"The rows and column values are not set"<<endl;
			return -1;
		}
	}//set

	template <class data_type>
	void Matrix<data_type>::fill(data_type value) 
	{
		if(this->isZero()==true && this->isEmpty()!=true)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					mat[i][j]=value;
				}
			}
		}
		else if(this->isEmpty()==true)
		{
			cout<<"The dimensions of matrix not set"<<endl;
		}
		else if(this->isZero()!=true)
		{
			cout<<"Overwriting the data already present in the matrix"<<endl;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					mat[i][j]=value;
				}
			}
		}
		else 
		{
			cout<<"something wrong in filling"<<endl;
		}
	}

//#######################################################################################
//  						Operator overloading
// ######################################################################################
	template <class data_type>
	Matrix<data_type> Matrix<data_type>::operator+(const Matrix<data_type> &B)
	{
		Matrix<data_type> temp(B.rows(),B.cols());
		if(B.rows()==m && B.cols()==n)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					try{
						temp.set(i,j,B.at(i,j)+mat[i][j]);
					}
					catch(...)
					{
						cout<<"error in adding"<<endl;
					}
				}
			}
		}
		else
		{
			cout<<"Dimensions of matrix do not match for addition"<<endl;
		}		
		return temp;	
	}// + overloading

	template <class data_type>
	Matrix<data_type> Matrix<data_type>::operator-(const Matrix<data_type> &B)
	{
		Matrix<data_type> temp(B.rows(),B.cols());
		if(B.rows()==m && B.cols()==n)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					try{
						temp.set(i,j,B.at(i,j)-mat[i][j]);
					}
					catch(...)
					{
						cout<<"error in adding"<<endl;
					}
				}
			}
		}
		else
		{
			cout<<"Dimensions of matrix do not match for subtraction"<<endl;
		}		
		return temp;	
	}// - overloading

	template <class data_type>
	Matrix<data_type> Matrix<data_type>::operator*(const Matrix<data_type> &B)
	{
		Matrix<data_type> temp(m,B.cols());
		if(B.rows()==n)
		{
#define NAIVE_METHOD_FOR_MULTIPLICATION
#ifdef 	NAIVE_METHOD_FOR_MULTIPLICATION
			
			// This is O(n^3)
			for (int i = 0; i < m; ++i)
			{
				for (int l = 0; l <n ; ++l)
				{
					int j=0,k=0;
					data_type sum=0;
					while(j<n && k<B.rows())
					{
						sum+=mat[i][j]*B.at(k,l);
						j++;
						k++;
					}
					temp.set(i,l,sum);	
				}
			}
#else
			//Strassen's algorithm for matrix multiplication
			// This is almost O(2.8) but does not work well due to large constants which make it impractical for use 
#endif
		}
		else
		{
			cout<<"Dimensions of matrix do not match for multiplication"<<endl;
		}		
		return temp;	
	}// * overloading

	template <class data_type>
	bool Matrix<data_type>::operator==(const Matrix<data_type> &B)
	{
		if(m==B.rows() && n==B.cols())
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if(mat[i][j]!=B.mat[i][j])
						return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}// == overloading 

//#######################################################################################
//  							Advanced Operations
// ######################################################################################
	template <class data_type>
	Matrix<data_type> Matrix<data_type>::transpose()
	{
		Matrix<data_type> trans(n,m);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				trans.set(j,i,mat[i][j]);
			}
		}
		return trans;
	}//transpose 

	template <class data_type>
	Matrix<data_type> Matrix<data_type>::pow(int a)
	{
		Matrix<data_type> powered(m,n);
		std::vector<std::vector<data_type> > temp;
		if(m==n)
		{	
			if(a==0)
			{
				for (int i = 0; i < m; ++i)
				{
					std::vector<data_type> v(n,0);
					v[i]=1;
					temp.push_back(v);
				}
				for (int i = 0; i < m; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						powered.set(i,j,temp[i][j]);
					}
				}
			}
			else
			{
				for (int i = 0; i < m; ++i)
				{
					temp.push_back(mat[i]);
				}
				for(int l=0;l<a-1;l++)
				{
					temp=multpl(temp);
				}
				for (int i = 0; i < m; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						powered.set(i,j,temp[i][j]);
					}
				}
			}
		}
		else
		{
			cout<<"Not a square matrix, can not raise power"<<endl;
		}
		return powered;
	}// pow int

	template <class data_type>
	Matrix<data_type> Matrix<data_type>::pow(float a)
	{
		Matrix<data_type> powered(m,n);

		if(m==n)
		{
						
		}
		else
		{
			cout<<"Not a square matrix, can not raise power"<<endl;
		}
		return powered;
	}// pow float

//#######################################################################################
//  							Boolean functions
// ######################################################################################
	template <class data_type>
	bool Matrix<data_type>::isZero()
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(mat[i][j]!=0)
					return false;
			}
		}
		return true;
	} //isZero

	template <class data_type>
	bool Matrix<data_type>::isEmpty()
	{
		if(mat.empty()) return true;
		return false;
	} //isEmpty

	template <class data_type>
	bool Matrix<data_type>::isSquare()
	{
		if(m==n && m!=0) return true;
		return false;
	} //isSquare

	template <class data_type>
	bool Matrix<data_type>::isUpperTriangular()
	{
		if(isEmpty()!=true)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if(j<i && mat[i][j]!=0)
						return false;
				}
			}
			return true;
		}
		else return false;
	} //isUpperTriangular

	template <class data_type>
	bool Matrix<data_type>::isLowerTriangular()
	{
		if(isEmpty()!=true)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if(j>i && mat[i][j]!=0)
						return false;
				}
			}
			return true;
		}
		else return false;
	} //isLowerTriangular

	template <class data_type>
	bool Matrix<data_type>::isSparse()
	{
		if(isEmpty())
			return false;
		if(isZero())
			return true;
		int count=0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(mat[i][j]!=0)
					count++;
			}
		}
		if((count/(m*n))<0.3)
			return true;
	}
}