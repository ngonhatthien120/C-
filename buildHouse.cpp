#include <iostream>
#include <vector>
using namespace std;

//bản tối ưu hơn
vector<long long> buildHouse(long long S)
{
    vector<long long> res;
    int max, maxx;
    for (int i = sqrt(S); i > 0; i--) {
        if (S % i == 0) {
            max = i;
            break;
        }
    }
    maxx = S / max;
    res.push_back(maxx);
    res.push_back(max);
    return res;
}
//bản phèn hơn, chậm hơn
vector<long long> buildHouse_(long long S)
{
    vector<long long> res;
    long long max, maxx;
    for (int i = 1; i * i <= S; i++) {
        if (S % i == 0) max = i;
    }
    maxx = S / max;
    res.push_back(maxx); 
    res.push_back(max);
    return res;
}
int main()
{
    long long s;
    cin >> s;   
    cout << buildHouse(s)[0] << endl;
    cout << buildHouse(s)[1];
}
