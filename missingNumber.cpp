#include <iostream>
#include <vector>
using namespace std;

int main()
{   
int k, j=1;
int n;
int result = 0, dem = 0;
cout << "Nhap so phan tu trong mang: "<<endl;
cin >> n;
cout << "Nhap so nguyen duong thu k khong xuat hien trong mang: <<endl";
cin >> k;
cin.ignore();
vector<int> arr(n);
for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
}
while (dem != k)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == j) {
            j++;
            break;
        }
        if (i == arr.size() - 1) {
            result = j;
            dem++;
            j++;
        }
    }
    
        
    
}
cout << result;
return 0;
}
