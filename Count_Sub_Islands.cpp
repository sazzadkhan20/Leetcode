const int N = 505;
class Solution
{
public:
    int n, m;
    vector<vector<int>> Grid1, Grid2;
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool flag;

    bool validity(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int sr, int sc)
    {
        if (Grid2[sr][sc] != Grid1[sr][sc])
            flag = false;
        Grid2[sr][sc] = 0;
        for (auto child : p)
        {
            int cr = child.first + sr;
            int cc = child.second + sc;
            if (validity(cr, cc) && Grid2[cr][cc] == 1)
                dfs(cr, cc);
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        n = grid1.size();
        m = grid1[0].size();
        Grid1 = grid1;
        Grid2 = grid2;
        int subIsland = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Grid2[i][j] == 1)
                {
                    flag = true;
                    dfs(i, j);
                    if (flag)
                        subIsland++;
                }
            }
        }
        return subIsland;
    }
};