#include <vector>
#include <unordered_map>

using namespace std;

// 1. 两数之和
// https://leetcode.cn/problems/two-sum/
// 标签: 数组 / 哈希表
// 难度: 简单
//
// 
//暴力算法:
//  复杂度: 时间 O(n2) / 空间 O(1)

class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        int n = (int)nums.size();
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {};
    };
};

//两遍哈希表：一遍迭代将元素插入哈希表，一遍迭代查找目标元素并返回下标
//复杂度: 时间 O(n) / 空间 O(n)


class Solution_2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int n = (int)nums.size();
        unordered_map <int,int> mp;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        for(i=0;i<n;i++)
        {
            if(mp.count(target-nums[i])&&mp[target-nums[i]]!=i)
            {
                return {i,mp[target-nums[i]]};
            }
        }

        return {};
        
    }
};

//一遍哈希表：迭代插入元素同时查询已插入的元素内是否有目标元素
//复杂度: 时间 O(n) / 空间 O(n)

class Solution_3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int n = (int)nums.size();
        unordered_map <int,int> mp;
        for(i=0;i<n;i++)
        {
            if(mp.count(target-nums[i]))
            {
                return {i,mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
       
        return {};
        
    }
};
