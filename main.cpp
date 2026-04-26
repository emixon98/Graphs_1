#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue> //for dfs and bfs structure
#include <stack>
#include <unordered_set>

using namespace std;

class Graph{
    private:
        unordered_map<char, vector<char>> adjList; 
    
    public:
        void addEdge(char u, char v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

    void BFS(char start) {
        queue<char> frontierQ;
        unordered_set<char> discovered;
        
        frontierQ.push(start);
        discovered.insert(start);
        cout << "BFS Visit Order: ";

        while(!frontierQ.empty()) {
            char curr = frontierQ.front();
            frontierQ.pop();

            cout << curr << " ";

            for(char adjV : adjList[curr]){
                if(!discovered.count(adjV)){
                    frontierQ.push(adjV);
                    discovered.insert(adjV);
                }
            }
        }
        cout << endl;
    }
}