
ll LCS(string& s, string& t) {


	auto dp = make_v<ll>(s.size() + 10, t.size() + 10);
	fill_v(dp, 0);

	for (ll i = 0; i < s.size(); i++) {
		for (ll j = 0; j < t.size(); j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	return dp[s.size()][t.size()];
}