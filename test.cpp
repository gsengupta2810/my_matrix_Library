#include "my_matrix.cpp"

using namespace matrix;

int main()
{
	Matrix<float> a(3,3);
	Matrix<int> b(3,3);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			a.set(i,j,(2*i+1+0.12)*(3*j+1));
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(i>j) b.set(i,j,0);
			else b.set(i,j,(2*i+1)*(j+1)*2);
		}
	}
a.show();
cout<<"--------------------"<<endl;
b.show();
Matrix<float> c=a.pow(2);
c.show();
}