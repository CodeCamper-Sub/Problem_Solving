//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;

ll n, s_x, s_y, t_x, t_y, s, t;
ll x[3030];
ll y[3030];
ll r[3030];
bool visited[3030];
vector<ll> e[3030];
queue<ll> q;

bool is_on_s(ll i);
bool is_on_t(ll i);
bool is_adjacent(ll i, ll j);

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> s_x >> s_y >> t_x >> t_y;
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> r[i];
    if(is_on_s(i)) {
      s = i;
    }
    if(is_on_t(i)) {
      t = i;
    }
  }
  for(int i = 1; i < n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(is_adjacent(i, j)) {
        e[i].push_back(j);
        e[j].push_back(i);
      }
    }
  }
  
  visited[s] = true;
  q.push(s);
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    for(int i = 0; i < e[now].size(); i++) {
      ll next = e[now][i];
      if(!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
  if(visited[t] == true) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}

bool is_on_s(ll i) {
  ll x_pow = (x[i] - s_x) * (x[i] - s_x);
  ll y_pow = (y[i] - s_y) * (y[i] - s_y);
  ll squared_distance = x_pow + y_pow;
  ll squared_r = r[i] * r[i];
  if(squared_distance == squared_r) {
    return true;
  } else {
    return false;
  }
}

bool is_on_t(ll i) {
  ll x_pow = (x[i] - t_x) * (x[i] - t_x);
  ll y_pow = (y[i] - t_y) * (y[i] - t_y);
  ll squared_distance = x_pow + y_pow;
  ll squared_r = r[i] * r[i];
  if(squared_distance == squared_r) {
    return true;
  } else {
    return false;
  }
}

bool is_adjacent(ll i, ll j) {
  ll x_pow = (x[i] - x[j]) * (x[i] - x[j]);
  ll y_pow = (y[i] - y[j]) * (y[i] - y[j]);
  ll squared_distance = x_pow + y_pow;
  ll squared_r_sum = r[i]*r[i] + 2*r[i]*r[j] + r[j]*r[j];
  ll squared_r_difference = r[i]*r[i] - 2*r[i]*r[j] + r[j]*r[j];
  if(squared_distance > squared_r_sum) {
    return false;
  } else if(squared_r_difference > squared_distance) {
    return false;
  } else {
    return true;
  }
}

