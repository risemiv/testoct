#include <iostream>
#include <climits>

void citire_vector(int *&arr, int &n)
{
    std::cout << "n = "; std::cin >> n;
    arr = new int[n];
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void merge(int *&A, int p, int q, int r)
{
    int n1 = q - p + 1, // computes the length n1 of the subarray A[p..q]
        n2 = r - q,     // computes the length n2 of the subarray A[q+1..r]
        /* We create arrays L and R ("left" and "right") of lenghts n1 + 1 and
         * n2 + 1; the extra position in each array will hold the sentinel. */
        *L = new int[n1 + 1],
        *R = new int[n2 + 1],
        i,
        j;
    // This for loop copies the subarray A[p..q] into L[1..n1].
    for(i = 0; i < n1; i++)
        L[i] = A[p + i];
    // This for loop copies the subarray A[q+1..r] into R[1..n2].
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    // These lines put the sentinels at the ends of the arrays L and R.
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void merge_sort(int *&A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int *arr, n, i;
    citire_vector(arr, n);
    merge_sort(arr, 0, n);
    std::cout << "Elementele de pe pozițiile pare sortate crescător:\n";
    for (i = 0; i < n; i = i + 2)
        std::cout << arr[i] << " ";
    std::cout << "\nElementele de pe pozițiile impare sortate descrescător:\n";
    for (i = n - 1; i > 0; i = i - 2)
        std::cout << arr[i] << " ";
    return 0;
}
