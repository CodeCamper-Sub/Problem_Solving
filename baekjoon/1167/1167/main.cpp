//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
typedef long long ll;
using namespace std;

ll v, origin, destination, cost;
vector<pair<ll, ll>> e[100100];
bool visited[100100];

pair<ll, ll> query(ll node) {
  priority_queue<ll> distances;
  ll ret = 0;
  ll distance, maximum, local_max;
  maximum = LONG_LONG_MIN;
  for(ll i = 0; i < e[node].size(); i++) {
    ll next = e[node][i].first;
    ll added_distance = e[node][i].second;
    if(!visited[next]) {
      visited[next] = true;
      ll local_max;
      tie(distance, local_max) = query(next);
      distance += added_distance;
      maximum = max(maximum, local_max);
      distances.push(distance);
    }
  }
  if(distances.size() >= 2) {
    ret = distances.top();
    local_max = distances.top();
    distances.pop();
    local_max += distances.top();
    maximum = max(maximum, local_max);
    return {ret, maximum};
  } else if(distances.size() == 1) {
    ret = distances.top();
    local_max = distances.top();
    maximum = max(maximum, local_max);
    return {ret, maximum};
  } else {
    return {0, 0};
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> v;
  for(ll i = 1; i <= v; i++) {
    cin >> origin;
    while(true) {
      cin >> destination;
      if(destination == -1) break;
      cin >> cost;
      e[origin].push_back({destination, cost});
    }
  }
  for(ll i = 1; i <= v; i++) {
    if(e[i].size() >= 2) {
      origin = i;
      break;
    }
  }
  
  visited[origin] = true;
  cout << query(origin).second << '\n';
  
  return 0;
}

