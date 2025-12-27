#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 가능한 높이는 각 색상당 10^6이므로 약 3,000,000
const int MAX_H = 3000005;
long long floor_scores[MAX_H];
long long score_diff[MAX_H];
int tree[MAX_H * 4];
int tree_size = 1;

// 세그먼트 트리 초기화: 모든 층을 1(존재함)로 설정
void init_tree(int max_h) {
    while (tree_size < max_h) tree_size *= 2;
    for (int i = 1; i <= max_h; i++) {
        tree[tree_size + i - 1] = 1;
    }
    for (int i = tree_size - 1; i > 0; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

// k번째 살아있는 층을 찾고 제거한 뒤 실제 층 번호 반환
int find_and_remove(int k) {
    if (tree[1] < k) return -1; // 해당 높이에 캔이 없음

    int idx = 1;
    while (idx < tree_size) {
        if (tree[2 * idx] >= k) {
            idx = 2 * idx;
        } else {
            k -= tree[2 * idx];
            idx = 2 * idx + 1;
        }
    }

    int actual_floor = idx - tree_size + 1;
    
    // 층 제거 업데이트
    tree[idx] = 0;
    while (idx > 1) {
        idx /= 2;
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
    return actual_floor;
}

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> black(N), grey(N), white(N);
    for (int i = 0; i < N; i++) cin >> black[i];
    for (int i = 0; i < N; i++) cin >> grey[i];
    for (int i = 0; i < N; i++) cin >> white[i];

    int max_h = 0;
    for (int i = 0; i < N; i++) {
        int b = black[i], g = grey[i], w = white[i];
        max_h = max(max_h, b + g + w);

        // 누적합 기법으로 각 높이별 점수 가산
        if (b > 0) {
            score_diff[1] += 1;
            score_diff[b + 1] -= 1;
        }
        if (g > 0) {
            score_diff[b + 1] += 2;
            score_diff[b + g + 1] -= 2;
        }
        if (w > 0) {
            score_diff[b + g + 1] += 5;
            score_diff[b + g + w + 1] -= 5;
        }
    }

    // 각 층의 실제 점수 계산
    long long current_score = 0;
    for (int i = 1; i <= max_h; i++) {
        current_score += score_diff[i];
        floor_scores[i] = current_score;
    }

    if (max_h > 0) init_tree(max_h);

    int M;
    cin >> M;
    while (M--) {
        int target_h;
        cin >> target_h;
        
        int actual_idx = find_and_remove(target_h);
        if (actual_idx == -1) {
            cout << 0 << "\n";
        } else {
            cout << floor_scores[actual_idx] << "\n";
        }
    }

    return 0;
}