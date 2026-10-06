#include <vector>

using namespace std;

// 26. 删除有序数组中的重复项
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
// 标签: 数组 / 双指针
// 难度: 简单
//
// 
//暴力算法:
//  复杂度: 时间 O(n2) / 空间 O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==nums[i])
                {
                    nums.erase(nums.begin()+j);
                    j--;
                }
            }
        }
        return nums.size();
    }
};
//双指针（快慢指针）
//
//  复杂度: 时间 O(n) / 空间 O(1)
//思路：慢指针指向目标数组的终点位置，快指针遍历数组，当快指针指向元素与慢指针指向不一致时将快指针指向元素添加到目标数组末端
class Solution_2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(nums[j]!=nums[i])
            nums[++j]=nums[i];
        }
        return j+1;
    }
};
//还有能适用保留k个元素的版本，思路是固定保留前k个元素，之后如果第n个元素与第n-k个元素不同则保留
