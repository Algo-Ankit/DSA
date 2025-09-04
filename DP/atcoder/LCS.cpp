#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();

	// Step 1: Build the dp table
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// Step 2: Reconstruct the LCS string
	string lcs = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (s[i - 1] == t[j - 1])
		{
			lcs += s[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	// Since we added characters from end to start, reverse the result
	reverse(lcs.begin(), lcs.end());

	// Output the LCS string
	cout << lcs << endl;
}
