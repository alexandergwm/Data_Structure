#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class LinearProbingHashTable{
public:
    // 构造函数，创建一个大小为size的散列表并初始化为-1
    LinearProbingHashTable(int size): table(size,-1){}

    // 插入关键字到散列表
    void insert(int key)
    {
        int index = hash(key);
        // 如果当前位置已经被占用，那么就向后探测
        while (table[index] != -1)
        {
            index = (index + 1) % table.size();
        }
        // 将关键字插入到找到的空位置
        table[index] = key;
    }

    // 显示散列表内容
    void display()
    {
        for (int i = 0;i < table.size();i++)
        {
            cout << i << " : " << table[i] << endl;
        }
    }
private:
    // 散列表存储数据的向量
    vector<int> table;

    // 哈希函数
    int hash(int key)
    {
        return key % table.size();
    }
};

class ChainingHashTable
{
public:
    // 构造函数， 创建一个大小为size的散列表
    ChainingHashTable(int size): table(size) {}

    // 插入关键字到散列表
    void insert(int key)
    {
        int index = hash(key);
        // 将关键字添加到链表的尾部
        table[index].push_back(key);
    }

    // 显示散列表内容
    void display()
    {
        for (int i = 0;i < table.size();i++)
        {
            cout << i << " : ";
            // 遍历链表并输出关键字
            for (int key : table[i])
            {
                cout << key << " -> ";
            }
            cout << "null" << endl;
        }
    }

private:
    // 散列表存储数据的向量，每个元素是一个链表
    vector<list<int>> table;

    // 哈希函数
    int hash(int key)
    {
        return key % table.size();
    }
};


int main()
{
    vector<int> keys = {19,14,23,1,68,20,84,27,55,11,10,79};

    // 创建线性探测法哈希表并插入关键字
    LinearProbingHashTable lpht(13);
    for (int key:keys)
    {
        lpht.insert(key);
    }

    // 显示线性探测法哈希表的内容
    cout << "Linear Probing Hash Table:" << endl;
    lpht.display();

    // 创建链地址哈希表并插入关键字
    ChainingHashTable cht(13);
    for (int key: keys)
    {
        cht.insert(key);
    }

    // 显示链地址哈希表内容
    cout << endl << "Chaining Hash Table:" << endl;
    cht.display();

    return 0;
}