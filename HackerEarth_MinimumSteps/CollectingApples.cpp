

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int N, P, tmp;
		vector<int> Milk, Apple;

		cin >> N >> P;
		for (int j = 0; j < N; ++j)
		{
			cin >> tmp;
			Milk.push_back(tmp);
		}
		for (int j = 0; j < N; ++j)
		{
			cin >> tmp;
			Apple.push_back(tmp);
		}
		int Ans = 0;

		//sort(Apple.begin(), Apple.end(), std::less<int>());


		--P;
		for (int j = 0; j < N-1; ++j)
		{
			if (P > 0) 
			{
				if (Milk[j + 1] == 0)
				{
					P += Milk[j];
				}
				else
				{
					Ans += Apple[j];
				}
			}
			else
			{
				P += Milk[j];
			}
			--P;
		}
		cout << Ans + Apple[N-1] << endl;

	}
	
	return 0;
}


