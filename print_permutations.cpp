/*
    GIVEN: AN ARRAY OF SIZE 'n'
    TO DO: PRINT ALL THE POSSIBLE PERMUTATIONS
    SPACE -> O(n)  || TIME -> O(n! * n)
    PROBLEM -> https://leetcode.com/problems/permutations/
    Eg:
    INPUT -> 
    3
    [1,2,3]
    OUTPUT -> 
    [1,2,3]
    [1,3,2]
    [2,1,3]
    [2,3,1]
    [3,1,2]
    [3,2,1]
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

void helper(vector<int> nums,vector<vector<int>> &res,vector<int>&curr_per,map<int,bool>&vis);

vector<vector<int>> permute(vector<int> &nums){
	vector<vector<int>> res;
	vector<int> curr_per;
	map<int,bool> vis;
	helper(nums,res,curr_per,vis);
	curr_per.clear(); vis.clear();
	return res;
}
void helper(vector<int> nums,vector<vector<int>> &res,vector<int>&curr_per,map<int,bool>&vis){
	if(curr_per.size() == nums.size()){
		res.push_back(curr_per);
		return;
	}// base case, a permutation of size 'n' recieved 

	for(int i=0;i<nums.size();i++){
		if(vis[i])		
			continue;
		vis[i] = true;
		curr_per.push_back(nums[i]);
		helper(nums,res,curr_per,vis);
		vis[i] = false;
		curr_per.pop_back();
	}
}


void print(vector<vector<int>>res){
	for(auto i:res){
		cout << "[";
		for(auto j:i)
			cout << j << ",";
		cout << "]" << endl;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &i:nums)
		cin >> i;
	auto res = permute(nums);
	print(res);
}
