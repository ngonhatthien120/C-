int quickPow(int a, int n) {
     if (n == 1) return a;
     if (n == 0) return 1;
     if (n % 2 == 0) {
         return ((quickPow(a, n / 2)%1337) * (quickPow(a, n / 2)%1337))%1337;
     }
     else {
         return ((quickPow(a, n / 2)%1337) * (quickPow(a, n / 2 + 1)%1337))%1337;
     }
 }
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 0 || a == 1) return a;
        int res = 0;
        int n = 0;
        if (b.size() == 1) {
            return quickPow(a, b[0]);
        }
        else {
            int lastVal = b.back();
            b.pop_back();
            return ((long)quickPow(superPow(a, b), 10) * (long)quickPow(a, lastVal)) % 1337;
        }
    }
};
