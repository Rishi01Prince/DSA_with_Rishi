#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
private:
    vector<int> v;
    bool isMinHeap;

    bool compare(int a, int b) {
        if (isMinHeap) {
            return a < b;
        } else {
            return a > b;
        }
    }

    void heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int minIndex = i;

        if (left < v.size() && compare(v[left], v[minIndex])) {
            minIndex = left;
        }

        if (right < v.size() && compare(v[right], v[minIndex])) {
            minIndex = right;
        }

        if (minIndex != i) {
            swap(v[i], v[minIndex]);
            heapify(minIndex);
        }
    }

public:
    Heap(int n, bool isMinHeap) {
        v.resize(n + 1);
        v[0] = -1;
        this->isMinHeap = isMinHeap;
    }

    void buildHeap(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            v[i + 1] = a[i];
        }

        for (int i = v.size() / 2; i >= 1; i--) {
            heapify(i);
        }
    }

    void push(int val) {
        v.push_back(val);
        int i = v.size() - 1;
        int parent = i / 2;

        while (i > 1 && compare(v[i], v[parent])) {
            swap(v[i], v[parent]);
            i = parent;
            parent = i / 2;
        }
    }

    int top() {
        return v[1];
    }

    void pop() {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    bool empty() {
        return v.size() == 1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Create a min heap
    Heap minHeap(n, true);
    minHeap.buildHeap(v);

    // Create a max heap
    Heap maxHeap(n, false);
    maxHeap.buildHeap(v);

    // Print the top element of each heap
    cout << "Min Heap: " << minHeap.top() << endl;
    cout << "Max Heap: " << maxHeap.top() << endl;
}

int32_t main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }
    return 0;
}