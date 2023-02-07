// 循环链表：头尾相接的链表，表中最后一个结点的指针域指向头结点
// 循环链表没有NULL指针，所以使用遍历时，终止条件不是判断p或p->next是否为空，而是判断他们是否等于头指针
// 操作循环链表时，用尾指针指向最后一个结点更多，使用尾指针更方便，寻找尾指针和头指针都是O(1)复杂度
// 循环链表的基本操作与单链表基本相同，不同在于，循环链表的最后一个结点的next不再是空指针，而是指向
// 头结点
#include<iostream>
using namespace std;

class List
{
public:
    List()
    {
        // 创建链表
        create_List();
    }
    ~List()
    {
        clear();
    }
    // 创建头结点
    void create_List();
    // 从头插入结点
    void insert(const int &d);
    // 在指定位置插入结点
    void insert_pos(const int &pos, const int &d);
    // 删除指定数据的结点
    void erase(const int &d);
    // 修改指定数据
    void update(const int &pos,const int &d);
    // 反转链表函数
    void reverse();
    // 打印链表
    void list_print();
    // 合并两个带尾指针的循环链表
    List MergeList(List &L1,List &L2);

private:
    // 结点结构
    struct Node
    {
        int data;
        Node *next;
        Node(const int &d):data(d),next(NULL){}
    };
    Node *head;
    void clear()
    {
        Node *p = head;  //从头结点开始
        while(p->next != head)
        {
            Node * q = p->next;
            delete p;
            p = q;
        }
    }
    // 查找数据d的上一个结点位置的函数
    Node * find(const int &d)
    {
        Node *p = head;
        for(;p->next!=head;p = p->next)
        {
            if(p->next->data ==d)
                break;
        }
        return p;
    }
};

void List::create_List()
{
    head = new Node(0);
    head->next = head;
}

void List::insert(const int &d)
{
    Node *p = new Node(d);
    p->next = head->next;
    head->next = p;
}

void List::insert_pos(const int &pos,const int &d)
{
    Node *p = find(pos);
    Node *q = new Node(d);
    q->next = p->next;
    p->next = q;
}

void List::erase(const int &d)
{
    Node *p = find(d);
    Node *q = p->next;
    p->next = p->next->next;
    delete q;
}

void List::update(const int &pos,const int &d)
{
    Node *p = find(pos);
    p->next->data = d;
}

void List::reverse()
{
    Node *p  = head->next;
    Node *q = head->next->next;
    Node *m = head->next->next->next;
    p->next = head;
    //
    while(m->next!=head)
    {
        q->next = p;
        p = q;
        q = m;
        m = m->next;
    }
    q->next = p;
    head->next = q;
}

void List::list_print()
{
    for(Node *p = head->next;p!=head;p =p->next)
    {
        if(p->next != head)
        {
            cout << p->data <<"->";
        }
        else
        {
            cout << p->data << endl;
        }
    }
}

// 两个循环链表的合并
// 即链表1的尾指针指向链表2的头结点的下一个元素
// 释放链表2的头结点
// 将链表2的尾指针指向链表1的头结点
List List::MergeList(List &L1, List &L2)
{
    List L3;
    L3 = L1;
    Node *p1 = L1.head;  // 从表头开始找
    Node *p1_head = L1.head ;// 存放L1的头结点
    while(p1->next!= L1.head)
    {
        p1 = p1->next;
    }
    // 此时p1就是L1的表尾了
    Node *p2 = L2.head;  // 从表头开始找
    Node *p2_head = L2.head;// 存放L2的头结点
    while(p2->next!= L2.head)
    {
        p2 = p2->next;
    }
    // 找到了两个链表的尾指针
    // L2的表头连接L1的表尾
    p1->next = p2_head->next;
    delete p2_head;
    // L2的表尾连接L1的表头
    p2->next = p1_head;
    L3 = L1;
    return L3;
}

int main()
{
    // // 链表中插入值
    // List L;
    // for (int i =0 ;i<10;i++)
    // {
    //     L.insert(i);
    // }
    // L.list_print();
    // cout << "Inserts 100 before 5" << endl;
    // L.insert_pos(5,100);
    // L.list_print();
    // cout << "Delete the inserting 100" << endl;
    // L.erase(100);
    // L.list_print();
    // cout << "Reverse the list" << endl;
    // L.reverse();
    // L.list_print();
    // cout << "Use 100 to update the fifth item of the Link table " << endl;
    // L.update(5,100);
    // L.list_print();

    // 带尾指针的两个循环链表的合并
    // 首先创建两个链表
    List L1;
    List L2;
    // 往两个链表里分别插值
    for(int i = 10;i>0;i--)
    {
        L1.insert(i);
    }
    for(int j = 20;j>10;j--)
    {
        L2.insert(j);
    }
    L1.list_print();
    L2.list_print();
    List L3 = L1.MergeList(L1,L2);
    L3.list_print();

}

// 合并两个带尾指针的循环链表
