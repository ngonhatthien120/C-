#include <iostream>
#include <vector>
using namespace std;

int maxWater(std::vector<int> arr)
{
    int n = arr.size();
    int maximum = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] < arr[j])
        {
            maximum = max(maximum, (j - i) * arr[i]);
            i++;
        }
        else if (arr[j] < arr[i])
        {
            maximum = max(maximum, (j - i) * arr[j]);
            j--;
        }
        else
        {
            maximum = max(maximum, (j - i) * arr[i]);
            i++;
            j--;
        }
    }

    return maximum;
}
int main()
{
    int n;
    cin >> n;
    vector <int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cout << maxWater(s);
}
