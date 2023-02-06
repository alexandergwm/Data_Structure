// 单向链表
// 地址的存储在物理上不是连续的，逻辑上相邻的元素物理上不相邻，上一个结点存储下一个结点的地址
// 结点：数据域+指针域  最后一个结点存储的地址为空，
// 结点只有一个指针域的链表为单链表或线性链表
// 结点有两个指针域的链表，为双链表，双链表一个指针域存储前向地址，一个存储后向地址
// 首尾相接的链表称为循环链表，最后一个元素的指针域指向带头结点


#include <iostream>
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
    void insert_pos(const int &d, const int &d1);
    // 删除指定数据的结点
    void erase(const int &d);
    // 修改指定数据
    void update(const int &d, const int &d1);
    // 反转链表函数
    void reverse();
    // 打印链表
    void list_print();
private:
    // 节点结构
    struct Node
    {
        int data;
        Node * next;
        Node(const int &d):data(d),next(NULL){}
    };
    Node * head; // 定义头结点
    // 清理链表函数
    void clear()
    {
        Node * p = head;   // 从头结点开始
        while(p)
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
        for(;p;p=p->next)
        {
            if(p->next->data == d)
                break;
        }
        return p;
    }
};

// 创建头结点
void List::create_List()
{
    head = new Node(0);
    head->next = NULL;
}

// 从头插入一个结点
void List::insert(const int &d)
{
    Node *p = new Node(d);
    p->next = head->next;
    head->next = p;
}

// 在d位置之前插入d1
void List::insert_pos(const int &pos, const int &d1)
{
    Node *p = find(pos);
    Node *q = new Node(d1);
    q->next = p->next;
    p->next = q;
}

// 删除指定数据的结点
void List::erase(const int &d)
{
    Node *p = find(d);
    // 先找到d对应的上一个结点的位置
    // 用q来保存要删除的结点的地址
    Node *q = p->next;
    p->next = p->next->next;
    delete q;
}
// 修改指定数据的数据
void List::update(const int &d, const int &d1)
{
    Node *p = find(d);
    p->next->data = d1;
}
// 反转链表函数
void List::reverse()
{
    Node *p = head->next;  // 此时定义结点为头结点之后第一个结点
    Node *q = head->next->next;  // 头结点之后的第2个结点
    Node *m = head->next->next->next;  // 头结点之后的第3个结点
    p->next = NULL;   // 头结点之后的第一个结点的next指针置空
    // 根据m是否为空来判断，然后逆序每一个结点
    while(m)
    {
        q->next = p;
        p = q;
        q = m;
        m = m->next;
    }
    // 将最后一个结点逆序
    q->next = p;
    // 将头结点指向新的第一个结点（也就是之前的最后一个结点）
    head->next = q;
}

// 打印链表
void List::list_print()
{
    for (Node *p = head->next;p;p = p->next)
    {
        if(p->next != NULL)
        {
            cout << p->data << "->";
        }
        else
        {
            cout << p->data << endl;
        }
       
    }

}

int main()
{
    // 链表中插入值
    List L;
    for (int i =0 ;i<10;i++)
    {
        L.insert(i);
    }
    L.list_print();
    cout << "Inserts 100 before 5" << endl;
    L.insert_pos(5,100);
    L.list_print();
    cout << "Delete the inserting 100" << endl;
    L.erase(100);
    L.list_print();
    cout << "Reverse the list" << endl;
    L.reverse();
    L.list_print();
    cout << "Use 100 to update the fifth item of the Link table " << endl;
    L.update(5,100);
    L.list_print();
}

