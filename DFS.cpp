#include<bits/stdc++.h>

using namespace std;

class graph
{
private:
    int v;
    list<int> *adj;
public:
    graph(int v);
    void addEdge(int v , int w); 
    void DFS(int s);   
};

graph::graph(int v)
{
    this->v =v;
    adj = new list<int>[v];
}
void graph::addEdge(int v , int w){
    adj[v].push_front(w);
}
void graph::DFS(int s){
    vector<bool> visited(v , false);
    stack<int> stk;
    stk.push(s);
    while(!stk.empty()){
        s = stk.top(); stk.pop();
        if(!visited[s]){
            cout<<s<<" ";
            visited[s]=true;
        }
        for (auto i = adj[s].begin() ; i != adj[s].end() ; i++){
            if(!visited[*i]){
                stk.push(*i);
            }
        }
    }
    
}


int main(){
    graph g(5);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(1,4);
    g.addEdge(2,1);
    
    g.DFS(0);
    return 0;

}