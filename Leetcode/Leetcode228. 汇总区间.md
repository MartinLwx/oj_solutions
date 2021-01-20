#### 题意

有序序列，将每个有序小区间表示出来

#### 思路

- 主要是用双指针进行模拟，每次定出有序小区间的开头和末尾，将其转换为字符串进行处理

- ⚠️
  - 1⃣️双指针注意都不要越界访问了非法地址
  - 2⃣️小区间长度为1和不为1是用不同的字符串表示的

#### 代码

```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int cur1 = 0, cur2 = 0;
        while(cur1 < nums.size()){
            cur2++;
            //1.跑在前面的指针如果刚好超出，说明[cur1, nums.size() - 1]这个是一个有序小区间
            //2.或者是到了另一个有序区间的开头
            if(cur2 == nums.size() ||  nums[cur2] != nums[cur2 - 1] + 1){
                string tmp = "";
                if(nums[cur1] != nums[cur2 - 1]){
                    tmp += to_string(nums[cur1]);
                    tmp += "->";
                    tmp += to_string(nums[cur2 - 1]);
                    ans.emplace_back(tmp); 
                }else{
                    tmp = to_string(nums[cur1]);
                    ans.emplace_back(tmp);
                }
                cur1 = cur2;
                if(cur2 >= nums.size()) break;   //说明已经处理完了要退出循环
            }
        }
        return ans;
    }
};
```

