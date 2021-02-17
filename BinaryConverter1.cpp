#include <iostream>

using namespace std;
//Bị quá time hai key cuối
string textToBinary(string text)
{
    string res;
    string ans;
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (text[i] & 1) res.insert(0, "1");
            else res.insert(0, "0");
            text[i] = text[i] >> 1;
        }
            ans += res + ' ';
            res = "";        
    }
    ans.pop_back();
    return ans;
}
//Dùng for each(vẫn bị quá thời gian)
string textToBinary_(string text)
{
    string res;
    string ans;
    for (char i : text) {
        for (int j = 0; j < 8; j++) {
            if (i & 1) res.insert(0, "1");
            else res.insert(0, "0");
            i = i >> 1;
        }
            ans += res + ' ';
            res = "";        
    }
    ans.pop_back();
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << textToBinary(s) ;
    cout << ".";
    return 0;
}
