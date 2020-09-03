#### 题意

给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

#### 思路

- 对于回溯题目画出它的递归树是最好分析的。可以看出1⃣️如果是数字，直接将数字加到当前保存结果的字符串`str`里，2⃣️如果是字母，那么要扩展2个结点，分别是它的大写字母和小写字母。**这样最后递归到叶子结点就得到了一个解。**递归树如下图所示

![](./images/Leetcode784.jpeg)

#### 代码

```c++
class Solution {
public:
    vector<string> ans;
		//index为str字符串的长度
    void backtrace(string& str, string& S, int index)
    {
        if(index == S.size())
        {
            ans.push_back(str);
            return;
        }
        if(isdigit(S[index]))
        {
            str.push_back(S[index]);
            backtrace(str, S, index + 1);
            str.pop_back();
        }
        if(isalpha(S[index]))
        {
            //分别扩展小写字母，大写字母
            str.push_back(tolower(S[index]));
            backtrace(str, S, index + 1);
            str.pop_back();

            str.push_back(toupper(S[index]));
            backtrace(str, S, index + 1);
            str.pop_back();
        }
    }
    vector<string> letterCasePermutation(string S) {
        if(S.size() == 0)   return {};
        string path = "";
        backtrace(path, S, 0);
        return ans;
    }
};
```

