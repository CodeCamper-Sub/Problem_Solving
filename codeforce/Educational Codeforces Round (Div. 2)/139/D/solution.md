# Codeforces 1766D - Lucky Chains

[문제 링크](https://codeforces.com/problemset/problem/1766/D)

## 문제를 푸는 데 필요한 배경지식

<br />

### 1. [에라토스테네스의 체](https://codecamper.me/blog/142/)

<br />
<br />

## 문제 풀이

$10^7$ 이하의 두 수 $x$, $y$를 가지고 나열된 쌍들이 모두 서로소가 될 때 까지만 $(x, y), (x+1, y+1), (x+2, y+2)...$의 형태로 나열했을 때, 가장 긴 배열의 길이를 구하는 문제 입니다.

$x$와 $y$의 차이를 $d$라고 하고, $d$의 약수 중 하나 $k(d = q*k)$에 대해서 다음이 성립합니다.

> $y = x + d = x + q * k$ 이므로,  
> $x$가 $k$의 배수라면, $x + q * k = q' * k + q * k = k(q' + q)$입니다.  
> 즉, $y$도 $k$의 배수입니다. 다시 말해, $k$는 $x$와 $y$의 공약수입니다.

위 성질을 이용해서, $d$의 약수 $k$들을 모두 구한 뒤에, $x$보다 크거나 같은 $k$의 배수들 중 $x$에 가장 가까운 값까지만 $(x, y)$ 쌍을 나열할 수 있음을 알 수 있습니다.

또한, $d$의 약수들 중 합성수인 약수들은 그 약수를 구성하는 소수들 또한 $d$의 약수가 되고, 합성수들의 배수는 소수들의 배수이기도 하므로, $d$의 약수들 중에서 소수인 약수들만 고려하면 됩니다.

따라서 이 문제는,

> $d = y - x$인 $d$를 소인수분해하고,$(p_0, p_1, ..., p_i)$  
> 그 소수들에 대해 $p_i * ((x / p_i) + 1) - x$의 최솟값을 구하는 문제입니다.

$x$와 $y$의 범위가 $10^7$이하이므로, $d$의 범위도 $10^7$이하입니다.  
범위가 그리 크지 않으므로 에라토스테네스의 체를 이용해 소인수분해를 $O(log d)$시간 안에 수행할 수 있습니다.

위 과정을 총 $N(1 \le N \le 10^6)$번 반복하게 되므로, 전체 시간복잡도는 $O(Nlogd)$로, 4초 안에 충분히 해결이 가능합니다.

<br />
<br />

## 풀이 코드

```CPP
#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, x, y, answer, differ;
ll sieve[10001000];
vector<ll> primes;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sieve[1] = -1;
  for(ll i = 2; i <= 10000000; i++) {
    if(sieve[i] == 0) {
      sieve[i] = -1;
      for(ll j = 2; i * j <= 10000000; j++) {
        sieve[i * j] = i;
      }
    }
  }

  cin >> tt;
  while(tt--) {
    cin >> x >> y;
    if(y - x == 1) {
      cout << -1 << '\n';
      continue;
    } else if (gcd(x, y) != 1) {
      cout << 0 << '\n';
      continue;
    }
    answer = INF;
    differ = y - x;
    primes = vector<ll>();
    while(sieve[differ] != -1) {
      primes.push_back(sieve[differ]);
      differ /= sieve[differ];
    }
    if(differ > 1) primes.push_back(differ);
    for(ll i = 0; i < primes.size(); i++) {
      answer = min(answer, primes[i] * ((x / primes[i]) + 1) - x);
    }
    cout << answer << '\n';
  }

  return 0;
}
```
