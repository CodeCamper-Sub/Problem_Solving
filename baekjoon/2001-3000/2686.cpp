#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Byte {
  char bit[2];
  
  bool operator==(const Byte& rhs) {
    return bit[0] == rhs.bit[0] && bit[1] == rhs.bit[1];
  }
  
  bool operator!=(const Byte& rhs) {
    return !(*this == rhs);
  }
};

istream& operator>> (istream& cin, Byte& b) {
  cin >> b.bit[0] >> b.bit[1];
  return cin;
}

ll tt, b;
vector<Byte> d, answer;

char to_bit(ll n) {
  if(n <= 9) {
    return '0' + n;
  } else {
    return 'A' + n - 10;
  }
}

ll to_num(char c) {
  if(c >= '0' && c <= '9') return c - '0';
  else return c - 'A' + 10;
}

void random_init() {
  b = rand() % 5000 + 1;
  d.resize(b);
  answer.clear();
  char pool[16];
  for(ll i = 0; i <= 9; i++) pool[i] = '0' + i;
  for(ll i = 10; i <= 15; i++) pool[i] = 'A' + i - 10;
  for(ll i = 0; i < b; ) {
    Byte random_byte = {pool[rand() % 15], pool[rand() % 15]};
    ll num = 1;
    if(rand() % 4 == 0) {
      num = rand() % 300 + 1;
    } else {
      num = rand() % 2 + 1;
    }
    for(ll j = 0; j < num && i < b; j++) {
      d[i] = random_byte;
      i++;
    }
  }
}

void init() {
  cin >> b;
  d.resize(b);
  answer.clear();
  for(Byte& b: d) cin >> b;
}

void solve() {
  deque<pair<Byte, ll>> q;
  for(ll i = 0; i < b; i++) {
    if(q.size() && q.back().first == d[i]) {
      q.back().second += 1;
    } else {
      q.push_back({d[i], 1});
    }
    if(i == b - 1 || (d[i] != d[i + 1] && q.back().second >= 3) || q.back().second >= 130) {
      queue<Byte> prefix_d;
      while(q.size() && q.front().second < 3) {
        if(q.front().second == 1) {
          prefix_d.push(q.front().first);
          q.pop_front();
        } else {
          prefix_d.push(q.front().first);
          q.front().second -= 1;
        }
        if(prefix_d.size() >= 128) {
          answer.push_back({'7', 'F'});
          while(prefix_d.size()) {
            answer.push_back(prefix_d.front());
            prefix_d.pop();
          }
        }
      }
      if(prefix_d.size()) {
        ll cnt = prefix_d.size() - 1;
        answer.push_back({to_bit(cnt / 16), to_bit(cnt % 16)});
        while(prefix_d.size()) {
          answer.push_back(prefix_d.front());
          prefix_d.pop();
        }
      }
      if(q.size()) {
        ll cnt = q.front().second - 3;
        answer.push_back({to_bit(8 + (cnt / 16)), to_bit(cnt % 16)});
        answer.push_back(q.front().first);
        q.pop_front();
      }
    }
  }
  cout << answer.size() << '\n';
  for(ll i = 0; i < answer.size(); i++) {
    cout << answer[i].bit[0] << answer[i].bit[1];
    if(i == answer.size() - 1 || (i + 1) % 40 == 0) {
      cout << '\n';
    }
  }
}

void decode_answer() {
  vector<Byte> decoded;
  for(ll i = 0; i < answer.size(); i++) {
    if(to_num(answer[i].bit[0]) >= 8) {
      // run
      for(ll j = 0; j < (to_num(answer[i].bit[0]) - 8) * 16 + to_num(answer[i].bit[1]) + 3; j++) {
        decoded.push_back(answer[i + 1]);
      }
      i++;
    } else {
      // prefix
      for(ll j = 1; j <= to_num(answer[i].bit[0]) * 16 + to_num(answer[i].bit[1]) + 1; j++) {
        decoded.push_back(answer[i + j]);
      }
      i += to_num(answer[i].bit[0]) * 16 + to_num(answer[i].bit[1]) + 1;
    }
  }
  for(ll i = 0; i < d.size(); i++) {
    if(decoded[i] != d[i]) {
      cout << "HACKED!!!!";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  srand(time(NULL));

  cin >> tt;
  while(tt--) {
    // random_init();
    init();
    solve();
    // decode_answer();
  }
  
  return 0;
}