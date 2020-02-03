#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int verifypath(vector <int>graph[], int i, int j,int currnode, int covered[])
   { 
     
	     
      for(auto point = graph[currnode].begin();point!=graph[currnode].end();point++)
         {
            if(covered[*point] ==0)
	       {
	   	if(*point == j)
		return 1;
                covered[*point]=1;
	        return verifypath(graph,i,j,*point,covered);
               }
	 } 
	int temp=0,sum=0;
	    for(auto point = graph[i].begin();point!=graph[i].end();point++)
	    {
		  temp+=1;
		  sum+=(covered[*point]);
	    }
            if(sum==temp)
             return 0;	    



    }
   
int main()
{
    
    int no_of_vertices,no_of_edges,i,j;
    cout<<"Vertices";
    scanf("%d",&no_of_vertices);
    cout<<"edges";
    scanf("%d",&no_of_edges);
    vector <int>graph[no_of_vertices];
    cout<<"input pairs";
    for(int m = 0;m<no_of_edges;m++)
    { 
      scanf("%d%d",&i,&j);
      graph[i].push_back(j);
      graph[j].push_back(i);
    }
    int covered[no_of_vertices];
    for(int k =0;k<no_of_vertices;k++)
	    covered[k] = 0;
     printf("enter the two nodes");
     int n1,n2;
     scanf("%d %d",&n1,&n2);
     if(verifypath(graph,n1,n2,n1,covered))
     {
	     printf("Yes");
	     
     }
     else printf("No"); 
   
   return 0; 
}


