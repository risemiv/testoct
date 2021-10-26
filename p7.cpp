// Input:    1 2 3   4 5 6 7 8   9 10
// Output: 1 1 2 3 2 4 5 6 7 8 3 9 10

#include <iostream>
#include <cmath>

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

void inserare(int *&arr, int &n, int &index, int value)
{
    for (int i = n - 1; i >= index; i--)
        arr[i + 1] = arr[i];
    arr[index] = value;
    n++;
}

int main()
{
    int *arr, n;
    float sqrt;
    citire_vector(arr, n);
    for (int i = 0; i < n;)
    {
        sqrt = std::sqrt(arr[i]);
        if (sqrt == (int) sqrt)
        {
            inserare(arr, n, i, sqrt);
            i = i + 2;
        }
        else i++;
    }
    print_array(arr, n);
    return 0;
}
