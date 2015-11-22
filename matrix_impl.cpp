#include "matrix.h"
//Print matrix
template <class T>
void Matrix<T>::output() {
	
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			std::cout << std::setw(16) << A[j * n + i] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//Construct a matrix whose i,i element is 1, other 0
template <class T>
Matrix<T>::Matrix(const int m, const int n) : m(m), n(n) {
	A = new T[m * n];
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			A[j * n + i] = i == j ? 1.0 : 0.0;
}

//Construct matrix according to input array
template <class T>
Matrix<T>::Matrix(const int m, const int n, const T temp[]) : m(m), n(n) {
	A = new T[m * n];
	for (int i = 0; i < m * n; i++) A[i] = temp[i];
}

//Destructor
template <class T>
Matrix<T>::~Matrix() {
	delete [] A;
}

//Set matrix according to input array
template <class T>
Matrix<T>& Matrix<T>::set(const T temp[]) {
	for (int i = 0; i < m * n; i++) A[i] = temp[i];
	return *this;
}

//Set 0 matrix
template <class T>
Matrix<T>& Matrix<T>::zero() {
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			A[j * n + i] = 0.0;
	return *this;
}

//Transpose matrix
template <class T>
Matrix<T> Matrix<T>::transpose() {
	Matrix<T> R(n, m);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			R.A[i * m + j] = A[j * n + i];
	return R;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& B) {
	Matrix<T> Temp(m, B.n);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < B.n; i++) {
			Temp.A[j * B.n + i] = 0.0;
			for (int k = 0; k < n; k++)
				Temp.A[j * B.n + i] += A[j * n + k] * B.A[k * B.n + i];
		}
	return Temp;
}


template <class T>
Matrix<T> Matrix<T>::operator*(const T s) {
	Matrix<T> Temp(m, n);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			Temp.A[j * n + i] = A[j * n + i] * s;
	return Temp;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& B) {
	Matrix<T> Temp(m, n);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			Temp.A[j * n + i] = A[j * n + i] + B.A[j * n + i];
	return Temp;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& B) {
	Matrix<T> Temp(m, n);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			Temp.A[j * n + i] = A[j * n + i] - B.A[j * n + i];
	return Temp;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& B) {
	if (m * n != B.m * B.n) {
		delete [] A;
		A = new T[B.m * B.n];
	}
	m = B.m;
	n = B.n;

	for (int i = 0; i < m * n; i++) A[i] = B.A[i];
	return *this;
}

template <class T>
void Matrix<T>::householderDecomposition(Matrix<T>& Q, Matrix<T>& R) {
	T mag, alpha;
	Matrix<T> u(m, 1), v(m, 1);
	Matrix<T> P(m, m), I(m, m);

	Q = Matrix(m, m);
	R = *this;

	for (int i = 0; i < n; i++) {
		u.zero(); v.zero();
		
		mag = 0.0;
		for (int j = i; j < m; j++) {
			u.A[j] = R.A[j * n + i];
			mag += u.A[j] * u.A[j];
		}
		mag = sqrt(mag);
		
		alpha = u.A[i] < 0 ? mag : -mag;

		mag = 0.0;
		for (int j = i; j < m; j++) {
			v.A[j] = j == i ? u.A[j] + alpha : u.A[j];
			mag += v.A[j] * v.A[j];
		}
		mag = sqrt(mag);

		if (mag < 0.0000000001) continue;

		for (int j = i; j < m; j++) v.A[j] /= mag;

		P = I - (v * v.transpose()) * 2.0;

		R = P * R;
		Q = Q * P;
	}
}

template <class T>
T Matrix<T>::determinant()   
{
 int i,j,sum = 0;
 Matrix<T> c(n-1,n-1);
 if(n==2)
  {                                        //BASE CONDITION
	sum = A[0]*A[1 * n +1] - A[0 * n +1] * A[1 * n +0];
	return sum;
  }
 for(int p=0;p<n;p++)
 {
  int h = 0,k = 0;
  for(i=1;i<n;i++)
  {
	for( j=0;j<n;j++)
	{
	 if(j==p)
	  continue;
	 c.A[h * (n-1) +k] = A[i * n +j];
	 k++;
	 if(k == n - 1)
	  {
		 h ++;
		 k = 0;
	  }

	}
  }

  sum = sum + A[0 * n + p]*pow(-1,p)*c.determinant();
 }
 return sum;
}

template <class T>
void Matrix<T>::lu(Matrix<T>& L, Matrix<T>& U)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                L.A[j * n + i] = 0;

            }

            else
            {
                L.A[j * n + i] = A[j * n + i];

                for (int k = 0; k < i; k++)
                {	
          
                    L.A[j * n + i] = L.A[j * n + i] - L.A[j * n + k] * U.A[k * n + i];

                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (j < i)
                U.A[i * n + j] = 0;
            else if (j == i)
                U.A[i * n + j] = 1;
            else
            {
                U.A[i * n + j] = A[i * n + j] / L.A[i * n + i];
                for (int k = 0; k < i; k++)
                {
                    U.A[i * n + j] = U.A[i * n + j] - ((L.A[i * n +k] * U.A[k * n + j]) / L.A[i * n + i]);
                }
            }
        }
    }
}



