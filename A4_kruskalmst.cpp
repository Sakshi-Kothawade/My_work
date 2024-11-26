#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int parU = findUltimateParent(u);
        int parV = findUltimateParent(v);

        if(parU == parV){
            return;
        }

        if (rank[parU] < rank[parV]){
            parent[parU] = parV;
        }
        else if (rank[parU] > rank[parV]) {
            parent[parV] = parU;
        }
        else{
            parent[parV] = parU;
            rank[parU]++;
        }
    }
};

int KruskalMST(int n, vector<vector<int>>& edges){

    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    DisjointSet ds(n);

    int mstWeight = 0;
    int mstEdges = 0;
    int retWeight = 0;

    for(int i=0; i<edges.size(); i++){
        retWeight += edges[i][2];
    }
    cout << endl << "Minimum Spanning Tree:" << endl;
    cout << "from" << "\t" << "to" << "\t" << "Weight" << endl;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            ds.unionByRank(u, v);
            
            mstWeight += weight;
            mstEdges++;

            cout << edges[i][0] << "\t" << edges[i][1] << "\t" << edges[i][2] << endl;

            if(mstEdges == n-1){
                break;
            }
        }
        else{
            cout << edges[i][0] << endl;
        }
    }
    cout << endl << "Total Weight of the Graph: " << retWeight << endl;
    return mstWeight;
}

int main(){
    vector<vector<int>> edges = {
    // u, v, weight
        {1, 4, 1},
        {1, 2, 2},
        {2, 3, 3},
        {2, 4, 3},
        {1, 5, 4},
        {3, 4, 5},
        {2, 6, 7},
        {3, 6, 8},
        {4, 5, 9}
    };

    int n = edges.size() + 1;

    int mstWeight = KruskalMST(n, edges);

    cout << "The weight of the MST is: " << mstWeight << endl << endl;
    return 0;
}