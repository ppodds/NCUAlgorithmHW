#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Graph
{
public:
    int V;                    // 點數
    vector<vector<bool>> adj; // adjacency matrix
    vector<bool> visit;       // 目前已經經過的點
    vector<int> solution;     // Hamilton circuit
    bool finded = false;
    Graph(int v)
    {
        V = v;
        adj.resize(V);
        for (int i = 0; i < V; i++)
            adj[i].resize(V);
        solution.resize(V);
        visit.resize(V);
    }
    void addEdge(int from, int to)
    {
        // 記得都要統一減一
        adj[from - 1][to - 1] = true;
    }
    void backtrack(int n);
    void HamiltonCircuit();
};

void Graph::backtrack(int n)
{
    if (!finded)
    {
        if (n == V)
        {
            // 判斷最後一點到第一點是否頭尾銜接
            int a = solution[V - 1];
            int b = solution[0];
            if (adj[a][b])
            {
                // 找到一組解
                /*
            for (int i=0; i<V; ++i)
                cout << solution[i];
            cout << '\n';
            */
                finded = true;
                cout << "True" << endl;
            }
            return;
        }

        int a = solution[n - 1];
        for (int b = 0; b < V; ++b)
            if (adj[a][b] && !visit[b])
            {
                visit[b] = true;
                solution[n] = b;
                backtrack(n + 1);
                visit[b] = false;
            }
    }
    else
        return;
}

void Graph::HamiltonCircuit()
{
    visit[0] = true; // Hamilton Circuit從哪一點開始都行，
    solution[0] = 0; // 直接將第一個點設定為第0點，
    backtrack(1);    // 然後從下一個點開始backtrack。
}

int main()
{
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++)
    {
        int edgeAmount;
        cin >> edgeAmount;
        vector<pair<int, int>> edges;
        vector<int> tmp;
        for (int __ = 0; __ < edgeAmount; __++)
        {
            string edge;
            cin >> edge;
            int splitPos = edge.find(",");
            string a = edge.substr(1, splitPos - 1);
            string b = edge.substr(splitPos + 1, edge.length() - splitPos - 2);
            int v1 = stoi(a);
            int v2 = stoi(b);
            edges.push_back({v1, v2});
            tmp.push_back(v1);
            tmp.push_back(v2);
        }
        sort(tmp.begin(), tmp.end());
        Graph g(tmp[tmp.size() - 1]);
        for (auto item : edges)
        {
            g.addEdge(item.first, item.second);
            g.addEdge(item.second, item.first);
        }
        g.HamiltonCircuit();
        if (!g.finded)
            cout << "False" << endl;
    }
    return 0;
}