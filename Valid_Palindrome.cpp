/**
 *    author:  sazzad
 *    created: 10.01.2026 21:41:23
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pa pair<int, int>
#define pa2 pair<ll, ll>
#define pa3 pair<ll, int>
#define nl cout << '\n'
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string t = "";
        for (char c : s)
        {
            if (c >= 97 && c < 123 || (c >= 48 && c < 58))
                t += c;
        }
        string t2 = t;
        reverse(t.begin(), t.end());
        return t == t2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s = Solution();
    cout << s.isPalindrome("0P");
}