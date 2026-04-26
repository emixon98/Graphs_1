# Graphs_1
Activity 10 Lab On BFS & DFS for Graphs in C++

### Task 1: Create a theoretical graph
<img width="848" height="405" alt="Graph" src="https://github.com/user-attachments/assets/d158c7f8-828a-4eb0-b2bd-c05a13cb54db" />

### Task 2: Implement BFS and DFS on the theoretical graph in C++
Utilizing the psseudocode from the text provided I came up with the following functions for my program. My main program added the edges through a class defined function addEdge.
#### BFS
```cpp
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
```
### BFS Description
My BFS implementation utilizes a queue for the frontier, or in other words a queue with the nodes we plan to explore. An unordered set is declared for any discovered nodes, the goal is to avoid visiting the same node twice, which is defined through my cout statement, while aiming to visit all adjacent nodes before traversing deeper. In the while loop you can note that we pop our curr node, cout it, move to the for loop and if any of its adjacent neighbors are not discovered, we prep them to join the queue and repeat the process, ensuring we continue until there are no univsited nodes. Doing so in this way allows us to delve 1 layer at a time, starting with all 1 length neighbors, all 2 length neigbors, and so on until the process is completed. 

#### DFS
```cpp
    void DFS(char start){
        stack<char> dfsStack;
        unordered_set<char> visited; //track visited nodes

        dfsStack.push(start);

        cout << "DFS Order: ";

        //keep stack LIFO behavior through top and pop
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
```
### DFS description
In this function we utilize stack to keep DFS' LIFO behavior. Where BFS goal was to traverse one "layer" at a time, DFS goal is to traverse as deep as possible along one path/branch before backtracking and visiting any other node. You can not that the if statement ensure we only cout and mark as visited if the node is not currently visited, this ensure we do not repeat our nodes, and we push all neighbors onto the stack, regardless if visited, because we can verify if we've been there through our if statement. \

#### Basic Graph Class
```cpp
class Graph{
    private:
        unordered_map<char, vector<char>> adjList; //key-value pairs for adjacency list, storing an undirected graph
    
    public:
        void addEdge(char u, char v) { //responsible for setting up edge correlations
            adjList[u].push_back(v);    //add the passed in chars as neighbors of eachother, 2-way since undirectional graph is being made
            adjList[v].push_back(u);
        }
```
#### Graph short description
Since our graph is not directional we use an unordered map which is a hash map that stores key value pairs. In this case the char represents each node and the attached vector all of its neighbors. 
```cpp
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
```

### Task 3: Compare the search algorithms in context of Big O notations
Both functions created hold the same time complexity of Big O notation of O(V + E), where V is the number of vertices or nodes and E is the number of edges. Each function has a while loop that runs a maximum of V times and each node is in turn processed once through either discovered or visited. Both for loops also iterate over the neighbors of every V which would occur E total iterations, and specifically does so in this case since there is not direction. 
