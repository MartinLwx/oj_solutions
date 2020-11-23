####  题意

判断两个字符串里面的数字是否每个字母出现的频度和字母都一样。即字符串`s2`是否为字符串`s1`的排列组合

#### 思路

- 1⃣️很容易想到的是用排序的方法，然后逐个判断，用快排的代码这里的时间复杂度是$O(nlogn)$。  这里要练习快排的代码就手写了快排，效率果然比`sort()`低好多😓

- 2⃣️采用哈希表的思路，字符串是由字母组成的，所以我们直接把对应字符串`s1`的字母进行统计（加法），然后读第二个字符串的时候进行删减（减法），如果是对应的排列组合，一加一减操作完整个数组应该还是`0`的，这个方法的时间复杂度只有`O(n)`

#### 代码一（快排）

```c++
class Solution {
public: 
    int partition(string& a, int low, int high)
    {
        char pivot = a[low];
        while(low < high)
        {
            while(low < high && a[high] >= pivot)   high--;
            a[low] = a[high];
            while(low < high && a[low] <= pivot)    low++;
            a[high] = a[low];
        }
        a[low] = pivot;
        return low;
    }
    void quick_sort(string& v, int low, int high)
    {
        if(low < high)
        {
            int pos = partition(v, low, high);
            quick_sort(v, low, pos-1);
            quick_sort(v, pos+1, high);
        }
    }
    bool isAnagram(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if(len1 != len2)     return false;
        quick_sort(s, 0, len1 - 1);
        quick_sort(t, 0, len2 - 1);
        for(int i=0;i<len1;i++)
        {
            if(s[i] != t[i])    return false;
        }
        return true;
    }
};
```

#### 代码二（哈希表法）

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashtable(26,0);
        for(int i=0;i<s.size();i++)
            hashtable[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
            hashtable[t[i]-'a']--;
        for(auto i: hashtable)
            if(i != 0)  return false;
        return true;
    }
};
```

