#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

string s;
ll n;

using Edge = tuple<ll, ll, ll>;
vector<vector<vector<Edge>>> e;
vector<vector<tuple<ll, ll, ll>>> tracking;
vector<vector<bool>> visited;

string int_to_string(ll a) {
  if(a == 0) return "00";
  else if(a < 10) return "0" + to_string(a);
  else return to_string(a);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  n = s.size();

  e.assign(n + 1, vector<vector<Edge>>(n + 1));
  tracking.assign(n + 1, vector<tuple<ll, ll, ll>>(n + 1));
  visited.assign(n + 1, vector<bool>(n + 1, false));
  for(ll i = 0; i <= n; i++) {
    for(ll j = 0; j <= n; j++) {
      for(ll k = 0; k < 100; k++) {
        if(k == 0) {
          if(i == n || j == n) continue;
          if(s[i] == '0' && s[n - j - 1] == '0') {
            e[i][j].push_back({i + 1, j + 1, 0});
          }
        } else if(k < 10) { // 0X
          if(i == n) continue;
          if(s[i] == '0' + k) {
            e[i][j].push_back({i + 1, j, k});
          }
        } else if(k % 10 == 0) { // X0
          if(j == n) continue;
          if(s[n - j - 1] == '0' + (k / 10)) {
            e[i][j].push_back({i, j + 1, k});
          }
        } else {
          if(i == n || j == n) continue;
          ll a = k / 10;
          ll b = k % 10;
          bool is_valid = true;
          for(ll u = 0; u < b; u++) {
            if(i + u - a < 0 || i + u - a >= n) {
              is_valid = false;
              break;
            }
            if(i + u < 0 || i + u >= n) {
              is_valid = false;
              break;
            }
            if(s[i + u - a] != s[i + u]) {
              is_valid = false;
              break;
            }
          }
          for(ll u = 0; u < a; u++) {
            if(n - j - u - 1 - b < 0 || n - j - u - 1 - b >= n) {
              is_valid = false;
              break;
            }
            if(n - j - u - 1 < 0 || n - j - u - 1 >= n) {
              is_valid = false;
              break;
            }
            if(s[n - j - u - 1 - b] != s[n - j - u - 1]) {
              is_valid = false;
              break;
            }
          }
          if(is_valid) {
            e[i][j].push_back({i + b, j + a, k});
          }
        }
      }
    }
  }

  queue<pair<ll, ll>> q;
  tracking[0][0] = {-1, -1, -1};
  visited[0][0] = true;
  q.push({0, 0});
  while(q.size()) {
    auto [y, x] = q.front();
    q.pop();
    if(y == n && x == n) break;
    for(auto [ny, nx, k]: e[y][x]) {
      if(!visited[ny][nx]) {
        visited[ny][nx] = true;
        tracking[ny][nx] = {y, x, k};
        q.push({ny, nx});
      }
    }
  }

  auto [y, x, k] = tracking[n][n];
  string answer = "";
  while(y != -1 && x != -1) {
    string s_k = int_to_string(k);
    reverse(s_k.begin(), s_k.end());
    answer += s_k;
    tie(y, x, k) = tracking[y][x];
  }
  reverse(answer.begin(), answer.end());

  cout << answer << '\n';

  
  return 0;
}