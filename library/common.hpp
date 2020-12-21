#ifndef SOLUTION_COMMON_H

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Pii = pair<int, int>;
template<typename T> using V = vector<T>;
using Vi = V<int>;
#define _1 first
#define _2 second
#define all(x) x.begin(), x.end()
#define pb push_back
#define lb lower_bound
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
#define tmax(_next, _prev, expr) if (_prev != INF) { auto prev = _prev; amax(_next, expr); }
#define tmin(_next, _prev, expr) if (_prev != INF) { auto prev = _prev; amin(_next, expr); }
#define dim2(a, b, init) vector(a, vector(b, init))
#define dim3(a, b, c, init) vector(a, vector(b, vector(c, init)))
#define dim4(a, b, c, d, init) vector(a, vector(b, vector(c, vector(d, init))))

#ifndef M_PI
static const double M_PI = acos(-1.0);
#endif

#ifdef MY_DEBUG
# define DEBUG(x) x
const bool isDebug = true;
#else
# define DEBUG(x)
const bool isDebug = false;
#endif

template<class A, class B>
std::ostream & operator <<(ostream &os, const pair<A, B> &p) {
  os << "(" << p._1 << "," << p._2 << ")";
  return os;
}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const V<bool> &x) {for (auto i : x) cerr << i;}
template<typename T>
void __print(const set<T> &x) {int f = 0; cerr << '{'; for (auto const &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '('; __print(x.first); cerr << ','; __print(x.second); cerr << ')';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto const &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef MY_DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


template<class T>
string join(T &A, string delimiter = " ") {
  ostringstream os;
  int i = 0;
  for (const auto &a : A) {
    if (i > 0) os << delimiter;
    os << a;
    i++;
  }
  return os.str();
}

template <typename T>
istream& operator>>(istream& in, vector<T> &A) {
  for (int i = 0; i < A.size(); i++) {
    in >> A[i];
  }
  return in;
}

template <typename T = int>
tuple<V<T>, V<T>> na2(istream& in, int N, int add = 0) {
  auto res = make_tuple(V<T>(N), V<T>(N));
  for (int i = 0; i < N; ++i) {
    in >> get<0>(res)[i] >> get<1>(res)[i];
    get<0>(res)[i] += add;
    get<1>(res)[i] += add;
  }
  return res;
}


template <typename T = int>
V<V<T>> nm(istream& in, int N, int M, int add = 0) {
  auto res = dim2(N, M, 0);
  for (int i = 0; i < N; ++i) {
    in >> res[i];
    if (add) {
      for (auto &a : res[i]) {
        a += add;
      }
    }
  }
  return res;
}

template <typename T>
inline T floorDiv(T num, T d) {
  if (num >= 0) {
    return num / d;
  } else {
    T res = num / d;
    if (num % d) --res;
    return res;
  }
}

template<typename T>
inline T min2(T a, T b) {
  return min(a, b);
}
template<typename T>
inline T max2(T a, T b) {
  return max(a, b);
}


#define SOLUTION_COMMON_H

#endif //SOLUTION_COMMON_H