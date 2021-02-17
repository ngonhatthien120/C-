#include <iostream>
#include<vector>
using namespace std;


int dao(int n)
{
    int so = 0;
    while (n > 0) {
        so = so * 10 + (n % 10);
        n /= 10;
    }
    return so;
}

int goodReverseNumbers(int n)
{
    int dem = 0;
    for (int i = 12; i <= n; i++) {
        if (i % 10 != 0) {
            int so = (i + dao(i));
            while (so > 0) {
                int k = so % 10;
                if (k % 2 == 0) break;
                else so /= 10;
            }
            if (so == 0) dem++;
        }
    }
    return dem;
}

int main()
{
    int s  ;
    cin >> s;
    cout << goodReverseNumbers(s) ;
    return 0;
}
