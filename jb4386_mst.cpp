#include <bits/stdc++.h>

using namespace std;

#define VMAX 101 // vertex 갯수의 최댓값

typedef pair<double, int> node;
typedef pair<double, double> coord;

class MST
{
private:
	vector<node> StarsGraph[VMAX];
	vector<coord> stars;
	priority_queue<node, vector<node>, greater<node> > pq;

	bool Marked[VMAX];

	double getDistance(coord& a, coord& b)
	{
		return sqrt(pow(a.first - b.first, 2.0) + pow(a.second - b.second, 2.0));
	}

	double sumofweight;

public:
	MST()
	{
		sumofweight = 0;
		memset(Marked, 0, VMAX);
	}

	void getInput(void)
	{
		int starNum;
		double x, y;
		double weight;

		cin >> starNum;
		for (int i = 0; i < starNum; i++)
		{
			cin >> x >> y;
			stars.push_back(coord(x, y));
		}
		for (int i = 0; i < starNum; i++)
		{
			for (int j = i; j < starNum; j++)
			{
				weight = getDistance(stars[i], stars[j]);
				StarsGraph[i].push_back(node(weight, j));
			}
		}
	}

	void prim(void)
	{
		node nd;
		pq.push(node(0, 1));

		while (!pq.empty())
		{
			nd = pq.top();
			pq.pop();

			if (Marked[nd.second])
				continue;
			Marked[nd.second] = 1;
			sumofweight += nd.first;

			for (size_t i = 0; i < StarsGraph[nd.second].size(); i++)
			{
				if (!Marked[StarsGraph[nd.second][i].second])
				{
					pq.push(StarsGraph[nd.second][i]);
				}
			}
		}
	}

	double getAnswer(void)
	{
		return sumofweight;
	}
};

int main(void)
{
	MST mst;

	mst.getInput();
	mst.prim();
	cout << setprecision(3);
	cout << mst.getAnswer() << endl;
}
