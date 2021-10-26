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

bool is_prime (int n)
{
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;
    return true;
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
    int *arr, n, S;
    citire_vector(arr, n);
    S = suma_elementelor (arr, n, S);
    for (int i = 0; i < n;)
    {
        // Din enunț, înțeleg că poziția i trebuie
        // să fie numărul prim, nu elementul v[i].
        if (is_prime(i))
        {
            inserare(arr, n, i, S);
            i = i + 2;
        }
        else i++;
    }
    print_array(arr, n);
    return 0;
}
