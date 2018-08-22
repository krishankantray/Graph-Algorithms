#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <deque>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ull unsigned long long int

void DFS(int start, vector<int>adj[], bool vis[])
{
    vis[start]=true;
    cout<<start<<" ";
    for(int i=0; i<adj[start].size(); i++)
    {
        if(!vis[adj[start][i]])
            DFS(adj[start][i],adj,vis);
    }
}

int main()
{
    int n;
    cin>>n; // number of vertices
    vector<int>adj[n];
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        string s;
        getline(cin,s);
        for(int j=0; j<s.length(); j++)
            adj[i].push_back((s[j]-'0'));
    }
    bool vis[n]={false};
    for(int i=0; i<n; i++)
        if(!vis[i])
            DFS(i,adj,vis);
    return 0;
}
