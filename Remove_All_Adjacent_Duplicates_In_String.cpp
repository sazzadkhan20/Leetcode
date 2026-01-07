class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            bool flag = false;
            while (!st.empty() && c == st.top())
            {
                flag = true;
                st.pop();
            }
            if (!flag)
                st.push(c);
        }
        string unique = "";
        while (!st.empty())
        {
            unique += st.top();
            st.pop();
        }
        reverse(unique.begin(), unique.end());
        return unique;
    }
};