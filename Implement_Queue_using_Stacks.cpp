class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        stack<int> copy;
        int x;
        int last;
        while (!st.empty())
        {
            x = st.top();
            st.pop();
            if (st.empty())
            {
                last = x;
                break;
            }
            copy.push(x);
        }
        while (!copy.empty())
        {
            st.push(copy.top());
            copy.pop();
        }
        return last;
    }

    int peek()
    {
        stack<int> copy;
        int x;
        int last;
        while (!st.empty())
        {
            x = st.top();
            st.pop();
            if (st.empty())
            {
                last = x;
            }
            copy.push(x);
        }
        while (!copy.empty())
        {
            st.push(copy.top());
            copy.pop();
        }
        return last;
    }

    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */