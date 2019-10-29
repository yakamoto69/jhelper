#include "common.hpp"

class KMP {
private:
  string word;
  VI kmp;

public:
  KMP(const string &w) {
    word = w;
    kmp = {0, 0};
    kmp.resize(w.size() + 1);
    for (int i = 2; i <= word.size(); ++i) {
      // kmp(i-1)以下しか参照されないからOK
      kmp[i] = longestSuffix(kmp[i - 1], word[i - 1]);
    }
  }

  int longestSuffix(int j, char c) {
    while(true) {
      if (j < word.size() && word[j] == c) return j + 1;
      else if (j == 0) return 0;
      else j = kmp[j];
    }
  }

  int find_first(const string &text) {
    int j = 0;
    for (int i = 0; i < text.size(); ++i) {
      j = longestSuffix(j, text[i]);
      if (j == word.size()) return (int)(i - word.size() + 1);
    }
    return -1;
  }
};
