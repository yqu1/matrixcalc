#include "matrix.h"


using namespace std;

void qrDecomp();
void luDecomp();
void determinant();

int main()
{
	char option;

	cout << "Choose calculation: " << endl;
	cout << "a) LU decomposition" << endl;
	cout << "b) QR decomposition" << endl;
	cout << "c) determinant" << endl;
	cout << "d) quit" << endl;

	cin>>option;
	option = tolower(option);

	while(option!='d')
	{

		if(option == 'a')  luDecomp(); 

		else if(option == 'b')  qrDecomp(); 

		else if(option == 'c')  determinant(); 

		else { cout << "invalid input"; }

		cout << "Choose calculation: " << endl;
		cout << "a) LU decomposition" << endl;
		cout << "b) QR decomposition" << endl;
		cout << "c) determinant" << endl;
		cout << "d) quit" << endl;

		cin>>option;
		option = tolower(option);

	}

	cout << "thank you for using matrix calculator!" << endl;

	return 0;

}

void qrDecomp()
{
    int m,n;

    cout << "enter matrix rows: ";
    cin>>m;
    cout << "enter matrix columns: ";
    cin>>n;

    double temp[m*n];

    for (int i = 0; i < m * n; i++)
    {
        cout << "enter element: " << endl;
        cin>>temp[i];
    }


    Matrix<double> A__(m,n,temp);
    Matrix<double> Q__(1,1), R__(1,1);
    A__.householderDecomposition(Q__, R__);

    cout << "matrix you entered is: " << endl;
    A__.output();
    cout << "Q matrix: " << endl;
    Q__.output();
    cout << "R matrix: " << endl;
    R__.output();
    cout << "Q*R: " << endl;
    (Q__*R__).output();


}

void luDecomp()
{

    int n = 0, i = 0, j = 0;
    cout  <<  "Enter size of Square matrix : ";
    cin >> n;
    double temp[n*n], l[n*n], u[n*n];

    for (i = 0; i < n * n; i++)
    {
        cout  <<  "Enter element: " << endl;
        cin >> temp[i];
    }

    Matrix<double> A__(n,n,temp);
    Matrix<double> L__(n,n), U__(n,n);
    L__.zero(); U__.zero();

    cout << "matrix you entered is: " << endl;
    A__.output();

    if (A__.determinant() != 0)
    {
        cout << "determinant is: " << A__.determinant() << endl;
        A__.lu(L__, U__);
        cout  <<  "\nL Decomposition\n\n";
        L__.output();
        cout  <<  "\nU Decomposition\n\n";
        U__.output();
        cout << "L*U: " << endl;
        (L__*U__).output();
    }

    else {cout << "matrix is singular" << endl;}
}

void determinant()
{
    int n = 0, i = 0, j = 0;
    cout  <<  "Enter size of Square matrix : ";
    cin >> n;
    double temp[n*n], l[n*n], u[n*n];

    for (i = 0; i < n*n; i++)
    {
        cout << "Enter element: " << endl;
        cin >> temp[i];
    }

    Matrix<double> A__(n,n,temp);

    cout << "matrix you entered is: " << endl;
    A__.output();

    cout << "determinant is: " << A__.determinant() << endl;

}
