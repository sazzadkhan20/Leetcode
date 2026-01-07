
class Solution
{
public:
    bool stack_operation(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                    return false;
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (st.empty())
                    return false;
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (st.empty())
                    return false;
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
    bool isValid(string s)
    {
        return stack_operation(s);
    }
};