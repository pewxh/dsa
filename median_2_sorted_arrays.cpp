/*
    GIVEN: 2 INDIVIDUALLY SORTED ARRAYS OF SIZE 'n' AND 'm' RESPECTIVELY.
    TO DO: FIND THE MEDIAN 
    SPACE -> O(1)  || TIME -> O(log(min(n,m)))
    PROBLEM -> https://leetcode.com/problems/median-of-two-sorted-arrays/
    Eg:
    INPUT -> 
	4 5
	2 3 5 8
	1 10 12 14 20
    OUTPUT -> 
    8
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>&arr1,vector<int>&arr2){
	if(arr1.size() > arr2.size())
		arr1.swap(arr2); // arr1 is never supposed to be greater than arr2 , for our algo to work properly.
	double median = 0; 
	int n = arr1.size(),m = arr2.size();
	int l_size = (n+m+1)/2; // size of the left partition
	int low = 0 , high = n;
	while(low <= high){
		int mid = (low+high)/2; 
		int cut_arr1 = mid , cut_arr2 = l_size - cut_arr1; // array cuts to split the arrays to complete left and right partitions.
		int l1,l2,r1,r2;
		l1 = (cut_arr1) ? arr1[cut_arr1-1] : INT_MIN;
		l2 = (cut_arr2) ? arr2[cut_arr2-1] : INT_MIN;
		r1 = (cut_arr1 < n) ? arr1[cut_arr1] : INT_MAX;
		r2 = (cut_arr2 < m) ? arr2[cut_arr2] : INT_MAX;

		if(l1 > r2)
			high = mid - 1;
		else if(l2 > r1)
			low = mid + 1;
		else{
			if((n+m)%2)
				median = max(l1,l2);
			else
				median = (max(l1,l2) + min(r1,r2))/2.0;
			break;
		} 
	}
	return median;
}

int main(){
	int n , m;
	cin >> n >> m;
	vector<int> arr1(n), arr2(m);
	for(auto &i:arr1)
		cin >> i;
	for(auto &i:arr2)
		cin >> i;
	cout << findMedianSortedArrays(arr1,arr2);
	return 0;
}