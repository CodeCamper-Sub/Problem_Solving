#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct MinSeg {
  vector<ll> tree, arr;
  ll root, start, end;
  MinSeg(vector<ll> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size() - 1;
    build_tree(root, start, end);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = min(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return INF;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }
};

ll n, answer;
vector<ll> a, psum;
map<ll, vector<ll>> inv;
MinSeg* seg;

ll get_sum(ll left, ll right) {
  return psum[right] - (left > 0 ? psum[left - 1] : 0);
}

void divide_conquer(ll left, ll right) {
  ll mini = seg->query(left, right);
  answer = max(answer, mini * get_sum(left, right));
  auto lower = lower_bound(inv[mini].begin(), inv[mini].end(), left);
  auto upper = upper_bound(inv[mini].begin(), inv[mini].end(), right);
  for(auto iter = lower; iter != upper; iter++) {
    if(iter == lower) {
      if(left <= *iter - 1) {
        divide_conquer(left, *iter - 1);
      }
    } else {
      if(*(iter - 1) + 1 <= *iter - 1) {
        divide_conquer(*(iter - 1) + 1, *iter - 1);
      }
    }
    
    if(iter + 1 == upper && *iter + 1 <= right) {
      divide_conquer(*iter + 1, right);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  psum.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    psum[i] = a[i] + (i > 0 ? psum[i - 1] : 0);
  }

  seg = new MinSeg(a);

  for(ll i = 0; i < n; i++) {
    inv[a[i]].push_back(i);
  }

  answer = -INF;
  divide_conquer(0, n - 1);

  cout << answer << '\n';
  
  return 0;
}