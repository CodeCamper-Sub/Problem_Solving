//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, c, x, answer;
vector<ll> list_a, list_a_sum;
vector<ll> list_b, list_b_sum;

void brute_force_list_a(ll index, ll sum) {
  if(index == list_a.size() - 1) {
    list_a_sum.push_back(sum + list_a[index]);
    list_a_sum.push_back(sum);
    return;
  }
  brute_force_list_a(index+1, sum + list_a[index]);
  brute_force_list_a(index+1, sum);
}

void brute_force_list_b(ll index, ll sum) {
  if(index == list_b.size() - 1) {
    list_b_sum.push_back(sum + list_b[index]);
    list_b_sum.push_back(sum);
    return;
  }
  brute_force_list_b(index+1, sum + list_b[index]);
  brute_force_list_b(index+1, sum);
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> c;
  for(ll i = 0; i <= n/2; i++) {
    cin >> x;
    list_a.push_back(x);
  }
  for(ll i = n/2 + 1; i < n; i++) {
    cin >> x;
    list_b.push_back(x);
  }
  if(list_a.size() > 0) {
    brute_force_list_a(0, 0);
  } else {
    list_a_sum.push_back(0);
  }
  if(list_b.size() > 0) {
    brute_force_list_b(0, 0);
  } else {
    list_b_sum.push_back(0);
  }
  sort(list_a_sum.begin(), list_a_sum.end());
  for(ll i = 0; i < list_b_sum.size(); i++) {
    auto iter = upper_bound(list_a_sum.begin(), list_a_sum.end(), c-list_b_sum[i]);
    iter--;
    answer += distance(list_a_sum.begin(), iter) + 1;
  }
  
  cout << answer << '\n';
  
  return 0;
}

