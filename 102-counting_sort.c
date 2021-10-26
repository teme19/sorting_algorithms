#include "sort.h"
/**
 * counting_sort - sorts an array using the counting sort algorithm
 *
 * @array: pointer to integer array
 * @size: size of integer array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *countarray = NULL, *newarray = NULL;
	int j, z, key = 0, newposition = 0, sum = 0, max = 0;
	size_t i, k, y, g;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	countarray = malloc((max + 1) * sizeof(int));
	if (!countarray)
		return;
	newarray = malloc((size) * sizeof(int));
	if (!newarray)
		return;
	for (j = 0; j < max; j++)
		countarray[j] = 0;
	for (k = 0; k < size; k++)
		countarray[array[k]] += 1;
	for (z = 0; z <= max; z++)
	{
		sum += countarray[z];
		countarray[z] = sum;
	}
	print_array(countarray, max + 1);
	for (y = 0; y < size; y++)
	{
		key = array[y];
		newposition = countarray[key];
		newarray[newposition - 1] = array[y];
		countarray[key]--;
	}
	for (g = 0; g < size; g++)
		array[g] = newarray[g];
	free(newarray);
	free(countarray);
}
