#### 题意

就是判断字符串内的括号是否匹配的问题

#### 思路

- 在学习栈的数据结构的时候，括号匹配一直都是很经典的应用，所以一看到题目就很自然想到用栈去做来。
- 稍微注意一下下面的几种情况：1⃣️`}{`这样右侧的符号先开始的。2⃣️`{{[]]}{`这种末尾多了左侧括号的所以最后return的时候要判断是否栈空。3️⃣`{}]`这样右侧括号比较多的(出栈的时候这里要判断一下👀

#### 代码

```c++
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)   return true;
        stack<char> sk;
        sk.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')   sk.push(s[i]);
            else{
                if(sk.size() == 0)  return false;
                char last = sk.top();
                if(last == '{' && s[i] == '}' || 
                   last == '[' && s[i] == ']' || 
                   last == '(' && s[i] == ')')
                    sk.pop();
                else return false;
            }
        }
        if(sk.size() == 0)  return true;
        else return false;
    }
};
```

