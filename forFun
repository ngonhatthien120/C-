#include <iostream>
#include <cmath>
#include <string>
using namespace std;


float cong(float value1, float value2)
{
	return value1 + value2;
}
float tru(float value1, float value2)
{
	return value1 - value2;
}
float nhan(float value1, float value2)
{
	return value1 * value2;
}
float chia(float value1, float value2)
{
	return value1 / value2;
}
float luythua(float value1, int value2)
{
	float result = 1;
	for (int i = 1; i <= value2; i++)
	{
		result *= value1;
	}
	return result;
}
int chuoi(string pheptinh)
{
	if (pheptinh == "cong") return 0;
	else if (pheptinh == "tru") return 1;
	else if (pheptinh == "nhan") return 2;
	else if (pheptinh == "chia") return 3;
	else if (pheptinh == "luythua") return 4;
}
void tinhtoan()
{
	string n; int x; float ketqua;
	cout << "Chon phep tinh: "; cin >> n;
	x = chuoi(n);
	switch (x)
	{
	case 0:
	{
		float a, b;
		cout << "Nhap gia tri 1: "; cin >> a;
		cout << "Nhap gia tri 2: "; cin >> b;
		ketqua = cong(a, b);
		break;
	}
	case 1:
	{
		float a, b;
		cout << "Nhap gia tri 1: "; cin >> a;
		cout << "Nhap gia tri 2: "; cin >> b;
		ketqua = tru(a, b);
		break;
	}
	case 2:
	{
		float a, b;
		cout << "Nhap gia tri 1: "; cin >> a;
		cout << "Nhap gia tri 2: "; cin >> b;
		ketqua = nhan(a, b);
		break;
	}
	case 3:
	{
		float a, b;
		cout << "Nhap gia tri 1: "; cin >> a;
		cout << "Nhap gia tri 2: "; cin >> b;
		ketqua = chia(a, b);
		break;
	}
	case 4:
	{
		float a, b;
		cout << "Nhap gia tri 1: "; cin >> a;
		cout << "Nhap gia tri 2: "; cin >> b;
		ketqua = luythua(a, b);
		break;
	}

	default:
		cout << "Wrong!!";
		break;

	}
	cout << "Ketqua: " << ketqua<<endl;
	system("pause");
	system("cls");
}
int main()
{
	int choice;
	do
	{
		cout << "----------------------------Program Funny----------------------------" << endl;
		cout << "(1)  : Tinh toan !" << endl;
		cout << "else : Exit !" << endl;
		cout << "---------------------------------------------------------------------"<< endl ;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			tinhtoan(); break;
		}
		default :
			cout << "Thoat chuong trinh!!"<<endl;
			break;

		}
	} while (choice == 1);
	return 0;
}
