#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n, ad = 0, br = 0, go = 0,i, j, max;
    string x;
    cin >> n >> x;
    for (i = 0; i < n; i +=3 )
    {
        if (i < n) if (x[i] == 'A') ad += 1;
        if (i + 1 < n) if (x[i+1] == 'B') ad += 1;
        if (i + 2 < n) if (x[i+2] == 'C') ad += 1;
    }
    for (i = 0; i < n; i++)
    {
        j = 4 * i;
        if (j + 1 < n) if (x[j + 1] == 'A') br += 1;
        if (2*i < n) if (x[2*i] == 'B') br += 1;
        if (j + 3 < n) if (x[j + 3] == 'C') br += 1;
    }
    for (i = 0; i < n ; i++)
    {
        j = 6 * i;
        if (j + 2 < n) if (x[j + 2] == 'A')  go += 1;
        if (j + 4 < n) if (x[j + 4] == 'B')  go += 1;
        if (j < n) if (x[j] == 'C')  go += 1;
        if (j + 3 < n) if (x[j + 3] == 'A') go += 1;
        if (j + 5 < n) if (x[j + 5] == 'B') go += 1;
        if (j + 1 < n) if (x[j + 1] == 'C') go += 1;

    }
    max = ad;
    if (max < br) max = br;
    if (max < go) max = go;
    cout << max << endl;
    if (ad == max) cout << "Adrian" << endl;
    if (br == max) cout << "Bruno" << endl;
    if (go == max) cout << "Goran" << endl;
    return 0;
}
