#### 题意

只要求全排列的第k个

#### 思路

- 最近做的都是回溯题，看到这一题立刻想到了全排列的题，以及要求的是第`k`个的解，很容易想到，`>k`的我们都没有必要遍历。结果发现用时将近2000ms....。好歹还是过了😓
- 逛了题解，才发现这题要用数学方法来进行剪枝。对于当前能扩展到多少个状态以及有没有我们想要的解我们是可以算出来的，完全可以**跳步**来进行剪枝。比如`123`，第一次选择`1`，对应能扩展到的状态数为`2!`，也就是`123`，`132`两种。那么如果我们要的是第`3`个结果就可以跳过`1`开始的状态，从2开始排，`2xx`，这样**不断跳步最后就可以定位想要的状态，也因为跳步的特性，这题可以不用回溯**。不得不说对回溯的理解又提高了🤔

#### 代码（2000ms）

```c++
class Solution {
public:
    int cnt = 0;
    string ans;
    void backtrace(string& path, vector<int>& vis, int n, int k)
    {
        if(cnt >= k)    return;
        if(path.size() == n)
        {
            cnt++;
            if(cnt == k)    ans = path;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                path.push_back(i  + 1 + '0');
                backtrace(path, vis, n, k);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int> vis(n, 0);
        string path = "";
        backtrace(path, vis, n, k);
        return ans;
    }
};
```

#### 代码（0ms）

```c++
class Solution {
public:
    int cnt = 0;
    string ans;
    vector<int> factorial;
    vector<int> vis;
    void backtrace(string& path, int cur, int n, int& k)
    {
        if(cur == n)
            return;

        int remain = factorial[n - cur - 1];    //看全排列个数
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(remain < k)
                {
                    k -= remain;
                    continue;
                }   //直接跳过对应的个数
                vis[i] = 1;
                path.push_back(i + 1 + '0');
                backtrace(path, cur + 1, n, k);
            }
        }
    }
    void generate_fac(vector<int>& factorial, int n)
    {
        factorial.resize(n, 0);
        factorial[0] = 1;
        for(int i=1;i<n;i++)
            factorial[i] = factorial[i - 1] * i;
    }//阶乘生成函数
    string getPermutation(int n, int k) {
        generate_fac(factorial, n);
        vis.resize(n, 0);

        string path = "";
        backtrace(path, 0, n, k);
        return path;
    }
};
```

