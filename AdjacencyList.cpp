#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;
	
	list<int> *l;
public:
	Graph(int v){
		this->v = v;
		l = new list<int>[v];
	}

	void addedge(int node1,int node2,bool bidirect=true){
		l[node1].push_back(node2);
		if(bidirect){
			l[node2].push_back(node1);
		}
	}
	void printAdjList(){
		for (int i = 0; i < v ; ++i)
		{
			cout<<i<<"-->";
			for(int vertex:l[i]){
				cout<<vertex<<" , ";
			}
			cout<<endl;
			/* code */
		}
	}
};

int main(){
	Graph g(5);

	g.addedge(0,1);
	g.addedge(0,4);
	g.addedge(4,3);
	g.addedge(1,4);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(1,3);

	g.printAdjList();

	return 0;
}

//output====>>
// 0-->1 , 4 ,
// 1-->0 , 4 , 2 , 3 ,
// 2-->1 , 3 ,
// 3-->4 , 2 , 1 ,
// 4-->0 , 3 , 1 ,
