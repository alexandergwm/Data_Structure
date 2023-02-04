#include<iostream>
#include<math.h>
using namespace std;

// int log2(int value)  
// // Using recursion to determine how many times a number is 2
// {
//     if (value == 1)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1+log2(value>>1);
//     }
// }

void test01()
// if 128 programmer and 1 room we have to find the diseased programmer using at most 7 tests.
{
    int num_Pro = 128;
    int num_Room = 1;
    num_Room ++;
    int count = 0;
    while(num_Pro != 1)
    {
        num_Pro = num_Pro / 2;
        count ++;
    }
    cout << "The number of most tests is " << count << endl;

}
void test02()
// The tests I need if I have n programmers instead of 128 is the closest bigger the power of 2
{
    int num_Pro;
    cin >> num_Pro;
    int count = 0;
    int num_Ori = num_Pro;
    while(num_Pro != 1)
    {
        num_Pro = ceil(num_Pro/2);
        count ++;
   
    }
    
    if (num_Ori < pow(2,count+1)&& (num_Ori&(num_Ori-1)))
    {
        count = count+1 ;
    }

    cout << "The maximum number of tests is " << count << endl;
}

void test03()
// Now we have k>1 rooms and can use to test k groups of programmers simultaneously.
// there are still some problems
{
    // Get the number of rooms
    int num_Pro;
    cin >> num_Pro;
    int num_Rooms;
    cin >> num_Rooms;
    num_Rooms = num_Rooms + 1;
    int num_Ori = num_Pro;
    int count = 0;
    while(num_Pro != 1)
    {
        num_Pro = ceil(num_Pro/num_Rooms);
        count++;
    }
    if (num_Ori < pow(num_Rooms,count+1)&& (num_Pro % num_Rooms == 0))
    {
        count = count+1 ;
    }

    cout << "The maximum number of tests is " << count << endl;

}

int main()
{
    test03();
    return 0;
}