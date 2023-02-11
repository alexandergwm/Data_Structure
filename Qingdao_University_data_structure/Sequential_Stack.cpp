// 栈和队列是两种常用的，重要的数据结构
// 栈和队列是限定插入和删除只能在表的“端点”进行的线性表
// 最后插入的元素在删除的时候会被最先删除
// 栈就像弹夹，后进先出,只能在表尾进行删除和插入，最后插入的元素最先被删除
// 队列是先进先出

#include<iostream>
using namespace std;
#define MAXSIZE 100

class SqStack
{
public:
    SqStack()
    {   
        InitStack();
    }
    ~SqStack()
    {
        DestroyStack();
    }
    // 初始化空栈
    void InitStack();
    // 判断顺序栈是否为空
    bool IsEmpty();
    // 求顺序栈的长度
    int StackLength();
    // 清空栈内元素
    void ClearStack();
    // 销毁顺序栈
    void DestroyStack();
    // 入栈
    void Push(int e);
    // 出栈
    int Pop();
    // 栈的打印
    void PrintStack();

private:
    int *top;  // 栈顶指针
    int *base; // 栈底指针
    int stacksize;  // 栈存放最大元素个数
};

// 初始化空栈
void SqStack::InitStack()
{
    base = new int[MAXSIZE];
    if(!base)
    {
        cout<<"failed to get memory for stack" << endl;
    }
    top = base;
    stacksize = MAXSIZE;
    cout << "Intialise successfully" << endl;
}

bool SqStack::IsEmpty()
{
    if (base == top)
    {
        //cout << "The stack is empty" << endl;
        return true;
    }
    else
    {
        //cout << "The stack is not empty" << endl;
        return false;
    }
}

void SqStack::ClearStack()
{
    if(base)
    {
        top = base;
    }
    cout << "The stack is cleared" << endl;
}

int SqStack::StackLength()
{
    return top - base;
}

void SqStack::DestroyStack()
{
    if(base)
    {
        delete base;
        stacksize = 0;
        base = top =nullptr;
    }
}

void SqStack::Push(int e)
{
    // 先判断是否栈满，若满则出错（上溢）
    if((top-base)==stacksize)
    {
        cout << "full of stack" << endl;
    }
    *top = e;
    top++;
}

int SqStack::Pop()
{
    // 先判断栈是否为空
    if(IsEmpty())
    {
        cout << "Error, this stack is empty" << endl;
    }
    top--;
    int e = *top;
    return e;
}

void SqStack::PrintStack()
{
    // 先判断栈是否为空
    if(IsEmpty())
    {
        cout << "error" << endl;
    }
    cout << "Now print this stack " << endl;
    for( ; top!=base;)
    {
        // 因为在pop处已经对栈顶指针--了
        cout << Pop() << endl;
    }
}

int main()
{
    SqStack S;
    S.IsEmpty();
    int len = S.StackLength();
    cout << "The length of stack is " << len << endl;
    S.ClearStack();
    int e = 100;
    for (int i =0 ;i <10;i++)
    {
        S.Push(i);
    }
    S.PrintStack();
    return 0;
}
