/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author emli
 */


#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forx(i, n) for(int i = 1 ; (i) <= (n) ; ++i)
#define ll long long
#define all(x) (x).begin(),(x).end()
#define sqr(x) (x) * (x)
#define debug(x) cout << #x <<" = " << x << endl
#define printvpair(v) for(auto x : v) cout << x.first  <<" " << x.second << endl;
#define printv(v) if (v.size()> 0) {for(auto x : v) cout << x << " "; cout << endl;}
#define MINUS(a) memset(a,0xff,sizeof(a))
#define vertex pair<int,pair<int,int> >
const int N = (int)1e2 + 7;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};

bool isKthBitSet(int n, int k) {
	return static_cast<bool>((n & 1 << k) != 0);
}
string keyOrder = "byrg";

class globalVariables {
public:
	bool used[N][N][(1 << 4) + 1];
	int d[N][N][(1 << 4) + 1];
	char a[N][N];
};
class KeyTask {
public:
	void run(int n,int m){
		auto *g = new globalVariables();
		vector<vector<char> > exits(n,vector<char >(m));
		int x,y, endX = 0, endY = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", g->a[i]);
			for (int j = 0; j < m; ++j) {
				if (g->a[i][j] == '*'){
					x = i;
					y = j;
				}
				if (g->a[i][j] == 'X' || g->a[i][j] == 'x'){
					exits[i][j] = true;
				}
			}
		}
		queue<vertex> queue1;


		vertex temp;
		temp.first = x;
		temp.second.first = y;
		temp.second.second = 0;
		queue1.emplace(temp);
		g->used[x][y][0] = true;
		g->d[x][y][0] = 1;
		int ans = 0;
		while (!queue1.empty()){
			vertex cur = queue1.front();
			queue1.pop();
			for (int i = 0; i < 4; ++i) {
				int x1 = cur.first + dx[i];
				int y1 = cur.second.first + dy[i];
				int keys = cur.second.second;

				if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && g->a[x1][y1] != '#'){
					if (exits[x1][y1]){
						ans = g->d[cur.first][cur.second.first][cur.second.second];
						printf("Escape possible in %d steps.\n", ans);
						return;
					}
					vertex v;
					v.first = x1;
					v.second.first = y1;
					v.second.second = keys;
					if ((g->a[x1][y1] == '.' || g->a[x1][y1] == '*')){
						if (!g->used[x1][y1][keys]){
							queue1.push(v);
							g->used[x1][y1][keys] = true;
							g->d[x1][y1][keys] = g->d[cur.first][cur.second.first][cur.second.second] + 1;
						}
					} else if (islower(g->a[x1][y1])){
						int order = static_cast<int>(keyOrder.find(g->a[x1][y1]));
						if (order != -1){
							keys |= (1 << (order));
						}
						v.second.second = keys;
						if (!g->used[x1][y1][keys]){
							queue1.push(v);
							g->used[x1][y1][keys] = true;
							g->d[x1][y1][keys] = g->d[cur.first][cur.second.first][cur.second.second] + 1;
						}
					} else {
						char key = (char)tolower(g->a[x1][y1]);
						int order = static_cast<int>(keyOrder.find(key));
						if (!g->used[x1][y1][keys] && order != -1 && isKthBitSet(keys,order)){
							g->used[x1][y1][keys] = true;
							queue1.push(v);
							g->d[x1][y1][keys] = g->d[cur.first][cur.second.first][cur.second.second] + 1;
						}
					}
				}
			}
		}
		if (queue1.empty()){
			printf("The poor student is trapped!\n");
		}
	}
	void solve() {
		int n,m;
		while (scanf( "%d %d", &n, &m))
		{
			if (n == 0 && m == 0){
				break;
			}
			run(n,m);
		}
	}
};


int main() {
	KeyTask keyTask;
	keyTask.solve();
	return 0;
}