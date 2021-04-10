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
string taoChuoi(char c, int so)
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
//them ki tu vao ( # )
char Them(char C)
{
    if (C == 'Z') return 'A';
    else return C + 1;
}
//tao chuoi dao voi chuoi ban dau ( @ )
string dao(string input)
{
    string res;
    for (unsigned int i = 0; i < input.size(); i++) {
        res += input[input.size() - i - 1];
    }
    return res;
}
//xu li vu @ va #
//chua xu ly vy @ va # nam trong 1 chuoi vd #abc@lt
//Nguyen Trong Nghia
void giaiMa(string &str)
{
    string hashAt;
    for (int i = 0; i < str.size(); i++) {
        string tach;
        while (str[str.size() - 1] == '#' || str[str.size() - 1] == '@') str.erase(str.size() - 1, 1);
        if (str[i] == '#' || str[i] == '@') {
            tach += str[i];
            for (int j = i + 1; j < str.size(); j++) { // if the character != # and @ tao chuoi moi
                if (str[j] != '#' && str[j] != '@') tach += str[j];
                else {
                    i = j - 1;
                    break;
                }
            }
            if (tach[0] == '#') {
                tach.push_back(Them(tach[tach.size() - 1]));
                hashAt += tach;
            }
            if (tach[0] == '@') {
                string a = dao(tach.substr(1));
                tach.replace(1, a.size(), a);
                hashAt += tach;
            }
        }
    }
    str = hashAt;
}
//sap xep
string sortS(string s)
{
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] > s[j]) swap(s[i], s[j]);
        }
    }
    return s;
}
bool check(string text, string pattern, int i) {
    if (text.size() - i < pattern.size()) return false;
    for (int j = i; j < (int)text.size(); j++) {
        if (j - i < (int)pattern.size()) {
            if (text[j] != pattern[j - i]) return false;
        }
    }
    return true;
}
//Chuyen string thanh int
int StringInt(string s) {
    int n = 0;
    while (s != "") {
        n = s[0] - '0' + n * 10;
        s.erase(0, 1);
    }
    return n;
}
//dich chuoi
void shiftArray(string &arr, int B) {
    //TODO
    int n = arr.size();
    if (B < 0) {
        for (int i = 0; i < B; i++) {
            char x = arr[0];
            for (int i = 0; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = x;
        }
    }
    else if(B > 0) {
        for (int i = 0; i < B; i++) {
            char x = arr[n - 1];
            for (int i = n - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = x;
        }
    }
}
//thay doi ki tu trong findRoute
char change(char C, int N, int i)
{
    int x = abs(N - 2 * i) ;
    string s = "UDLR";
    size_t pos = s.find(C);
    return s[(pos + x) % 4];
}
//tim so lon nhat
int Maxx(int* arr, int size) {
    if (size == 1) return arr[0];
    else return arr[size - 1] > Maxx(arr, size - 1) ? arr[size - 1] : Maxx(arr, size - 1);
}
// chuyen tu chuoi sang ma tran
vector<vector<int>> stringToMatrix(string input, int N7) {
    vector<vector<int>> Matrix(N7, vector<int>(N7));
    string s = "";
    for (int i = 0; i < input.size(); i++) {
        int x = 0, y = 0;
        if (input[i] != ' ') s += input[i];
        else {
            if (y == N7) {
                x++;
                y = 0;
            }
            Matrix[x][y] = StringInt(s);
            s = ""; y++;
        }
    }
    return Matrix;
}
//ket qua phep nhan (chu nhat ta test thu xem^^)
vector<vector<int>> resultVector(vector<vector<int>> A, vector<vector<int>> B, int N7) {
    vector<vector<int>> res(N7, vector<int>(N7));
    for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
            res[i][j] = A[i][j] * B[j][i];
        }
    }
    return res;
}
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    vector <string> res = Chuyen(input1, N1); 
    //tao chuoi
    vector <string> ans(N1);
    for (int i = 0; i < res.size(); i++) {
        int dem = 0; int j = 0;
        for (; j < res[i].size(); j++) {
            if (res[i][j] != ' ') {
                dem++;
            }
            else {
                ans[i] += taoChuoi(res[i][j - 1], dem);
                dem = 0;
            }
        }
        ans[i] += taoChuoi(res[i][j - 1], dem);
        dem = 0;
    }
    for (int i = 0; i < ans.size(); i++) {
        giaiMa(ans[i]);
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            if (ans[i][j] == '@' || ans[i][j] == '#') {
                ans[i].erase(j, 1);
                j--;
            }
        }
    }
    // coi lai cau hoi cua Tran Quang Thang
    for (int i = 0; i < NID; i++) {
        //Co vua
        if (kiemTra(ID[i]) == 1) {
            for (int i = 0; i < N1; i++) {
                string chan, le;
                for (int j = 0; j < ans[i].size(); j++) {
                    if (i % 2 == 0) chan += ans[i][j];
                    else le += ans[i][j];
                }
                chan = dao(chan); 
                le = dao(le); 
                for (int j = 0; j < ans[i].size(); j++) {
                    if (i % 2 == 0) {
                        if (chan[i / 2] > ans[i][j]) ans[i][j] = chan[i / 2];
                    }
                    else {
                        if (le[i / 2] > ans[i][j]) le += ans[i / 2];
                    }
                }
            }
        }
        //Co tuong
        else if (kiemTra(ID[i]) == -1) {
            for (int i = 0; i < N1; i++) {
                int cout = 0;
                for (int j = 0; j < ans[i].size(); j++) {
                    if (i % 3 == 0) {
                        ans[i].erase(j + cout, 1);
                        cout++;
                    }
                }
                ans[i] = sortS(ans[i]);
            }
        }
    }
    string result;
    for (int i = 0; i < N1; i++) {
        if (i != N1 - 1) result += ans[i] + ' ';
        else result += ans[i];
    }
    return result;
}

