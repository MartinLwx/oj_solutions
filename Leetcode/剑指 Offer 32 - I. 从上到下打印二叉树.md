#### 题意

从上到下打印二叉树的每一行，最后返回一个层序遍历的序列

#### 思路

- 使用队列作为辅助工具来进行层序遍历，都存储到一个`vector`里面返回即可

#### 代码

```c++
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            ans.emplace_back(cur->val);
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right) {
                q.push(cur->right);
            }
        }       
        return ans;
    }
};
```

