#include<iostream>
using namespace std;

int main()
{
    int Anna;
    int Laura;
    int Oscar;
    cin >> Anna;
    cin >> Laura;
    cin >> Oscar;
    int count = 0;
    if(Laura > Anna && Oscar > Anna)
    {
        cout << "Anna"<<endl;
        count ++;
    }
    if(Anna>Laura)
    {
        cout << "Laura"<< endl;;
        count ++;
    }
    if(Anna > Oscar || Laura > Oscar)
    {
        cout << "Oscar" << endl;
        count++;
    }
    if (count ==0)
    {
        cout << "NONE";
    }
    
    return 0;
}