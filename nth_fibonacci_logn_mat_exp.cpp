/*
    GIVEN: A POSITIVE INTEGER 'n'
    TO DO: FIND THE n-th FIBONACCI NUMBER IN LOG(n) TIME USING MATRIX EXPONENTIATION
    Eg: 
    INPUT ->
    19
    OUTPUT -> 
    4181
    HINT/REF -> https://www.youtube.com/watch?v=nN8Tk70-DOc
*/

#include<iostream>
#define ll long long
#define MOD 1000000007
using namespace std;

ll** identityMatrix(ll n);// returns an identity matrix of size (n x n)
ll** matrixMul(ll**,ll**,ll,ll,ll,ll); // returns result, A x B
ll** matrixPow(ll**,ll,ll); // returns result, matrix x(n x n) raised to the power y
void matrixPrint(ll** m,int r,int c);

int main(){
    int n,res; 
    cin >> n; 
    //0 1 1 2 3 5 8 13 21
    ll **mat = new ll*[2];
    mat[0] = new ll[2]{1,1};
    mat[1] = new ll[2]{1,0};
    ll** mat_n = matrixPow((ll **)mat,n-1,2);
    // matrixPrint(mat_n,2,2);
    res = (mat_n[1][0] + mat_n[1][1]) % MOD;
    if(n==0)  res = 0;
    cout << res;
    return 0;
}

ll** matrixPow(ll **x,ll y,ll n){
    if(!y){
        return identityMatrix(n);
    } // base case
    ll **temp = matrixPow(x,y/2,n);
    ll **res = matrixMul(temp,temp,n,n,n,n);
    if(y%2)
        return matrixMul(res,x,2,2,2,2);
    return res;
}

ll** identityMatrix(ll n){
    ll** res = new ll *[n];
    for(int i=0;i<n;i++){
        ll *temp = new ll[n];
        for(int j=0;j<n;j++)
            temp[j] = 0;
        temp[i] = 1;
        res[i] = temp;
    }
    return res;
}

ll** matrixMul(ll** A,ll** B,ll r1,ll c1,ll r2, ll c2){
    ll** res = new ll*[r1];
    for(int i=0;i<r1;i++){
        ll* temp = new ll[c2];
        for(int j=0;j<c2;j++)
            temp[j] = 0;
        res[i] = temp;
    }
    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
                res[i][j] += (A[i][k] % MOD * B[k][j] % MOD) % MOD;
    return res;
}


void matrixPrint(ll** m,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}