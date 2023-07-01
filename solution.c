#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Starting of the function to find numbers closest to zero
void close_to_zero(int arr[], int n, int *a, int *b)
{
    // Sorting of the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int min_diff = 999999;   // A big number always greater than the difference of any two elements of the array
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int curr_sum = arr[left] + arr[right];
        int curr_diff = abs(curr_sum);

        if (curr_diff < min_diff)
        {
            min_diff = curr_diff;
            *a = arr[left];
            *b = arr[right];
        }

        if (curr_sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

int main()
{   int index;
    printf("Enter the number of element in the array\n");
    scanf("%d",&index);
    int nums[index];
    printf("Now enter the value for each array element \n");
    for (size_t i = 0; i < index; i++)
    {
    scanf("%d",&nums[i]);
    }
    
     int n = sizeof(nums) / sizeof(nums[0]);
    int a ,b;

    close_to_zero(nums, n, &a, &b);

    printf("The set two required numbers is : [%d, %d]\n", a, b);

    return 0;
}
