#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 繼承logic_error的class，方便之後BFS的操作
class InvalidOperation : public logic_error
{
public:
    explicit InvalidOperation(const string &message) : logic_error(message) {}
};

// 用來記錄拼圖的盤面資訊，且方便對盤面做操作
class board
{
public:
    board() {}
    // 以矩陣方式初始化拼圖盤面
    board(vector<vector<int>> &copyMatrix)
    {
        // 調整vector的大小為3*3，直接當成3*3的矩陣使用
        matrix.resize(3);
        for (int i = 0; i < 3; i++)
        {
            matrix[i].resize(3);
        }
        // 從來源矩陣複製值到拼圖盤面上
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = copyMatrix[i][j];
                // 紀錄拼圖的空白位置
                if (matrix[i][j] == 0)
                    blankPos = {i, j};
            }
        }
    }
    // 將拼圖的盤面印在console
    void print()
    {
        for (int i = 0; i < 3; i++)
            cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << endl;
    }
    // 檢查兩個拼圖盤面是否相等
    bool equal(board target)
    {
        bool isEqual = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] != target.matrix[i][j])
                {
                    // 若是拼圖盤面不同會直接跳出兩層迴圈輸出結果
                    isEqual = false;
                    break;
                }
            }
            if (!isEqual)
                break;
        }
        return isEqual;
    }
    // 對拼圖盤面的空白做向上的操作，操作後會回傳被操作後的新盤面
    board moveTop()
    {
        // 如果沒辦法再向上移動就丟錯誤出去
        if (blankPos.first == 0)
            throw InvalidOperation("空白格子已在最上方列");
        // 複製一份現在的盤面
        board newBoard(matrix);
        // 將空白格子和上面的格子做交換
        swap(newBoard.matrix[blankPos.first][blankPos.second], newBoard.matrix[blankPos.first - 1][blankPos.second]);
        newBoard.blankPos = {blankPos.first - 1, blankPos.second};
        return newBoard;
    }
    // 對拼圖盤面的空白做向右的操作，操作後會回傳被操作後的新盤面
    board moveRight()
    {
        // 如果沒辦法再向右移動就丟錯誤出去
        if (blankPos.second == 2)
            throw InvalidOperation("空白格子已在最右方列");
        // 複製一份現在的盤面
        board newBoard(matrix);
        // 將空白格子和右邊的格子做交換
        swap(newBoard.matrix[blankPos.first][blankPos.second], newBoard.matrix[blankPos.first][blankPos.second + 1]);
        newBoard.blankPos = {blankPos.first, blankPos.second + 1};
        return newBoard;
    }
    // 對拼圖盤面的空白做向下的操作，操作後會回傳被操作後的新盤面
    board moveDown()
    {
        // 如果沒辦法再向下移動就丟錯誤出去
        if (blankPos.first == 2)
            throw InvalidOperation("空白格子已在最下方列");
        // 複製一份現在的盤面
        board newBoard(matrix);
        // 將空白格子和下面的格子做交換
        swap(newBoard.matrix[blankPos.first][blankPos.second], newBoard.matrix[blankPos.first + 1][blankPos.second]);
        newBoard.blankPos = {blankPos.first + 1, blankPos.second};
        return newBoard;
    }
    // 對拼圖盤面的空白做向左的操作，操作後會回傳被操作後的新盤面
    board moveLeft()
    {
        // 如果沒辦法再向左移動就丟錯誤出去
        if (blankPos.second == 0)
            throw InvalidOperation("空白格子已在最左方列");
        // 複製一份現在的盤面
        board newBoard(matrix);
        // 將空白格子和左邊的格子做交換
        swap(newBoard.matrix[blankPos.first][blankPos.second], newBoard.matrix[blankPos.first][blankPos.second - 1]);
        newBoard.blankPos = {blankPos.first, blankPos.second - 1};
        return newBoard;
    }
    // 檢查這個盤面是否已經出現過了，用於避免產生重複的可能解答
    bool hasExisted(vector<board> &alreadyExisted)
    {
        // 窮舉比對盤面的值是否有重複出現
        for (auto &b : alreadyExisted)
        {
            bool isSameBoard = true;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (matrix[i][j] != b.matrix[i][j])
                    {
                        isSameBoard = false;
                        break;
                    }
                }
                if (!isSameBoard)
                    break;
            }
            if (isSameBoard)
            {
                return true;
            }
        }
        return false;
    }

