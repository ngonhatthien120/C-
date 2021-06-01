#include <iostream>
using namespace std;


void mul(int* res, int x, int& size) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int k = res[i] * x + carry;
        res[i] = k % 10;
        carry = k / 10;
    }
    while (carry) {
        res[size] = carry % 10;
        carry /= 10;
        size++;
    }
}
void extraLongFactorials(int n) {
    //TODO
    int res[200] = {};
    res[0] = 1; 
    int size = 1;
    for (int i = 2; i <= n; i++) {
        mul(res, i, size);
    }
    for (int i = size-1; i >= 0; i--) {
        cout << res[i];
    }
}

int main()
{
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
