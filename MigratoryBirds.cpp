#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

//Phương pháp tốm time
int migratoryBirds(std::vector<int> list_of_birds)
{
    int dem = 0, res = 0;
    for (int i = 0; i < list_of_birds.size(); i++) {
        for (int j = 0; j < list_of_birds.size(); j++) {
            if (list_of_birds[i] == list_of_birds[j]) dem++;
        }
        if (dem > res) res = dem;
        dem = 0;
    }
    for (int i = 0; i < list_of_birds.size(); i++) {
        for (int j = 0; j < list_of_birds.size(); j++) {
            if (list_of_birds[i] == list_of_birds[j]) dem++;
        }
        if (dem == res) return list_of_birds[i];
        dem = 0;
    }
}

//phương pháp ngắn gọn
int migratoryBirds_(vector<int> arr) {

    int dem = 0, max = 0, res = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        ++dem;
        if (i == n - 1 || arr[i] != arr[i + 1]) {
            if (dem > max) {
                max = dem;
                res = arr[i];
            }
            dem = 0;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    std::vector<int> res(n);
    for (int i = 0; i < res.size(); i++) {
        cin >> res[i];
    }
    cout << migratoryBirds(res) ;
    return 0;
}
