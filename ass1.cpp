//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

//chuyen bit sang so
char so(string s) {
    if (s == "00") return '0';
    else if (s == "01") return '1';
    else if (s == "10") return '2';
    else if (s == "11") return '3';
    else return '\0';
}
//Chuyen nhi phan sang thap phan
vector <string> Chuyen(const string input1[], const int N1)
{
    vector<string> res(N1);
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < input1[i].size(); j += 2) {
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
    if (s[0] == 'V' && s[1] == 'U' && s[2] == 'A') return 1; //co vua
    else {
        for (int i = 2; i < s.size() - 1; i++) {
            if (s[i - 1] == 'T' && s[i] == 'H' && s[i + 1] == 'D') return -1; // co tuong
        }
    }
    return 0;
}
string taoChuoi(char c, int so)
{
    so = so % 7 ;
    string ans;
    switch (c) {
    case '0':
        if (so == 1) ans += 'E';
        else if (so == 2) ans += 'F';
        else if (so == 3) ans += 'G';
        else if (so == 4) ans += 'H';
        else if (so == 5) ans += 'I';
        else if (so == 6) ans += 'J';
        else if (so == 0) ans += 'K';
        break;
    case '1':
        if (so == 1) ans += 'L';
        else if (so == 2) ans += 'M';
        else if (so == 3) ans += 'N';
        else if (so == 4) ans += 'O';
        else if (so == 5) ans += 'P';
        else if (so == 6) ans += 'Q';
        else if (so == 0) ans += 'R';
        break;
    case '2':
        if (so == 1) ans += '#';
        else if (so == 2) ans += 'T';
        else if (so == 3) ans += 'U';
        else if (so == 4) ans += 'V';
        else if (so == 5) ans += 'W';
        else if (so == 6) ans += 'X';
        else if (so == 0) ans += 'Y';
        break;
    case '3':
        if (so == 1) ans += '@';
        else if (so == 2) ans += 'A';
        else if (so == 3) ans += 'S';
        else if (so == 4) ans += 'Z';
        else if (so == 5) ans += 'B';
        else if (so == 6) ans += 'C';
        else if (so == 0) ans += 'D';
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
void giaiMa(string& str)
{
    string hashAt;
    for (int i = 0; i < str.size(); i++) {
        string tach;
        if ((str[0] == '#' || str[0] == '@') && str.size() == 1) str = "";
        else {
            while (str[str.size() - 1] == '#' || str[str.size() - 1] == '@') str.erase(str.size() - 1, 1);
            if (str[i] == '#' || str[i] == '@') {
                tach += str[i];
                for (int j = i + 1; j < str.size(); j++) { // if the character != # and @ tao chuoi moi
                    if (str[j] != '#' && str[j] != '@') tach += str[j];
                    else {
                        i = j-1 ;
                        break;
                    }
                    i = str.size();
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
            else hashAt += str[i];
        }
    }
    str = hashAt ;
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
// Xu ly B tu [0..M-1]
void xuLyChuoi(string B, int M, int xuLy[])
{
    // Do dai cua chuoi tien to = hau to dai nhat truoc do
    int len = 0;
    xuLy[0] = 0;
    int i = 1;
    while (i < M) {
        if (B[i] == B[len]) {
            len++;
            xuLy[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = xuLy[len - 1];
            }
            else
            {
                xuLy[i] = 0;
                i++;
            }
        }
    }
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
    int dau = 0;
    if (s[0] == '-') {
        s.erase(0, 1);
        dau = 1;
    }
    while (s != "") {
        n = s[0] - '0' + n * 10;
        s.erase(0, 1);
    }
    return dau ? -n : n;
}
//dich chuoi
void shiftArray(string& arr, int B) {
    //TODO
    int n = arr.size();
    if (B < 0) {
        for (int i = 0; i < abs(B); i++) {
            char x = arr[0];
            for (int i = 0; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = x;
        }
    }
    else if (B > 0) {
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
    int x = abs(N - 2 * i);
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
    int x = 0, y = 0;
    for (int i = 0; i < input.size(); i++) {
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
vector<vector<long long>> resultVector(vector<vector<long long>> A, vector<vector<int>> B, int N7) {
    vector<vector<long long>> res(N7, vector<long long>(N7));
    for (int i = 0; i < N7; i++) {
        for (int j = 0; j < N7; j++) {
            for (int x = 0; x < N7; x++)
                res[i][j] += A[i][x] * B[x][j];
        }
    }
    return res;
}
//dem V trong chuoi
int demV(string s) {
    int dem = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'V') dem++;
    }
    return dem;
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
    for (int i = 0; i < NID; i++) {
        //Co vua
        if (kiemTra(ID[i]) == 1) {
            for (int i = 0; i < N1; i++) {
                string chan, le;
                for (int j = 0; j < ans[i].size(); j++) {
                    if (j % 2 == 0) le += ans[i][j];
                    else chan += ans[i][j];
                }
                chan = dao(chan);
                le = dao(le);
                int index = 0;
                for (int j = 0; j < ans[i].size(); j++) {
                    if (index % 2 == 0) {
                        if (le[index / 2] > ans[i][j]) ans[i][j] = le[index / 2];
                    }
                    else {
                        if (chan[index / 2] > ans[i][j]) ans[i][j] = chan[index / 2];
                    }
                    index++;
                }
            }
        }
        //Co tuong
        else if (kiemTra(ID[i]) == -1) {
            for (int i = 0; i < N1; i++) {
                int cout = 0;
                for (int j = 0; j < ans[i].size(); j++) {
                    if ((j + cout) % 3 == 0) {
                        ans[i].erase(j , 1);
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
    int M = B.size();
    int N = A.size();
    // xuLy[] de tim chuoi dai nhat tien to = hau to
    int* xuLy = new int[M];
    xuLyChuoi(B, M, xuLy);

    int i = 0; // bien chay cua A
    int j = 0; // bien chay cua B
    while (i < N) {
        if (B[j] == A[i]) {
            j++;
            i++;
        }
        if (j == M) {
            j = xuLy[j - 1];
            dem++;
        }
        else if (i < N && B[j] != A[i]) {
            if (j != 0)
                j = xuLy[j - 1];
            else
                i = i + 1;
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
    shiftArray(input[2], B);
    for (int i = 0; i < input[2].size(); i++) {
        input[2][i] = change(input[2][i], N, i);
    }
    int x = 0, y = 0;
    for (int i = 0; i < input[2].size(); i++) {
        if (input[2][i] == 'U') y++;
        else if (input[2][i] == 'D') y--;
        else if (input[2][i] == 'R') x++;
        else if (input[2][i] == 'L') x--;
    }
    string res = "";
    string X,Y;
    if (x < 0) {
        X = '-'; X += abs(x) + '0';
    }

    else X = x + '0';
    if (y < 0) {
        Y = '-'; Y += (abs(y) + '0');
    }
    else Y = y + '0';
    res += '('; res += X; res += ','; res += Y; res += ')';
    return res;
}
string decodeVfunction(const string A, const string B)
{
    int res = demV(A) * demV(B);
    if (res == 0) return "0";
    string result = "V(0)";
    for (int i = 1; i < res; i++) {
        result.push_back(')');
        result.insert(0, "V(");
    }
    return result;
}
//sua lai cai return
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
        int x = Maxx(kiTu, 26) - j;
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
            if (input6[i][j] == '2') { // khi no bang 2 thi khong danh duoc
                danThuong[i] = -1;
                break;
            }
        }
    }
    int max = Maxx(danThuong, 10);
    if (max != -1) {
        for (int i = 0; i <= 9; i++) {
            if (danThuong[i] == max) {
                res += i + '0';
            }
        }
    }
        if (res != "") return res[res.size() - 1] - '0';
        return -1;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    vector<int> Lay;
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
    vector<vector<long long>> A(N7, vector<long long>(N7));
    for (int k = 0; k < N7; k++) {
        A[k][k] = 1;
    }
    for (int x = 0; x < k; x++) {
        vector<vector<int>> B = stringToMatrix(input7Matrix[x], N7);
        A = resultVector(A, B, N7);
    }
    int res = A[i - 1][j - 1] % V;
    return res < 0 ? V + res : res;
}

#endif /* MONGOL_H */
