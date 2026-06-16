// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = k % (nums.size());
        int new_k = nums.size() - temp;
        reverse(nums.begin(), nums.begin() + new_k);
        reverse(nums.begin() + new_k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

//rotating an array k steps right means rotating it n-k times left 