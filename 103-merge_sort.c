#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order using the Merge
 * sort algorithm
 *
 * @array: pointer to integer array
 * @size: size of integer array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *comparray = NULL;

	if (!array || size < 2)
		return;
	comparray = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
		comparray[i] = array[i];
	split_array(comparray, 0, size, array);
	free(comparray);
}
/**
 * split_array - splits an array via recursive calls
 *
 * @comparray: pointer to integer array
 * @left: left element
 * @right: right elemeent
 * @array: pointer to integer array
 *
 * Return: Nothing
 */
void split_array(int *comparray, size_t left, size_t right, int *array)
{
	int middle;

	if (right - left < 2)
		return;
	middle = (right + left) / 2;
	split_array(array, left, middle, comparray);
	split_array(array, middle, right, comparray);
	merge_arrays(comparray, left, middle, right, array);
}
/**
 * merge_arrays - merges arrays in sorted order
 *
 * @array: pointer to integer array
 * @left: left element
 * @middle: middle element
 * @right: right element
 * @comparray: pointer to integer array
 *
 * Return: Nothing
 */
void merge_arrays(int *array, size_t left, size_t middle, size_t right,
int *comparray)
{
	size_t i = left, j = middle, z = 0;

	printf("Merging...\n");
	printf("[left]: ");
	for (z = left; z < middle; z++)
	{
		if (z < middle - 1)
			printf("%d, ", array[z]);
		else
			printf("%d\n", array[z]);
	}
	printf("[right]: ");
	for (z = middle; z < right; z++)
		if (z < right - 1)
			printf("%d, ", array[z]);
		else
			printf("%d\n", array[z]);
	for (z = left; z < right; z++)
	{
		if (i < middle && (j >= right || array[i] <= array[j]))
		{
			comparray[z] = array[i];
			i++;
		}
		else
		{
			comparray[z] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	for (z = left; z < right; z++)
		if (z < right - 1)
			printf("%d, ", comparray[z]);
		else
			printf("%d\n", comparray[z]);
}
