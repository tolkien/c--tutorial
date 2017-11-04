#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
#define INF	INT_MAX

const int sz=16;
vector< pair<int, int> > a[sz];
int dis[sz];
int vis[sz];

void Dijkstra(int source, int n) {
	class prioritze {
	public:
		bool operator () (pair<int, int> &p1, pair<int, int> &p2) {
			return p1.second > p2.second;
		};
	};
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritze> pq;
	pq.push(make_pair(source, dis[source] = 0));
	while(!pq.empty()) {
		pair<int, int> curr=pq.top();
		pq.pop();
		//'cw' the final shortest distance for this vertex
		int cv = curr.first, cw = curr.second;
		if (vis[cv])
			continue;
		vis[cv] = true;

		for(int i=0; i < a[cv].size(); i++)
			//If this node is not visited and 
			// the current parent node distance+distance from there to this node
			//    is shorted than the initial distace set to this node, update it
			if (!vis[a[cv][i].first] &&
				a[cv][i].second + cw < dis[a[cv][i].first])
				pq.push(make_pair(a[cv][i].first,
					(dis[a[cv][i].first] = a[cv][i].second + cw)));
	}
}

#define _TEST
int main(void) {
	int n, m, y, w;
    int source;

	for(int i; i < sz; i++) {
		dis[i] = INF;
		vis[i] = false;
	}

#ifndef _TEST
	//cout<<"Enter number of vertices and edges in the graph\n";
	cin>>n>>m;
	for(int i=0;i<m;i++) //Building Graph
    {
        cin>>x>>y>>w; //Vertex1, Vertex2, weight of edge
        a[x].push_back(make_pair(y,w));
        a[y].push_back(make_pair(x,w));
    }
    //cout<<"Enter source for Dijkstra's SSSP algorithm\n";
    cin>>source;
#else
    n = 5;
    m = 7;
    a[0].push_back(make_pair(1,10));
    a[0].push_back(make_pair(2,3));
    a[1].push_back(make_pair(0,10));
    a[1].push_back(make_pair(2,5));
    a[1].push_back(make_pair(4,2));
    a[2].push_back(make_pair(0,3));
    a[2].push_back(make_pair(1,5));
    a[2].push_back(make_pair(3,2));
    a[2].push_back(make_pair(4,7));
    a[3].push_back(make_pair(2,2));
    a[3].push_back(make_pair(4,3));
    a[4].push_back(make_pair(1,2));
    a[4].push_back(make_pair(2,7));
    a[4].push_back(make_pair(3,3));

    source = 0;
#endif

    Dijkstra(source, n);
    cout<<"Source is: "<<source<<".\n The shortest distance to every other vertex from here is: \n";
    for(int i=1; i < n; i++) {
        cout<<"Vertex: "<<i<<" , Distance: ";
        (dis[i]!=INF) ? cout<<dis[i]<<"\n" : cout<<"-1\n";
    }
    return 0;
}