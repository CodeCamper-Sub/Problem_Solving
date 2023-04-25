#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

vector<ll> get_pi(const vector<ll>& from) {
  vector<ll> pi(from.size(), 0);
  ll j = 0;
  for(ll i = 1; i < from.size(); i++) {
    while(j > 0 && from[i] != from[j]) j = pi[j - 1];
    if(from[i] == from[j]) j++;
    pi[i] = j;
  }
  return pi;
}

bool kmp(const vector<ll>& pi, const vector<ll> t, const vector<ll> p) {
  ll j = 0;
  for(ll i = 0; i < t.size(); i++) {
    while(j > 0 && t[i] != p[j]) 
      j = pi[j - 1];
    if(t[i] == p[j]) j++;
    if(j == p.size()) return true;
  }
  return false;
}

ll n, k, t;
vector<vector<ll>> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  m.assign(2 * n, vector<ll>());
  for(ll i = 0; i < n; i++) {
    cin >> t;
    m[i].resize(t);
    m[n + i].resize(t);
    for(ll j = 0; j < t; j++) {
      cin >> m[i][j];
      m[n + i][t - j - 1] = m[i][j];
    }
  }

  for(ll i = 0; i <= ll(m[0].size()) - k; i++) {
    bool is_possible = true;
    vector<ll> p;
    for(ll j = i; j < i + k; j++) {
      p.push_back(m[0][j]);
    }
    vector<ll> pi = get_pi(p);
    for(ll j = 1; j < n; j++) {
      if(kmp(pi, m[j], p) || kmp(pi, m[j + n], p)) continue;
      is_possible = false;
      break; 
    }
    if(is_possible) {
      cout << "YES\n";
      return 0;
    }
    
    reverse(p.begin(), p.end());
    pi = get_pi(p);
    for(ll j = 1; j < n; j++) {
      if(kmp(pi, m[j], p) || kmp(pi, m[j + n], p)) continue;
      is_possible = false;
      break; 
    }
    if(is_possible) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  
  return 0;
}