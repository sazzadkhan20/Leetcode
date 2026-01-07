const int N = 105;

class Compare
{
public:
    bool operator()(pair<int, int> l, pair<int, int> r)
    {
        return l.second > r.second;
    }
};
class Solution
{
public:
    vector<pair<int, int>> networks[N];
    int dis[N];

    void dijkstra(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push({src, 0});
        dis[src] = 0;
        while (!pq.empty())
        {
            pair<int, int> pa = pq.top();
            pq.pop();

            int node = pa.first;
            int nodeCost = pa.second;

            for (auto connectedNode : networks[node])
            {
                int pathCost = nodeCost + connectedNode.second;
                if (pathCost < dis[connectedNode.first])
                {
                    dis[connectedNode.first] = pathCost;
                    pq.push({connectedNode.first, pathCost});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        for (vector<int> node : times)
            networks[node[0]].push_back({node[1], node[2]});
        for (int i = 1; i <= n; i++)
            dis[i] = INT_MAX;
        dijkstra(k);
        int maxTime = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == INT_MAX)
                return -1;
            else
                maxTime = max(maxTime, dis[i]);
        }
        return maxTime;
    }
};