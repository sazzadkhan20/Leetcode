class Solution
{
public:
    int n, m;
    vector<vector<int>> Grid;
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int numOfFishCatch;

    bool validity(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int sr, int sc)
    {
        numOfFishCatch += Grid[sr][sc];
        Grid[sr][sc] = 0;
        for (auto child : p)
        {
            int cr = child.first + sr;
            int cc = child.second + sc;
            if (validity(cr, cc) && Grid[cr][cc] > 0)
                dfs(cr, cc);
        }
    }
    int findMaxFish(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        Grid = grid;
        int maxNumOfFishCatch = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Grid[i][j] > 0)
                {
                    numOfFishCatch = 0;
                    dfs(i, j);
                    maxNumOfFishCatch = max(maxNumOfFishCatch, numOfFishCatch);
                }
            }
        }
        return maxNumOfFishCatch;
    }
};