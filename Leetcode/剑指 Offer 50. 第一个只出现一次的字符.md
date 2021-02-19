#### 题意

如题目所示

#### 思路

- 遍历字符串建立一个哈希表来统计每个字符出现的次数，然后再从头遍历字符串进行查询即可

#### 代码

```c++
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty()) {
            return ' ';
        }
        unordered_map<char, int> table;
        for(auto ch: s) {
            table[ch]++;
        }
        for(auto ch: s) {
            if(table[ch] == 1) {
                return ch;
            }
        }
        return ' ';
    }
};
```

