#include <iostream>
#include <vector>
#include <string>
using namespace std;

string amaranthus(int n, vector <int> lst)
{
    string s = "";
    int st = 0, nd = 0, rd = 0, max1 = 0, max2 = 0, max3 = 0;
        for (int i = 0; i < n; i++) {
            if (max1 < lst[i]) {
                max2 = max1;
                max1 = lst[i];
            }
            else if (max1 > lst[i] && max2 < lst[i]) {
                max2 = lst[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if ((max3 < lst[i]) && ( lst[i] < max2)) max3 = lst[i];
        }
        for (int i = 0; i < n; i++) {
            if (lst[i] == max1) st++;
            if (lst[i] == max2) nd++;
            if (lst[i] == max3) rd++;
        }
    s = s = "1st : " + to_string(st) + "; 2nd : " + to_string(nd) + "; 3rd : " + to_string(rd);
    return s;
}
int main()
{
    int n;
    cin >> n;
    vector <int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cout << amaranthus(n, s);
}
