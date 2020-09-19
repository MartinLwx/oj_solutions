#### 题意

求二叉树的的层次遍历，但是是逆序的

#### 思路

- 其实还是求二叉树的层次遍历，只要最后逆置一下得到的结果就好了。

#### 代码

```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> tmp;
            int level_length = q.size();
            for(int i=0;i<level_length;i++)
            {
                auto cur = q.front();
                q.pop();
                tmp.emplace_back(cur->val);
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            ans.emplace_back(tmp);
        }
        reverse(ans.begin(), ans.end());		//逆置
        return ans;
    }
};
```

