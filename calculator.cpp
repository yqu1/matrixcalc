#include "matrix.h"


using namespace std;

int main()
{
	char option;

	cout<<"Choose calculation: "<<endl;
	cout<<"a) LU decomposition"<<endl;
	cout<<"b) QR decomposition"<<endl;
	cout<<"c) determinant"<<endl;
	cout<<"d) quit"<<endl;

	cin>>option;
	option=tolower(option);

	while(option!='d')
	{

		if(option=='a') { LUdecomp(); }

		else if(option=='b') { QRdecomp(); }

		else if(option=='c') { determinant(); }

		else { cout<<"invalid input"; }

		cout<<"Choose calculation: "<<endl;
		cout<<"a) LU decomposition"<<endl;
		cout<<"b) QR decomposition"<<endl;
		cout<<"c) determinant"<<endl;
		cout<<"d) quit"<<endl;

		cin>>option;
		option=tolower(option);

	}

	cout<<"thank you for using matrix calculator!"<<endl;

	return 0;

}