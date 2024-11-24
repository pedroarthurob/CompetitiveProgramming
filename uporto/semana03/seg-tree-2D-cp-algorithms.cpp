#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

using namespace std;

const int MAXN = 1005;

int st[4 * MAXN][4 * MAXN];
int a[MAXN][MAXN];
int rows, cols;

int merge(int left, int right) {
    return left + right;
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
    build_y(node_x, start_x, end_x, 1, 1, cols);
}

int query_y(int node_x, int node_y, int start_y, int end_y, int query_start_y, int query_end_y) {
    if (query_start_y > query_end_y) return 0;
    if (start_y == query_start_y && end_y == query_end_y) {
        return st[node_x][node_y];
    }
    int middle_y = start_y + (end_y - start_y) / 2;
    int left = query_y(node_x, node_y * 2, start_y, middle_y, query_start_y, min(query_end_y, middle_y));
    int right = query_y(node_x, node_y * 2 + 1, middle_y + 1, end_y, max(query_start_y, middle_y + 1), query_end_y);
    return merge(left, right);
}

int query_x(int node_x, int start_x, int end_x, 
        int query_start_x, int query_start_y, 
        int query_end_x, int query_end_y) {
    if (query_start_x > query_end_x) return 0;
    if (start_x == query_start_x && end_x == query_end_x) {
        return query_y(node_x, 1, 1, cols, query_start_y, query_end_y);
    }
    int middle_x = start_x + (end_x - start_x) / 2;
    int left = query_x(node_x * 2, start_x, middle_x, query_start_x, query_start_y, min(query_end_x, middle_x), query_end_y);
    int right = query_x(node_x * 2 + 1, middle_x + 1, end_x, max(query_start_x, middle_x + 1), query_start_y, query_end_x, query_end_y);
    return merge(left, right);
}

void update_y(int node_x, int start_x, int end_x, int node_y, int start_y, int end_y, int x, int y, int new_val) {
    if (start_y == end_y) {
        if (start_x == end_x) {
            st[node_x][node_y] = new_val;
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
    update_y(node_x, start_x, end_x, 1, 1, cols, x, y, new_val);
}

int main() {
    rows = 3;
    cols = 3;
    a[1][1] = 1, a[1][2] = 2, a[1][3] = 3;
    a[2][1] = 4, a[2][2] = 5, a[2][3] = 6;
    a[3][1] = 7, a[3][2] = 8, a[3][3] = 9;

    build_x(1, 1, rows);

    cout << "Sum of submatrix (1, 1) to (2, 2): " << query_x(1, 1, rows, 1, 1, 2, 2) << endl;

    update_x(1, 1, rows, 2, 2, 10);
    cout << "After updating (2, 2) to 10, sum of submatrix (1, 1) to (2, 2): " 
        << query_x(1, 1, rows, 1, 1, 2, 2) << endl;

    return 0;
}

