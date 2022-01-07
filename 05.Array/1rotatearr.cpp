// rotate an array  by the function rotate(arr[],d,n) that rotates the array of size n elements by d elements
#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int d, int n)
{
    int temp = arr[n - 1];
    for (int i = (n - 1); i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}

int main()
{
    int n, d;
    cout << "Enter the size of array.\t";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:\t";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // printing the original array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Enter value of d\t";
    cin >> d;
    // calling the function
    for (int j = 0; j < d; j++)
    {
        rotate(arr, d, n);
    }

    // printing the rotated array
    cout << "The rotated array is:\t";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}