class Solution
{
public:
    vector<vector<int>> Grid;
    bool visit[52][52];
    int maxArea;
    int n, m;
    int trackLand;
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs_2D_grid(int sr, int sc)
    {
        visit[sr][sc] = true;
        trackLand++;
        for (auto child : p)
        {
            int cr = sr + child.first;
            int cc = sc + child.second;
            if (valid(cr, cc) && !visit[cr][cc] && Grid[cr][cc] == 1)
                dfs_2D_grid(cr, cc);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        Grid = grid;
        n = grid.size();
        m = grid[0].size();
        // cout<<n<<" "<<m<<endl;
        memset(visit, false, sizeof(visit));
        maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visit[i][j] && Grid[i][j] == 1)
                {
                    trackLand = 0;
                    dfs_2D_grid(i, j);
                    maxArea = max(maxArea, trackLand);
                }
            }
        }
        return maxArea;
    }
};