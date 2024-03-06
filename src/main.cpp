#include "files/Solution.cpp"
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

int binarySearch(vector<int> values, int target){
    sort(values.begin(), values.end());
    int low = 0, high = values.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(values[mid] == target){
            return mid;
        }
        else if(values[mid] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

//Level Order
vector<int> bfs(int n, vector<vector<int>> edges, int s){
    unordered_map<int, vector<int>> neighbors;
    for(auto edge : edges){
        neighbors[edge[0]].push_back(edge[1]);
        neighbors[edge[1]].push_back(edge[0]);
    }

    unordered_map<int, bool> visited;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    vector<int> distances(n+1, INT_MAX);
    distances[s] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbor : neighbors[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
                distances[neighbor] = distances[node] + 6;
            }
        }
    }

    vector<int> ans;
    for(int i = 1; i < n+1; i++){
        if(i == s){
            continue;
        }
        if(distances[i] == INT_MAX){
            ans.push_back(-1);
        }
        else{
            ans.push_back(distances[i]);
        }
    }
    return ans;
}

//PreOrder
void preOrder(Node *root) {
    std::cout << root->data << " ";
    if(root->left){
        preOrder(root->left);
    }
    if(root->right){
        preOrder(root->right);
    }
}

//PostOrder
void postOrder(Node *root) {
    if(root->left){
        postOrder(root->left);
    }
    if(root->right){
        postOrder(root->right);
    }
    std::cout << root->data << " ";
}

//InOrder
void inOrder(Node *root) {
    if(root->left){
        inOrder(root->left);
    }
    std::cout << root->data << " ";
    if(root->right){
        inOrder(root->right);
    }
}

//PreOrder/InOrder/PostOrder
void dfs(vector<vector<int>> edges, int head){
    unordered_map<int, vector<int>> neighbors;
    for(auto edge : edges){
        neighbors[edge[0]].push_back(edge[1]);
        neighbors[edge[1]].push_back(edge[0]);
    }

    unordered_map<int, bool> visited;
    visited[head] = true;    
    dfsHelper(head, visited, neighbors);
}

void dfsHelper(int node, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> neighbors){
    visited[node] = true;
    for(auto neighbor : neighbors[node]){
        if(!visited[neighbor]){
            visited[neighbor] = true;
            dfsHelper(neighbor, visited, neighbors);
        }
    }
}



int main() {
    return 0;
}