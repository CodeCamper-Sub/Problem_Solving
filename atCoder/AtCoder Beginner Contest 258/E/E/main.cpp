//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n, q, x, w[200200], k;
ll sum[200200], start, left_bound, right_bound, now, x_left, potatos, cycle_start_index, k_prime;
bool visited[200200];
vector<pair<ll, ll>> boxes;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> q >> x;
  for(int i = 1; i <= n; i++) {
    cin >> w[i];
    sum[i] = sum[i-1] + w[i];
  }
  
  visited[1] = true;
  start = 1;
  while(true) {
    now = start;
    x_left = x;
    potatos = 0;
    while(x_left > sum[n] - sum[now-1]) {
      x_left -= sum[n] - sum[now-1];
      potatos += n - now + 1;
      now = 1;
    }
    ll left_bound = now;
    ll right_bound = n;
    while(left_bound <= right_bound) {
      ll mid = (left_bound + right_bound) / 2;
      if(x_left <= sum[mid] - sum[now-1]) {
        right_bound = mid - 1;
      } else {
        left_bound = mid + 1;
      }
    }
    potatos += left_bound - now + 1;
    boxes.push_back({start, potatos});
    ll next = left_bound + 1;
    if(visited[next] == true) {
      for(ll i = 0; i < boxes.size(); i++) {
        if(boxes[i].first == next) {
          cycle_start_index = i;
        }
      }
      break;
    } else {
      visited[next] = 1;
      start = next;
    }
  }
  
  for(ll i = 1; i <= q; i++) {
    cin >> k;
    if(k <= boxes.size()) {
      k_prime = k - 1;
    } else {
      k_prime = k - boxes.size() - 1;
      k_prime = cycle_start_index + k_prime % (boxes.size() - cycle_start_index);
    }
    cout << boxes[k_prime].second << '\n';
  }
  
  
  return 0;
}

