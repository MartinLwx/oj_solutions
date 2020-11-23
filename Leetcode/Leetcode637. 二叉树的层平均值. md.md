#### 题意

求二叉树每一层的结点的平均值

#### 思路

- 采用最符合直觉的层次遍历方式。在层次遍历的时候，取每一层结点的时候进行计算就好了。

#### 代码

```C++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)   return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            double tmp = 0.0;
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                auto cur = q.front();
                q.pop();
                tmp += cur->val;	//多了这里的计算
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            ans.emplace_back(tmp / len);
        }
        return ans;
    }
};
```

