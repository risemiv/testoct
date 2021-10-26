#include <iostream>

void print_array(float *&arr, int &n)
{
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

void citire_vector(float *&arr, int &n)
{
    std::cout << "n = "; std::cin >> n;
    arr = new float[n + n / 2];
    std::cout << "v: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void inserare(float *&arr, int &n, int index, float value)
{
    for (int i = n - 1; i >= index; i--)
        arr[i + 1] = arr[i];
    arr[index] = value;
    n++;
}

int main()
{
    int n, count = 0;
    float *arr, sum = 0.0, ma = 0.0;
    citire_vector(arr, n);
    for (int i = 0; i < n;)
    {
        if ((int) arr[i] % 2 == 1)
        {
            sum += arr[i];
            count++;
            ma = sum / count;
            i++;
        } else {
            inserare(arr, n, i+1, ma);
            i = i + 2;
        }
    }
    print_array(arr, n);
    return 0;
}
