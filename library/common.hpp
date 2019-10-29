#ifndef SOLUTION_COMMON_H

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using PI = pair<int, int>;
template<class T> using V = vector<T>;
using VI = V<int>;
#define _1 first
#define _2 second

#ifdef MY_DEBUG
# define DEBUG(x) x
#else
# define DEBUG(x)
#endif

template<class A, class B>
std::ostream & operator <<(ostream &os, const pair<A, B> &p) {
  os << "(" << p._1 << "," << p._2 << ")";
  return os;
}

template<class T>
inline void debug(T &A) {
  DEBUG(
      for (const auto &a : A) {
        cerr << a << " ";
      }
      cerr << '\n';
  )
}

template<class T, class Func>
inline void debug_with_format(T &A, Func f) {
  DEBUG(
      for (const auto &a : A) {
        cerr << f(a) << " ";
      }
      cerr << '\n';
  )
}

template<class T>
inline void debug_dim2(T &A) {
  DEBUG(
      for (const auto &as : A) {
        debug(as);
      }
  )
}

template<typename ... Args>
inline void debug(const char *format, Args const &... args) {
  DEBUG(
      fprintf(stderr, format, args ...);
      cerr << '\n';
  )
}

template<typename ... Args>
string format(const string &fmt, Args ... args) {
  size_t len = snprintf(nullptr, 0, fmt.c_str(), args ...);
  vector<char> buf(len + 1);
  snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
  return string(&buf[0], &buf[0] + len);
}

template<class T1, class T2>
string fmtP(pair<T1, T2> a) {
  stringstream ss;
  ss << "(" << a._1 << "," << a._2 << ")";
  return ss.str();
}

#define SOLUTION_COMMON_H

#endif //SOLUTION_COMMON_H