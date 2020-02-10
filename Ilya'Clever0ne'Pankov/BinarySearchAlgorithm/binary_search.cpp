int binarySearch(int *array, int left, int right, int x)
{
    int middle = left + (right - left) / 2;
    int length = right - left + 1;
    if (length <= 1)
    {
        if(array[middle] == x) return middle;
        else return -1;
    }
    if(array[middle] >= x)
    {
        return binarySearch(array, left, middle, x);
    }
    else
    {
        return binarySearch(array, middle + 1, right, x);
    }
}
