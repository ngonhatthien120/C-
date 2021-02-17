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
int reversePairSum(std::vector<int> a)
{
    int sum = 0;
    for (int i : a) {
        if (i > 9 && i % 10 != 0) {
          if (i != dao(i)) {
             for (int j : a) {
                 if (dao(i) == j) {
                     sum += i + j;
                     break;
                 }
             } 
          }
        }
    }
    return sum/2;
}
int main()
{
    int s  ;
    cin >> s;
    vector<int> a(s);
    for (int i = 0; i < s; i++) {
        cin >> a[i] ;
    }
    cout << reversePairSum(a) ;
    return 0;
}
