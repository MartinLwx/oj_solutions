#### 题意

找到所有根结点到叶子结点到路径

#### 思路

- 1⃣️简单的DFS问题。可以按照二叉树的遍历模版写，采用后序遍历，在最后这个`visit()`函数执行完后就要回到上一层了（此时撤销选择）。关键是要如何记住路径选择的信息。我这里的的方法略蠢，用了一个`vector`记住选择，最后再单独处理生成字符串。带来的一个比较麻烦的点是要回溯的时候要撤销选择。

  ```c++
  void dfs(TreeNode* root)
  {
  		递归终止退出处理
  		dfs(root->left);
  		dfs(root->right);
  		visit();
  		return;
  }
  ```

- 2⃣️BFS，这个代码比较长，就没写了。

- 💯字符串的回溯问题，可以通过不传`&`，每一层都生成新的字符串。这样就不用担心处理撤销选择的问题了。

#### 代码

```c++
class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* cur, vector<int>& path)
    {
        if(!cur->left && !cur->right)
        {
            string tmp = "";
            for(int i=0;i<path.size();i++)
                tmp += to_string(path[i]) + "->";
            tmp += to_string(cur->val);
            ans.emplace_back(tmp);
            // return;
        }
        if(cur->left)
        {
            path.emplace_back(cur->val);
            dfs(cur->left, path);
        }
        if(cur->right)
        {
            path.emplace_back(cur->val);
            dfs(cur->right, path);
        }
        if(path.size() > 0) path.pop_back();    //处理单独一个结点的情况，这里撤销选择
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return {};
        vector<int> path;
        dfs(root, path); 
        return ans;   
    }
};
```

#### 代码（不带`&`直接处理字符串）

```c++
class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* cur, string str)
    {
        if(cur)
        {
            str += to_string(cur->val);
            if(!cur->left && !cur->right)
                ans.emplace_back(str);
            else{
                str += "->";
                dfs(cur->left, str);
                dfs(cur->right, str);
            }
            
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return {};
        dfs(root, ""); 
        return ans;   
    }
};
```

