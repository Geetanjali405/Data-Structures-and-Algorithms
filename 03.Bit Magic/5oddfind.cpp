// all numbers appear even number of times except one number ,we need to find only odd occuring number

#include <iostream>
using namespace std;
void num(int arr[])
{
    //  naive solution,TC-O(n^2)
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count % 2 != 0)
        {
            cout << arr[i] << endl;
            break;
        }
    }
}
void findodd(int arr[])
{
    // Time complexity->O(n) and Space complexity->O(1)
    int res = 0;
    for (int i = 0; i < 5; i++)
        res = res ^ arr[i];
    cout << res << endl;
}
int main()
{
    int count = 0;
    int arr[5] = {
        8,
        7,
        7,
        8,
        8,
    };
    cout << "NAIVE METHOD" << endl;
    num(arr);
    cout << "EFFICIENT METHOD" << endl;
    findodd(arr);
    return 0;
}