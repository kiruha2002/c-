#include <iostream>


template <typename T>
class standart_cmp
{
public:
    static bool less(const T &a, const T &b)
    {
        return a < b;
    }
};


template <typename T, typename cmp = standart_cmp<T> >
void merge(T *array, T *buffer, int left, int middle, int right)
{
    int it_left = 0;
    int it_right = 0;

    while (left + it_left < middle && middle + it_right < right)
    {
        if (cmp::less(array[left + it_left], array[middle + it_right]))
        {
            buffer[it_left + it_right] = array[left + it_left];
            it_left++;
        }
        else
        {
            buffer[it_left + it_right] = array[middle + it_right];
            it_right++;
        }
    }


    while (left + it_left < middle)
    {
        buffer[it_left + it_right] = array[left + it_left];
        it_left++;
    }

    while (middle + it_right < right)
    {
        buffer[it_left + it_right] = array[middle + it_right];
        it_right++;
    }


    for (int i = 0; i < it_left + it_right; i++)
        array[left + i] = buffer[i];
}

template <typename T, typename cmp = standart_cmp<T> >
void merge_sort(T *array, T *buffer, int left, int right)
{

    if (right - left <= 1)
    {
        return;
    }


    int middle = left + (right - left) / 2;


    merge_sort(array, buffer, left,  middle);
    merge_sort(array, buffer, middle, right);


    merge<T, cmp>(array, buffer, left, middle, right);
}

int main()
{
    int n;
    std::cin >> n;

    int *arr = new int[n];
    int *buff = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    merge_sort(arr, buff, 0, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
