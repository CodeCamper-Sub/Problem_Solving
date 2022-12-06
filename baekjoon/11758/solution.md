# CCW

[문제 링크](https://www.acmicpc.net/problem/11758)

## 문제를 푸는 데 필요한 배경지식

<br />

### 1. [두 벡터의 외적](https://codecamper.me/blog/138/)

<br />
<br />

## 문제 풀이

세 점 A, B, C에 대해 $\vec{AB}\times\vec{AC}$의 결과는 2가지 정보를 담고 있습니다.

> 1. 외적의 크기 = $\vec{AB}$와 $\vec{AC}$를 두 변으로 하는 평행사변형의 넓이
> 2. 외적의 부호 = 외적이 양(+)의 값이라면 A, B, C는 순서대로 반시계 방향으로 위치해 있고, 음(-)의 값이라면 순서대로 시계 방향으로 위치해 있습니다. 마지막으로 0이라면, 세 점은 한 직선 위에 위치해 있습니다.

위의 두 가지 정보 중 외적의 부호를 통해 이 문제를 해결할 수 있습니다.

<br />
<br />

풀이 코드

```CPP
#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

Point p[3];

ll cross_product(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 0; i < 3; i++) {
    cin >> p[i].x >> p[i].y;
  }

  ll ccw = cross_product(p[0], p[1], p[2]);

  if(ccw > 0) {
    cout << 1 << '\n';
  } else if (ccw == 0) {
    cout << 0 << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
```
