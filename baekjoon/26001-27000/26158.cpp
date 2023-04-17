#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 500500
typedef long long ll;
using namespace std;

struct Seg {
  vector<pair<ll, ll>> tree;
  vector<pair<ll, ll>> arr;
  ll root, start, end;
  Seg(vector<pair<ll, ll>> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size() - 1;
    build_tree(root, start, end);
  }

  void update(ll target) {
    update(root, start, end, target);
  }

  pair<ll, ll> query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  pair<ll, ll> update(ll node, ll start, ll end, ll target) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      arr[target] = {-INF, -INF};
      return tree[node] = arr[target];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = max(update(node * 2, start, mid, target), update(node * 2 + 1, mid + 1, end, target));
    }
  }
  
  pair<ll, ll> query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return {-INF, -INF};
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }

  pair<ll, ll> build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = max(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
    }
  }
};

ll n, k, d, answer;
vector<pair<ll, ll>> arr;

ll remove_remain(Seg& seg, ll last_solved, ll left, ll right, ll &next_solved) {
  if(left > right) return 0;
  auto [max_d, index] = seg.query(left, right);
  if(max_d <= last_solved) return 0;
  seg.update(-index);
  next_solved = max(next_solved, max_d);
  return 1 + remove_remain(seg, last_solved, left, -index - 1, next_solved);
}

ll next_available(Seg& seg, ll now) {
  if(now == n || seg.arr[now].first != -INF) return 0;
  else return 1 + next_available(seg, now + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  arr.resize(n);
  
  for(ll i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = -i;
  }

  answer = 1;
  Seg seg(arr);
  ll last_solved = seg.arr[0].first;
  seg.update(0);
  ll left = 1, right = min(k, n - 1);
  while(left < n) {
    ll next_solved = -INF;
    ll c = remove_remain(seg, last_solved, left, right, next_solved);
    if(c == 0) {
      ll k = next_available(seg, left - 1);
      left += k;
      right += k;
      right = min(right, n - 1);
      if(left - 1 < n) {
        last_solved = seg.arr[left - 1].first;
        seg.update(left - 1);
        answer++;
      }
    } else {
      right += c;
      right = min(right, n - 1);
      last_solved = next_solved;
    }
  }

  cout << answer << '\n';
  
  return 0;
}