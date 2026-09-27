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
 
int ask(vector<int> q) {
    cout << "? ";
 
    int clip = 100000;
 
    for (int i = 1; i < (int)q.size(); i++) {
        cout << max(-clip, min(clip, q[i])) + clip + 1 << " ";
    }
 
    cout << endl;
    cout.flush();
 
    return get_int() - clip - 1;
}
 
struct MMT {
    int L, R;
    vector<MMT*> child;
 
    bool up;
    bool leaf;
 
    MMT(int L, int R, vector<MMT*> child, bool up) {
        this->L = L;
        this->R = R;
        this->child = child;
        this->up = up;
        this->leaf = (L == R);
    }
 
    int eval(const vector<int>& x) {
        if (leaf)
            return x[L];
 
        int ans = up ? -INF : INF;
 
        for (auto v : child) {
            int cur = v->eval(x);
 
            if (up)
                ans = max(ans, cur);
            else
                ans = min(ans, cur);
        }
 
        return ans;
    }
};
 
int bs_fwd(int L, int R, bool up, vector<int> defaults) {
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
 
int bs_rev(int L, int R, bool up, vector<int> defaults) {
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
 
    // Determine whether root is MAX or MIN.
    int s = bs_fwd(L, R, true, defaults);
    int t = bs_rev(L, R, true, defaults);
 
    bool up = (s < t);
 
    vector<int> upd = defaults;
 
    for (int i = L; i <= R; i++)
        upd[i] = !up;
 
    int mf = bs_fwd(L, R, up, upd);
    int kf = bs_fwd(mf + 1, R, up, upd);
 
    int mr = bs_rev(L, R, up, upd);
    int kr = bs_rev(L, mr - 1, up, upd);
 
    vector<int> gf = upd;
    vector<int> gr = upd;
 
    for (int i = L; i < kf; i++)
        gf[i] = up;
 
    for (int i = R; i > kr; i--)
        gr[i] = up;
 
    int fwd_take = -1;
    int rev_take = -1;
    int cut = -1;
 
    for (int i = 0; i <= R - L; i++) {
 
        // Forward search
        gf[L + i] = !up;
 
        if (ask(gf) != up) {
            gf[L + i] = up;
            fwd_take = L + i;
        }
 
        vector<int> check_fwd = gf;
 
        for (int j = L + i + 1; j <= R; j++)
            check_fwd[j] = !up;
 
        if (ask(check_fwd) == up) {
            cut = fwd_take;
            break;
        }
 
        // Reverse search
        gr[R - i] = !up;
 
        if (ask(gr) != up) {
            gr[R - i] = up;
            rev_take = R - i;
        }
 
        vector<int> check_rev = gr;
 
        for (int j = L; j <= R - i - 1; j++)
            check_rev[j] = !up;
 
        if (ask(check_rev) == up) {
            cut = rev_take - 1;
            break;
        }
    }
 
    vector<int> left_defaults = upd;
 
    for (int i = cut + 1; i <= R; i++)
        left_defaults[i] = !up;
 
    vector<int> right_defaults = upd;
 
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
 
        cout << "!" << endl;
        cout.flush();
 
        while (true) {
            vector<int> q(1, 0);
 
            bool finished = false;
 
            for (int i = 0; i < n; i++) {
                int x = get_int();
 
                if (x == 0) {
                    finished = true;
                    break;
                }
 
                q.push_back(x);
            }
 
            if (finished)
                break;
 
            cout << root->eval(q) << endl;
            cout.flush();
        }
    }
 
    return 0;
}