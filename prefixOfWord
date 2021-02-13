#include <iostream>
#include <string>
using namespace std;

int prefixOfWord(string s, string p)
{
	int dem = 1;
	for (int i = 0; i < s.size(); i++) {
	if (s[i] == ' ') dem++;
	if (s[i] == p[0]) {
		for (int j = 0; j < p.size(); j++) {
			if(s[i + j] != p[j]) break;
			if (j == p.size() - 1) return dem;
		}
	  }
	}
    return -1;
}

int main()
{
	string s, p;
	int result;
	getline(cin, s);
	getline(cin, p);
	result = prefixOfWord(s, p);
	cout << result;

}
