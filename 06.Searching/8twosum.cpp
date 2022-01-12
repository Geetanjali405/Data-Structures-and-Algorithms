// two pointer approach
// given a sorted array and a sum ,find if there is a pair with given sum
#include <iostream>
using namespace std;
bool pair2(int arr[], int n, int sum)
{
    int l = 0, h = n - 1;
    while (l < h)
    {
        if (arr[l] + arr[h] == sum)
            return true;
        else if (arr[l] + arr[h] > sum)
            h--;
        else
            l++;
    }
    return false;
}
int main()
{
    int arr[] = {2, 5, 8, 12, 30};
    int x = 17;
    int n = 5;
    if (pair2(arr, n, x))
        cout << "yes";
    else
        cout << "no";
    return 0;
}