#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (LLONG_MAX / 3)

ll n;
vector<ll> arr;
vector<pair<ll, ll>> asc, desc;
map<ll, ll> answer;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree(ll n) {
    tree.assign(n * 4, 0);
    root = 1;
    start = 0;
    end = n - 1;
  }

  ll query(ll left, ll right) { 
    return query(root, start, end, left, right);
  }

  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  private:
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll delta) {
    if(target < start || end < target) return tree[node];
    else if(start == target) {
      return tree[node] += delta;
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    arr.push_back(x);
    asc.push_back({x, i});
    desc.push_back({x, i});
    answer[x] = true;
  }
  sort(asc.begin(), asc.end());
  sort(desc.begin(), desc.end(), greater<>());

  SegTree asc_seg(n), desc_seg(n);
  for(auto [k, i]: asc) {
    if(asc_seg.query(i, asc_seg.end)) {
      answer[k] = false;
    }
    asc_seg.update(i, 1);
  }

  for(auto [k, i]: desc) {
    if(desc_seg.query(desc_seg.start, i)) {
      answer[k] = false;
    }
    desc_seg.update(i, 1);
  }

  vector<ll> answers;
  for(ll i = 0; i < arr.size(); i++) {
    if(answer[arr[i]]) {
      answers.push_back(arr[i]);
    }
  }

  if(answers.size() == 0) {
    cout << 0;
  } else {
    cout << answers.size() << ' ';
    for(ll i = 0; i < min(ll(answers.size()), ll(100)); i++) {
      cout << answers[i];
      if(i < min(ll(answers.size()), ll(100)) - 1) {
        cout << ' ';
      }
    }
  }
}