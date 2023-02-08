// 在单向链表中，我们主要是关心一个结点指向后续的指针域，但是无前驱的指针域，找前驱结点比较难
// 查找某结点前驱结点的复杂度为O(n)
// 故提出双向链表，在单链表的每个结点里再增加一个指向其直接前驱的指针域prior,链表中有两个方向的链
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class List_D
{
public:
    // 构造函数
    List_D()
    {
        //创建链表
        Intial_List();
    }
    // 析构函数
    ~List_D()
    {
        clear();
    }
    // 创建头结点
    void Intial_List();
    // 清理链表
    void clear();
    // 求长度
    int getsize();
    // 判断是否为空
    bool isempty();
    // 创建链表
    void create_List(int Len);
    // 从头遍历打印链表
    void print_List_head();
    // 从尾巴遍历打印链表
    void print_List_tail();
    // 查找对应位置元素的值
    int find(int index);
    // 在特定位置插入
    void insert(int index,int data);
    // 头插法
    void insert_front(int data);
    // 尾插法
    void insert_append(int data);
    // 删除指定元素
    void erase(int index);
    // 两个线性表的合并
    List_D merge_list(List_D &L);
    // 将线性表中的元素改变为升序排列
    List_D ascending();
    
private:
    // 结点结构
    struct Node
    {
        int data;
        Node * prior;
        Node * next;
    };
    Node * head; // 头结点
    Node * tail; // 尾结点
};

void List_D::clear()
{
    // 清理链表函数
        if(getsize()!=0) // 空链表不能析构
        {
            Node * ptemp = head;  // 从头结点开始
            Node * p;
            while(p)
            {
                p = ptemp;
                ptemp = ptemp->next;
                delete p;
                p = nullptr;
            }
        }
}
void List_D::Intial_List()
{
    head = new Node;  // 定义一个头结点
    tail = new Node;  // 定义一个尾结点
    head->prior = nullptr;
    head->next = nullptr;
}

int List_D::getsize()
{
    Node * temp = new Node;
    temp = head;
    int length = 0;
    while(temp->next!=nullptr)
    {
        length++;
        temp = temp->next;
    }
    return length;

}

bool List_D::isempty()
{
    if(head == nullptr||head->next == nullptr)
    {
        cout << "The list is empty" << endl;
        return true;
    }
    else
    {
        cout << "The list is not empty" << endl;
        return false;
    }
}

void List_D::create_List(int len)
{
    if(len <= 0)
    {
        cout <<"Input is illegal" << endl;
        return;
    }
    head = new Node;
    head->next = nullptr;
    head->prior = nullptr;
    tail = new Node;
    tail = head;
    for(int i = 0;i < len;i++)
    {
        Node *pnew = new Node;  // 创建一个新结点
        cout << "please input a num: " << i+1 << " value: " <<endl; 
        cin >> pnew->data; 
        pnew->next = nullptr;
        pnew->prior = tail;
        tail->next = pnew;

        tail = pnew;
    }
    // 此时需要再新建一个结点将tail 置空
    Node *temp = new Node;
    temp->next = nullptr;
    temp->prior = tail;
    tail = temp;
}

void List_D::print_List_head()
// 从头开始遍历
{
    Node * temp = head->next;
    if(temp == nullptr)
    {
        cout << "This list is empty" << endl;
        return;
    }
    while(temp!=nullptr&&temp!=tail)
    {
        if(temp->next == nullptr)
        {
            cout << temp->data << endl;
        }
        else
        {
            cout << temp->data << "<->";
        }
        temp = temp->next;
    }
}

void List_D::print_List_tail()
// 从尾巴开始遍历
{
    Node *temp = tail;
    if(temp == nullptr)
    {
        cout << "This list is empty" << endl;
    }
    while(temp->prior!=nullptr&&temp->prior!=head)
    {
        temp = temp->prior; // 尾结点与头结点相同，只有指针域
        if(temp->prior->prior == nullptr )
        {
            cout << temp->data<<endl;
        }
        else
        {
             cout << temp->data << "<->" ;
        }
    }


}

int List_D::find(int index)
{
    int length = this->getsize();
    if(length == 0)
    {
        cout << "this list is empty" << endl;
    }
    if(index>length||index<=0)
    {
        cout << "Illegal index value" << endl;
        return 0;
    }
    // 这里采用了二分查找的思想，如果结点的值在前一半，
    // 就使用前驱遍历，如果是后一般，就使用后驱遍历
    // 这样计算更快，复杂度更低。
    if(index<=length/2) // 前一半
    {
        Node *temp = head;
        for(int i=0;i<index;i++)
        {
            temp = temp->next;
        }
        cout << "search from head" << endl;
        return temp->data;
    }
    else
    {
        Node *temp = tail;
        for(int i =0;i<length-index+1;i++)
        {
            temp = temp->prior;
        }
        cout << "search from tail" << endl;
        return temp->data;
    }
}

