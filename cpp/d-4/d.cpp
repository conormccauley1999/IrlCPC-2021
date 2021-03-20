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

int64 N, G, P;

VI get_diff(VI a, VI b) {
  VI diff;
  diff.resize(a.size());
  REP(i, a.size()) {
    diff[i] = a[i] - b[i];
    // cout << diff[i] << " ";
  }
  return diff;
}

void printv(VI a) {
  REP(i, a.size()) { cout << a[i] << " "; }
  cout << endl;
}

bool checkP(VI diff, VI pos) {
  int64 same = 1;
  REP(i, pos.size() - 1) {
    if (abs(diff[i]) != abs(diff[i + 1])) {
      same = 0;
      break;
    }
  }
  if (same == 1 && abs(diff[0]) == 1) {
    return true;
  }

  return false;
}

bool checkR(VI diff, VI pos, VI wk_pos, int64 wk, int64 p,
            vector<VI> positions) {
  int64 c = 0;
  int64 dim = -1;
  REP(i, pos.size()) {
    if (diff[i] != 0) {
      c++;
      dim = i;
    }
  }
  if (c == 1) {
    bool possible = true;
    REP(pp, positions.size()) {
      if (pp != wk && pp != p) {
        VI dif2 = get_diff(wk_pos, positions[pp]);
        // printv(dif2);
        int64 c2 = 0;
        int64 dim2 = -1;
        REP(i, pos.size()) {
          if (dif2[i] != 0) {
            c2++;
            dim2 = i;
          }
        }
        if (c2 != 1 || dim != dim2) {
          // cout << "here" << endl;
          continue;
        }

        if (diff[dim] > 0 && dif2[dim] > 0 && diff[dim] > dif2[dim]) {
          possible = false;
        } else if (diff[dim] < 0 && dif2[dim] < 0 && diff[dim] < dif2[dim]) {
          possible = false;
        }
      }
    }
    return possible;
  }
  return false;
}

bool checkk(VI diff, VI pos) {
  int64 one = 0;
  int64 two = 0;
  REP(i, pos.size()) {
    if (abs(diff[i]) == 1) {
      one++;
    }
    if (abs(diff[i]) == 2) {
      two++;
    }

    if (one == 1 && two == 1) {
      return true;
    }
  }
  return false;
}
bool checkB(VI diff, VI pos, VI wk_pos, int64 wk, int64 p,
            vector<VI> positions) {
  int64 same = 1;
  REP(i, pos.size() - 1) {
    if (abs(diff[i]) != abs(diff[i + 1])) {
      same = 0;
      break;
    }
  }
  if (same == 1) {
    bool possible = true;
    REP(pp, positions.size()) {
      if (pp != wk && pp != p) {
        VI dif2 = get_diff(wk_pos, positions[pp]);
        // printv(dif2);
        int64 same2 = 1;
        REP(i, pos.size() - 1) {
          if (abs(dif2[i]) != abs(dif2[i + 1])) {
            same2 = 0;
            break;
          }
        }
        REP(i, pos.size()) {
          if (dif2[i] * diff[i] < 0) {
            same2 = 0;
            break;
          }
        }
        if (same2 == 1) {
          if (abs(diff[0]) > abs(dif2[0])) {
            possible = false;
          }
        }
      }
    }
    return possible;
  }
  return false;
}

