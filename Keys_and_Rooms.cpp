const int N = 1000 + 5;
class Solution
{
public:
    vector<vector<int>> v;
    bool visit[N];
    void dfs(int src)
    {
        visit[src] = true;
        for (int child : v[src])
        {
            if (!visit[child])
                dfs(child);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        v = rooms;
        memset(visit, false, sizeof(visit));
        dfs(0);
        for (int i = 0; i < rooms.size(); i++)
        {
            if (!visit[i])
                return false;
        }
        return true;
    }
};