int decode(const string A, const string B)
{
    int dem = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        if (A[i] == B[0]) {
            if (check(A, B, i)) {
                dem++;
            }
        }
    }
    return dem;
}
string findRoute(const string input3)
{
    vector<string> input;
    string s;
    for (int i = 0; i < input3.size(); i++) {
        if (input3[i] != ' ') s += input3[i];
        else {
            input.push_back(s);
            s = "";
        }
    }
    input.push_back(s);
    //Chuyen ma su kien
    int N = StringInt(input[0]);
    //Chuyen mot so nguyen
    int B = StringInt(input[1]);
    //Dich chuoi
    shiftArray(input[2],B);
    for (int i = 0; i < input[2].size(); i++) {
        input[2][i] = change(input[2][i], N, i);
    }
    int x = 0,y = 0;
    for (int i = 0; i < input[2].size(); i++) {
        if (input[2][i] == 'U') y++;
        else if (input[2][i] == 'D') y--;
        else if (input[2][i] == 'R') x++;
        else if (input[2][i] == 'L') x--;
    }
    string res ="";
    res += '('; res += (x + '0'); res += ','; res += (y + '0'); res += ')';
    return res;
}
// chua lam lun
string decodeVfunction(const string A, const string B)
{
    return "You can remove this return";
}
// sua lai return la xong
string findBetrayals(const string input5[], const int N5)
{
    int kiTu[26] = {};
    string res;
    for (int i = 0; i < N5; i++) {
        for (int j = 0; j < input5[i].size(); j++) {
            kiTu[input5[i][j] - 65] += 6 - j;
        }
    }
    int count = 0;
    for (int j = 0;; j++) {
        int x = Maxx(kiTu, 26)-j;
        for (int i = 0; i <= 25; i++) {
            if (kiTu[i] == x && count < 3) {
                res += i + 'A';
                count++;
            }
            if (count == 3) return res;
        }
    }
    return "You can remove this return";
}
int attack(const string input6[])
{
    string res;
    int danThuong[10] = {};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < input6[i].size(); j++) {
            if (input6[i][j] == '0') danThuong[i]++;
        }
    }
    int count = 0;
    for (int j = 0;; j++) {
        int max = Maxx(danThuong, 10);
        for (int i = 0; i <= 9; i++) {
            if (danThuong[i] == max && count < 3) {
                res += i + '0';
                count++;
            }
            if (count == 3) break;
        }
        if (count == 3) break;
    }
    for (int i = 0; i < res.size(); i++) {
        int k = res[i] - '0';
        int viTri = input6[k].find('2');
        if (viTri != string::npos) {
            res.erase(i, 1);
            i--;
        }
    }
    if (res != "") return res[res.size()-1] - '0';
    return -1;
}
//Coi lai cai cua Ha Tan Khanh Nam
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{ 
    //vector<vector<int>> Matrix (N7, vector<int>(N7));
    //vector<vector<vector<int>>> Matrix (k, vector<vector<int>>(N7, vector<int>(N7)));

    vector<int> Lay(4);
    string s = "";
    for (int i = 0; i < input7Str.size(); i++) {
        if (input7Str[i] != ' ') s += input7Str[i];
        else {
            Lay.push_back(StringInt(s));
            s = "";
        }
    }
    Lay.push_back(StringInt(s)); s = "";
    int N7 = Lay[0], V = Lay[1], i = Lay[2], j = Lay[3];
    for (int x = 0; x < k; x++) {

    }
    return -1;
}
int main()
{
    /*string ID[1] = { "Hii" };
    const int NID = 0;
    const int N1 = 3;
    const string input1[] = { "10 1111 1010", "11 01 1010" ,"11 01 1010 11 01 101010"};
    string res = readyForBattle(ID, NID, input1, N1);
    cout << res;
    string s = "#ABC#CDE#";
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == '@' || s[j] == '#') {
            s.erase(j, 1);
            j--;
        }
    }
    cout << s;*/
    cout << findRoute("3 0 UDL");
    string input6[] = { "0 0 1 0 0 0 0 0 0 0",
                       "1 1 0 0 0 0 0 0 0 0",
                       "1 0 1 1 1 0 0 0 0 0",
                       "0 0 0 2 0 0 0 0 0 0",
                       "1 0 0 0 0 0 0 0 0 0",
                       "1 1 0 0 0 0 0 0 0 0",
                       "1 1 0 0 0 0 0 0 0 0",
                       "1 1 0 0 0 0 0 0 0 0",
                       "1 1 0 0 0 0 0 0 0 0",
                       "1 1 0 0 0 0 0 0 0 0" };

    std:: cout << attack(input6);
}