void List_D::insert(int index, int data)
{
    int length = this->getsize();
    if((index <= 0) || (index > length))
    {
        cout << "index error" << endl;
        return;
    }
    Node *p = new Node; // 定义一个新结点
    p->data = data;
    if(index <= length/2)  // 二分查找，前半部分
    {
        Node *temp = head;
        // 遍历找到想要插入位置的前一个元素
        for(int i = 0;i<index;i++)
        {
            temp = temp->next;
        }
        // 此时temp存的便是插入位置的前一个位置
        p->next = temp->next;
        temp->next = p;
        p->prior = temp;
    }
    else // 二分查找，后半部分
    {
        Node *temp = tail;
        for(int i = 0;i<length-index+1;i++)
        {
            temp = temp->prior;
        }
        p->prior = temp->prior;
        temp->prior = p;
        p->next = temp;
    }
}

void List_D::insert_front(int data)
{
    Node *p = new Node;
    p->data = data;
    if(this->getsize()==0)
    {
        cout << "This is an empty list" << endl;
        head = new Node;
        head->prior = nullptr;
        head->next = p;
        p->prior = head;
        tail = new Node;
        p->next = tail;
        tail->prior = p;
        tail->next = nullptr;
    }
    else
    {
        p->next = head->next;
        p->prior = head;
        head->next = p;
    }
}

void List_D::insert_append(int data)
{
    Node *p = new Node;
    p->data = data;
    if(this->getsize()==0)
    {
        cout << "This is an empty list" << endl;
        head = new Node;
        head->prior = nullptr;
        head->next = p;
        p->prior = head;
        tail = new Node;
        p->next = tail;
        tail->prior = p;
        tail->next = nullptr;
    }
    else
    {
        p->prior = tail->prior;
        p->next = tail;
        tail->prior = p;
    }
}

void List_D::erase(int index)
{  
    // 使用二分查找
    int length = this->getsize();
    if(length == 0)
    {
        cout <<"The list is empty" << endl;
    }
    else if(index <= length/2)
    {
        Node *p = head;
        for(int i =0;i<index;i++)
        {
            p = p->next;
        }
        // 现在已经找到了想删除元素位置的前一个结点
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;

    }
     else if(index>length/2)
    {
        Node *p =tail;
        for(int i=0;i<length-index+1;i++)
        {
            p=p->prior;
        }
        p->prior->next = p->next;
        p->next->prior = p->prior;
    }
}

// 有序表的合并，需要两个表都是一个升序排列
List_D List_D::merge_list(List_D &L)
{

    Node *pa = this->head->next;
    Node *pb = L.head->next;
    List_D La,Lb,Lc;
    La = *this;
    Lb = L;
    Lc.Intial_List(); // 新建c为一个空表
    Node *pc = Lc.head;  // 新建一个结点为c此时的头结点 
    while((pa)&&(pb))
    {
        if(pa->data <= pb->data)  // 尾插法，插入元素
        {
            // pc 的指针域指向小元素地址
            pc->next = pa;
            pc = pc->next;
            pa = pa->next;
        }
        else if(pa->data >= pb->data)
        {
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }
    }
    pc->next = (pa?pa:pb);
    delete Lb.head;
    return Lc;
}

List_D List_D::ascending()
{
   // 重新构建链表
   int a[getsize()];
   List_D L;
   L.Intial_List();
   vector<int> vec;
   Node * cur = this->head->next;
   while(cur)
   {
        vec.push_back(cur->data);
        cur = cur->next;
   }
   sort(vec.begin(),vec.end());
   cout << "after sorting"<<endl;
//    for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
//     {
        
//         cout << *it <<" ";
//     }
   L.head->next = L.tail;
   L.tail->data = vec[0];
   for (int i =1;i<=vec.size();i++)
   {
       L.tail->next = new Node;
       L.tail->next->data = vec[i];
       L.tail = L.tail->next;
   }
   L.tail->next = nullptr;
   return L;
}
    
void test01()
{
    // 测试合并前代码
    List_D L;
    int len;
    cout << "Please define the length of List: " <<endl;
    cin >> len;
    L.create_List(len);
    cout << "The list can be shown as:" << endl;
    L.print_List_head();
    L.print_List_tail();
    int size = L.getsize();
    cout << size << endl;
    int pos = L.find(5);
    cout << "The 5th number in the list is " << pos << endl;
    cout << "Insert 100 to the 5th element's position " << endl;
    L.insert(5,100);
    L.print_List_head();
    cout << "Insert 5 from head" << endl;
    L.insert_front(5);
    L.print_List_head();
}

void test02()
{
    //测试线性表的合并
    List_D L1;
    cout << "please input the length of list1" << endl;
    int len1;
    cin >> len1;
    L1.create_List(len1);
    List_D L2;
    cout << "please input the length of list2" << endl;
    int len2;
    cin >> len2;
    L2.create_List(len2);
    cout << "Now the two lists are shown as" << endl;
    L1.print_List_head();
    L2.print_List_head();
    // 现在两个链表已经创建好
    // 合并链表
    List_D L3 = L1.merge_list(L2);
    L3.print_List_head();
}

void test03()
// 测试是否能够升序排列链表
{
    List_D L;
    int len3;
    cout <<"please input the length of list"<<endl;
    cin >> len3;
    L.create_List(len3);
    L.print_List_head();
    L = L.ascending();
    L.print_List_head();
}



int main()
{
    test03();
    return 0;
}