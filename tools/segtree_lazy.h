struct node{
    int lm;//從左端開始的最大連續和
    int rm;//從右端開始的最大連續和
    int ans;//區間最大連續和
    int sum;//區間和
}tree[maxn*4];

node pull(node lc,node rc){
    node f;
    f.lm = max(lc.lm , lc.sum + rc.lm);
    f.rm = max(rc.rm , rc.sum + lc.rm);
    f.sum= lc.sum + rc.sum;
    f.ans= max(max(lc.ans , rc.ans) , lc.rm + rc.lm);
    return f;
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt].lm = tree[rt].rm = tree[rt].sum = tree[rt].ans = a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1) , build(mid+1,r,rt<<1|1);
    tree[rt] = pull(tree[rt<<1] ,tree[rt<<1|1]);
}

node query(int L,int R,int l,int r,int rt){
    if(L <= l && R >= r )
        return tree[rt];
    int mid = (l+r) >> 1;
    if(R <= mid) 
        return query(L,R,l,mid,rt<<1);
    else if(L > mid) 
        return query(L,R,mid+1,r,rt<<1|1);
    else{
        node back;
        back = pull (query(L,mid,l,mid,rt<<1),query(mid+1,R,mid+1,r,rt<<1|1));
        return back;
    }
}