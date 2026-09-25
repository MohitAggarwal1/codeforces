#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
 
int get_int() {
    int x;
    cin >> x;
 
    if (x == -1) {
        exit(0);
    }
 
    return x;
}
 
int ask(const vector<int>& q) {
    cout << "? ";
 
    // Values are encoded because the interactor expects
    // values in a safe range.
    int clip = 100000;
 
    for (int i = 1; i < (int)q.size(); i++) {
        int x = max(-clip, min(clip, q[i]));
        cout << x + clip + 1 << " ";
    }
 
    cout << endl;
    cout.flush();
 
    return get_int() - clip - 1;
}
 
struct MMT {
    int L, R;
    vector<MMT*> children;
 
    bool up;   // true = max, false = min
    bool leaf;
 
    MMT(int L, int R, vector<MMT*> children, bool up)
        : L(L), R(R), children(children), up(up) {
        leaf = (L == R);
    }
 
    int eval(const vector<int>& x) {
        if (leaf)
            return x[L];
 
        int ans = up ? -INF : INF;
 
        for (auto child : children) {
            int v = child->eval(x);
 
            if (up)
                ans = max(ans, v);
            else
                ans = min(ans, v);
        }
 
        return ans;
    }
};
 
// Find the first position where the value changes.
int bs_fwd(int L, int R, bool up, const vector<int>& defaults) {
    int lo = L;
    int hi = R;
 
    while (lo < hi) {
        int mid = (lo + hi) / 2;
 
        vector<int> q = defaults;
 
        for (int i = L; i <= mid; i++)
            q[i] = up;
 
        for (int i = mid + 1; i <= R; i++)
            q[i] = !up;
 
        if (ask(q) == up)
            hi = mid;
        else
            lo = mid + 1;
    }
 
    return lo;
}
 
// Same idea, but searching from the right.
int bs_rev(int L, int R, bool up, const vector<int>& defaults) {
    int lo = L;
    int hi = R;
 
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
 
        vector<int> q = defaults;
 
        for (int i = L; i < mid; i++)
            q[i] = !up;
 
        for (int i = mid; i <= R; i++)
            q[i] = up;
 
        if (ask(q) == up)
            lo = mid;
        else
            hi = mid - 1;
    }
 
    return lo;
}
 
MMT* mimic_full(int L, int R, vector<int> defaults) {
 
    if (L == R) {
        return new MMT(L, R, {}, false);
    }
 
    // Determine whether the current node is max or min.
    int s = bs_fwd(L, R, true, defaults);
    int t = bs_rev(L, R, true, defaults);
 
    bool up = (s < t);
 
    vector<int> upd_defaults = defaults;
 
    for (int i = L; i <= R; i++)
        upd_defaults[i] = !up;
 
    int m_fwd = bs_fwd(L, R, up, upd_defaults);
    int k_fwd = bs_fwd(m_fwd + 1, R, up, upd_defaults);
 
    int m_rev = bs_rev(L, R, up, upd_defaults);
    int k_rev = bs_rev(L, m_rev - 1, up, upd_defaults);
 
    vector<int> g_fwd = upd_defaults;
    vector<int> g_rev = upd_defaults;
 
    for (int i = L; i < k_fwd; i++)
        g_fwd[i] = up;
 
    for (int i = R; i > k_rev; i--)
        g_rev[i] = up;
 
    int fwd_take = -1;
    int rev_take = -1;
    int cut = -1;
 
    for (int i = 0; i < INF; i++) {
 
        // Search from the left.
        g_fwd[L + i] = !up;
 
        if (ask(g_fwd) != up) {
            g_fwd[L + i] = up;
            fwd_take = L + i;
        }
 
        vector<int> check_fwd = g_fwd;
 
        for (int j = L + i + 1; j <= R; j++)
            check_fwd[j] = !up;
 
        if (ask(check_fwd) == up) {
            cut = fwd_take;
            break;
        }
 
        // Search from the right.
        g_rev[R - i] = !up;
 
        if (ask(g_rev) != up) {
            g_rev[R - i] = up;
            rev_take = R - i;
        }
 
        vector<int> check_rev = g_rev;
 
        for (int j = L; j <= R - i - 1; j++)
            check_rev[j] = !up;
 
        if (ask(check_rev) == up) {
            cut = rev_take - 1;
            break;
        }
    }
 
    vector<int> left_defaults = upd_defaults;
 
    for (int i = cut + 1; i <= R; i++)
        left_defaults[i] = !up;
 
    vector<int> right_defaults = upd_defaults;
 
    for (int i = L; i <= cut; i++)
        right_defaults[i] = !up;
 
    vector<MMT*> children;
 
    children.push_back(
        mimic_full(L, cut, left_defaults)
    );
 
    children.push_back(
        mimic_full(cut + 1, R, right_defaults)
    );
 
    return new MMT(L, R, children, up);
}
 
MMT* recover(int n) {
    vector<int> defaults(n + 1, 0);
    return mimic_full(1, n, defaults);
}
 
int main() {
    int T = get_int();
 
    while (T--) {
 
        int n = get_int();
 
        MMT* root = recover(n);
 
        // Tell the interactor that reconstruction is finished.
        cout << "!" << endl;
        cout.flush();
 
        while (true) {
 
            vector<int> q(1, 0);
 
            for (int i = 0; i < n; i++) {
 
                int x = get_int();
 
                if (x == 0)
                    break;
 
                q.push_back(x);
            }
 
            // 0 means this test case is finished.
            if (q.size() == 1)
                break;
 
            cout << root->eval(q) << endl;
            cout.flush();
        }
    }
 
    return 0;
}