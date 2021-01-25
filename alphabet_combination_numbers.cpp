/*
    GIVEN: A POSITIVE INTEGER
    NOTE: { 1 , 2 , 3 ... 26 } --> { a , b , c ... z }
    TO DO: PRINT ALL THE POSSIBLE COMBINATION OF LETTERS BY REPLACING DIGIT(S) BY THEIR RESPECTIVE ALPHABETIC VALUE GIVEN ABOVE
    Eg:
    INPUT -> 
    1223
    OUTPUT -> 
    abbc
    abv
    avc
    kbc
    kv
*/

#include<iostream>
#include<string>
using namespace std;

void solve(string,int , int , string);
int main(){
    string num;
    cin >> num; //STORING THE NUMBER IN A STRING
    solve(num,0,num.size(),"");
    return 0;
} 
void solve(string num , int curr , int n, string str){
    if(curr == n){
        cout << str << "\n";
        return;
    }// BASE CONDITION: NO FURTHER COMBINATION CAN BE FORMED.
    int valid_alpha = 0;   
     for(int i = curr; i < n ; i++){
        valid_alpha = valid_alpha * 10 + num[curr] - '0'; 
        if(valid_alpha < 27) // IF AN ALPHABET CAN BE FORMED USING 1 OR 2 DIGITS
            solve(num,i+1,n,str + (char)('a' + valid_alpha - 1)); // CHECK THE COMBINATION FOR OTHER DIGITS AND APPEND THE RESULTANT ALPHA AT LAST
    }
}