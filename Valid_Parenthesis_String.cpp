class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<pair<char, int>> bracketStack;
        stack<pair<char, int>> starStack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                bracketStack.push({s[i], i});
            else if (s[i] == ')')
            {
                if (!bracketStack.empty() && bracketStack.top().first == '(')
                    bracketStack.pop();
                else if (!starStack.empty() && starStack.top().first == '*')
                    starStack.pop();
                else
                    return false;
            }
            else
                starStack.push({s[i], i});
        }
        while (!bracketStack.empty() && !starStack.empty())
        {
            if (bracketStack.top().second < starStack.top().second)
            {
                bracketStack.pop();
                starStack.pop();
            }
            else
                return false;
        }
        if (!bracketStack.empty() && starStack.empty())
            return false;
        return true;
    }
};