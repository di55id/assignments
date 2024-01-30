#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<bool> > &vis,vector<vector<char> > &l,int i,int j)
{
    if(i==l.size()||j==l[0].size()||i<0||j<0)
        return 0;
    if(vis[i][j]==true)
        return 0;
    vis[i][j]=true;
    if(l[i][j]=='w')
        return 1+f(vis,l,i+1,j)+f(vis,l,i,j+1)+f(vis,l,i-1,j)+f(vis,l,i,j-1);
    else
        return 0;
}

int main()
{
	int n;
    cin >> n;
	vector<vector<char> > matrix(n, vector<char>(n));  // declare a 2D vector

    // read input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
  vector<int> ans;
  vector<vector<bool> > vis;
  for(int i=0;i<n;i++)
  {
      vector<bool> temp(n,false);
      vis.push_back(temp);
  }
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          if(vis[i][j]==false&&matrix[i][j]=='w')
          {
              ans.push_back(f(vis,matrix,i,j));
          }
      }
  }
  cout<< "Number of white patches: "<< ans.size()<<endl;
  for(int i=0;i<ans.size();i++)
  {
      cout<< "White cells in patch "<< i+1 << ": " << ans[i]<<endl;
  }
}

