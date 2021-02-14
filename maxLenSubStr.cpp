#include <iostream>
using namespace std;

int maxLenSubStr(string str)
{
    int dem = 0;
    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j]) if (j - i + 1 > dem) dem = j - i + 1;
        }
    }
    return dem;
}
int main()
{
    string s;
    cin >> s;
    cout << maxLenSubStr(s);
}
