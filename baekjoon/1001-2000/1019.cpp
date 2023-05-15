#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;

vector<vector<ll>> cnt; // 1~10^i-1까지 사용된 각 자리의 개수
vector<ll> answer(10, 0);

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp * a;
  else return temp * temp;
}

ll get_zero_cnt(ll digit) {
  ll result = 0;
  for(ll i = 0; i < digit; i++) {
    result *= 10;
    result += 1;
  }
  return result;
}

void get_cnt(ll digit) {
  if(cnt[digit].size() > 0) return;
  cnt[digit].resize(10, 0);
  if(digit == 1) {
    for(ll i = 1; i <= 9; i++) cnt[digit][i] = 1;
  } else {
    get_cnt(digit - 1); 
    for(ll i = 0; i <= 9; i++) cnt[digit][i] += cnt[digit - 1][i];
    for(ll i = 1; i <= 9; i++) {
      cnt[digit][0] += get_zero_cnt(digit - 1);
      cnt[digit][i] += power(10, digit - 1);
      for(ll j = 0; j <= 9; j++) cnt[digit][j] += cnt[digit - 1][j];
    }
  }
}

void bruteforce() {
  vector<ll> cnt(10, 0);
  for(ll i = 1; i <= n; i++) {
    ll j = i;
    while(j) {
      cnt[j % 10]++;
      j /= 10;
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;

  cnt.resize(floor(log10(n)) + 1);
  cnt[0].resize(10);
  get_cnt(floor(log10(n)));

  vector<ll> decomp;
  ll _n = n;
  while(_n) {
    decomp.push_back(_n % 10);
    _n /= 10;
  }
  reverse(decomp.begin(), decomp.end());
  for(ll i = 0; i < cnt.back().size(); i++) {
    answer[i] = cnt.back()[i];
  }
  for(ll i = 0; i < decomp.size(); i++) {
    for(ll j = 0; j < decomp[i]; j++) {
      if(i == 0 && j == 0) continue;
      answer[0] += get_zero_cnt(cnt.size() - 1 - i);
      answer[j] += power(10, cnt.size() - 1 - i);
      for(ll k = 0; k <= 9; k++) {
        answer[k] += cnt[cnt.size() - i - 1][k];
      }
    }
    answer[decomp[i]] += (n % power(10, cnt.size() - i - 1) + 1);
  }
  
  #ifdef LOCAL
  bruteforce();
  #endif

  for(ll a: answer) {
    cout << a << ' ';
  }
  
  return 0;
}