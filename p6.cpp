#include <iostream>
#include <climits>

void print_array(int *&arr, int &n)
{
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

void citire_vector(int *&arr, int &n)
{
    std::cout << "n = "; std::cin >> n;
    arr = new int[n + n / 2];
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void inserare(int *&arr, int &n, int &index, int &value)
{
    for (int i = n - 1; i >= index; i--)
        arr[i + 1] = arr[i];
    arr[index] = value;
    n++;
}

int main()
{
    int *arr, n, max = INT_MIN, i;
    citire_vector(arr, n);
    for (i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for  (i = 2; i < n; i = i + 2)
        inserare(arr, n, i, max);
    print_array(arr, n);
    return 0;
}
