#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll dist[5][5];

ll is_triangle(ll i, ll j, ll k) {  // -1 삼각형 x 0 직선 1 삼각형
  vector<ll> l = {dist[i][j], dist[j][k], dist[k][i]};
  sort(l.begin(), l.end());
  if(l[0] + l[1] > l[2]) return 1;
  else if(l[0] + l[1] == l[2]) return 0;
  else return -1;
}

pair<double, double> calc(ll i, ll j, ll k) { // {높이, i번 점과 k에서 ij 직선에 내린 수선의 발 까지의 좌표}
  double x = double(dist[i][k] * dist[i][k] - dist[k][j] * dist[k][j] + dist[i][j] * dist[i][j]) / double(2 * dist[i][j]);
  double h = sqrt(dist[i][k] * dist[i][k] - x * x);
  return {h, x};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 1; i <= 4; i++) {
    for(ll j = 1; j <= 4; j++) {
      cin >> dist[i][j];
    }
  }

  if(is_triangle(1, 2, 3) == -1 || is_triangle(1, 2, 4) == -1) {
    cout << "NO\n";
  } else {
    auto [h1, x1] = calc(1, 2, 3);
    auto [h2, x2] = calc(1, 2, 4);
    double min_d = (x1 - x2) * (x1 - x2) + (h1 - h2) * (h1 - h2);
    min_d = max(min_d, double(1));
    double max_d = (x1 - x2) * (x1 - x2) + (h1 + h2) * (h1 + h2);
    if(min_d <= dist[3][4] * dist[3][4] && dist[3][4] * dist[3][4] <= max_d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  
  return 0;
}