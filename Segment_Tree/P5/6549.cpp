#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 높이가 10억까지 가능하므로 충분히 큰 값 설정
const int INF = 2000000000;

typedef struct RMQ {
    int n;
    vector<int> rangeMin;
    vector<int> locMin;

    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        locMin.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    int init(const vector<int>& array, int left, int right, int node) {
        if (left == right) {
            locMin[node] = left;
            return rangeMin[node] = array[left];
        }
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);

        if (leftMin <= rightMin) {
            locMin[node] = locMin[node * 2];
            rangeMin[node] = leftMin;
        } else {
            locMin[node] = locMin[node * 2 + 1];
            rangeMin[node] = rightMin;
        }
        return rangeMin[node];
    }

    // pair<값, 인덱스>를 반환하도록 유지
    pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) return make_pair(INF, -1);
        if (left <= nodeLeft && nodeRight <= right) return make_pair(rangeMin[node], locMin[node]);

        int mid = (nodeLeft + nodeRight) / 2;
        pair<int, int> left_res = query(left, right, node * 2, nodeLeft, mid);
        pair<int, int> right_res = query(left, right, node * 2 + 1, mid + 1, nodeRight);

        if (left_res.first <= right_res.first) return left_res;
        else return right_res;
    }

    pair<int, int> query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
} RMQ;

long long get_ans(int left, int right, RMQ& stree) {
    if (left > right) return 0;

    pair<int, int> min_node = stree.query(left, right);
    int min_val = min_node.first;
    int min_pos = min_node.second;

    // 현재 구간의 최대 넓이 (long long 형변환 주의)
    long long max_area_center = (long long)min_val * (right - left + 1);

    // 분할 정복
    long long max_area_left = get_ans(left, min_pos - 1, stree);
    long long max_area_right = get_ans(min_pos + 1, right, stree);

    return max({max_area_center, max_area_left, max_area_right});
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int N;
        if (!(cin >> N) || N == 0) break;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        RMQ stree(A);
        cout << get_ans(0, N - 1, stree) << "\n";
    }
    return 0;
}