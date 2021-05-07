#include <iostream>
#include <vector>

unsigned long long cells(unsigned long long i) {
	if (i & 1)
		return i / 4 * 2 + 1;
	else
		return (i - 1) / 4 * 2 + 2;
}


int main()
{
	unsigned long long n, k;
	k = 3;
	std::cin >> n;
	if (k > 2 * n - 1) {
		std::cout << 0;
		return 0;
	}

	std::vector<std::vector<unsigned long long>> d(n * 2, std::vector<unsigned long long>(k + 2));
	for (unsigned long long i = 0; i < n * 2; ++i)
		d[i][0] = 1;
	d[1][1] = 1;
	for (unsigned long long i = 2; i < n * 2; ++i)
		for (unsigned long long j = 1; j <= k; ++j)
			d[i][j] = d[i - 2][j] + d[i - 2][j - 1] * (cells(i) - j + 1);

	unsigned long long ans = 0;
	for (unsigned long long i = 0; i <= k; ++i)
		ans += d[n * 2 - 1][i] * d[n * 2 - 2][k - i];
	std::cout << ans;


	return 0;
}