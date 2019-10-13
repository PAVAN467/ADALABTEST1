#include<iostream>

using namespace std;


int adj[50][50],n,indegree[50];

void TopologicalOrder()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        indegree[i]=0;
        for(j=0;j<n;j++)
            indegree[i]=indegree[i]+adj[j][i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(indegree[j]==0){
                cout<<j<<" ";
                break;
            }
        indegree[j]=-1;
        for(k=0;k<n;k++)
            if(adj[j][k]==1)
                indegree[k]-=1;
    }

}
int main()
{
    int d,p1,p2;
    cout<<"Enter the number of tasks: ";
    cin>>n;
    cout<<"Enter the number of dependencies: "<<endl;
    cin>>d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            adj[i][j]=0;
    }
    for(int i=0;i<d;i++)
    {
        cout<<"Enter the dependencies: ";
        cin>>p1>>p2;
        adj[p2][p1]=1;
    }

    TopologicalOrder();
    return 0;
}
