// P2.

#include <iostream>

void bubbleSort(int A[], int length)
{
    int i, j;
    bool exchanged;
    for (i = 0; i < length - 1; i++)
    {
    exchanged = false;
    for (j = 0; j < length - i - 1; j++)
        if (A[j+1] < A[j])
        {
            std::swap(A[j+1], A[j]);
            exchanged = true;
        }
    if (!exchanged)
        break;
   }
}

int main()
{
    int *A, n;
    std::cout << "n = ";
    std::cin >> n;
    A = new int [n];
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cin >> A[i];
    bubbleSort(A, n);
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    return 0;
}
