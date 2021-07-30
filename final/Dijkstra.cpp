#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <limits>

using namespace std;

// 設定最大節點的總數
int maxNodeAmount = 26;
// 將char的節點名稱轉為數字的index，方便vector操作
int nodeNameToIndex(char nodeName)
{
    return nodeName - 97;
}
// 利用Dijkstra演算法求取最短路徑並回傳
int findShortestPath(int startNode, int targetNode, map<int, vector<int>> &adjacent, vector<vector<int>> &w)
{
    // 初始化用來記錄從起始節點到各節點的路徑長度
    vector<int> distance;
    distance.resize(maxNodeAmount);
    for (int i = 0; i < maxNodeAmount; i++)
    {
        distance[i] = INT32_MAX;
    }
    distance[startNode] = 0;
    // 初始化用來紀錄哪些節點曾經被拿來當過起點的vector
    vector<bool> s;
    s.resize(maxNodeAmount);
    // 更新所有和起始節點鄰接的節點的距離
    for (auto toNode : adjacent[startNode])
    {
        distance[toNode] = w[startNode][toNode];
    }
    // 起始節點已經當過起點了，因此記錄到s中
    s[startNode] = true;
    // 更新節點總數-1次distance，可以保證全部的節點都被探索過
    for (int i = 1; i < maxNodeAmount; i++)
    {
        // 找出當前distance最短的節點
        int tmp = INT32_MAX;
        // u用來保存當前鄰接點中距離最小的點的號碼
        int u = -1;
        for (int j = 0; j < maxNodeAmount; j++)
        {
            if ((!s[j]) && distance[j] < tmp)
            {
                u = j;
                tmp = distance[j];
            }
        }
        // 若是所有點都被更新過了就會跑到這裡面，可以提早結束迴圈
        if (u == -1)
            break;
        // 將 u 設定為已當過起點
        s[u] = true;
        // 將 u 當作起點開始更新 distance
        for (auto toNode : adjacent[u])
        {
            // 檢查該點是否已當過起點 (若已當過起點表示已探索過，若再次探索會導致錯誤)
            if (!s[toNode])
            {
                int newDistance = distance[u] + w[u][toNode];
                // 若有更短的距離就更新distance的紀錄
                if (newDistance < distance[toNode])
                {
                    distance[toNode] = newDistance;
                }
            }
        }
    }
    return distance[targetNode];
}

int main()
{
    char t1, t2;
    cin >> t1 >> t2;
    int startNode = nodeNameToIndex(t1);
    int targetNode = nodeNameToIndex(t2);
    int edgeAmount;
    cin >> edgeAmount;
    /* 
    * 儲存各邊權重
    * w[0][1] 即為 node 0 到 node 1的權重
    */
    vector<vector<int>> w;
    // 初始化成矩陣型式便於後續操作
    w.resize(maxNodeAmount);
    for (int i = 0; i < maxNodeAmount; i++)
        w[i].resize(maxNodeAmount);
    /* 
    * 儲存節點的鄰接邊
    * adjacent[0] 即為 node 0 的所有鄰接邊
    * 可以稍微增加一點速度
    */
    map<int, vector<int>> adjacent;
    for (int _ = 0; _ < edgeAmount; _++)
    {
        cin >> t1 >> t2;
        // 將題目給的字元型式的node名稱轉成index
        int from = nodeNameToIndex(t1);
        int to = nodeNameToIndex(t2);
        // 將邊的聯繫關係加入map
        adjacent[from].push_back(to);
        int t;
        cin >> t;
        // 將權重加入權重儲存的矩陣中
        w[from][to] = t;
    }
    cout << findShortestPath(startNode, targetNode, adjacent, w) << endl;
    return 0;
}