bool check(vector<VI> positions, int64 wk, int64 p, int64 piece) {
  VI wk_pos = positions[wk];
  VI pos = positions[p];
  VI diff;
  diff.resize(wk_pos.size());

  REP(i, pos.size()) { diff[i] = wk_pos[i] - pos[i]; }
  // printv(diff);

  if (piece == 'P') {
    return checkP(diff, wk_pos);
  } else if (piece == 'R') {
    return checkR(diff, pos, wk_pos, wk, p, positions);
  } else if (piece == 'k') {
    int64 one = 0;
    int64 two = 0;
    REP(i, pos.size()) {
      if (abs(diff[i]) == 1) {
        one++;
      }
      if (abs(diff[i]) == 2) {
        two++;
      }

      if (one == 1 && two == 1) {
        return true;
      }
    }
  } else if (piece == 'B') {
    return checkB(diff, pos, wk_pos, wk, p, positions);

  } else if (piece == 'Q') {
    if (checkP(diff, pos) || checkR(diff, pos, wk_pos, wk, p, positions) ||
        checkB(diff, pos, wk_pos, wk, p, positions)) {
      return true;
    }
  }
  return false;
}

bool check2(int64 wk, int64 bk, vector<string> names, vector<VI> positions) {
  if (wk >= 0) {
    for (int64 p = positions.size() - 1; p >= 0; p--) {
      if (p == wk) {
        continue;
      }
      string name = names[p];
      char colour = name[0];
      char piece = name[1];

      if (colour == 'B') {
        if (check(positions, wk, p, piece)) {
          return true;
        }
      } else {
      }
    }
  }
  if (bk >= 0) {
    for (int64 p = positions.size() - 1; p >= 0; p--) {
      if (p == bk) {
        continue;
      }
      string name = names[p];
      char colour = name[0];
      char piece = name[1];

      if (colour == 'W') {
        if (check(positions, bk, p, piece)) {
          return true;
        }
      } else {
      }
    }
  }
  return false;
}

void solve(int64 wk, int64 bk, vector<string> names, vector<VI> positions) {
  VI del;
  del.resize(positions[0].size());
  REP(i, del.size()) { del[i] = 10e11; }

  vector<bool> can_move;
  // can_move.resize(positions[0].size());
  // for (int64 p = positions.size() - 1; p >= 0; p--) {
  //   string name = names[p];
  //   char colour = name[0];
  //   char piece = name[1];
  //   VI old{positions[p]};
  //   names[p] = "XXX";
  //   positions[p] = del;

  //   if (colour == 'B') {
  //     can_move[p] = (check2(-1, bk, names, positions));
  //   } else {
  //     can_move[p] = (check2(wk, -1, names, positions));
  //   }
  //   names[p] = name;
  //   positions[p] = old;
  // }

  if (wk >= 0) {
    for (int64 p = positions.size() - 1; p >= 0; p--) {
      if (p == wk ) {
        continue;
      }
      string name = names[p];
      char colour = name[0];
      char piece = name[1];

      if (colour == 'B') {
        if (check(positions, wk, p, piece)) {
          VI old{positions[p]};
          names[p] = "XXX";
          positions[p] = del;

          if (!(check2(-1, bk, names, positions))) {
            cout << "WHITE CHECK FROM " << name << endl;
            return;
          }

          names[p] = name;
          positions[p] = old;
        }
      } else {
      }
    }
  }
  if (bk >= 0) {
    for (int64 p = positions.size() - 1; p >= 0; p--) {
      if (p == bk ) {
        continue;
      }
      string name = names[p];
      char colour = name[0];
      char piece = name[1];

      if (colour == 'W') {
        if (check(positions, bk, p, piece)) {
          cout << "BLACK CHECK FROM " << name << endl;
          return;
        }
      } else {
      }
    }
  }
  cout << "NO CHECK" << endl;
}

int main() {
  cin >> N >> G;

  REP(g, G) {
    cin >> P;
    int64 wk = -1;
    int64 bk = -1;
    vector<VI> positions;
    vector<string> names;

    REP(p, P) {
      positions.resize(P);
      names.resize(P);
      string name;
      VI pos;
      pos.resize(N);
      cin >> name;
      if (name == "WK") {
        wk = p;
      }
      if (name == "BK") {
        bk = p;
      }
      names[p] = name;
      REP(n, N) { cin >> pos[n]; }
      positions[p] = pos;
    }
    solve(wk, bk, names, positions);
  }

  return 0;
}
