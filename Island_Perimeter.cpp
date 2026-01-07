const int N = 105;
class Solution
{
public:
    int islandPerimeterNum;
    int n, m;
    vector<vector<int>> v;
    bool visit[N][N];
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool validity(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int sr, int sc)
    {
        visit[sr][sc] = true;
        for (auto child : p)
        {
            int cr = child.first + sr;
            int cc = child.second + sc;
            if (validity(cr, cc) && !visit[cr][cc] && v[cr][cc] == 1)
                dfs(cr, cc);
            else if (!validity(cr, cc) || v[cr][cc] == 0)
                islandPerimeterNum++;
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        islandPerimeterNum = 0;
        n = grid.size();
        m = grid[0].size();
        v = grid;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visit[i][j] && v[i][j] == 1)
                    dfs(i, j);
            }
        }
        return islandPerimeterNum;
    }
};