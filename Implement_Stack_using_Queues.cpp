class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        queue<int> q2;
        int x;
        if (q1.size() != 0)
        {
            x = q1.front();
            cout << x << endl;
            q1.pop();
        }
        while (q1.size() != 0)
        {
            q2.push(x);
            cout << x << endl;
            x = q1.front();
            cout << x << endl;
            q1.pop();
        }
        q1 = q2;
        return x;
    }

    int top()
    {
        queue<int> q2;
        int x;
        // bool flag = false;
        while (!q1.empty())
        {
            x = q1.front();
            q2.push(x);
            q1.pop();
        }
        q1 = q2;
        return x;
    }

    bool empty()
    {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */