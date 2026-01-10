/**
 *    author:  sazzad
 *    created: 10.01.2026 18:09:24
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

void simple_op(stack<string> &st, string &folderName)
{
    if (folderName.length() > 0 && folderName != ".")
    {
        if (folderName == ".." && !st.empty())
            st.pop();
        else if (folderName != "..")
            st.push(folderName);
    }
    folderName = "";
}

void simplify_path(stack<string> &st, string path)
{
    string folderName = "";
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] != '/')
            folderName += path[i];
        else
            simple_op(st, folderName);
    }
    simple_op(st, folderName);
}

void reverse_stack(stack<string> &st)
{
    if (st.empty())
        return;
    string s = st.top();
    st.pop();
    reverse_stack(st);
    stack<string> cp;
    while (!st.empty())
    {
        cp.push(st.top());
        st.pop();
    }
    st.push(s);
    while (!cp.empty())
    {
        st.push(cp.top());
        cp.pop();
    }
}

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string s = "";
        simplify_path(st, path);
        if (st.empty())
            return "/";
        reverse_stack(st);
        while (!st.empty())
        {
            s += "/" + st.top();
            st.pop();
        }
        return s;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s = Solution();
    cout << s.simplifyPath("/.../a/../b/c/../d/./") << '\n';
}