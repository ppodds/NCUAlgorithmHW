#include <deque>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    int freq;
    Node* lchild;
    Node* rchild;

    Node(char _val, int _freq, Node* _lchild, Node* _rchild) {
        val = _val;
        freq = _freq;
        lchild = _lchild;
        rchild = _rchild;
    }
};

unordered_map<char, int> freq;  // 用來統計各個字元的出現次數
deque<Node*> forest;            // 用來儲存各個節點之指標

// 提供給sort函數使用
bool comp(Node* a, Node* b) {
    return a->freq < b->freq;
}

bool cmp(pair<char, int> a, pair<char, int> b) {
    return a.second > b.second;
}

void dfs(const Node* ptr, vector<pair<char, string> >* ans, const string path) {
  if(ptr->lchild == nullptr || ptr->rchild == nullptr) {
    ans->push_back(pair<char, string>(ptr->val, path));
  } else {
    dfs(ptr->lchild, ans, path + "0");
    dfs(ptr->rchild, ans, path + "1");
  }
}

bool cmp2(const pair<char, string>& a, const pair<char, string>& b) {
  return stoi(a.second) < stoi(b.second);
}

int main() {
    string input;
    cin >> input;
    for (int i=0;i<input.length();i++)
    {
        char c = input[i];
        if (freq.count(c))
            freq[c]++;
        else
            freq[c] = 1;
    }
    vector<pair<char, int>> tmp;
    // 製作節點，並儲存到forest之中
    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        forest.push_back(new Node((*it).first, (*it).second, nullptr, nullptr));
        tmp.push_back({(*it).first, (*it).second});
    }
    sort(tmp.begin(), tmp.end(), cmp);
    // 按照字元出現頻率排序forest中的節點，取出出現頻率最小的兩個節點，將其合併，
    // 再儲存回forest之中
    for(int i = 0; i < freq.size()-1; i++) {
        sort(forest.begin(), forest.end(), comp);
        Node* ptr1 = forest.front(); forest.pop_front();
        Node* ptr2 = forest.front(); forest.pop_front();
        Node* parentNode = new Node(-1, ptr1->freq + ptr2->freq, ptr1, ptr2);
        forest.push_back(parentNode);
    }
    vector<pair<char, string> > ans;
    dfs(forest.front(), &ans, "");
    sort(ans.begin(), ans.end(), cmp2);
    for(auto &iter : ans) {
        cout << iter.first << ":" << iter.second << endl;
    }
    return 0;
}