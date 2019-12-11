#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <bitset>
using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;

pair<int, int> dp[10][512][512]; //kターン目でchokudaiが埋めているマスがi、chokukoが埋めているマスがj
int ban[3][3];									 //0が空、1が直大、2がchokuko
int cnt[1201][1201];						 //得点率の構成

//盤面を構成する
void getban(int a, int b)
{
	fill(ban[0], ban[3], 0);
	for (int i = 0; i < 9; i++)
	{
		int tmp = (1 << i);
		if ((a & tmp) > 0)
			ban[i / 3][i % 3] = 1;
		if ((b & tmp) > 0)
			ban[i / 3][i % 3] = 2;
	}
	return;
}

//現在立っているビットの数を出力する
int bitstanding(int n)
{
	int ret = 0;
	for (int i = 0; i < 9; i++)
	{
		int j = (1 << i);
		if ((j & n) > 0)
			ret++;
	}
	return ret;
}

//最適な盤面の進め方を求める(chokudai)
pair<int, int> chokudaiwin(pair<int, int> a, pair<int, int> b)
{
	auto g=make_pair(-1,-1);
	if(a==g)
		return b;
	if(b==g)
		return a;
	if (a.first > b.first)
		return a;
	else if (b.first-a.first > b.second-a.second)
		return a;
	else
		return b;
}

//最適な盤面の進め方を求める(chokuko)
pair<int, int> chokukowin(pair<int, int> a, pair<int, int> b)
{
	auto g=make_pair(-1,-1);
	if(a==g)
		return b;
	if(b==g)
		return a;
	if (a.second > b.second)
		return a;
	else if (b.second-a.second > b.first-a.first)
		return a;
	else
		return b;
}

int main()
{
	int err=0;
	int b[2][3];
	int c[3][2];
	int dx[] = {0, 1, 0, -1};
	int dy[] = {-1, 0, 1, 0};
	pair<int, int> ans = make_pair(0, 0);
	for (int i = 0; i < 6; i++)
		cin >> b[i / 3][i % 3];
	for (int i = 0; i < 6; i++)
		cin >> c[i / 2][i % 2];

	fill(dp[0][0], dp[10][0], make_pair(-1, -1));
	dp[0][0][0] = make_pair(0, 0);
	//chokudaiが最初に塗るマス
	for (int t = 0; t < 9; t++)
	{
		dp[1][1 << t][0] = make_pair(0, 0);
		fill(cnt[0], cnt[1201],0);
		for (int turn = 2; turn < 10; turn++)
		{
			for (int i = 0; i < 512; i++)
			{
				for (int j = 0; j < 512; j++)
				{
					if (dp[turn - 1][i][j] == make_pair(-1, -1))
						continue;

					//直大の番
					if (turn % 2 == 1)
					{
						for (int k = 0; k < 9; k++)
						{
							getban(i, j); //現在埋まっている盤面
							if (ban[k / 3][k % 3] != 0)
								continue;

							int tmp = 1 << k;
							ban[k / 3][k % 3] = 1;
							int nowx = k % 3;
							int nowy = k / 3;
							int chokudai = dp[turn - 1][i][j].first;
							int chokuko = dp[turn - 1][i][j].second;
							//kの近傍について調べる
							for (int l = 0; l < 4; l++)
							{
								if (nowx + dx[l] > -1 && nowx + dx[l] < 3 && nowy + dy[l] > -1 && nowy + dy[l] < 3)
								{
									if (ban[nowy + dy[l]][nowx + dx[l]] == 1)
									{
										if (dy[l] == -1)
											chokudai += b[nowy - 1][nowx];
										if (dy[l] == 1)
											chokudai += b[nowy][nowx];
										if (dx[l] == -1)
											chokudai += c[nowy][nowx - 1];
										if (dx[l] == 1)
											chokudai += c[nowy][nowx];
									}
									if (ban[nowy + dy[l]][nowx + dx[l]] == 2)
									{
										if (dy[l] == -1)
											chokuko += b[nowy - 1][nowx];
										if (dy[l] == 1)
											chokuko += b[nowy][nowx];
										if (dx[l] == -1)
											chokuko += c[nowy][nowx - 1];
										if (dx[l] == 1)
											chokuko += c[nowy][nowx];
									}
								}
							}
							dp[turn][i | tmp][j] = chokudaiwin(make_pair(chokudai, chokuko), dp[turn][i | tmp][j]);
						}
					}
					else
					{
						//chokukoの番
						for (int k = 0; k < 9; k++)
						{
							if (ban[k / 3][k % 3] != 0)
								continue;

							getban(i, j); //現在埋まっている盤面
							int tmp = 1 << k;
							ban[k / 3][k % 3] = 2;
							int nowx = k % 3;
							int nowy = k / 3;
							int chokudai = dp[turn - 1][i][j].first;
							int chokuko = dp[turn - 1][i][j].second;
							//kの近傍について調べる
							for (int l = 0; l < 4; l++)
							{
								if (nowx + dx[l] > -1 && nowx + dx[l] < 3 && nowy + dy[l] > -1 && nowy + dy[l] < 3)
								{
									if (ban[nowy + dy[l]][nowx + dx[l]] == 2)
									{
										if (dy[l] == -1)
											chokudai += b[nowy - 1][nowx];
										if (dy[l] == 1)
											chokudai += b[nowy][nowx];
										if (dx[l] == -1)
											chokudai += c[nowy][nowx - 1];
										if (dx[l] == 1)
											chokudai += c[nowy][nowx];
									}
									if (ban[nowy + dy[l]][nowx + dx[l]] == 1)
									{
										if (dy[l] == -1)
											chokuko += b[nowy - 1][nowx];
										if (dy[l] == 1)
											chokuko += b[nowy][nowx];
										if (dx[l] == -1)
											chokuko += c[nowy][nowx - 1];
										if (dx[l] == 1)
											chokuko += c[nowy][nowx];
									}
								}
							}
							dp[turn][i][j | tmp] = chokukowin(make_pair(chokudai, chokuko), dp[turn][i][j | tmp]);
						}
					}
				}
			}
		}
		//どのケースがよかったか調べる
		for (int i = 0; i < 512; i++)
		{
			for (int j = 0; j < 512; j++)
			{
				if (bitstanding(i) == 5 && bitstanding(j) == 4 && (i & j) == 0)
				{
					//cerr<<bitset<9>(i)<<" "<<bitset<9>(j)<<" "<<dp[9][i][j].first<<" "<<dp[9][i][j].second<<endl;
					if(dp[9][i][j]==make_pair(-1,-1))
					{
						err++;
						continue;
					}
					cnt[dp[9][i][j].first][dp[9][i][j].second]++;
				}
			}
		}
		int m = 0;
		for (int i = 0; i < 1201; i++)
		{
			for (int j = 0; j < 1201; j++)
			{
				if (m < cnt[i][j])
				{
					//cerr << i << " " << j << " " << cnt[i][j] << endl;
					m = cnt[i][j];
					ans = make_pair(i, j);
				}
			}
		}
		//cerr<<t/3<<" "<<t%3<<" "<<ans.first<<" "<<ans.second<<endl;
	}

	cout << ans.first << endl;
	cout << ans.second << endl;
	cerr<<err<<endl;
	return 0;
}