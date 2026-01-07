const int N = 1005;
class Solution
{
public:
    int n, m;
    vector<vector<int>> Grid;
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool validity(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int sr, int sc)
    {
        Grid[sr][sc] = 0;
        for (auto child : p)
        {
            int cr = child.first + sr;
            int cc = child.second + sc;
            if (validity(cr, cc) && Grid[cr][cc] == 1)
                dfs(cr, cc);
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        Grid = grid;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (Grid[i][j] == 1)
                        dfs(i, j);
                }
            }
        }
        int enclavesNum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Grid[i][j] == 1)
                {
                    enclavesNum++;
                }
            }
        }
        return enclavesNum;
    }
};