#include <iostream>
#include "src/lib/solution.h"
#include <map>
#include <set>
using namespace std;

int main()
{
    map<int,set<int>> vertices {{0,{1,2,5}}, 
    {1,{0,2,3}},
    {2,{0,1,3}},
    {3,{1,2,4,6}},
    {4,{3}},
    {5,{0}},
    {6,{3}}};
    Graph g(vertices);
    int root=0;
    g.modified_BFS(vertices,root);
    map<int,int> dist=g.dist_node;
    map<int,vector<int>> path=g.path_node;
    cout<<"1.Shortest distances: {";
    for(auto it=dist.begin();it!=dist.end();it++)
    {
        cout<<"("<<it->first<<","<<it->second<<")";
    }
    cout<<"}"<<endl;
    cout<<"2.Shortest paths: {";
    for(auto it=path.begin();it!=path.end();it++)
    {
        cout<<"("<<it->first<<",[";
        for(auto it1=(it->second).begin();it1!=(it->second).end();it1++)
        {
            cout<<*it1;
            if(it1!=((it->second).end()-1))
                cout<<",";
        }
        cout<<"])";
        /*if(it!=(path.end()-1))
            cout<<",";*/
    }
    cout<<"}"<<endl;
    return EXIT_SUCCESS;
}