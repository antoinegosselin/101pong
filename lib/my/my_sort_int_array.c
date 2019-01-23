/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** Function that sorts an array of int by ascending order
*/

static void sort_that_array(int *array, int size, int i)
{
    int swapping_value;

    for (int j = i + 1; j < size; j++) {
        if (array[i] > array[j]) {
            swapping_value = array[j];
            array[i] = array[j];
            array[j] = swapping_value;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        sort_that_array(array, size, i);
    }
}