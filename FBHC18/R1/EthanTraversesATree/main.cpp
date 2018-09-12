#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
    int n, _nset;
    vi p, rank;
public:
    UnionFind(int n){
        this -> n = n;
        _nset = n;
        p.assign(n, 0);
        rank.assign(n, 0);
        for (int i=0; i<n; i++){
            p[i] = i;
        }
    }
    int findSet(int i){
        return (p[i] == i)? i: (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return (findSet(i) == findSet(j));
    }
    void merge(int i, int j){
        if (!isSameSet(i, j)){
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else if (rank[y] > rank[x]){
                p[x] = y;
            } else {
                if (x < y) {
                    p[y] = x;
                    rank[x]++;
                } else {
                    p[x] = y;
                    rank[y]++;
                }
            }
            _nset--;
        }
    }
    int nset(){
        return _nset;
    }
    vi sets(){
        vi res;
        for (int i=0; i<n; i++){
            res.push_back(findSet(i) + 1);
        }
        return res;
    }
};
class Node {
public:
    int value;
    int label;
    Node * left;
    Node * right;
};

Node * buildTree(int a[][2]){
    stack<Node*> s;
    Node * root= new Node;
    root -> value = 1;
    Node * cur;
    s.push(root);
    while (!s.empty()){
        cur = s.top();
        s.pop();
        int i = cur -> value;
        if (a[i-1][0] == 0) cur -> left = nullptr;
        else {
            Node * temp = new Node;
            temp -> value = a[i-1][0];
            cur -> left = temp;
            s.push(temp);
        }
        if (a[i-1][1] == 0) cur -> right = nullptr;
        else {
            Node * temp = new Node;
            temp -> value = a[i-1][1];
            cur -> right = temp;
            s.push(temp);
        }
    }
    return root;
}

vi pre_order(Node * root){
    vi res;
    res.push_back(root -> value - 1);
    if (root -> left != nullptr){
        vi temp = pre_order(root -> left);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    if (root -> right != nullptr){
        vi temp = pre_order(root -> right);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}
vi post_order(Node * root){
    vi res;
    if (root -> left != nullptr){
        vi temp = post_order(root -> left);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    if (root -> right != nullptr){
        vi temp = post_order(root -> right);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    res.push_back(root -> value - 1);
    return res;
}
vi pre_order_label(Node * root){
    vi res;
    res.push_back(root -> label);
    if (root -> left != nullptr){
        vi temp = pre_order_label(root -> left);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    if (root -> right != nullptr){
        vi temp = pre_order_label(root -> right);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    return res;
}
vi post_order_label(Node * root){
    vi res;
    if (root -> left != nullptr){
        vi temp = post_order_label(root -> left);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    if (root -> right != nullptr){
        vi temp = post_order_label(root -> right);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    res.push_back(root -> label);
    return res;
}
vi label(int n, vi pre, vi post, int k){
    UnionFind s(n);
    for (int i=0; i<n; i++){
        if (pre[i] != post[i]){
            s.merge(pre[i], post[i]);
        }
    }
    if (s.nset() < k) return vi();
    while (s.nset() > k) {
        bool flag = false;
        vi sets = s.sets();
        for (int i=0; i<sets.size(); i++){
            if (flag) break;
            for (int j=0; j<sets.size(); j++){
                if (sets[i]!= sets[j]) {
                    s.merge(i, j);
                    flag = true;
                    break;
                }
            }
        }
    }
    vi labels = s.sets();
    // rearrange labels using number 1..k
    map<int, int> m;
    set<int> v;
    for (int i=0; i<labels.size(); i++){
        int l = labels[i];
        if (m.find(l) == m.end()){
            if (l <=k && l >=1) {
                m.insert(make_pair(l, l));
                v.insert(l);
            }
            else {
                int r = l%k;
                while (v.find(r+1) != v.end())
                    r = (r+1)%k;
                m.insert(make_pair(l, r+1));
                v.insert(r+1);
            }
        }
    }
    for (int i=0; i<labels.size(); i++) labels[i] = m.find(labels[i]) -> second;
    return labels;
}
void labeling(Node * root, vi labels){
    stack<Node *> s;
    Node * cur;
    s.push(root);
    while(!s.empty()){
        cur = s.top();
        s.pop();
        cur -> label = labels[cur -> value - 1];
        if (cur -> left != nullptr) s.push(cur -> left);
        if (cur -> right != nullptr) s.push(cur -> right);
    }
}

string print_vector(vi &a){
    string s = "";
    for (int i=0; i<a.size(); i++){
        s+=to_string(a[i]);
        if (i!=a.size() - 1) s+= " ";
    }
    return s;
}
int main()
{
    ifstream in;
    in.open("ethan_traverses_a_tree_sample_input.txt");
    ofstream out;
    out.open("ethan_traverses_a_tree_sample_output.txt");
    int t;
    in >> t;
    for (int i=0; i<t; i++){
        int n, k;
        in >> n >> k;
        int a[2000][2];
        for (int j=0; j<n; j++){
            in >> a[j][0] >> a[j][1];
        }
        Node * root = buildTree(a);
        vi pre = pre_order(root);
        vi post = post_order(root);
        vi labels = label(n, pre, post, k);
        if (!labels.empty()){
            labeling(root, labels);
            out << "Case #" << i+1 << ": " <<print_vector(labels);
            vi pre_label = pre_order_label(root);
            vi post_label = post_order_label(root);
            cout << print_vector(pre_label) << endl;
            cout << print_vector(post_label) << endl;
        }
        else out << "Case #" << i+1 << ": Impossible";
        if (i!= t-1) out << endl;
    }
    return 0;
}
