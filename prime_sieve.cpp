/*  GIVEN: AN INTEGER 'n'
    TO DO: COUNT AND PRINT ALL THE PRIMES LESS THAN 'n'
    SPACE -> O(N) | TIME -> O(NloglogN)
    EG:
    INPUT  -> 
    10
    OUTPUT ->
    4
    2 3 5 7
*/

//-------> SIEVE OF ERATOSTHENES <-------
#include<iostream>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;

int checkPrime(int n){
    // if(n > 2)
    for(int i = 2 ; i * i <= n ; i++)
        if(!(n % i))
            return 0;
    return ( n > 1) ;
} // returns 1 if the number 'n' is prime

set<int> sieveOfEratosthenes(int n){
    set<int> primes;
    int *sieve= new int[n + 1]; // sieve[i] = 1 , if i is a prime and vice versa
    sieve[0] = sieve[1] = 0; // 0 and 1 are non - primes
    for(int i=2;i<= n;i++)
        sieve[i] = 1; // initially every number from 2 to sqrt(n) is marked as prime
    for(int i=2;i<=n;i++){
        if(sieve[i]){
            if(checkPrime(i)){
                primes.insert(i); 
                for(int j = i*i ; j <= n; j += i)
                    sieve[i] = 0;
            }
        }
    }
    delete [] sieve;
    return primes;
}


int main(){
    int n;
    cin >> n;
    set<int> primes = sieveOfEratosthenes(n);
    cout << primes.size() << "\n"; 
    for(auto i:primes)
        cout << i << " ";
    return 0;
}