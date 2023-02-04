#include<iostream>
using namespace std;
// 同一线性表中的元素必定具有相同特性
// 在非空的线性表，有且只有一个开始结点a_1,没有直接前驱，而仅有一个直接后续a_2
// 有且仅有一个终端结点an,它没有直接后继，而仅有一个直接前驱a_(n-1)
// 其余内部结点a_i都有且仅有一个直接前驱a_(i-1) 和一个直接后继a_(i+1)
// 顺序表可以根据下标读取想读取位置的元素
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量

// 线性表的定义
class SqList
{
public:
    SqList(int elem[], int length)  // 构造函数
    {
        this->elem = elem;
        this->length = length;
    }
    // 1.线性表的初始化
    bool InitList_Sq(SqList &L)
    {
        L.elem = new int[LIST_INIT_SIZE];  // 在堆区开辟内存
        if(!L.elem)  // 如果分配内存失败
        {
            cout<<"Error in allocating memory" << endl;
        }
        L.length = 0;  // 设定空表长度为0
        return true;
    }

    // 2.线性表的销毁
    void DestroyList(SqList &L)
    {
        if(L.elem)
        {
            delete L.elem;
        }
    }

    // 3.线性表的清空
    void ClearList(SqList &L)
    {
        L.length = 0;
    }

    // 4.求线性表L的长度
    int GetLength(SqList &L)
    {
        return L.length;
    }

    // 5.判断线性表是否为空
    bool IsEmpty(const SqList &L)
    {
        if(L.length == 0)
        {
            cout << "The list is empty" << endl;
            return 1;
        }
        else
        {
            cout << "The list is not empty" << endl;
            return 0;
        }
    }

    // 6.线性表中第i个元素的取值
    int GetElem(const SqList &L,const int i, int &e)
    {
        if(i<1||i>L.length)
        {
            cout << "The input i is error" << endl;
            return 0;
        }
        e = L.elem[i-1];
        return e;
    }

    // 7.线性表的按值查找
    // 主要是顺序查找法，遍历所有元素查找是否有相同的
    // 在线性表中查找与指定值e相同的数据元素的位置
    int LocateList(const SqList &L, int e)
    {
        for(int i = 0;i<L.length;i++)
        {
            if(L.elem[i] == e)
            {
                return i+1;   // 查找成功，返回序号
            }
        }
        return 0;
        // 时间复杂度为O(n)
    }

    // 8. 打印当前线性表
    void PrintList(SqList &L)
    {
        for(int i = 0;i<L.length ;i++)
        {
            cout << L.elem[i] << " ";
        }
        cout << endl;
    }

    //int elem[LIST_INIT_SIZE];  // 数组静态分配 视频中使用的是 ElemType 抽象数据类型，可以存放自定义数据类型
    int *elem;            // 还可以表示成存储空间的基地址，数组动态分配
    int length;  // 顺序线性表的当前长度

    // 9.顺序表的插入
    // 判断插入位置i 是否合法
    // 判断顺序表的存储空间是否已满
    bool InsertList(SqList &L, int i, int e)
    {
        //判断插入位置是否合法
        if(i<0||i>L.length+1)
        {
            cout << "wrong insert position" << endl;
            return false;
        }
        //判断线性表长度是否小于最大长度
        if(L.length == LIST_INIT_SIZE)
        {
            cout << "The List reaches the maximum length, error" << endl;
            return false;
        }
        // 将位于插入位置之后的元素依次向后挪动一位
        for(int j = L.length-1;j>=i;j--)
        {
            L.elem[j+1]  = L.elem[j];
        }
        // 插入元素
        L.elem[i] = e;
        // 线性表长度+1
        L.length += 1;
        return true;
    }
    // 算法时间复杂度: O(n)

    // 10.顺序表的删除
    bool EraseList(SqList &L, int i)
    {
        // 判断异常
        if(i<0|| i > L.length)
        {
            cout << "Wrong erase position" << endl;
            return false;
        }
        if(L.length == 0)
        {
            cout << "The length of List is 0 and List has no elements" << endl;
            return false;
        }
        // 将位于删除位置之后的元素依次向前挪动一位
        for(int j = i+1;j < L.length; j++)
        {
            L.elem[j-1] = L.elem[j];
        }
        // 线性表长度减一
        L.length -= 1;
        return true;
        // 算法复杂度为o(n)
    }
 
};

int main()
{
    int a[10];
    for(int i = 0 ;i < 10 ;i++)
    {
        a[i] = i;
    }
    SqList L(a,10);
    L.IsEmpty(L);
    int lengthList = L.GetLength(L);
    cout << "The length of list is " << lengthList << endl;
    L.PrintList(L);
    int pos = L.LocateList(L,3);
    cout << "the position of 3 in the list is "<< pos << endl;
    L.InsertList(L,4,100);
    cout << "After insertion" << endl;
    L.PrintList(L);
    L.EraseList(L,4);
    cout << "After erase" << endl;
    L.PrintList(L);
    return 0;
}