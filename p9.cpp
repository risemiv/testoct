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

int suma_elementelor(int *&arr, int &n, int &S)
{
    S = 0;
    for (int i = 0; i < n; i++)
        S += arr[i];
    return S;
}

bool is_palindrome (int &n)
{
    int n1 = n, n2 = 0;
    unsigned short int u;
    while (n1 > 0)
    {
        u = n1 % 10;
        n2 = n2 * 10 + u;
        n1 /= 10;
    }
    return n == n2;
}

void ștergere(int *&arr, int &n, int &index)
{
    for (int i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main()
{
    int *arr, n;
    citire_vector(arr, n);
    for (int i = 1; i < n; i++)
        if (i % 2 == 1 && is_palindrome(arr[i]))
            ștergere(arr, n, i);
    print_array(arr, n);
    return 0;
}
