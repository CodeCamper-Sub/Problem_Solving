#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

struct Segment { 
  ll l = -1, r = -1, now;

  Segment(ll l): l(l) {
    now = l + 1;
  }
  Segment(ll l, ll r): l(l), r(r) {
    now = l;
  }

  bool next() {
    if(r == -1) {
      now++;
      return true;
    } else if(l == r) {
      return false;
    } 
    if(now <= (l + r) / 2) {
      if((l + r) % 2 == 0 && now == (l + r) / 2) return false;
      ll delta = now - l;
      now = r - delta;
      return true;
    } else {
      if((l + r) % 2 == 1 && now == (l + r) / 2 + 1) return false;
      ll delta = r - now;
      now = l + delta + 1;
      return true;
    }
  }

  ll value() {
    if(r == -1) {
      return INF;
    } else if(l == r) {
      return 0;
    } else {
      return (now - l) * (r - now) - 1;
    }
  }
};

struct Compare {
  bool operator()(Segment& a, Segment& b) {
    if(a.value() != b.value()) {
      return a.value() > b.value();
    } else {
      return a.now > b.now;
    }
  }
};

ll l, n;
vector<ll> s;
vector<Segment> segments;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> l;
  s.resize(l);
  for(ll i = 0; i < l; i++) cin >> s[i];
  s.push_back(0);
  sort(s.begin(), s.end());

  for(ll i = 0; i < s.size(); i++) {
    if(segments.empty()) {
      segments.push_back(Segment(s[i]));
    } else {
      if(segments.back().l + 1 < s[i]) {
        segments.back().r = s[i];
      } else {
        segments.pop_back();
      }
      segments.push_back(Segment(s[i], s[i]));
      segments.push_back(Segment(s[i]));
    }
  }

  priority_queue<Segment, vector<Segment>, Compare> q;
  for(ll i = 0; i < segments.size(); i++) q.push(segments[i]);

  cin >> n;
  
  reverse(s.begin(), s.end()); 
  s.pop_back();

  while(n--) {
    Segment seg = q.top(); q.pop();
    cout << seg.now << ' ';
    if(seg.next()) {
      q.push(seg);
    }
  }
  
  return 0;
}