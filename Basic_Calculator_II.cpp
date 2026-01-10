/**
 *    author:  sazzad
 *    created: 10.01.2026 00:04:02
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

void calc_mul_div(deque<string> &dq, string s, char sign)
{
    dq.pop_back();
    int num1 = stoi(dq.back());
    dq.pop_back();
    int num2 = stoi(s);
    if (sign == '*')
        dq.push_back(to_string(num1 * num2));
    else
        dq.push_back(to_string(num1 / num2));
}

void calc_add_sub(deque<string> &dq, int num1)
{
    string sign = dq.front();
    dq.pop_front();
    int num2 = stoi(dq.front());
    dq.pop_front();
    if (sign == "+")
        dq.push_front(to_string(num1 + num2));
    else
        dq.push_front(to_string(num1 - num2));
}

class Solution
{
public:
    int calculate(string s)
    {
        deque<string> dq;
        int n = s.length(), i = 0;
        string temp = "";
        while (i < n)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (!dq.empty() && dq.back() == "*")
                    calc_mul_div(dq, temp, '*');
                else if (!dq.empty() && dq.back() == "/")
                    calc_mul_div(dq, temp, '/');
                else
                    dq.push_back(temp);
                dq.push_back(string(1, s[i]));
                temp = "";
            }
            else
            {
                if (s[i] != ' ')
                    temp += s[i];
            }
            i++;
        }
        if (!dq.empty() && dq.back() == "*")
            calc_mul_div(dq, temp, '*');
        else if (!dq.empty() && dq.back() == "/")
            calc_mul_div(dq, temp, '/');
        else
            dq.push_back(temp);
        while (!dq.empty() && dq.size() > 1)
        {
            int num1 = stoi(dq.front());
            dq.pop_front();
            calc_add_sub(dq, num1);
        }
        return stoi(dq.front());
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s = Solution();
    cout << s.calculate("2*3+4") << '\n';
}