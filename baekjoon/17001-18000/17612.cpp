#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Counter {
  ll id, sum = 0;
  Counter(ll id): id(id) { }


  struct Compare {
    bool operator()(Counter &a, Counter &b) {
      return a.sum != b.sum ? a.sum > b.sum : a.id > b.id;
    }
  };
};

struct Customer {
  ll id, counter, out;
  Customer(ll id, ll counter, ll out): id(id), counter(counter), out(out) { }

  struct Compare {
    bool operator()(Customer &a, Customer &b) {
      return a.out != b.out ? a.out > b.out : a.counter < b.counter;
    }
  };
};

priority_queue<Counter, vector<Counter>, Counter::Compare> q1;
priority_queue<Customer, vector<Customer>, Customer::Compare> q2;
ll n, k, id, w;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  for(ll i = 1; i <= k; i++) {
    q1.push(Counter(i));
  }

  while(n--) {
    Counter c = q1.top();
    q1.pop();
    cin >> id >> w;
    q2.push(Customer(id, c.id, c.sum + w));
    c.sum += w;
    q1.push(c);
  }

  ll answer = 0;
  ll k = 1;
  while(q2.size()) {
    answer += q2.top().id * k;
    q2.pop();
    k++;
  }

  cout << answer << '\n';
  
  return 0;
}