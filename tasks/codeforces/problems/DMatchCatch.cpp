#include "../../../library/common.hpp"

const int MOD = 1000000007;

struct Node {
  unordered_map<int, int> chars;
  VI cnt;
  int len;
  char c;

  Node(int len, char c): cnt(2), len(len), c(c) {}
};

class DMatchCatch {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S1, S2;
    in >> S1 >> S2;

    V<Node> tri;
    tri.push_back(Node(0, ' '));

    auto step = [&](string &s, int ix) {
      VI cur;
      for (int i = 0; i < s.length(); ++i) {
        cur.push_back(0);
        for (int j = 0; j < cur.size(); ++j) {
          auto &node = tri[cur[j]];
          int c = s[i]-'a';
          int next;
          if (node.chars.count(c) == 0) {
            next = tri.size();
            node.chars[c] = next;
            tri.push_back(Node(node.len + 1, 'a'+c));
          } else {
            next = node.chars[c];
          }
          cur[j] = next;
          tri[next].cnt[ix]++;
        }
      }
    };

    step(S1, 0);
    step(S2, 1);

    DEBUG(
        for (int i = 0; i < tri.size(); ++i) {
          debug("%d %c %d %d %d", i, tri[i].c, tri[i].len, tri[i].cnt[0], tri[i].cnt[1]);
        }
        )

    int INF = 1e9;
    int mn = INF;
    for (int i = 0; i < tri.size(); ++i) {
      if (tri[i].cnt[0] == 1 && tri[i].cnt[1] == 1) {
        mn = min(mn, tri[i].len);
      }
    }
    if (mn == INF) out << -1;
    else out << mn;
  }
};
