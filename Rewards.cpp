#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

//bị sai một số lỗi(12/13)

long long maxReward(int n, std::vector<long long> k)
{
    int min = k[0];
    int dem = 0;
    for (int i = 0; i < k.size(); i++) {
        if (min > k[i]) min = k[i];
    }
    for (int i = min; i > 1; i--) {
        if (min % i == 0) {
            for (int j = 0; j < k.size(); j++) {
                if (k[j] % i == 0)  dem++;
            }
            if (dem == k.size()) return i;
        }
        dem = 0;
    }
    return min;
}


//cái này thì đúng hết

int gcd(int a, int b) {
    while (a * b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}
//giai thich code ở trên trang nguyenvanhieu.vn
long long maxReward(int n, vector<long long> k)
{
    sort(k.begin(), k.end()); // Phải khai báo thư viện algorithm
    int UCLN = gcd(k[0], k[1]);
    for (int i = 2; i < k.size(); i++) {
        if (UCLN == 1) break;
        UCLN = gcd(UCLN, k[i]);
    }
    return (UCLN == 1) ? k[0] : UCLN;
}

int main()
{
    int n;
    cin >> n;
    std::vector<long long> res(n);
    for (int i = 0; i < res.size(); i++) {
        cin >> res[i];
    }
    cout << maxReward(n,res) ;
    return 0;
}
