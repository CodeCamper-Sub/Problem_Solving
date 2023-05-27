#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<vector<ll>> answer;

unsigned long long generateRandomNumber(unsigned long long max_value)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis(1, max_value);

    return dis(gen);
}

void init() {
  cin >> n;
  // n = generateRandomNumber(1000);
}

bool solution(ll k, ll n, ll c) {
  while(n) {
    ll d = n % 10;
    d = (d - c + 10) % 10;
    if(d > 3 * k) return false;
    if((d < k && d + 10 > 3 * k)) return solution(d, n, c);

    if(n < k) {
      answer.push_back(vector<ll>(d, 1));
      c = 0;
    } else if(d + c >= 10 || d < k) {
      answer.push_back(vector<ll>(k, 1));
      if(d + c < 10) d += 10;
      d -= k;
      for(ll i = 0; i < k; i++) {
        if(d >= 2) {
          answer.back()[i] += 2;
          d -= 2;
        } else if(d == 1) {
          answer.back()[i] += 1;
          d -= 1;
        } else {
          break;
        }
      }
      c = 1;
    } else {
      answer.push_back(vector<ll>(k, 1));
      d -= k;
      for(ll i = 0; i < k; i++) {
        if(d >= 2) {
          answer.back()[i] += 2;
          d -= 2;
        } else if(d == 1) {
          answer.back()[i] += 1;
          d -= 1;
        } else {
          break;
        }
      }
      c = 0;
    }
    
    n /= 10;
  }
  
  return c == 0;
}

void validate() {
  #ifdef LOCAL
  ll k = 1;
  ll sum = 0;
  for(ll i = 0; i < answer.size(); i++) {
    for(ll j = 0; j < answer[i].size(); j++) {
      sum += answer[i][j] * k;
    }
    k *= 10;
  }

  if(sum != n) {
    cout << "???\n";
  }

  #endif
}

void solve() {
  for(ll i = 1; i <= 5; i++) {
    answer.clear();
    if(solution(i, n, 0)) {
      cout << i << '\n';
      break;
    }
  }

  validate();
  
  return;
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