private:
    // 紀錄盤面用的3*3矩陣
    vector<vector<int>> matrix;
    // 紀錄空白在矩陣中出現的位置
    pair<int, int> blankPos;
};

int main()
{
    // 建立一個起始盤面的矩陣
    vector<vector<int>> inputMatrix;
    inputMatrix.resize(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int t;
            cin >> t;
            inputMatrix[i].push_back(t);
        }
    }
    // 用使用者的輸入來初始化起始盤面
    board startBoard(inputMatrix);
    // 紀錄目標盤面
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int t;
            cin >> t;
            inputMatrix[i][j] = t;
        }
    }
    // 紀錄目標盤面
    board goalBoard(inputMatrix);
    // 初始化BFS會用到的queue
    queue<board> ansSpace;
    // 紀錄已經出現過的可能解答
    vector<board> alreadyExisted;
    // 如果沒有把起始盤面也丟進可能解答裡面，在搜尋可能解答時就會再出現他一次
    alreadyExisted.push_back(startBoard);
    ansSpace.push(startBoard);
    // BFS
    while (ansSpace.size() != 0)
    {
        // 從queue中取出節點來探索
        board current = ansSpace.front();
        ansSpace.pop();
        // 把正在探索的節點盤面印出來
        current.print();
        // 檢查此節點是否是目標盤面，若是的話就可結束程式
        if (current.equal(goalBoard))
            return 0;
        // 產生可能解答，並且把沒有重複的丟到queue裡面
        for (int i = 0; i < 4; i++)
        {
            try
            {
                board tmp;
                /** 
                * 根據拜訪的順序產生可能解
                * 迴圈第一次產生上，第二次產生右... 以此類推
                * 若是盤面沒辦法做該操作的話會直接跳到catch區塊，變成do nothing
                */ 
                switch (i)
                {
                case 0:
                    // 產生向上移動的解
                    tmp = current.moveTop();
                    // 若產生出來的解已經出現過的話就直接跳過
                    if (!tmp.hasExisted(alreadyExisted))
                    {
                        // 往queue尾端插入可能解
                        ansSpace.push(tmp);
                        // 紀錄已此解已產生過
                        alreadyExisted.push_back(tmp);
                    }
                    break;
                case 1:
                    // 產生向右移動的解
                    tmp = current.moveRight();
                    // 若產生出來的解已經出現過的話就直接跳過
                    if (!tmp.hasExisted(alreadyExisted))
                    {
                        // 往queue尾端插入可能解
                        ansSpace.push(tmp);
                        // 紀錄已此解已產生過
                        alreadyExisted.push_back(tmp);
                    }
                    break;
                case 2:
                    // 產生向下移動的解
                    tmp = current.moveDown();
                    // 若產生出來的解已經出現過的話就直接跳過
                    if (!tmp.hasExisted(alreadyExisted))
                    {
                        // 往queue尾端插入可能解
                        ansSpace.push(tmp);
                        // 紀錄已此解已產生過
                        alreadyExisted.push_back(tmp);
                    }
                    break;
                case 3:
                    // 產生向左移動的解
                    tmp = current.moveLeft();
                    // 若產生出來的解已經出現過的話就直接跳過
                    if (!tmp.hasExisted(alreadyExisted))
                    {
                        // 往queue尾端插入可能解
                        ansSpace.push(tmp);
                        // 紀錄已此解已產生過
                        alreadyExisted.push_back(tmp);
                    }
                    break;
                }
            }
            catch (const InvalidOperation &e)
            {
                // 如果產生解的時候出現不能產生的狀況就會跳到這裡，表示該盤面操作不被允許
            }
        }
    }
    // 搜尋完所有解答空間仍然沒有解
    cout << "There is no answer." << endl;
    return 0;
}