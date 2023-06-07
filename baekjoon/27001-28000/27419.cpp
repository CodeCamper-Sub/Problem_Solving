#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll h, w, H, W;
vector<vector<char>> source_grid, target_grid;
vector<pair<ll, ll>> source_coins, target_coins;

void rotate(ll h) { // 돌리기 전 현재 세로 길이
  // ny = x;
  // nx = h - y;
  for(auto &[y, x]: source_coins) {
    ll ny = x, nx = h - y;
    y = ny; x = nx;
  }
}

pair<ll, ll> check_pre(ll& dy, ll& dx) {
  ll i = 0, j = 0, cnt = 0;
  pair<ll, ll> result = {-1, -1};
  dy = source_coins[0].first - target_coins[0].first;
  dx = source_coins[0].second - target_coins[0].second;
  i = 1; j = 1;
  while(i < source_coins.size() && j < target_coins.size()) {
    if(dy == source_coins[i].first - target_coins[j].first && dx == source_coins[i].second - target_coins[j].second) {
      i++; j++;
      continue;
    }
    cnt++;
    if(cnt == 1) {
      result.first = i;
      result.second = target_coins.size() - 1;
      i++;
    } else if(cnt == 2) {
      result.second = j;
      j++;
    } else {
      result = {-1, -1};
      break;
    }
  }

  if(result.first != -1 && result.second != -1) return result;
  dy = source_coins[1].first - target_coins[0].first;
  dx = source_coins[1].second - target_coins[0].second;
  result = {0, target_coins.size() - 1};
  cnt = 1; i = 2; j = 1;
  while(i < source_coins.size() && j < target_coins.size()) {
    if(dy == source_coins[i].first - target_coins[j].first && dx == source_coins[i].second - target_coins[j].second) {
      i++; j++;
      continue;
    }
    cnt++;
    if(cnt == 2) {
      result.second = j;
      j++;
    } else {
      result = {-1, -1};
      break;
    }
  }

  return result;
}

pair<ll, ll> check_post(ll& dy, ll& dx) {
  ll i = 0, j = 0, cnt = 0;
  pair<ll, ll> result = {-1, -1};
  dy = source_coins[0].first - target_coins[0].first;
  dx = source_coins[0].second - target_coins[0].second;
  i = 1; j = 1;
  while(i < source_coins.size() && j < target_coins.size()) {
    if(dy == source_coins[i].first - target_coins[j].first && dx == source_coins[i].second - target_coins[j].second) {
      i++; j++;
      continue;
    }
    cnt++;
    if(cnt == 1) {
      result.second = j;
      result.first = source_coins.size() - 1;
      j++;
    } else if(cnt == 2) {
      result.first = i;
      i++;
    } else {
      result = {-1, -1};
      break;
    }
  }

  if(result.first != -1 && result.second != -1) return result;
  dy = source_coins[0].first - target_coins[1].first;
  dx = source_coins[0].second - target_coins[1].second;
  result = {source_coins.size() - 1, 0};
  cnt = 1; i = 1; j = 2;
  while(i < source_coins.size() && j < target_coins.size()) {
    if(dy == source_coins[i].first - target_coins[j].first && dx == source_coins[i].second - target_coins[j].second) {
      i++; j++;
      continue;
    }
    cnt++;
    if(cnt == 2) {
      result.first = i;
      i++;
    } else {
      result = {-1, -1};
      break;
    }
  }

  return result;
}

pair<ll, ll> check_in(ll& dy, ll& dx) {
  ll i = 0, j = 0, cnt = 0;
  pair<ll, ll> result = {-1, -1};
  dy = source_coins[0].first - target_coins[0].first;
  dx = source_coins[0].second - target_coins[0].second;
  i = 1; j = 1;
  while(i < source_coins.size() && j < target_coins.size()) {
    if(dy == source_coins[i].first - target_coins[j].first && dx == source_coins[i].second - target_coins[j].second) {
      i++; j++;
      continue;
    }
    cnt++;
    if(cnt == 1) {
      result.first = i;
      result.second = j;
      i++; j++;
    } else {
      result = {-1, -1};
      break;
    }
  }

  if(result.first != -1 && result.second != -1) return result;
  dy = source_coins[1].first - target_coins[1].first;
  dx = source_coins[1].second - target_coins[1].second;
  result = {0, 0};
  cnt = 1; i = 2; j = 2;
  while(i < source_coins.size() && j < target_coins.size()) {
    if(dy == source_coins[i].first - target_coins[j].first && dx == source_coins[i].second - target_coins[j].second) {
      i++; j++;
      continue;
    }
    result = {-1, -1};
    break;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  source_grid.assign(h, vector<char>(w));
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> source_grid[i][j];
      if(source_grid[i][j] == 'o') {
        source_coins.push_back({i, j});
      }
    }
  }

  cin >> H >> W;
  target_grid.assign(H, vector<char>(W));
  for(ll i = 0; i < H; i++) {
    for(ll j = 0; j < W; j++) {
      cin >> target_grid[i][j];
      if(target_grid[i][j] == 'o') {
        target_coins.push_back({i, j});
      }
    }
  }

  assert(source_coins.size() > 1);

  sort(target_coins.begin(), target_coins.end());
  ll a, b, dy, dx;
  ll k;
  for(k = 0; k < 4; k++) {
    sort(source_coins.begin(), source_coins.end()); // O(NlogN)
    tie(a, b) = check_pre(dy, dx);
    if(a != -1 && b != -1) break;

    tie(a, b) = check_post(dy, dx);
    if(a != -1 && b != -1) break;

    tie(a, b) = check_in(dy, dx);
    if(a != -1 && b != -1) break;

    if(k + 1 < 4) {
      rotate(k % 2 ? w : h); // O(N)
    }
  }
  
  assert(a != -1);
  assert(b != -1);

  pair<ll, ll> source = source_coins[a];
  pair<ll, ll> target = target_coins[b];
  target.first += dy;
  target.second += dx;
  source_coins.clear();
  source_coins.push_back(source);
  source_coins.push_back(target);

  while(k < 4) {
    rotate(k % 2 ? w : h);
    k++;
  }

  assert(source_coins[0].first >= 0);
  assert(source_coins[0].first < h);
  assert(source_coins[0].second >= 0);
  assert(source_coins[0].second < w);


  cout << source_coins[0].second << ' ' << source_coins[0].first << '\n';
  cout << source_coins[1].second << ' ' << source_coins[1].first << '\n';
  
  return 0;
}