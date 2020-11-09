#include <bits/stdc++.h>

using namespace std;

using ll = long long;
struct Node {
    ll pref, suff, seg, sum;

    static Node single(int x) {
        if (x > 0) return {x, x, x, x};
        return {0, 0, 0, x};
    }

    static Node merge(Node l, Node r) {
        return {
            max(l.pref, l.sum + r.pref),
            max(r.suff, l.suff + r.sum),
            max({l.seg, r.seg, l.suff + r.pref}),
            l.sum + r.sum
        };
    }

    static const Node INF;
};

const Node Node::INF = {0, 0, 0, 0};

template <class T>
class SegmentTree {
public:
    int size;
    vector<T> v;
    SegmentTree(int  n) {
        size = 1;
        while (size < n) size *= 2;
        v.resize(2*size);
    }

    void build_tree(vector<int>& a) {
        build_tree(a, 0, 0, size);
    }

    void set(int index, int val) {
        set(index, val, 0, 0, size);
    }

    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
private:
    void build_tree(vector<int>& a, int i, int l, int r) {
        if (r - l == 1) {
            if (l < a.size()) v[i] = T::single(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build_tree(a, 2*i+1, l, mid);
        build_tree(a, 2*i+2, mid, r);
        v[i] = T::merge(v[2*i+1], v[2*i+2]);
    }

    void set(int index, int val, int i, int l, int r) {
        if (r - l == 1) {
            v[i] = T::single(val);
            return;
        }

        int mid = (l + r) / 2;
        if (index < mid) set(index, val, 2*i+1, l, mid);
        else set(index, val, 2*i+2, mid, r);
        v[i] = T::merge(v[2*i+1], v[2*i+2]);
    }

    T query(int left, int right, int i, int l, int r) {
        if (r <= left || right <= l) return T::INF;
        if (left <= l && r <= right) return v[i];
        int mid = (l + r) / 2;
        return T::merge(query(left, right, 2*i+1, l, mid),
                        query(left, right, 2*i+2, mid, r));
    }
};