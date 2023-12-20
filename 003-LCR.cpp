#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int A[1 << 18], B[1 << 18];
vector<int> G[1 << 18]; //グラフ（木）
int dist[1 << 18]; // iまでの距離
const int INF = (1 << 29); // 無限を設定

void getdist(int start){
    //G[start]から一番遠いノードまでの距離を幅優先探索で探索
    for(int i = 1; i <= N; i++) dist[i] = INF;

    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while(!Q.empty()){
        int pos = Q.front(); Q.pop();// 探索中のノードをposに入れる
        for(int to: G[pos]){
            if(dist[to] == INF){//探索中のノードに隣接するノードが未探索なら
                Q.push(to);
                dist[to] = dist[pos] + 1;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N-1; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    getdist(1);
    int maxdist = -1;
    int maxid = -1;
    for(int i = 1; i <= N; i++){
        if(maxdist < dist[i]){
            maxdist = dist[i];
            maxid = i;
        }
    }

    maxdist = -1;
    getdist(maxid);
    for(int i = 1; i <= N; i++){
        maxdist = max(dist[i], maxdist);
    }

    cout << maxdist + 1 << endl;
    return 0;
}
