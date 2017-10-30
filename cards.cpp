#include <bits/stdc++.h>

using namespace std;


int parent[101], size[101];

int find(int v)
{
	if(parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a == b) return;
	if(size[a] < size[b]) swap(a, b);

	size[a] += size[b];
	parent[b] = a;
}

int main()
{
	int test;
	cin>>test;
	int ii = 1;
	while(ii <= test)
	{
		int n;
		cin>>n;
		// cout<<"n    "<<n<<endl;
		int a[101] , b[101];
		vector<pair < int, pair<int, int> > > v;
		for(int i=0; i<n; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}

		for(int i=0; i<n; i++)
			cin>>a[i];
		
		for(int i=0; i<n; i++)
			cin>>b[i];

		// cout<<"heheiheih"<<endl;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i==j) continue;
				// cout<<i<<" "<<j<<endl;
				int aa = a[i] ^ b[j];
				int bb = b[i] ^ a[j];
				int tt = min(aa, bb);
				v.push_back({tt, {i, j}});
			}
		}
		// cout<<"KBHOKBKBNKL"<<endl;
		sort(v.begin(), v.end());
		// cout<<"hello"<<endl;
		long long int sum = 0;
		for(auto it:v)
		{
			int w = it.first;
			int a = it.second.first;
			int b = it.second.second;
			// cout<<a<<b<<endl;
			if(find(a) == find(b)) continue;

			sum += w;
			unite(a, b);
		}

		cout<<"Case #"<<ii<<": "<<sum<<endl;
		ii++;
	}
}