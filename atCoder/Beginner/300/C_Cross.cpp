#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll h, w;
vector<vector<char>> c;
vector<vector<ll>> visited;
vector<ll> answers;
ll dy[4] = {1, 1, -1, -1};
ll dx[4] = {1, -1, 1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  c.assign(h, vector<char>(w));
  visited.assign(h, vector<ll>(w));
  answers.resize(min(h, w) + 1);
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> c[i][j];
    }
  }
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      if(!visited[i][j] && c[i][j] == '#') {
        ll maxi = 0;
        queue<tuple<ll, ll, ll>> q;
        visited[i][j] = true;
        q.push({0, i, j});
        while(q.size()) {
          auto [d, y, x] = q.front();
          q.pop();
          for(ll k = 0; k < 4; k++) {
            ll ny = y + dy[k], nx = x + dx[k];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w || c[ny][nx] != '#' || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            maxi = max(maxi, d + 1);
            q.push({d + 1, ny, nx});
          }
        }
        answers[maxi / 2]++;
      }
    }
  }

  for(ll i = 1; i < answers.size(); i++) {
    cout << answers[i] << ' ';
  }

  
  return 0;
}