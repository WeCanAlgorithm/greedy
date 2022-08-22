#include <queue>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

#define VNUM 10001
#define EGNUM 100001

class MST
{
private:
	vector<pair<int, int> > Vertex[VNUM];
	bool Marking[VNUM];

	pair<pair<int, int>, int> Edge[EGNUM];
	long long  sumOfWeight;

	typedef pair<int, int> pq_node;
	priority_queue<pq_node, vector<pq_node>, greater<pq_node> > PQ;

public:
	MST()
	{
		memset(Marking, 0, VNUM);
		sumOfWeight = 0;
	}

	void getInput(void)
	{
		int V, E;
		int a, b, c;

		cin >> V >> E;
		for (int i = 0; i < E; i++) // graph 데이터를 vector의 배열에 저장
		{
			cin >> a >> b >> c; // a: vertex1, b: vertex2, c: weight
			Vertex[a].push_back(make_pair(c, b));
			Vertex[b].push_back(make_pair(c, a));
		}
	}

	void prim(void)
	{
		// pq_node는 pair<int, int> 이다. 
		// first: weight
		// second: vertex number
		PQ.push(pq_node(0, 1)); // 맨 처음 1번 노드를 그냥 고름(임의의 노드인데
								// 1번을 그냥 고름

		while (!PQ.empty())
		{
			pq_node curr = PQ.top(); // Prioriy queue의 top에 있는 것은 가장
									 // 작은 edge를 나타낸다. 
			PQ.pop();

			if (Marking[curr.second]) // vertex가 이미 spanning tree에
									  // 포함되어있는지 아닌지를 check
				continue;
			Marking[curr.second] = 1;
			sumOfWeight += curr.first;

			for (size_t i = 0; i < Vertex[curr.second].size(); i++)
			{
				if (!Marking[Vertex[curr.second][i].second])
				{
					PQ.push(Vertex[curr.second][i]);
				}
			}
		}
	}

	long long getAnswer(void)
	{
		return sumOfWeight;
	}
};

int main(void)
{
	MST mst;

	mst.getInput();
	mst.prim();
	cout << mst.getAnswer() << endl;
}
