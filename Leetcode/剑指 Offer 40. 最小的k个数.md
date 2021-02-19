#### 题意

如题所示

#### 思路

- 1⃣️题目已经限定了数组中元素的范围，暗示可以使用桶排，最后提交**用时32ms**
- 2⃣️利用快排，快排适合解决的就是最小的k个，第k个这种问题。好处是不用全部排完，只要划分的时候刚好就停在第k个元素就好。所以效率也是很高的，**用时36ms**

#### 代码一（桶排）

```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> buckets(10010, 0);
        for(auto e: arr) {
            buckets[e]++;
        }
        vector<int> ans;
        for(int i=0;i<=10000;i++) {
            while(k > 0 && buckets[i] > 0) {
                ans.emplace_back(i);
                buckets[i]--;
                k--;
            }
            if(k == 0) {
                break;
            }   //如果已经找到了最小的K个数字，就提前退出
        }
        return ans;
    }
};
```

#### 代码二（快排）

```c++
class Solution {
public:
    int partition(vector<int>& arr, int l, int r) {
        int t = arr[l];
        while(l < r) {
            while(l < r && arr[r] >= t)     r--;
            arr[l] = arr[r];
            while(l < r && arr[l] < t)      l++;
            arr[r] = arr[l];
        }
        arr[l] = t;
        return l;
    }
    void quick_sort(vector<int>&arr, int l, int r, int k) {
        if(l < r) {
            int pos = partition(arr, l, r);     //pos的含义我们可以解读为已经找到最小的pos个数
            if(pos > k) {   //大于题目要求
                quick_sort(arr, l, pos - 1, k);
            }else if(pos < k) {     //小于题目要求
                quick_sort(arr, pos + 1, r, k);
            }else {
                return;
            }
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort(arr, 0, arr.size() - 1, k);
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.emplace_back(arr[i]);
        }
        return ans;
    }
};
```

