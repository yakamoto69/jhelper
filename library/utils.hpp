#include "common.hpp"

// あえて型固定。Viが渡ってきてもllで返すのでoverflowしない
template <typename T>
inline ll sumOf(V<T> const &A) {
  ll s = 0;
  for (int i : A) s += i;
  return s;
}

inline V<ll> cum_sum(Vi const &A) {
  V<ll> res(A.size() + 1);
  res[0] = 0;
  for (int i = 0; i < A.size(); ++i) {
    res[i + 1] = res[i] + A[i];
  }
  return res;
}

template <typename T>
inline T maxOf(V<T> const &A) {
  return *std::max_element(all(A));
}

template <typename T>
inline T minOf(V<T> const &A) {
  return *std::min_element(all(A));
}

inline void remove(Vi &A, int x) {
  A.erase(std::remove(all(A), x), A.end());
}

template<typename T>
inline void sortAndUnique(V<T> &A) {
  sort(all(A));
  A.erase(unique(all(A)), A.end());
}

template<typename T>
inline int lbi(V<T> const &A, T const &x) {
  return lb(all(A), x) - A.begin();
}

/**
 * multisetのキーをiterateする方法
 */
void unique(std::multiset<int> const &A, const function<void(int)>& f) {
  for (auto it = A.begin(); it != A.end(); it = std::upper_bound(it, A.end(), *it)) {
    f(*it);
  }
}

inline bool within(int a, int until, int from = 0) {
  return from <= a && a < until;
}