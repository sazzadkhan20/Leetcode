class Solution
{
public:
    int n, m;
    vector<vector<int>> v;
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool flag;
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int sr, int sc)
    {
        if (sr == 0 || sr == n - 1 || sc == 0 || sc == m - 1)
            flag = false;
        v[sr][sc] = 1;
        for (pair<int, int> pa : p)
        {
            int cr = pa.first + sr;
            int cc = pa.second + sc;
            if (valid(cr, cc) && v[cr][cc] == 0)
                dfs(cr, cc);
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        v = grid;
        int numberOfCloseIsland = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j);
                    if (flag)
                        numberOfCloseIsland++;
                }
            }
        }
        return numberOfCloseIsland;
    }
};