//
//  main.cpp
//  assignment
//
//  Created by Mani Kireeti on 05/05/20.
//  Copyright © 2020 Mani Kireeti. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


//dfs function
void DFS(bool visited[],int N,vector<int> graph[],int vertex){
    visited[vertex]=true;
    int a=0;
    for(;a<graph[vertex].size();a++){
        if(visited[graph[vertex][a]]==false){
            DFS(visited,N,graph,graph[vertex][a]);
        }
    }
}


void func(vector<int> graph[],int N){
    bool visited[N];
    
    //this array is for not producing duplicate items
    //when printing out
    int A[N][2];
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            A[i][j]=-1;
        }
    }
    int X=0;
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<graph[i].size();j++){
            //initializing the boolean array
            for(int h=0;h<N;h++){
                visited[h]=false;
            }
            
            //removing the edge
            int a,b;
            a=i;b=graph[i][0];
            graph[i].erase(graph[i].begin());
            int index=0;
            for(;index<graph[b].size();index++){
                if(graph[b][index]==a) break;
            }
            graph[b].erase(graph[b].begin()+index);
            
            //calling the dfs function
            DFS(visited,N,graph,i);
            
            //checking if not connected
            for(int k=0;k<N;k++){
                if(visited[k]==false){
                    A[X][0]=a;
                    A[X][1]=b;
                    X++;
                    int index=0;
                    int flag=0;
                    while(index<N){
                        if(A[index][0]==b && A[index][1]==a){
                            flag=1;
                        }
                        index++;
                    }
                    if(flag==0) cout << a << " " << b<<endl;
                    break;
                }
            }
            
            //adding again the removed edge from the graph
            graph[i].push_back(b);
            graph[b].push_back(a);
        }
    }
    return;
}

int main() {
    //create a graph using adjacency list
    //N is the number of vertices in the graph
    int N;
    cin >> N;
    vector<int> graph[N];
    //assuming the graph is connected
    //T is the number of edges
    int T;
    cin >> T;
    while(T>0){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        T--;
    }
    func(graph,N);
    return 0;
}
