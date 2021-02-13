#include <iostream>
#include <string>
using namespace std;

string telephoneNumber(string s)

{
	string rs = "NO";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '8' && s.size() - i >= 11) rs = "YES";
	}
	return rs;
}

int main()
{
	string s;
	cout << "Nhap so dien thoai: ";
	cin >> s;
	cout << telephoneNumber(s);
	return 0;
}
