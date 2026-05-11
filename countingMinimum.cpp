struct Node
{
    int mn = 0, cnt = 0, lazy = 0;
    Node()
    {
        mn = 0;
        cnt = 0;
        lazy = 0;
    }
    Node operator+(const Node &a)
    {
        Node ans;
        if (mn > a.mn)
        {
            ans = a;
        }
        else if (mn < a.mn)
        {
            ans = *this;
        }
        else
        {
            ans.mn = mn;
            ans.cnt = cnt + a.cnt;
            ans.cnt %= MOD;
        }
        ans.lazy = 0;
        return ans;
    }
};
 
struct SegmentTree
{
    vector<Node> st;
    int n;
    void build(int v, int l, int r)
    {
        if (l == r)
        {
            st[v].mn = 0;
            st[v].cnt = 1;
        }
        else
        {
            int m = (l + r) / 2;
            build(2 * v, l, m);
            build(2 * v + 1, m + 1, r);
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }
    void prop(int v, int l, int r)
    {
        st[v].mn += st[v].lazy;
        if (l != r)
        {
            st[2 * v].lazy += st[v].lazy;
            st[2 * v + 1].lazy += st[v].lazy;
        }
        st[v].lazy = 0;
    }
    void update(int v, int val, int l, int r, int tl, int tr)
    {
        prop(v, l, r);
        if (tl > tr)
            return;
        if (tl <= l && r <= tr)
        {
            st[v].lazy += val;
            prop(v, l, r);
        }
        else
        {
            int m = (l + r) / 2;
            update(2 * v, val, l, m, tl, min(tr, m));
            update(2 * v + 1, val, m + 1, r, max(tl, m + 1), tr);
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }
    Node get(int v, int l, int r, int tl, int tr)
    {
        if (tl > tr)
            return Node();
        if (tl <= l && r <= tr)
        {
            return st[v];
        }
        else
        {
            int m = (l + r) / 2;
            return get(2 * v, l, m, tl, min(tr, m)) + get(2 * v + 1, m + 1, r, max(tl, m + 1), tr);
        }
    }
    SegmentTree(int len)
    {
        n = len;
        st.assign(4 * n, {});
        build(1, 0, n - 1);
    }
    void update(int val, int l, int r)
    {
        update(1, val, 0, n - 1, l, r);
    }
    Node get(int l, int r)
    {
        return get(1, 0, n - 1, l, r);
    }
};
