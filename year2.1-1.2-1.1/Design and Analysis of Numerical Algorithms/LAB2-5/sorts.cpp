void selectSort(int* arr, int size)
{
    int tmp, i, j, pos;
    for(i = 0; i < size; ++i)
    {
        pos = i;
        tmp = arr[i];
        for(j = i + 1; j < size; ++j)
        {
            if (arr[j] < tmp)
            {
               pos = j;
               tmp = arr[j];
            }
        }
        arr[pos] = arr[i];
        arr[i] = tmp;
    }
}

void bubbleSort(int* arr, int size)
{
    int tmp, i, j;
    for(i = 0; i < size - 1; ++i)
    {
        for(j = 0; j < size - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void insertSort(int* arr, int size)
{
    int i, j, tmp;
    for (i = 1; i < size; ++i)
    {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}
void shakerSort(int *arr, int size)
{
    for (int i = 0; i < size/2; i++)
    {
        bool swapped = false;
        for (int j = i; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = true;
            }
        }
        for (int j = size - 2 - i; j > i; j--)
        {
            if (arr[j] < arr[j-1])
            {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
}

void quickSort(int *arr, int l, int r)
{
    int x = arr[l + (r - l) / 2];
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(arr[i] > x)
        {
            i++;
        }
        while(arr[j] < x)
        {
            j--;
        }
        if(i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(arr, i, r);
    }
    if (l < j)
    {
        quickSort(arr, l, j);
    }
}

void shellSort(int *arr, int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j=i-gap; j>=0 && arr[j]>arr[j+gap]; j-=gap)
            {
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;

            }
        }
    }
}

void gnomeSort(int *arr, int n)
{
    int i = 0;
    while(i < n)
    {
        if(i == 0 || arr[i - 1] <=arr[i])
        {
            ++i;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            --i;
        }
    }
}
