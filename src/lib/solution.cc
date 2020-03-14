#include "solution.h"
#include <map>
#include <vector>
#include <queue>
using namespace std;


void Graph::modified_BFS(map<int,set<int>>& neighbour_map,int root) 
{
  //map<int,int> dist_node;
  //map<int,vector<int>> path_node;
/*  for(int i=0;i<v_.size();i++)
  {
    dist_node[i]=0;
  }*/

  queue<int> q;
  map<int,int> marks;
  q.push(root);
  marks[root]=1;
  dist_node[root]=0;
  path_node[root].push_back(root);
  while(!q.empty())
  {
    int cur=q.front();
    q.pop();
    for(auto &n:neighbour_map[cur])
    {
      if(!marks[n])
      {
        marks[n]=1;
        dist_node[n]=dist_node[cur]+1;
        path_node[n]=path_node[cur];
        path_node[n].push_back(n);
        q.push(n);
      }
    }
  }

}
