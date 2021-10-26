#include <iostream>

void citire_vector(int *&arr, int &n)
{
    std::cout << "n = "; std::cin >> n;
    arr = new int[n];
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

int main()
{
    int *arr, n, x, count = 0;
    citire_vector(arr, n);
    std::cout << "x = "; std::cin >> x;
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            count++;
    std::cout << "Elementul x apare de " << count << " ori în vectorul v.\n";
    return 0;
}
