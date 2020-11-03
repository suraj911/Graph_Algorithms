#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>

class Graph{

	map<T,list<T>> adjList;

public:

	Graph(){}

	void addedge(T u, T v,bool bidirect=true){
		adjList[u].push_back(v);
		
		if(bidirect){
			adjList[v].push_back(u);
		}
	}

	void print(){
		for(auto i:adjList){
			cout<<i.first<<"-->";
			for(auto entry :i.second){
				cout<<entry<<",";
			}
			cout<<endl;
		}
	}
	void BFS(T src){
		queue<T> q;
		std::map<T,bool> visited;
		q.push(src);
		visited[src]=true;

		while(!q.empty()){
			T node = q.front();
			cout<<node<<" ";
			q.pop();

			for(int neighbour : adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

};



int main(){
	Graph<int> g;
	g.addedge(1,0);
	g.addedge(1,2);
	g.addedge(0,4);
	g.addedge(4,2);
	g.addedge(4,3);
	g.addedge(2,3);
	g.addedge(3,5);

	g.BFS(0);
	return 0;
}

output==>
0 1 4 2 3 5
