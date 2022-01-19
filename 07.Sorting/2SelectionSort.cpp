#include <bits/stdc++.h>
using namespace std;
void selsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(arr[min_index], arr[i]);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array:   ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selsort(arr, n);
    cout << "Displaying the sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}