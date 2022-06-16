#include <cs50.h>
#include <stdio.h>

void merge(int L, int R, int arr[], int temp[])
{
    int mid = (L + R) / 2;
    int right_index = mid + 1;
    int left_index = L;
    int i = L;
    // check for the smallest number
    while (i <= R)
    {
        if (left_index > mid)
        {
            temp[i] = arr[right_index];
            right_index++;
        }
        else if (right_index > R)
        {
            temp[i] = arr[left_index];
            left_index++;
        }
        else if (arr[left_index] >= arr[right_index])
        {
            temp[i] = arr[right_index];
            right_index++;
        }
        else if (arr[right_index] >= arr[left_index])
        {
            temp[i] = arr[left_index];
            left_index++;
        }
        i++;
    }
    // copying the temp array to the original array
    for (int j = L; j < R + 1; j++)
    {
        arr[j] = temp[j];
    }
}
void merge_sort(int L, int R, int arr[], int temp[])
{
    if (R <= L)
    {
        return;
    }
    else
    {
        int mid = (L + R) / 2;
        merge_sort(L, mid, arr, temp);
        merge_sort(mid + 1, R, arr, temp);
        merge(L, R, arr, temp);
    }
}
int main(void)
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int temp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    merge_sort(0, 7, arr, temp);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", temp[i]);
    }
}