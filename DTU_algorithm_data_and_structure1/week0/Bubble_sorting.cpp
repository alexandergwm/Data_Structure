
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int n = 7;
	int a[n];
	int i, j;
	int temp;                                 //用于缓存需要交换的数字
	cout << "Please input tem numbers" << endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(i = 0; i< n-1;i++)
    {
        for (j = 0; j<n-i-1;j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
	cout << "After bubble sorting" << endl;
	for (i = 0; i < n; i++)
	{
	    cout << a[i] << ' ';
	}
	cout << endl;
    system("pause");
	return 0;
}
