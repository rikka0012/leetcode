#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 217. 存在重复元素
// https://leetcode.cn/problems/contains-duplicate/
// 标签: 数组 / 哈希表 / 排序
// 难度: 简单
//
// 
//哈希表
//  复杂度: 时间 O(n) / 空间 O(n)
//将数组插入哈希表，O(1)查找元素，不存在则存入，存在则返回
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag = false;
        unordered_set <int>st;

        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i])==0)
            st.insert(nums[i]);
            else
            {
            flag=true;
            break;
            }

        }


        return flag;
    }
};
//排序
//
//  复杂度: 时间 O(nlogn) / 空间 O(logn)
//思路：将数组从小到大排序，如果存在相同元素一定相邻，扫描已排序数组的相邻元素即可

class Solution_2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

