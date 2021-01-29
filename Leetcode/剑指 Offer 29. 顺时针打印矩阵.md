#### 题意

顺时针打印矩阵，如下所示⬇️

```c++
1 2 3
4 5 6
7 8 9

[1,2,3,6,9,8,7,4,5]
```

#### 思路

- 采用手动模拟的方法，容易知道顺时针打印矩阵的方向应该分别是：向右走→向下走→向左走→向上走，每次都是走到头就换方向，我们只要模拟一下即可

- 如何知道我们已经打印完所有的数字了呢，利用矩阵的长和宽算出矩阵一共有几个元素，我们进行计数即可

#### 代码

```c++
class Solution {
public:
    bool judge(int x, int y, vector<vector<int>>& vis, int row, int col) {
        if(x >= 0 && x < row && y >= 0 && y < col) {    //坐标没有越界
            if(vis[x][y] == 0) {
                return true;
            }else {
                return false;
            }
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) {
            return {};
        }
        int col = matrix[0].size();

        int x = 0, y = 0;
        //方向，分别是右，下，左，上
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int pos = 0;
        vector<int> ans;
        vector<vector<int>> vis(row, vector<int>(col));
        int count = row * col;
        while(count--) {
            ans.emplace_back(matrix[x][y]);
            vis[x][y] = 1;
            int new_x = x + dx[pos];
            int new_y = y + dy[pos];
            if(judge(new_x, new_y, vis, row, col)) {
                x = new_x;
                y = new_y;
            }else {
                pos = (pos + 1) % 4;
                new_x = x + dx[pos];
                new_y = y + dy[pos];
                x = new_x;
                y = new_y;
            }
        }
        return ans;
    }
};
```

