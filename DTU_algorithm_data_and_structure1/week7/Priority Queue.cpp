#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PriorityQueue
{
public:
    // 插入元素
    void insert(int value)
    {
        heap.push_back(value);  // 将值添加到堆的末尾
        int idx = heap.size() - 1; // 获取新元素的索引
        // 当新元素的父节点的值小于新元素时，交换他们的位置
        while (idx > 0 && heap[parent(idx)] < heap[idx])
        {
            swap(heap[parent(idx)],heap[idx]);
            idx = parent(idx);  // 更新索引为父节点的索引
        }
    }

    // 打印堆中的元素
    void print()
    {
        for(int value: heap)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    // 提取最大值
    int extractMax()
    {
        if(heap.empty())
        {
            return -1;  // 如果堆为空，那么返回-1
        }

        int maxValue = heap[0];  // 获取堆中的最大值
        heap[0] = heap.back();   // 将堆的最后一个元素移到堆顶
        heap.pop_back();   // 删除堆中的最后一个元素

        maxHeapify(0);   // 调整堆的结构，使其满足最大堆的性质

        return maxValue;  // 返回最大值
    }

private:
    vector <int> heap;

    // 获取父节点的索引
    int parent(int idx)
    {
        return (idx -1)/2;
    }

    // 获取左子节点的索引
    int left(int idx)
    {
        return 2* idx +1;
    }

    // 获取右子节点的索引
    int right(int idx)
    {
        return 2* idx +2;
    }

    // 从指定索引开始调整堆结构
    void maxHeapify(int idx)
    {
        int largest = idx;
        int l = left(idx);
        int r = right(idx);

        // 找到当前节点、左子节点、右子节点中的最大值
        if (l < heap.size() && heap[l] > heap[largest])
        {
            largest = l;
        }

        if (r < heap.size() && heap[r] > heap[largest])
        {
            largest = r;
        }

        // 如果当前节点不是最大值，与最大值的节点交换，并继续调整堆结构
        if (largest != idx)
        {
            swap(heap[idx],heap[largest]);
            maxHeapify(largest);
        }
    }

    

};
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PriorityQueue {
public:
    void insert(int value) {
        heap.push_back(value);
        int idx = heap.size() - 1;
        while (idx > 0 && heap[parent(idx)] < heap[idx]) {
            swap(heap[parent(idx)], heap[idx]);
            idx = parent(idx);
        }
    }

    void print() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }

    int extractMax() {
        if (heap.empty()) {
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        maxHeapify(0);

        return maxValue;
    }

private:
    vector<int> heap;

    int parent(int idx) {
        return (idx - 1) / 2;
    }

    int left(int idx) {
        return 2 * idx + 1;
    }

    int right(int idx) {
        return 2 * idx + 2;
    }

    void maxHeapify(int idx) {
        int largest = idx;
        int l = left(idx);
        int r = right(idx);

        if (l < heap.size() && heap[l] > heap[largest]) {
            largest = l;
        }

        if (r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != idx) {
            swap(heap[idx], heap[largest]);
            maxHeapify(largest);
        }
    }
};

int main() {
    int n;
    cin >> n;

    PriorityQueue pq;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "I") {
            int value;
            cin >> value;
            pq.insert(value);
        } else if (operation == "E") {
            cout << pq.extractMax() << endl;
        } else if (operation == "P") {
            pq.print();
        }
    }

    return 0;
}


