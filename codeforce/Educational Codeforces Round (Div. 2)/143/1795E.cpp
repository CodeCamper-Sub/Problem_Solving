#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> h, psum;

ll get_sum(ll from, ll to) {
  if(from == 0) return psum[to];
  else return psum[to] - psum[from - 1];
}

void init() {
  cin >> n;
  h.resize(n);
  psum.resize(n);
  for(ll& h: h) cin >> h;
}

void make_left(const vector<ll>& from, vector<ll>& to, ll at_most) {
  stack<ll> s;
  for(ll i = from.size() - 1; i--; i >= 0) {
    if(at_most > from[i]) {
      s.push(from[i]);
      at_most = from[i];
    } else {
      s.push(at_most - 1);
      at_most -= 1;
    }
    if(at_most == 1) break;
  }
  vector<ll> result;
  while(s.size()) {
    to.push_back(s.top());
    s.pop();
  }
}

void make_right(const vector<ll>& from, vector<ll>& to, ll at_most) {
  for(ll i = 0; i < from.size(); i++) {
    if(at_most > from[i]) {
      to.push_back(from[i]);
      at_most = from[i];
    } else {
      to.push_back(at_most - 1);
      at_most -= 1;
    }
    if(at_most == 1) break;
  }
}

tuple<vector<ll>*, vector<ll>*, vector<ll>*> divide_conquer(ll l, ll r) {
  vector<ll> left, right, center;
  if(l == r) {
    left.push_back(h[l]);
    right.push_back(h[l]);
    center.push_back(h[l]);
    return {&left, &center, &right};
  }
  ll mid = (l + r) / 2;
  auto [a, b, c] = divide_conquer(l, mid);
  auto [d, e, f] = divide_conquer(mid + 1, r);

  make_left(*a, left, d->front());
  for(ll i = 0; i < d->size(); i++) {
    left.push_back((*d)[i]);
  }

  for(ll i = 0; i < b->size(); i++) {
    right.push_back((*b)[i]);
  }
  make_right(*e, right, b->back());

  

  return {&left, &center, &right};
}

void solve() {
  psum[0] = h[0];
  for(ll i = 1; i < n; i++) {
    psum[i] = psum[i - 1] + h[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}