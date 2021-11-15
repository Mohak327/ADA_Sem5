#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Graph {
public:
	int v;
	vector<pair<int,int>> *m;
	Graph(int v){
		this->v = v;
		m = new vector<pair<int,int>>[v+1];
	}
	void addEdge(int s,int d,int wt){
		m[s].push_back({d,wt});
		m[d].push_back({s,wt});
	}
	void dijkstra(int src){
		set<pair<int,int>> s;
		vector<int> dist(this->v,2147483647);
		dist[src] = 0;
		s.insert({0,src}); // wt src
		while(!s.empty()){
			auto t = s.begin();
			s.erase(s.begin());
			int wt = t->first;
			int node = t->second;

			for(auto nbrs:m[node]){
				int nbr = nbrs.first;
				int nbr_wt = nbrs.second;

				if(wt+nbr_wt < dist[nbr]){
					auto it = s.find({dist[nbr],nbr});
					if(it!=s.end())
						s.erase(it);

					dist[nbr] = wt + nbr_wt;
					s.insert({dist[nbr],nbr});
				}
			}
		}
		cout<<"--------------------\nSrc\t->\tDest\n--------------------\n";
		for(int i=1;i<=v;i++){
			cout<<src<<"\t->\t"<<dist[i]<<endl;
		}
		return ;
	}
};

int main() {
	cout << "\t  Dijkstra Algorithm\n\n";
	int n,m;
	cout<<"Enter number of nodes: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>m;
	Graph g(n);
	cout<<"Enter all edges (src dest wt)\n";
	for(int i=0;i<m;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		g.addEdge(x,y,wt);
	}
	g.dijkstra(1);

	return 0;
}