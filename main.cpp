#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue> //for dfs and bfs structure
#include <stack>
#include <unordered_set>

using namespace std;

class Graph{
    private:
        unordered_map<char, vector<char>> adjList; //key-value pairs for adjacency list
    
    public:
        void addEdge(char u, char v) { //responsible for setting up edge correlations
            adjList[u].push_back(v);    //add the passed in chars as neighbors of eachother, 2-way since undirectional graph is being made
            adjList[v].push_back(u);
        }

    void BFS(char start) { //pass in our starting point, in this case it will always be the letter 'A'
        queue<char> frontierQ; //nodes to explore, we never visit the same node twice, ensure keep FIFO behavior
        unordered_set<char> discovered; //nodes already discovered
        
        frontierQ.push(start);
        discovered.insert(start);
        cout << "BFS Visit Order: ";

        //loop until no exploration left
        while(!frontierQ.empty()) {
            char curr = frontierQ.front();
            frontierQ.pop();

            // "visiting" 
            cout << curr << " ";

            //loop through neighbors, which we have to ensure are intialized ie) see main
            for(char adjV : adjList[curr]){
                if(!discovered.count(adjV)){
                    //add to queue for processing, and discover immediately, similar to start node
                    frontierQ.push(adjV);
                    discovered.insert(adjV);
                }
            }
        }
        cout << endl;
    }

    void DFS(char start){
        stack<char> dfsStack;
        unordered_set<char> visited; //track visited nodes

        dfsStack.push(start);

        cout << "DFS Order: ";

        //keep stack LIFO behavior
        while(!dfsStack.empty()) {
            //after first node is in curr, remove it
            char curr = dfsStack.top();
            dfsStack.pop();

            //check if visited, if not mark as visited through adding to set and cout for clarity of lab
            if(!visited.count(curr)){
                cout << curr << " ";
                visited.insert(curr);

                //push all neigbors onto stack, we can verify if visited through last check to avoid duplicates
                for(char adjV : adjList[curr]){
                    dfsStack.push(adjV);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph test;
    //Can't use "" have to use '', "" is marked as const char *
    //declaring edges that match my theoretical graph
    test.addEdge('A', 'B');
    test.addEdge('A', 'F');
    test.addEdge('B', 'C');
    test.addEdge('C', 'D');
    test.addEdge('D', 'G');
    test.addEdge('G', 'F');
    test.addEdge('F', 'E');

    test.BFS('A');
    test.DFS('A');

    return 0;
}