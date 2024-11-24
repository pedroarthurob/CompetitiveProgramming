#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

const int MAXN = 505;

struct Node {
    int maxValue, minValue;
};

Node st[4 * MAXN][4 * MAXN];
Node a[MAXN][MAXN];

Node merge(Node leftNode, Node rightNode) {
    Node result;
    result.maxValue = max(leftNode.maxValue, rightNode.maxValue);
    result.minValue = min(leftNode.minValue, rightNode.minValue);
    return result;
}

void build_y(int node_x, int start_x, int end_x, int node_y, int start_y, int end_y) {
    if (start_y == end_y) {
        if (start_x == end_x) {
            st[node_x][node_y] = a[start_x][start_y];
        } else {
            st[node_x][node_y] = merge(st[node_x * 2][node_y], st[node_x * 2 + 1][node_y]);
        }
    } else {
        int middle_y = start_y + (end_y - start_y) / 2;
        build_y(node_x, start_x, end_x, node_y * 2, start_y, middle_y);
        build_y(node_x, start_x, end_x, node_y * 2 + 1, middle_y + 1, end_y);
        st[node_x][node_y] = merge(st[node_x][node_y * 2], st[node_x][node_y * 2 + 1]);
    }
}

void build_x(int node_x, int start_x, int end_x) {
    if (start_x != end_x) {
        int middle_x = start_x + (end_x - start_x) / 2;
        build_x(node_x * 2, start_x, middle_x);
        build_x(node_x * 2 + 1, middle_x + 1, end_x);
    }
    build_y(node_x, start_x, end_x, 1, 1, MAXN);
}

Node query_y(int node_x, int node_y, int start_y, int end_y, int query_start_y, int query_end_y) {
    if (query_start_y > query_end_y) return {INT_MIN, INT_MAX};
    if (start_y == query_start_y && end_y == query_end_y) {
        return st[node_x][node_y];
    }
    int middle_y = start_y + (end_y - start_y) / 2;
    Node left = query_y(node_x, node_y * 2, start_y, middle_y, query_start_y, min(query_end_y, middle_y));
    Node right = query_y(node_x, node_y * 2 + 1, middle_y + 1, end_y, max(query_start_y, middle_y + 1), query_end_y);
    return merge(left, right);
}

Node query_x(int node_x, int start_x, int end_x, int query_start_x, int query_start_y, int query_end_x, int query_end_y) {
    if (query_start_x > query_end_x) return {INT_MIN, INT_MAX};
    if (start_x == query_start_x && end_x == query_end_x) {
        return query_y(node_x, 1, 1, MAXN, query_start_y, query_end_y);
    }
    int middle_x = start_x + (end_x - start_x) / 2;
    Node left = query_x(node_x * 2, start_x, middle_x, query_start_x, query_start_y, min(query_end_x, middle_x), query_end_y);
    Node right = query_x(node_x * 2 + 1, middle_x + 1, end_x, max(query_start_x, middle_x + 1), query_start_y, query_end_x, query_end_y);
    return merge(left, right);
}

void update_y(int node_x, int start_x, int end_x, int node_y, int start_y, int end_y, int x, int y, int new_val) {
    if (start_y == end_y) {
        if (start_x == end_x) {
            a[x][y].maxValue = new_val;
            a[x][y].minValue = new_val;
            st[node_x][node_y] = a[x][y];
        } else {
            st[node_x][node_y] = merge(st[node_x * 2][node_y], st[node_x * 2 + 1][node_y]);
        }
    } else {
        int middle_y = start_y + (end_y - start_y) / 2;
        if (y <= middle_y) {
            update_y(node_x, start_x, end_x, node_y * 2, start_y, middle_y, x, y, new_val);
        } else {
            update_y(node_x, start_x, end_x, node_y * 2 + 1, middle_y + 1, end_y, x, y, new_val);
        }
        st[node_x][node_y] = merge(st[node_x][node_y * 2], st[node_x][node_y * 2 + 1]);
    }
}

void update_x(int node_x, int start_x, int end_x, int x, int y, int new_val) {
    if (start_x != end_x) {
        int middle_x = start_x + (end_x - start_x) / 2;
        if (x <= middle_x) {
            update_x(node_x * 2, start_x, middle_x, x, y, new_val);
        } else {
            update_x(node_x * 2 + 1, middle_x + 1, end_x, x, y, new_val);
        }
    }
    update_y(node_x, start_x, end_x, 1, 1, MAXN, x, y, new_val);
}

int main() {
    fast_io;

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> a[i][j].maxValue;
            a[i][j].minValue = a[i][j].maxValue;
        }
    }

    build_x(1, 1, N);

    int Q;
    cin >> Q;
    while (Q--) {
        char query;
        cin >> query;
        if (query == 'q') {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Node result = query_x(1, 1, N, x1, y1, x2, y2);
            cout << result.maxValue << " " << result.minValue << endl;
        } else if (query == 'c') {
            int x, y, v;
            cin >> x >> y >> v;
            update_x(1, 1, N, x, y, v);
        }
    }

    return 0;
}
