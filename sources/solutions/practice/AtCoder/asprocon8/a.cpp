#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
const long long INF = 1LL << 60;

using Item = pair<int, int>;

struct Edge {
  size_t to; int cost;
  Edge(size_t t, int w) : to(t), cost(w) {}
};

template <class T>
using Graph = std::vector<std::vector<T>>;

using P = pair<long, int>;

// input
int H, S, C, a, b;
vector<int> K;
vector<vector<int> > N, A, B;

void read_input() {
    cin >> S >> C >> H >> a >> b;
    N.resize(S);
    for (int s = 0; s < S; s++) {
        N[s].resize(C);
        for (int c = 0; c < C; c++) cin >> N[s][c];
    }
    K.resize(S);
    for (int s = 0; s < S; s++) cin >> K[s];
    A.resize(S);
    for (int s = 0; s < S; s++) {
        A[s].resize(S);
        for (int t = 0; t < S; t++) cin >> A[s][t];
    }
    B.resize(C);
    for (int c = 0; c < C; c++) {
        B[c].resize(C);
        for (int d = 0; d < C; d++) cin >> B[c][d];
    }
}

void write_output(const vector<pair<int, int> > &ans) {
    cout << ans.size() << '\n';
    for (int i = 0; i < int(ans.size()); i++) {
        if (ans[i].first >= 0) {
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
        } else {
            cout << ans[i].first << '\n';
        }
    }
}

int itemVal(int s, int c) {
  return s*C + c;
}

Item itemPair(int v) {
  return Item(v/C, v%C);
}

vector<pair<int, int>> ans;
vector<int> hanger_on_hook;
vector<int> hangers_available;
int pos = 0, prev_s = -1, prev_c = -1;

void assign_item(int s, int c) {
  if (N[s][c] == 0) return;

  // need this amount of empty hooks
  const int setup = (prev_s == -1 ? 0 : max(A[prev_s][s], B[prev_c][c]));
  for (int i = 0; i < setup; i++) {
    ans.emplace_back(-2, 0);
    if (pos == H - 1) pos = 0; else pos++;
  }

  // put (s, c)
  for (int n = 0; n < N[s][c]; ) {
    if (hanger_on_hook[pos] != s and hangers_available[s] == 0) {
    // run out of hangers
    ans.emplace_back(-2, 0);
  	if (pos == H - 1) pos = 0; else pos++;
  } else {
    ans.emplace_back(s, c);
    n++;
    if (hanger_on_hook[pos] != s) {
      if (hanger_on_hook[pos] >= 0) {
        hangers_available[hanger_on_hook[pos]]++;
      }
      hangers_available[s]--;
      hanger_on_hook[pos] = s;
    }
   	if (pos == H - 1) pos = 0; else pos++;
  }
    prev_s = s;
    prev_c = c;
  }
  return;
}

vector<bool> seen;
void race(const Graph<Edge> &G, int v, ll &cost, vector<int>& path) {
  seen[v] = true;
  path.push_back(v);
  ll mc = -1;
  int ne;
  for (auto next_v : G[v]) {
    if (seen[next_v.to]) continue;
    if(mc == -1 || mc > next_v.cost) {
      mc = next_v.cost;
      ne = next_v.to;
    }
  }
  if(mc == -1) return;
  cost += mc;
  race(G, ne, cost, path);
}

int main() {
  read_input();

  hanger_on_hook.assign(H, -1);
  hangers_available = K;

  Graph<Edge> G(S*C);
  for (int s1 = 0; s1 < S; s1++) {
    for (int c1 = 0; c1 < C; c1++) {
      for (int s2 = 0; s2 < S; s2++) {
        for (int c2 = 0; c2 < C; c2++) {
          if(s1 == s2 && c1 == c2) continue;
          int cost = A[s1][s2]*a + B[c1][c2]*b;
          if(s1 != s2) cost += (H-K[s1])*10;
          G[itemVal(s1, c1)].emplace_back(itemVal(s2, c2), cost);
        }
      }
    }
  }

  vector<int> plan;
  ll min_cost = INF;
  for(int i=0; i<1; i++) {
    seen.clear();
    seen.resize(S*C);
    vector<int> path;
  	ll cost = 0;
    race(G, i, cost, path);
    //cout << cost << endl;
    if(min_cost >= cost) {
      plan = path;
      min_cost = cost;
    }
  }
  //cout << cost << endl;
  for(auto& v : plan) {
    Item p = itemPair(v);
    //cout << p.first+1 << "," << p.second+1 << endl;
    assign_item(p.first, p.second);
    //cout << p.first+1 << "," << p.second+1 << endl;
  }

  // write answer
  write_output(ans);
}

