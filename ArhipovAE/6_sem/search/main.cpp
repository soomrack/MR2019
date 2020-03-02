#include <iostream>

int search(int first, int last, int *a, int x){
    if (first == last) {
        if (a[first] == x)
            return first;
        else
            return -1;
    }
    int middle = (last - first) / 2 + first;
    //  if (a[middle] == x)
    //      return middle;
    if (a[middle] < x)
        return search(middle + 1, last, a, x);
    else
        return search(first, middle , a, x);

}
int main() {
    int a[7] = {1, 2};
    int k = search(0, 1, a, 2);
    printf ("%d", k);
}