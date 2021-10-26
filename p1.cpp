// P1.

#include <iostream>

int main()
{
    int *a, n, key, i;
    std::cout << "n = ";
    std::cin >> n;
    a = new int [n];
    std::cout << "v:";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    for (int j = 1; j < n; ++j)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }

    std::cout << "v:";
    for (int i = 0; i < n; ++i)
    {
        std::cout << " " << a[i];
    }
    std::cout << "\n";

	return 0;
}
