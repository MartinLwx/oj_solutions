#### 题意

N皇后问题

#### 思路

- N皇后是典型的回溯算法题目。最近刚好复习到回溯算法，找出来的时候发现刚好是今天的每日一题🤯。

- 对于回溯的题目，最好的分析方法就是画出它的递归树，看看实际上具体是怎么遍历所有可能的解的。我这里是把**每一层的工作看成在「每一行」找一个可以放棋子的位置，所以不需要一个变量来实现行互斥**

- 为了符合棋子的规则，要检查横，竖，正对角线，副对角线的位置是否有冲突。而我这里是**按行填**，所以还需要3个变量来实现上面的互斥操作

- 设置的变量有，具体见图⬇️

  - `col`：实现每一列的互斥

  - `diag1`：实现正对角线的互斥。这里利用的是(i,j)之和每行都不一样

  - `diag2`：实现副对角线的互斥。这里利用的时候是(i,j)的是每个副对角线j-i的差不一样，但是要注意⚠️棋盘的左下角可能为负值所以还需要映射到正的位置，我这里就直接加上`n-1`了，*比如`(3,0)`，`0 - 3 + (4 - 1) = 0`*

    ```c++
    00 01 02 03 
    10 11 12 13
    20 21 22 23
    30 31 32 33		//看坐标找规律
    ```

![](./images/Leetcode51.jpeg)

#### 代码

```c++
class Solution {
public:
    vector<vector<string>> ans;     //存放解
    void backtrace(vector<string>& path, vector<int>& col, vector<int>& diag1, vector<int>& diag2, int index)
    {
        if(index == path.size())
        {
            ans.emplace_back(path);
            return;
        }
        int n = path.size();    //表示棋盘的长度，也就是坐标(i,j)中的i
        for(int j=0;j<path[index].size();j++)
        {
            if(!col[j] && !diag1[index + j] && !diag2[j - index + n - 1])
            {
                col[j] = 1;
                diag1[index + j] = 1;
                diag2[j - index + n - 1] = 1;
                path[index][j] = 'Q';
                backtrace(path, col, diag1, diag2, index + 1);
                path[index][j] = '.';
                col[j] = 0;
                diag1[index + j] = 0;
                diag2[j - index + n - 1] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, 0);      //列互斥
        vector<int> diag1(2*n, 0);  //主对角线互斥
        vector<int> diag2(2*n, 0);  //副对角线互斥
        vector<string> path;
        string t = "";
        for(int i=0;i<n;i++)    t += ".";   //生成“空棋盘”
        for(int i=0;i<n;i++)    path.emplace_back(t);
        backtrace(path, col, diag1, diag2, 0);
        return ans;
    }
};
```

