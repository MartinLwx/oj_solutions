#### 题意

正如题目描述的，要求对字符串里面的空格进行替换

#### 思路

- 1⃣️新建一个字符串，遍历字符串的每一个字符，对每一个空格进行替代即可，不是空格的就直接添加
- 2⃣️用STL中string的相关函数来实现
- 3⃣️做完之后发现书上的双指针法的解法也挺巧妙的
  - 一个前提：因为一个`" "`替换`“%20“`长度是1→3，也就是长度差值为2
  - 遍历方向：要从后往前填，从前往后的移动会导致先前的移动后面又要移动，这样时间复杂度变成了$O(n^2)$，而从后往前就保证了每个字符的移动都只有一次

#### 代码（直接替代）

```c++
class Solution {
public:
    string replaceSpace(string s) {
        string ans = "";
        for(auto ch: s) {
            if(ch != ' ') {
                ans += ch;
            }else {
                ans += "%20";
            }
        }
        return ans;
    }
};
```

#### 代码（STL）

```c++
class Solution {
public:
    string replaceSpace(string s) {
        auto pos = s.find(" ");
        while(pos != s.npos) {
            s.replace(pos, 1, "%20");
            pos = s.find(" ");
        }
        return s;
    }
};
```

#### 代码（双指针法）

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int blank_cnt = 0;		//统计空格的个数
        for(auto ch: s) { 
            if(ch == ' ') {
                blank_cnt++;
            }
        }
        int new_len = blank_cnt * 2 + s.size();
        int pos_old = s.size() - 1, pos_new = new_len - 1;
        s.resize(new_len);
 				//从后往前填
        while(pos_old >= 0) {
            if(pos_new < pos_old) {
                break;
            }
            if(s[pos_old] != ' ') {
                s[pos_new--] = s[pos_old--];
            }else {
                s[pos_new--] = '0';
                s[pos_new--] = '2';
                s[pos_new--] = '%';
                pos_old--;
            }
        }
        return s;
    }
};
```

