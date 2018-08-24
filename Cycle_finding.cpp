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
#include <stack>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ull unsigned long long int

bool isCyclic(int s,vector<int>adj[], bool vis[],bool rec[])
{
   vis[s]=true;
   rec[s]=true;
   for(int i=0; i<adj[s].size(); i++)
   {
        if(!vis[adj[s][i]])
            return isCyclic(adj[s][i],adj,vis,rec);
        else
            if(rec[adj[s][i]])
                return true;
   }
   rec[s]=false;
   return false;
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
    bool vis[]={false};
    bool rec[]={false};
    cout<<isCyclic(0,adj,vis,rec);
    return 0;
}
