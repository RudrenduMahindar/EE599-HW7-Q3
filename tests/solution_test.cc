#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;

TEST(MODIFIED_BFSTEST, ReturnPathDistance) {
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
  map<int,int> actual_dist=g.dist_node;
  map<int,vector<int>> actual_path=g.path_node;
  map<int,int> expected_dist; 
  map<int,vector<int>> expected_path;
  //{ (0,0), (1,1), (2,1), (5,1), (3, 2), (4, 3), (6,3) };
  expected_dist[0]=0;
  expected_dist[1]=1;
  expected_dist[2]=1;
  expected_dist[5]=1;
  expected_dist[3]=2;
  expected_dist[4]=3;
  expected_dist[6]=3;
  EXPECT_EQ(expected_dist, actual_dist);
  //{ (0, [0]), (1, [0,1]}, (2, [0, 2]), (5, [0,5]), (3, [0,1,3]), (4, [0,1,3,4]), (6, [0,1,3,6])}
  expected_path[0]={0};
  expected_path[1]={0,1};
  expected_path[2]={0,2};
  expected_path[5]={0,5};
  expected_path[3]={0,1,3};
  expected_path[4]={0,1,3,4};
  expected_path[6]={0,1,3,6};
  EXPECT_EQ(expected_path, actual_path);
}