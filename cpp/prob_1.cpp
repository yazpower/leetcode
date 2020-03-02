/*

    1. Two Sum

    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    vector<int> twoSum_(vector<int>& v, int target){
        // O(nlogn) : only for sorted array, doesn't work here
        int l = 0; 
        int r = v.size() - 1;
        while(l <= r){
            int x = v[l] + v[r];
            if( x == target){
                return {l, r};
            }else if( x < target){
                l++;
            }else{
                r--;
            }
        }
        return {};
    }   
    
    vector<int> twoSum(vector<int>& v, int target) {
        // O(n)
        std::unordered_map<int,int> hash;
        std::vector<int> r;
        for(int i = 0; i < v.size(); i++){
            int x = target - v[i];
            if(hash.find(x)!= hash.end()){
                r = {hash[x], i};
            }
            hash[v[i]] = i;
        }
        return r;
    }
};

