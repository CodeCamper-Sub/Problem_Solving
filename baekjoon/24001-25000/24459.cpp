#define INF 999999999999
#define mp make_pair

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int check_leaf[100005], v[100005];
long long get_max[100005][3], get_min[100005][3];
vector<pair<int, long long> > adj[100005];
queue <int> q;

struct{
  int node, parent;
  long long val;
}path[100005];

void bfs(int st){
  int cnt = 0, now, next;
  long long next_val;
  q.push(st);
  cnt++;
  path[cnt].node = st, path[cnt].val = 0, path[cnt].parent = 0, v[st] = 1;
  while(!q.empty()){
    now = q.front();
    q.pop();
    for(int j = 0; j < adj[now].size(); j++){
      next = adj[now][j].first;
      next_val = adj[now][j].second;
      if(!v[next]){
        v[next] = 1;
        q.push(next);
        cnt++;
        path[cnt].node = next, path[cnt].val = next_val, path[cnt].parent = now;
      }
    }
  }
}

int main()
{
  int p, q, root_idx, now, parent;
  long long w, ans_max=0, ans_min=INF, max_value, min_value;
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N;
  
  for(int i = 1; i < N; i++){
    cin >> p >> q >> w;
    p++, q++;
    adj[p].push_back(mp(q, w));
    adj[q].push_back(mp(p, w));
    check_leaf[p]++, check_leaf[q]++;
  }

  for(int i=1; i<=N; i++){
    if(check_leaf[i]>1){
      root_idx = i;
      break;
    }
  }
  bfs(root_idx);
  for(int i=1; i<=N; i++){
    get_max[i][1]=get_max[i][2] = 0;
    get_min[i][1]=get_min[i][2] = INF;
  }

  for(int i=N; i>=1; i--){
    now = path[i].node;
    parent = path[i].parent;
  
    if(check_leaf[now] == 1){
      max_value = min_value = path[i].val;
    }else{
      max_value = get_max[now][1] + path[i].val;
      min_value = get_min[now][1] + path[i].val;
    }
        
    if(get_max[parent][1] < max_value){
      get_max[parent][2] = get_max[parent][1];
      get_max[parent][1] = max_value;
    }else if(get_max[parent][2] < max_value){
      get_max[parent][2] = max_value;
    }

    if(get_min[parent][1] > min_value){
      get_min[parent][2] = get_min[parent][1];
      get_min[parent][1] = min_value;
    }else if(get_min[parent][2] > min_value){
      get_min[parent][2] = min_value;
    }

    if(get_min[now][1] !=INF && get_min[now][2] !=INF && get_min[now][1]+get_min[now][2] < ans_min){
      ans_min = get_min[now][1]+get_min[now][2];
    }

    if(get_max[now][1] !=0 && get_max[now][2] !=0 && get_max[now][1]+get_max[now][2] > ans_max){
      ans_max = get_max[now][1]+get_max[now][2];
    }
  }

  cout << ans_max << endl << ans_min;
  return 0;
}
