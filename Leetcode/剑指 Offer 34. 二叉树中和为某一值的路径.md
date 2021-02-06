#### 题意

典型的路径和题目

#### 思路

- 路径和问题可以用DFS来解决，因为要记录序列，所以涉及了回溯操作，算是比较基础的题目

- `path_sum`没有采用`&`形式是因为每一层都可以生成新的，我们就省去了每一层`- root->val`的操作

#### 代码

```c++
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int>& path, int path_sum, int target) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            path_sum += root->val;
            path.emplace_back(root->val);
            if(path_sum == target) {
                ans.emplace_back(path);  
            }
            path.pop_back();
            return;
        }
        path.emplace_back(root->val);
        dfs(root->left, path, path_sum + root->val, target);
        dfs(root->right, path, path_sum + root->val, target);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int tmp;
        vector<int> path;
        dfs(root, path, 0, sum);
        return ans;
    }
};
```

