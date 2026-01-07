class MinStack
{
public:
    priority_queue<int, vector<int>, greater<int>> q;
    list<int> l;
    MinStack()
    {
    }

    void push(int val)
    {
        l.push_back(val);
        q.push(val);
    }

    void pop()
    {
        queue<int> temp;
        while (q.top() != l.back())
        {
            temp.push(q.top());
            q.pop();
        }
        q.pop();
        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
        l.pop_back();
    }

    int top()
    {
        return l.back();
    }

    int getMin()
    {
        return q.top();
    }
};