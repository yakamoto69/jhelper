#include "common.hpp"

template <typename T = int>
class Zip {
    V<T> zip;
public:
    int operator()(T v) {
      return lb(all(zip), v) - zip.begin();
    }

    T operator[](int i) {
      return zip[i];
    }

    int size() {
      return zip.size();
    }

    void push_back(T a) {
      zip.pb(a);
    }

    void build() {
      sort(all(zip));
      zip.erase(unique(all(zip)), zip.end());
    }
};