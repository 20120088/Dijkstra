#include <iostream> //std::cin std::cout std::endl;
#include <queue> //std::queue

const int maxn = 10, maxm = 20;

int n, m, s, f;
int head[maxn + 2], adj[maxn + 1], adv[maxn + 1], trace[maxn + 1], d[maxn + 1];
std::queue<int> q;
bool freeu[maxn + 1];

void docf() {
	int u[maxn + 1], v[maxn + 1], t[maxn + 1];
	std::cin >> n >> m >> s >> f;
	for (int i = 0; i <= n; i++) head[i] = 0;
	for (int i = 1; i <= m; i++) {
		std::cin >> u[i] >> v[i] >> t[i];
		head[u[i]]++;
	}
	for (int i = 2; i <= n + 1; i++)
		head[i] += head[i - 1];
	for (int i = 1; i <= m; i++) {
		adj[head[u[i]]] = v[i];
		adv[head[u[i]]] = t[i];
		head[u[i]]--;
	}
}

void init() {
	memset(freeu, true, maxn + 1);
	memset(trace, 0, maxn + 1);
	for (int i = 0; i <= n; i++) d[i] = 1000000;
	q.push(s);
	freeu[s] = true;
	d[s] = 0;
}

void dijkstra() {
	int u, v, mind;
	do {
		u = 0;
		mind = 10000000;
		for (int i = 1; i <= n; i++)
			if (freeu[i] && d[i] < mind) {
				u = i;
				mind = d[i];
			}
		if (u == 0 || u == f) return;
		freeu[u] = false;
		for (int i = head[u] + 1; i <= head[u + 1]; i++) {
			v = adj[i];
			if (freeu[v] && d[v] > d[u] + adv[i]) {
				d[v] = d[u] + adv[i];
				trace[v] = u;
			}
		}
	} while (true);
}

void xuat() {
	int u = f;
	while (u != 0) {
		std::cout << u << " ";
		u = trace[u];
	}
}

int main() {
	freopen("file.inp", "r", stdin);
	freopen("file.out", "w", stdout);

	docf();
	init();
	dijkstra();
	xuat();

	return 0;
}