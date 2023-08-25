#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

string s;
ll a, b, c;
vector<vector<vector<vector<vector<vector<ll>>>>>> visited; // {2개 전, 1개 전, 남은 a, 남은 b, 남은 c, 현재 위치}

bool backtracking(ll now, ll a, ll b, ll c, string& path) {
  if(now == s.size()) {
    cout << path << '\n';
    return true;
  }
  ll pp, p;
  if(path.size() >= 2) {
    pp = path[path.size() - 2] - 'A';
    p = path.back() - 'A';
  } else if(path.size() == 1) {
    pp = 3;
    p = path.back() - 'A';
  } else {
    pp = 3;
    p = 3;
  }
  if(visited[pp][p][a][b][c][now]) return false;
  visited[pp][p][a][b][c][now] = true;

  bool result = false;
  if(a > 0) {
    path.push_back('A');
    result |= backtracking(now + 1, a - 1, b, c, path);
    path.pop_back();
  }
  if(result) return result;

  if(b > 0 && p != 1) {
    path.push_back('B');
    result |= backtracking(now + 1, a, b - 1, c, path);
    path.pop_back();
  }
  if(result) return result;

  if(c > 0 && p != 2 && pp != 2) {
    path.push_back('C');
    result |= backtracking(now + 1, a, b, c - 1, path);
    path.pop_back();
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(char k: s) {
    if(k == 'A') a++;
    else if(k == 'B') b++;
    else c++;
  }

  visited.resize(4);
  for_each(visited.begin(), visited.end(), [](auto& pcube) {
    pcube.resize(4);
    for_each(pcube.begin(), pcube.end(), [](auto& hcube) {
      hcube.resize(a + 1);
      for_each(hcube.begin(), hcube.end(), [](auto& cube) {
        cube.resize(b + 1);
        for_each(cube.begin(), cube.end(), [](auto& layer) {
          layer.assign(c + 1, vector<ll>(s.size(), false));
        });
      });
    });
  });

  string path = "";
  if(!backtracking(0, a, b, c, path)) {
    cout << -1 << '\n';
  }

  
  return 0;
}