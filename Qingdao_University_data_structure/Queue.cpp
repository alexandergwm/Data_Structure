// 一端删除另一端插入
// 先进先出的线性表
// 引入循环队列解决假上溢

#include<iostream>
using namespace std;
#define MAXSIZE 100

class SqQueue
{
public:
    SqQueue()
    {
        InitQueue();
    }
    ~SqQueue()
    {
        DestroyQueue();
    }

    // 初始化空队列,构造函数
    void InitQueue();
    // 释放队列，析构函数
    void DestroyQueue();
    // 判断队列是否为空
    bool IsEmpty();
    // 判断队列是否满队
    bool IsFull();
    // 入队
    bool InsertQueue(int e);
    // 出队
    bool EraseQueue();
    // 求队列的元素个数
    int GetLength();
    // 打印队列
    void PrintQueue();
    // 批量插入一些有序数据
    void CreatQueue(const int n);

private:
    int *elem;  // 初始化数组并动态分配存储空间
    int front;  // 表示数组当中元素位置下标
    int rear;
};

void SqQueue::InitQueue()
{
    elem = new int[MAXSIZE];
    front = rear = 0;
}

void SqQueue::DestroyQueue()
{
    if(elem)
    {
        delete elem;
        front = rear = 0;
    }
}

bool SqQueue::IsEmpty()
{
    if (front == rear)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool SqQueue::IsFull()
{
    int rear_next = (rear+1) % MAXSIZE;
    if(rear_next == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SqQueue::InsertQueue(int e)
{
    if (IsFull())
    {
        cout << "Full of Queue" << endl;
        return false;
    }
    elem[rear] = e;
    rear = (rear + 1) % MAXSIZE;
    return true;
}

bool SqQueue::EraseQueue()
{
    if(IsEmpty())
    {
        cout << "There is no elem to erase" << endl;
        return false;
    }
    front = (front + 1) % MAXSIZE;
    return true;
}

int SqQueue::GetLength()
{
    int length = (rear - front +MAXSIZE) % MAXSIZE;
    return length;
}

void SqQueue::PrintQueue()
{
    cout << "Queue:" << endl;
    for (int i = front; i != rear; i=(i+1)%MAXSIZE)
    {
        cout << elem[i] <<" ";
    }
    cout << endl;
}

void SqQueue::CreatQueue(const int n)
{
    cout << "input msg" << endl;
    int input;
    for (int i = 0; i < n;++i)
    {
        cout << "please input the " << i << " number" << endl;
        cin >> input;
        InsertQueue(input);
    }
}

int main()
{
    SqQueue Q;
    cout << "Please input the number that you want to insert into this Queue" << endl;
    int n;
    cin >> n;
    Q.CreatQueue(n);
    Q.PrintQueue();
    Q.GetLength();
    cout << "After one element pop" << endl;
    Q.EraseQueue();
    Q.PrintQueue();
    return 0;
}