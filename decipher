#include <iostream>
using namespace std;
string decipher(string cipher)
{
    string res;
    int n = 0;
    for (char ch : cipher) {
        n = n * 10 + (ch - '0');
        if (('a' <= n) && (n <= 'z')) {
            res += char(n);
            n = 0;
        }          
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << decipher(s);
}
