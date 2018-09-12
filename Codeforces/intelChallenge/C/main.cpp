#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    public:
    int l,r;
    int cutVal;
    int sum;
    TreeNode * left;
    TreeNode * right;

    TreeNode (int l, int r, int sum) {
        this -> l = l;
        this -> r = r;
        this -> sum = sum;
    }

    bool operator>(TreeNode other) const {
        return sum > other.sum;
    }
    void print() {
        cout << l << endl << r << endl << sum  << endl;
    }
};

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};

int main()
{
    int n;
    int a[100000], order[100000], s[100000];
    custom_priority_queue<TreeNode> q;
    cin >> n;
    for (int i =0; i<n ; i++) {
        cin >> a[i];
    }
    for (int i =0; i<n; i++) {
        cin >> order[i];
        order[i] -= 1;
    }
    s[0] = a[0];
    for (int i =1; i< n; i++) {
        s[i] = s[i-1] + a[i];
    }

    TreeNode * root = new TreeNode(0, n-1, s[n-1]);
    TreeNode * iter = root;
    q.push(*root);
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum = iter -> sum;
        while (iter != nullptr) {
            if (order[i] < iter -> l) {
                iter = iter -> left;
            }
            else if (order[i] > iter -> r) {
                sum -= iter -> left -> sum;
                sum -= iter -> cutVal;
                iter = iter -> right;
            }
            else {
                iter -> cutVal = a[order[i]];
                iter -> left = new TreeNode(iter -> l, order[i]-1, sum - iter -> cutVal);
                iter -> right = new TreeNode(order[i]+1, iter -> r, iter -> sum = sum);
                q.remove(*iter);
                q.push(*(iter -> left));
                q.push(*(iter -> right));
                break;
            }
        }

        cout << q.top().sum << endl;
    }
    return 0;
}
