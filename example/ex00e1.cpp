#include <cstdio>

signed main(int argc, char *argv[]) {
	int h, m, a;
	scanf("%2d %2d %d", &h, &m, &a);
	printf("%02d %02d\n", (h + ((m + a) / 60)) % 24, (m + a) % 60);
	return 0;
}
