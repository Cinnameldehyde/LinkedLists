#include <iostream>
#include <malloc.h>
#include <string.h>
#include <cstring>
#include <windows.h>
#include <iomanip>
#include <cmath>
#include<bits/stdc++.h>
#include<map>
#include<list>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
       
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
       
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;

       
        pq.push({0, 1});
        while (!pq.empty())
        {
           
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

               
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                   
                    parent[adjNode] = node;
                }
            }
        }

        
        if (dist[n] == 1e9)
            return {-1};

        vector<int> path;
        int node = n;

        
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

       
        reverse(path.begin(), path.end());
        return path;
    }


    int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}


struct  job
{
    int id;
    int dead;
    int profit;
};

bool cmp(job a,job b)
{
    return a.profit>b.profit;
}
 
 int Max(int a,int b)
 {
    if(a>b)
    return a;
    else 
    return b;
 }

vector<int> jobSeq(job arr[],int n,int m)
{
    sort(arr,arr+n,cmp);
    int maxDeadline=-9999999;

    for(int i=0;i<n;i++)
    maxDeadline= Max(maxDeadline,arr[i].dead);

    int count=0;
    int maxprofit=0;

    vector<int> schedule(maxDeadline+1,-1);

    for(int i=0;i<n;i++)
    {
        int currp=arr[i].profit;
        int currj=arr[i].id;
        int currd=arr[i].dead;

        for(int k=currd;k>0;k--)
        {
            if(schedule[k]==-1)
            {
                maxprofit+=currp;

                if(maxprofit>m)
                break;
                schedule[k]=currj;
                break;
            }

        }

        if(maxprofit>m)
        break;
    }
return schedule;

}

    void intro()
{
    system("color 0b");
    string str = " ALGORITHM AND PROBLEM SOLVING LAB ";
    string str2 = "WELCOME TO OUR PROJECT (PBL) ";
    cout<< "\n\n\n\t\t\t\t\t==========================================" <<endl;
    cout<< "\t\t\t\t\t\t";
    for (int i = 0; i<str.length(); i++)
        {
            Sleep(50);
            cout<< str[i];
        }
    cout<< "\n\t\t\t\t\t\t ";
    for (int i = 0; i< str2.length(); i++)
        {
            Sleep(100);
            cout<< str2[i];
        }
        cout<< "\n\t\t\t\t===========================================" <<endl;
        Sleep(1000);
        string top = "\n\tTOPIC : SUPPLY CHAIN OPTIMISATION ";
        for (int i = 0; i<top.length(); i++)
            {
                Sleep(100);
        cout<< top[i];
       }
        cout<< "\n\t===========================================\n"<<endl;
        string crt = "\tSUBMITTED BY : ";
        for (int i = 0; i<crt.length(); i++)
            {
              Sleep(100);
             cout<<crt[i];
            }
    cout<< "\n\t============================================ \n"<<endl;
    string name_s = "\t1. Shivam Pandey - 9922103165\n\t2. Vanshika Gupta - 9922103034\n\t3. Mansi Arora - 9922103150\n\t4. Pragya Sharma - 9922103161\n ";
    for (int i = 0; i<name_s.length(); i++)
        {
            Sleep(100);
    cout<<name_s[i];
    }
    Sleep(1000);
    system("pause");
    system("cls");
    }

int main()
{
     intro();
            int n;
            
            label:system("color 0a");
            cout<<endl<<endl<<endl<<endl<<"How may I help you?"<<endl<<"1.Shortest path between supplier and the customer"<<endl<<"2.Minium cost of transportation if we want to deliver all customers "<<endl<<"3. Caesar Cipher"<<endl<<"4. Know more about Ciphers"<<endl<<"5. Exit"<<endl;
            cin>>n;
            if(n==1)
            {
                int V = 5, E = 6;
            vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    
            vector<int> path = shortestPath(V, E, edges);

            for (int i = 0; i < path.size(); i++)
            {

                cout << path[i] << " ";
            }
            cout << endl;
            system("pause");
            system("cls");
            goto label;
            }
            else if(n==2)
            {
                int V = 5;
	            vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	            vector<vector<int>> adj[V];
	            for (auto it : edges) {
	            	vector<int> tmp(2);
	            	tmp[0] = it[1];
	            	tmp[1] = it[2];
	            	adj[it[0]].push_back(tmp);

	            	tmp[0] = it[0];
	            	tmp[1] = it[2];
	            	adj[it[1]].push_back(tmp);
	            }


	            int sum = spanningTree(V, adj);
	            cout << "The minimium cost of transportation: " << sum << endl;
                cout << endl;
                system("pause");
                system("cls");
                goto label;

            }
            else if(n==3)
            {
                job arr[]={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
                vector<int> v=jobSeq(arr,4,70);
                cout<<"ORDER SEQUENCE IS ";
                for(int i=1;i<=4;i++)
                {
                    if(v[i]!=-1)
                    cout<<"Order "<<v[i]<<"-->\t";

                }
                 cout << endl;
                system("pause");
                system("cls");
                goto label;
            }
            else if(n==4)
            {
                system("color 0c");
                cout<<endl<<endl<<endl<<endl<<endl<<" Okay ";
                return 0;
            }
            else
            {
                system("color 0b");
                cout<<endl<<endl<<endl<<endl<<endl<<"OOPS!!!!! INVALID INPUT ! PLEASE TRY "<<endl;
                cout << endl;
                system("pause");
                system("cls");
                goto label;
            }


}