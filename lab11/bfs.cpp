#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>




using namespace std;

vector<int> graph[100000];
bool used[100000];

int main() {
    //Entering a graph ...

    queue<int> q;
    q.push(0);              //we use 0 as the initial vertex.
    used[0] = true;

    while (!q.empty()) {
        int cur = q.front();  //retrieve the current vertex from the queue
        q.pop();

        //This should be the processing of the current vertex.
        cout << "BFS at vertex " << cur + 1 << endl;

        for (int neighbor: graph[cur]) {    //add all unvisited neighbors.
            if (!used[neighbor]) {
                q.push(neighbor);
                used[neighbor] = true;
            }
        }
    }
}
