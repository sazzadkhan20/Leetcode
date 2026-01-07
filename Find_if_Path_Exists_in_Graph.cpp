class Solution
{
public:
    // const int N = 200005;
    vector<int> graph[200005];
    bool visit[200005];
    void dfs(int src, int des)
    {
        visit[src] = true;
        for (int ch : graph[src])
        {
            if (visit[des])
                return;
            if (!visit[ch])
                dfs(ch, des);
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        memset(visit, false, sizeof(visit));
        for (vector<int> p : edges)
        {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        dfs(source, destination);
        return visit[destination];
    }
};