#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (long double)1e19
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int64, int64> PII;
typedef vector<int64> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int64, int64> MPII;
typedef set<int64> SETI;
typedef multiset<int64> MSETI;

typedef long double ld;

template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}

int64 N, M;
int64 arr[201][201];
int64 dp[201][201];
int64 rows[201][201];
int64 cols[201][201];
int64 solve() { return 1; }

int main() {
  cin >> N >> M;

  REP(i, N) {
    REP(j, M) { cin >> arr[i][j]; }
  }

  int64 res = -1;

  REP(i, N) {
    rows[i][0] = 0;
    REP(j, M) { rows[i][j + 1] += rows[i][j] + arr[i][j]; }
  }

  REP(j, M) {
    cols[j][0] = 0;
    REP(i, N) { cols[j][i + 1] += cols[j][i] + arr[i][j]; }
  }

  dp[0][0] = 0;
  REP(i, N) {
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  REP(i, N) {
    REP(j, M) {
      dp[i + 1][j + 1] = dp[i][j] + arr[i][j] + rows[i][j] + cols[j][i];
    }
  }

  // REP(i, N + 1) {
  //   REP(j, M + 1) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }

  REP(i, N) {
    REP(j, M) { int64 val = dp[i][j]; }
  }

  REP(i, N) {
    REP(j, M) {
      for (int64 i2 = i; i2 < N; i2++) {
        for (int64 j2 = j; j2 < M; j2++) {
          int64 nums5 =
              dp[i2 + 1][j2 + 1] - dp[i2+1][j] - dp[i][j2+1] + dp[i][j];


          if (nums5 / 5 == (i2 + 1 - i) * (j2 + 1 - j) / 2) {
            amax(res, nums5 / 5);
              //         cout << i << " " << j << " " << i2 << " " << j2 << " " << nums5
              //  << endl;
          }
        }
      }
    }
  }
  if (res <= 0) {
    cout << "No possible chip" << endl;
  } else {
    cout << res*2 << endl;
  }

  return 0;
}
