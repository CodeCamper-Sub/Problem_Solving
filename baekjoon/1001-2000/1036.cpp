#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

char number_to_char(ll n) {
  if(n <= 9) return '0' + n;
  else return 'A' + n - 10;
}

ll char_to_number(char c) {
  if(c >= '0' && c <= '9') return c - '0';
  else return c - 'A' + 10;
}

struct ThirtySix {
  string s = "";
  
  ThirtySix operator+(const ThirtySix& rhs) {
    ThirtySix result;
    ll c = 0;
    for(ll i = 1; i <= max(s.size(), rhs.s.size()); i++) {
      ll d = c;
      if(s.size() >= i && rhs.s.size() >= i) {
        d += char_to_number(s[s.size() - i]) + char_to_number(rhs.s[rhs.s.size() - i]);
      } else if(s.size() >= i) {
        d += char_to_number(s[s.size() - i]);
      } else if(rhs.s.size() >= i) {
        d += char_to_number(rhs.s[rhs.s.size() - i]);
      }
      c = d / 36;
      d %= 36;
      result.s.push_back(number_to_char(d));
    }
    if(c > 0) {
      result.s.push_back(number_to_char(c));
    }
    reverse(result.s.begin(), result.s.end());
    return result;
  }

  bool operator<(const ThirtySix& rhs) const {
    if(s.size() != rhs.s.size()) return s.size() < rhs.s.size();
    for(ll i = 0; i < s.size(); i++) {
      if(s[i] != rhs.s[i]) return char_to_number(s[i]) < char_to_number(rhs.s[i]);
    }
    return false;
  }

  bool operator>(const ThirtySix& rhs) const {
    return rhs < *this;
  }
};

ll n, k;
vector<ThirtySix> cnt;
vector<ThirtySix> v;
vector<ll> changed_to_z;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  v.resize(n);
  ll max_length = 0;
  for(ll i = 0; i < n; i++) {
    cin>> v[i].s;
    max_length = max(max_length, ll(v[i].s.size()));
  }
  cnt.resize(36);
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < v[i].s.size(); j++) {
      ll len = v[i].s.size();
      ll k = char_to_number(v[i].s[len - 1- j]);
      if(k == 35) continue;
      ThirtySix rhs;
      rhs.s.push_back(number_to_char(35 - k));
      for(ll m = 0; m < j; m++) rhs.s.push_back('0');
      cnt[k] = cnt[k] + rhs;
    }
  }
  vector<pair<ThirtySix, ll>> candidates;
  for(ll i = 0; i < 36; i++) {
    candidates.push_back({cnt[i], i});
  }
  sort(candidates.begin(), candidates.end(), [](auto a, auto b) {
    return a.first > b.first;
  });



  cin >> k;
  changed_to_z.assign(36, false);
  for(ll i = 0; i < k; i++) {
    ll j = candidates[i].second;
    changed_to_z[j] = true;
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < v[i].s.size(); j++) {
      if(changed_to_z[char_to_number(v[i].s[j])]) {
        v[i].s[j] = 'Z';
      }
    }
  }

  ThirtySix answer;
  for(ll i = 0; i < n; i++) {
    answer = answer + v[i];
  }

  cout << answer.s << '\n';
  
  return 0;
}