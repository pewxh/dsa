/*
    GIVEN: AN ARRAY OF 'n' INTEGERS
    TO DO: FIND THE MAXIMUM RANGE OF CONSECUTIVE NUMBERS
    Eg: 
    INPUT ->
    9 
    8 10 1 2 3 5 4 6 9
    OUTPUT -> 
    [ 1 , 6 ]
    6
*/

#include<iostream>
#include<unordered_map>
using namespace std;


pair<int,int> maxRange(int *arr,int n){
    unordered_map<int,bool> mp; // HASHTABLE 
    pair<int,int> range; // PAIR WHICH STORES THE LEFT AND RIGHT VALUES OF OUR RESULTANT MAXIMUM RANGE
    for(int i=0;i<n;i++)
        mp[arr[i]] = true; // INTITIALIZE ALL VALUES OF OUR ARRAY TO true 
    int max_range_length = -1; 
    for(int i=0;i<n;i++){
        if(!(mp[arr[i]])) // ELEMENT ALREADY VISITED ONCE, NO NEED TO RE CALCULATE AAGAIN
            continue;
        mp[arr[i]] = false; // MARK ELEMENT AS VISITED
        int left = arr[i] - 1; 
        int right = arr[i] + 1;
        int curr_length = 1;
        while(mp[left]){
            mp[left] = false; // MARK AS VISITED
            left--;
            curr_length++;
        } // FINDS THE LEFT MOST ELEMENT FOR OUR RANGE (- 1) 
        while(mp[right]){
            mp[right] = false;
            right++;
            curr_length++;
        } // FINDS THE RIGHT MOST ELEMENT FOR OUR RANGE (- 1) 
        if(curr_length > max_range_length){
            max_range_length = curr_length; // UPDATE MAX LENGTH 
            range = make_pair(left+1,right-1); // UPDATE RESULT range 
        }
    }
    return range;
}

int main(){
    int n;
    cin >> n; // NUMBER OF ELEMENTS
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin >> arr[i]; // INPUT n ELEMENTS AND STORE THEM IN AN ARRAY
    auto max_range = maxRange(arr,n);
    cout << " [ " << max_range.first << " , " << max_range.second << " ] " << "\n";
    cout << max_range.second - max_range.first + 1; 
    return 0;
}