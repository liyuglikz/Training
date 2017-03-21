#include <cstdio>
const int MAXN = 10000000 + 1;
char S[MAXN];

int main() {
  int cases = 0;
  while (scanf("%s", S) == 1) {
    int num = 0;
    for (int i = 0; S[i]; i++) {
      num = (10 * num + S[i] - '0') % 10001;
    }
    printf("Case #%d: %s\n", ++cases, (num == 0) ? "YES" : "NO");
  }
  return 0;
}
