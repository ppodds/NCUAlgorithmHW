#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

// 設定最大節點的總數
int maxNodeAmount = 26;

bool hasExisted(vector<char> &v, char c)
{
    for (auto t : v)
    {
        if (c == t)
        {
            return true;
        }
    }
    return false;
}
// 將char的節點名稱轉為數字的index，方便vector操作
int nodeNameToIndex(char nodeName)
{
    if (nodeName >= 'A' && nodeName <= 'Z')
    {
        return nodeName - 65;
    }
    else
    {
        return nodeName - 97;
    }
}

map<char, int> getCharMappingTable(vector<char> &from, vector<char> &to)
{
    bool useA = false;
    bool usea = false;
    for (int i = 0; i < from.size(); i++)
    {
        if ((from[i] >= 'A' && from[i] <= 'Z') || (to[i] >= 'A' && to[i] <= 'Z'))
        {
            useA = true;
        }
        else
        {
            usea = true;
        }
    }
    vector<char> vertexsa;
    vector<char> vertexsA;
    if (useA && usea)
    {
        for (int i = 0; i < from.size(); i++)
        {
            char t = from[i];
            if (t >= 'a' && t <= 'z')
            {
                if (!hasExisted(vertexsa, t))
                    vertexsa.push_back(t);
            }
            t = to[i];
            if (t >= 'a' && t <= 'z')
            {
                if (!hasExisted(vertexsa, t))
                    vertexsa.push_back(t);
            }
        }
        for (int i = 0; i < from.size(); i++)
        {
            char t = from[i];
            if (t >= 'A' && t <= 'Z')
            {
                if (!hasExisted(vertexsA, t))
                    vertexsA.push_back(t);
            }
            t = to[i];
            if (t >= 'A' && t <= 'Z')
            {
                if (!hasExisted(vertexsA, t))
                    vertexsA.push_back(t);
            }
        }
    }
    sort(vertexsa.begin(), vertexsa.end());
    sort(vertexsA.begin(), vertexsA.end());
    map<char, int> nameToIndex;
    int index = 0;
    for (int i = 0; i < vertexsa.size(); i++)
    {
        nameToIndex[vertexsa[i]] = index;
        index++;
    }
    for (int i = 0; i < vertexsA.size(); i++)
    {
        nameToIndex[vertexsA[i]] = index;
        index++;
    }
    return nameToIndex;
}

void initWeightTable(map<char, int> &mapingTable, vector<char> &from, vector<char> &to, vector<int> &weight, vector<vector<int>> &w)
{
    if (mapingTable.size() != 0)
    {
        for (int i = 0; i < from.size(); i++)
        {
            int fromIndex = mapingTable[from[i]];
            int toIndex = mapingTable[to[i]];
            w[fromIndex][toIndex] = weight[i];
        }
    }
    else
    {
        for (int i = 0; i < from.size(); i++)
        {
            int fromIndex = nodeNameToIndex(from[i]);
            int toIndex = nodeNameToIndex(to[i]);
            w[fromIndex][toIndex] = weight[i];
        }
    }
}

// 利用Floyd-Warshall演算法求取最短路徑並回傳
void findShortestPath(int nodeAmount, vector<vector<int>> &w)
{
    // 初始化用來記錄從起始節點到各節點的路徑長度
    vector<vector<int>> distance;
    distance.resize(nodeAmount);
    for (int i = 0; i < nodeAmount; i++)
    {
        distance[i].resize(nodeAmount);
        for (int j = 0; j < nodeAmount; j++)
        {
            distance[i][j] = w[i][j];
            if (i == j)
                distance[i][j] = 0;
        }
    }
    for (int k = 0; k < nodeAmount; k++)
    {
        for (int i = 0; i < nodeAmount; i++)
        {
            for (int j = 0; j < nodeAmount; j++)
            {
                if (distance[i][k] != 99999 && distance[k][j] != 99999)
                {
                    int newDistance = distance[i][k] + distance[k][j];
                    if (distance[i][j] > newDistance)
                    {
                        distance[i][j] = newDistance;
                    }
                }
            }
        }
    }
    for (int i = 0; i < nodeAmount; i++)
    {
        string printRow = "";
        for (int j = 0; j < nodeAmount; j++)
        {
            if (distance[i][j] == 99999)
                printRow += "INF ";
            else
                printRow += to_string(distance[i][j]) + " ";
        }
        cout << printRow.substr(0, printRow.size() - 1) << endl;
    }
}

int main()
{
    int vertexAmount, edgeAmount;
    cin >> vertexAmount >> edgeAmount;
    /* 
    * 儲存各邊權重
    * w[0][1] 即為 node 0 到 node 1的權重
    */
    vector<vector<int>> w;
    // 初始化成矩陣型式便於後續操作
    w.resize(vertexAmount);
    for (int i = 0; i < vertexAmount; i++)
    {
        w[i].resize(vertexAmount);
        for (int j = 0; j < vertexAmount; j++)
        {
            w[i][j] = 99999;
        }
    }
    vector<char> from;
    vector<char> to;
    vector<int> weight;
    for (int _ = 0; _ < edgeAmount; _++)
    {
        char t1, t2;
        cin >> t1 >> t2;
        from.push_back(t1);
        to.push_back(t2);
        int t;
        cin >> t;
        weight.push_back(t);
    }
    map<char, int> mappingTable = getCharMappingTable(from, to);
    initWeightTable(mappingTable, from, to, weight, w);
    findShortestPath(vertexAmount, w);
    return 0;
}