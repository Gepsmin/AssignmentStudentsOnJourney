/*
Student Name:
Student Number:
Project Number: 4
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <limits>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include "HelpStudents.h"

using namespace std;

HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {
    this->ways= ways;
    this->N= N;
    this->M= M;
    this->K= K;
    visited = vector<bool>(M,false);
    INF = numeric_limits<long long int>::max();
    dist = vector<long long int> (N+1, INF);
    long long int finalResult;
}

long long int HelpStudents::firstStudent() {
    long long int ENF = numeric_limits<long long int>::max();
    set<pair<int, long long int>> setds;
    setds.insert(make_pair(0,1));
    dist[1]= 0;
    while(!setds.empty()){
        pair<int,long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        if(u==K){
            break;
        }
        vector < pair< pair <int,int> , int > >::iterator i;
        for(i= ways.begin(); i!= ways.end(); ++i){
            int v = -1;
            int weight = -1;
            if((*i).first.first == u){
                v = (*i).first.second;
                weight = (*i).second;
            }else if((*i).first.second == u){
                v = (*i).first.first;
                weight = (*i).second;
            }
            if(v!= -1){
                if(dist[v]>dist[u]+weight){
                    if(dist[v]!= ENF){
                        setds.erase(setds.find(make_pair(dist[v],v)));
                    }
                    dist[v]= dist[u]+weight;
                    setds.insert(make_pair(dist[v],v));
                }
            }
        }
    }
    if(dist[K]==ENF){
        return -1;
    }else{
        return dist[K];
    }

}
long long int HelpStudents::secondStudent() {
    vector<int> parent(N+1,0);
    vector<int> visitedNode(N+1,false);

    set<pair<int,int>>branches;
    vector<int> distances(N+1, INF);

    int u = 1;
    int weight = 0;
    pair<int,int> tmp = make_pair(weight,u);
    visitedNode[1] = true;

    for(int count= 1; count <N; count++){
        int v = -1;
        int weight;
        u = tmp.second;


        vector < pair< pair <int,int> , int > >::iterator i;
        for(i= ways.begin(); i!= ways.end(); ++i){
            if((*i).first.first == u){
                v = (*i).first.second;
                weight = (*i).second;
            }else if((*i).first.second == u){
                v = (*i).first.first;
                weight = (*i).second;
            }if(v!=-1&&!visitedNode[v]&&(distances[v]==-1||distances[v]>weight)){
                distances[v] = weight;
                parent[v] = u;
                branches.insert(make_pair(weight,v));
            }
        }


        while(!branches.empty()){
            tmp = *(branches.begin());
            branches.erase(branches.begin());
            if(!visitedNode[tmp.second]){
                visitedNode[tmp.second] = true;
                break;
            }
        }
        if(visited[K]){
            break;
        }
    }
    int k = K;
    long long int finalResult = 0;
    while(parent[k]!=0){
        if(finalResult<distances[k]){
            finalResult = distances[k];
        }
        k = parent[k];
    }

    if(k == 1){
        return finalResult;
    }else{
        return  -1;
    }
}
long long int HelpStudents::thirdStudent() {
    long long int ENF = numeric_limits<long long int>::max();
    set<pair<int, long long int>> setds;
    setds.insert(make_pair(0,1));
    dist[1]= 0;
    while(!setds.empty()){
        pair<int,long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        if(u==K){
            break;
        }
        vector < pair< pair <int,int> , int > >::iterator i;
        for(i= ways.begin(); i!= ways.end(); ++i){
            int v = -1;
            if((*i).first.first == u){
                v = (*i).first.second;
            }else if((*i).first.second == u){
                v = (*i).first.first;
            }
            if(v!= -1){
                if(dist[v]>dist[u]+1){
                    if(dist[v]!= ENF){
                        setds.erase(setds.find(make_pair(dist[v],v)));
                    }
                    dist[v]= dist[u]+1;
                    setds.insert(make_pair(dist[v],v));
                }
            }
        }
    }
    if(dist[K]==ENF){
        return -1;
    }else{
        return dist[K];
    }
}
void HelpStudents::dfs(int u) {
    if(u!=K) {

        int count = 0;

        set<pair<int, int>> setds;
        set<pair<int, int>> counter;
        int node = -1;
        int cnt = -1;
        int disty = -1;

        vector<pair<pair<int, int>, int> >::iterator i;
        for (i = ways.begin(); i != ways.end(); ++i, count++) {
            int v = -1;
            int weight = -1;
            if ((*i).first.first == u) {
                v = (*i).first.second;
                weight = (*i).second;
            } else if ((*i).first.second == u) {
                v = (*i).first.first;
                weight = (*i).second;
            }
            if (v != -1 && !visited[count]) {
                if(disty> weight||(disty==weight&&node>v)||disty==-1){
                    disty = weight;
                    node = v;
                    cnt = count;
                }
            }
        }
        if (node!=-1) {

            visited[cnt] = true;
            dist[node] = dist[u] + disty;
            dfs(node);
        }
    }

}

long long int HelpStudents::fourthStudent() {
    long long int ENF = numeric_limits<long long int>::max();
    dist[1] = 0;
    dfs(1);
    if(dist[K]==ENF){
        return -1;
    }else{
        return dist[K];
    }
}
long long int HelpStudents::fifthStudent() {
    long long int ENF = numeric_limits<long long int>::max();
    set<pair<int, long long int>> setds;
    setds.insert(make_pair(0,1));
    dist[1]= 0;
    vector<int> parents(N+1,1);
    while(!setds.empty()){
        pair<int,long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        if(u==K){
            dist[K] = tmp.first;
            break;
        }
        vector < pair< pair <int,int> , int > >::iterator i;
        for(i= ways.begin(); i!= ways.end(); ++i){
            int v = -1;
            int weight = -1;
            if((*i).first.first == u){
                v = (*i).first.second;
                if(parents[u]%3==0){
                    weight = 0;
                }else{
                    weight = (*i).second;
                }
            }else if((*i).first.second == u){
                v = (*i).first.first;
                if(parents[u]%3==0){
                    weight = 0;
                }else{
                    weight = (*i).second;
                }
            }
            if(v!= -1){
                weight= tmp.first +weight;
                parents[v] = parents[u] + 1;
                setds.insert(make_pair(weight,v));
            }
        }
    }
    if(dist[K]==ENF){
        return -1;
    }else{
        return dist[K];
    }
}

// YOU CAN ADD YOUR HELPER FUNCTIONS