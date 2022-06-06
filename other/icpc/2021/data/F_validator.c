#include <stdio.h>
#include <stdlib.h>

#define N_MAX 2000
#define M_MAX 100000

typedef struct Edge {
	struct Edge *next;
	int v;
} edge;



int DFS_bipartite_matching(edge* aux[], int par[], int u)
{
	int w;
	for (; aux[u] != NULL; aux[u] = aux[u]->next) {
		w = aux[u]->v;
		if (par[w] == 0) { // w is a sink
			par[w] = u;
			return w;
		} else if (par[w] > 0) continue; // w is already checked
		par[w] = u;
		w = DFS_bipartite_matching(aux, par, w);
		if (w > 0) return w;
	}
	return 0;
}

int bipartite_matching_augmentation(int N, char color[], edge* adj[], int mate[])
{
	static int i, u, w, depth[N_MAX * 2 + 1], par[N_MAX * 2 + 1], q[N_MAX * 2 + 1], head, tail;
	static edge *aux[N_MAX * 2 + 1], f[M_MAX * 2], *p;
	for (u = 1, tail = 0, par[0] = 0; u <= N; u++) {
		if (mate[u] == 0) { // u is a source of sink
			if (color[u] == 0) { // u is a source
				depth[u] = 0;
				q[tail++] = u;
			} else depth[u] = N;
			par[u] = 0;
		} else {
			depth[u] = N;
			par[u] = -1;
		}
	}
	
	// BFS for constructing the layered network
	for (head = 0, i = 0; head < tail; head++) {
		u = q[head];
		aux[u] = NULL;
		if (color[u] == 0) {
			for (p = adj[u]; p != NULL; p = p->next) {
				w = p->v;
				if (mate[u] == w) continue; // No arc in this direction
				if (depth[w] == N) { // w has been found for the first time
					depth[w] = depth[u] + 1;
					q[tail++] = w;
				}
				if (depth[w] == depth[u] + 1) { // Add the arc uw
					f[i].v = w;
					f[i].next = aux[u];
					aux[u] = &(f[i++]);
				}
			}
		} else if (mate[u] != 0) {
			w = mate[u];
			if (depth[w] == N) { // w has been found for the first time
				depth[w] = depth[u] + 1;
				q[tail++] = w;
			}
			if (depth[w] == depth[u] + 1) { // Add the arc uw
				f[i].v = w;
				f[i].next = aux[u];
				aux[u] = &(f[i++]);
			}
		}
	}

	// DFS for finding disjoint augmenting paths
	for (u = 1, tail = 0; u <= N; u++) {
		if (depth[u] != 0) continue;
		w = DFS_bipartite_matching(aux, par, u);
		if (w > 0) q[tail++] = w; // An augmenting path from u to w has been found
	}
	
	// Augmentation
	for (head = 0; head < tail; head++) {
		for (w = q[head], u = par[w]; u > 0; w = par[u], u = par[w]) {
			mate[u] = w;
			mate[w] = u;
		}
	}
	return tail;
}

int bipartite_matching(int N, char color[], edge* adj[], int mate[])
{
	int i, u, dif, ans = 0;
	edge *p;
	for (u = 1; u <= N; u++) mate[u] = 0; // Initialization
	do { // Augmentation
		dif = bipartite_matching_augmentation(N, color, adj, mate);
		ans += dif;
	} while (dif != 0);
	return ans;
}



void chmin(int* a, int b)
{
	if (*a > b) *a = b;
}

int DFS_SCC(edge* adj[], int label[], int ord[], int low[], int s[], int* head, int u)
{
	s[(*head)++] = u; // Add u to the stack (which maintains the vertices already found but not determined)
	ord[u] = ord[0]++;
	low[u] = ord[u];
	
	int w;
	edge *p;
	for (p = adj[u]; p != NULL; p = p->next) {
		w = p->v;
		if (ord[w] == 0) chmin(&(low[u]), DFS_SCC(adj, label, ord, low, s, head, w)); // w has been found
		else if (ord[w] <= N_MAX) chmin(&(low[u]), ord[w]); // w is already found but not determined
	}
	
	if (low[u] == ord[u]) { // A new SCC containing u has been determined
		while (s[--(*head)] != u) {
			label[s[*head]] = label[0];
			ord[s[*head]] = N_MAX + 1;
		}
		label[u] = label[0]++;
		ord[u] = N_MAX + 1;
	}
	return low[u];
}

