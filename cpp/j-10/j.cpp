#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>
#include <iomanip>

using namespace std;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (long double)1e19
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int64, int64> PII;
typedef vector<int64> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int64,int64> MPII;
typedef set<int64> SETI;
typedef multiset<int64> MSETI;

typedef long double ld;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int64 N, C;
void solve(){

}

//https://www.geeksforgeeks.org/prime-factor/
VI primeFactors(int n)  
{  
    // Print the number of 2s that divide n  
    VI v;
    while (n%2 == 0)  
    {  
        v.push_back(2);
        n = n/2;  
    }  
    
    // n must be odd at this point.  So we can skip   
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i+2)  
    {  
        // While i divides n, print i and divide n  
        while (n%i == 0)  
        {  
            v.push_back(i);
            n = n/i;  
        }  
    }  
    
    // This condition is to handle the case when n   
    // is a prime number greater than 2  
    if (n > 2)  
        v.push_back(n);

    return v;
}  

int main()
{
  cin >> N >> C; 

  int64 res = N;

  for(int i = 1; i <= N; i++){
    if(N % i == 0){
      int64 a = i;
      int64 b = N / a;
      amin(res, a-1+ceil(b/2));
      cout << a << " " << b <<endl;
    }
  }

  VI v = primeFactors(N);

  // find all C prime sums



  cout << res << endl;

  return 0;
}
