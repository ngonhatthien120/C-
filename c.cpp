#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
// cẩn thận trường hợp có thăng với @ cuối cùng
using namespace std;

char so(string s) { 
    if (s == "00") return '0';
    else if (s == "01") return '1';
    else if (s == "10") return '2';
    else if (s == "11") return '3';
}
//Chuyen nhi phan sang thap phan
vector <string> Chuyen(const string input1[], const int N1)
{
    vector<string> res(N1);
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < input1[i].size(); j+=2) {
            string s;
            if (input1[i][j] != ' ') {
                s.push_back(input1[i][j]); s.push_back(input1[i][j + 1]);
                res[i].push_back(so(s));
            }
            else {
                j--;
                res[i].push_back(' ');
            }
        }
    }
    return res;
}
//tao ham truyen mot chuoi, tinh so cac so trung voi so ban dau
int demSo(string s) 
{
    int dem = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == s[0]) dem++;
    }
    while (dem > 7) dem -= 7;
    return dem;
}
// kiem tra quan doi nha tran co vua or tương khong
int kiemTra(string s)
{
    if (s[0] == 'V' && s[1] == 'U' && s[1] == 'A') return 1; //co vua
    else {
        for (int i = 2; i < s.size() - 1; i++) {
            if (s[i - 1] == 'T' && s[i] == 'H' && s[i + 1] == 'D') return -1; // co tuong
        }
    }
    return 0;
}
string giaiMa(char c, int so)
{
    string ans;
    switch (c) {
    case '0':
        if (so == 1) ans += 'E';
        else if (so == 2) ans += 'F';
        else if (so == 3) ans += 'G';
        else if (so == 4) ans += 'H';
        else if (so == 5) ans += 'I';
        else if (so == 6) ans += 'J';
        else if (so == 7) ans += 'K';
        break;
    case '1':
        if (so == 1) ans += 'L';
        else if (so == 2) ans += 'M';
        else if (so == 3) ans += 'N';
        else if (so == 4) ans += 'O';
        else if (so == 5) ans += 'P';
        else if (so == 6) ans += 'Q';
        else if (so == 7) ans += 'R';
        break;
    case '2':
        if (so == 1) ans += '#';
        else if (so == 2) ans += 'T';
        else if (so == 3) ans += 'U';
        else if (so == 4) ans += 'V';
        else if (so == 5) ans += 'W';
        else if (so == 6) ans += 'X';
        else if (so == 7) ans += 'Y';
        break;
    case '3':
        if (so == 1) ans += '@';
        else if (so == 2) ans += 'A';
        else if (so == 3) ans += 'S';
        else if (so == 4) ans += 'Z';
        else if (so == 5) ans += 'B';
        else if (so == 6) ans += 'C';
        else if (so == 7) ans += 'D';
        break;
    }   
    return ans;
}
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    vector <string> res = Chuyen(input1, N1); // Co truong hop no nhieu ki tu trong 1 chuoi vidu ATZ

    vector <string> ans(N1);

    for (int i = 0; i < res.size(); i++) {
        int dem = 0; int j = 0;
        for (; j < res[i].size(); j++) {
            if (res[i][j] != ' ') {
                dem++;
            }
            else {
                ans[i] += giaiMa(res[i][j - 1], dem);
                dem = 0;
            }
        }
        ans[i] += giaiMa(res[i][j - 1], dem);
        dem = 0;
    }
    
    return 0;
}
int main()
{
    string ID[1] = { "Hii" };
    const int NID = 0;
    const int N1 = 2;
    const string input1[] = { "10 1111 1010", "11 01 1010" };
    string res = readyForBattle(ID, NID, input1, N1);
    cout << res;
}