int SCC(int N, edge* adj[], int label[], edge*** scc_adj, edge** scc_e)
{
	int u, w, head;
	static int ord[N_MAX + 1], low[N_MAX + 1], s[N_MAX + 1];
	for (u = 1; u <= N; u++) {
		label[u] = 0;
		ord[u] = 0;
	}
	for (u = 1, label[0] = 1, ord[0] = 1; u <= N; u++) {
		if (ord[u] != 0) continue;
		head = 0;
		DFS_SCC(adj, label, ord, low, s, &head, u);
	}
	
	int m = 0, n = label[0] - 1;
	edge *p;
	*scc_e = (edge*)malloc(sizeof(edge) * M_MAX);
	*scc_adj = (edge**)malloc(sizeof(edge*) * (n + 1));
	for (u = 1; u <= n; u++) (*scc_adj)[u] = NULL;
	for (u = 1; u <= N; u++) {
		for (p = adj[u]; p != NULL; p = p->next) {
			w = p->v;
			if (label[w] == label[u]) continue;
			(*scc_e)[m].v = label[w];
			(*scc_e)[m].next = (*scc_adj)[label[u]];
			(*scc_adj)[label[u]] = &((*scc_e)[m++]);
		}
	}
	*scc_e = (edge*)realloc(*scc_e, sizeof(edge) * m);
	return n;
}



// Judge the answer (k, x, y) to (N, M, s, t) in O(sqrt{N} M) time.
int judge(int N, int M, int s[], int t[], int k, int x[], int y[])
{
	static char color[N_MAX * 2 + 1];
	static int i, u, w, mate[N_MAX * 2 + 1];
	static edge *adj[N_MAX * 2 + 1], e[M_MAX * 2 + 1], *p;
	for (u = 1; u <= N * 2; u++) {
		adj[u] = NULL;
		color[u] = (u > N)? 1: 0;
	}
	for (i = 0; i < M; i++) {
		u = s[i+1];
		w = t[i+1] + N;
		e[i*2].v = w;
		e[i*2].next = adj[u];
		adj[u] = &(e[i*2]);
		e[i*2+1].v = u;
		e[i*2+1].next = adj[w];
		adj[w] = &(e[i*2+1]);
	}
	if (bipartite_matching(N * 2, color, adj, mate) != N) return -1; // No perfect matching (invalid input)
	
	int m = 0;
	static int label[N_MAX + 1];
	static edge *aux[N_MAX + 1], f[M_MAX + N_MAX], **scc_aux, *scc_e;
	for (u = 1; u <= N; u++) {
		aux[u] = NULL;
		for (p = adj[u]; p != NULL; p = p->next) {
			w = mate[p->v];
			if (w == u) continue;
			f[m].v = w;
			f[m].next = aux[u];
			aux[u] = &(f[m++]);
		}
	}
	
	// DM decomposition
	int n = SCC(N, aux, label, &scc_aux, &scc_e), ns, nt;
	static int deg[N_MAX + 1][2], flag[N_MAX + 1];
	for (u = 1; u <= n; u++) {
		deg[u][0] = 0; // Out-degree
		deg[u][1] = 0; // In-degree
	}
	for (u = 1; u <= n; u++) {
		for (p = scc_aux[u]; p != NULL; p = p->next) {
			w = p->v;
			deg[u][0]++;
			deg[w][1]++;
		}
	}
	free(scc_aux);
	free(scc_e);
	for (u = 1, ns = 0, nt = 0; u <= n; u++) {
		if (deg[u][0] == 0 && deg[u][1] != 0) nt++; // Sink
		else if (deg[u][0] != 0 && deg[u][1] == 0) ns++; // Source
	}
	i = (ns > nt)? ns: nt;
	if (k != i) return 0; // The number of additional edges is incorrect.

	// Check the strong connectivity of each component
	for (i = 1; i <= k; i++) {
		u = x[i];
		w = mate[y[i] + N];
		f[m].v = w;
		f[m].next = aux[u];
		aux[u] = &(f[m++]);
	}
	n = SCC(N, aux, label, &scc_aux, &scc_e);
	for (u = 1; u <= n; u++) {
		if (scc_aux[u] != NULL) { // Not strongly connected
			free(scc_aux);
			free(scc_e);
			return 0;
		}
	}
	free(scc_aux);
	free(scc_e);
	return 1; // Correct
}



// The input file name comes from argv and output file comes from stdin
int main(int argc, char* argv[])
{
	int i, j = 0, N, M, s[M_MAX + 1], t[M_MAX + 1], k, x[N_MAX + 1], y[N_MAX + 1];
	FILE *input = fopen(argv[1], "r");
	while (1) {
		fscanf(input, "%d", &N);
		if (N == 0) break;
		fscanf(input, "%d", &M);
		for (i = 1; i <= M; i++) fscanf(input, "%d %d", &(s[i]), &(t[i]));
		scanf("%d", &k);
		if (k > N) return 1; // Too many edges are added.
		for (i = 1; i <= k; i++) {
			if (scanf("%d %d\n", &(x[i]), &(y[i])) == EOF) return 1; // Less than k pairs.
			if (x[i] <= 0 || x[i] > N || y[i] <= 0 || y[i] > N) return 1; // Invalid pairs.
		}
		if (judge(N, M, s, t, k, x, y) == 0) return 1; // WA
	}
	// printf("AC\n");
	return 0; // AC
}