#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct phoneBook {
    string name;
    string phone;
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    
    cin >> n;
    string a;
    phoneBook* phones = new phoneBook[n];
    for (int i = 0; i < n; i++) {
        cin >> phones[i].name;
        cin >> phones[i].phone;
    }
    do {
        string result = "Not found";
        cin >> a;

        for (int i = 0; i < n; i++) {
            if (a == phones[i].name) {
                result = a + '=' + phones[i].phone;
                break;
            }
        }
        cout << result<< endl;
    } while (a != " ");
    delete[] phones;
    return 0;
}
