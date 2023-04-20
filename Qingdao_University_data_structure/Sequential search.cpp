#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int KeyType;
typedef int InfoType;
struct ElemType
{
    KeyType key;
    InfoType otherinfo;
};

struct SSTable
{
    ElemType *R;  // 顺序表地址指针
    int length; // 顺序表的长度
};

int SqSearch(SSTable &S, const KeyType e)
{
    // 添加关键字,在表头设置哨兵
    S.R[0].key = e;
    // 顺序比较查找
    int i;
    for (i = S.length; S.R[i].key != e;--i)
    {
        ;
    }
    return i;
    // 时间复杂度O(n),空间复杂度O(1)(要为哨兵增加一个辅助空间O(1)),ASL = (n+1)/2
}


// 创建顺序表
void CreateSSTable(SSTable &S)
{
    cout << "Please input the length of the table: " << endl;
    cin >> S.length;
    S.R = new ElemType[S.length + 1];
    cout << "Please input the key of the table: " << endl;
    for (int i = 1; i <= S.length;++i)
    {
        cin >> S.R[i].key;
    }
}

int main()
{
    SSTable S;
    CreateSSTable(S);
    int i = SqSearch(S, 3);
    cout << i << endl;
    return 0;
}
