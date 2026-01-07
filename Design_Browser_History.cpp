class BrowserHistory
{
public:
    stack<string> URL;
    stack<string> forwardURL;
    BrowserHistory(string homepage)
    {
        URL.push(homepage);
    }

    void visit(string url)
    {
        URL.push(url);
        while (!forwardURL.empty())
            forwardURL.pop();
    }

    string back(int steps)
    {
        while (!URL.empty() && steps != 0)
        {
            steps--;
            forwardURL.push(URL.top());
            URL.pop();
        }
        if (URL.size() == 0)
        {
            URL.push(forwardURL.top());
            forwardURL.pop();
        }
        return URL.top();
    }

    string forward(int steps)
    {
        while (!forwardURL.empty() && steps != 0)
        {
            steps--;
            URL.push(forwardURL.top());
            forwardURL.pop();
        }
        return URL.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */