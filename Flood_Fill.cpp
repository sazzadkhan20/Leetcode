class Solution
{
public:
    vector<vector<int>> v;
    bool visit[51][51];
    int n, m;
    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void DFS_2D_Grid(int sr, int sc, int color, int val)
    {
        v[sr][sc] = color;
        visit[sr][sc] = true;
        for (auto child : p)
        {
            int ci = sr + child.first;
            int cj = sc + child.second;
            if (valid(ci, cj) && !visit[ci][cj] && val == v[ci][cj])
                DFS_2D_Grid(ci, cj, color, val);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        v = image;
        n = image.size();
        m = image[0].size();
        memset(visit, false, sizeof(visit));
        DFS_2D_Grid(sr, sc, color, v[sr][sc]);
        return v;
    }
};