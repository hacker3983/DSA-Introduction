#include <stdio.h>
#include <stdbool.h>
#define MAXIMUM_ARRAY_CAPACITY 50


void add_element(int* arr, int element, size_t* size) {
	if(*size == MAXIMUM_ARRAY_CAPACITY) {
		printf("You have reached the maximum capacity in the array\n");
		return;
	}
	arr[(*size)++] = element;
}

void remove_element(int* arr, int element, size_t* size) {
	if(!(*size)) {
		return;
	}
	size_t target_index = 0;
	bool found = false;
	for(size_t i=0;i<*size;i++) {
		if(arr[i] == element) {
			target_index = i;
			found = true;
			break;
		}
	}
	if(!found) {
		return;	
	}
	for(size_t i=target_index;i<(*size)-1;i++) {
		arr[i] = arr[i+1];
	}
	(*size)--;
}

void shift_element_toright(int* arr, size_t shift_index, size_t shift_count, size_t size) {
	if(!size || !shift_count) {
		return;
	}
	if(shift_index >= size) {
		return;
	}
	//shift_count %= size;
	for(size_t i=0;i<shift_count;i++) {
		if(shift_index < size-1) {
			int current_value = arr[shift_index];
			arr[shift_index] = arr[shift_index+1];
			arr[shift_index+1] = current_value;
			shift_index++;
		}
	}
}

void print_array(int* arr, size_t size) {
	printf("[");
	for(size_t i=0;i<size;i++) {
		printf("\033[32m%d\033[0m", arr[i]);
		if(i != size-1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main() {
	int arr[MAXIMUM_ARRAY_CAPACITY] = {0}, removal_list[] = {10, 20, 30, 50, 80, 100, 400, 410, 200};
	size_t size = 0, removal_count = sizeof(removal_list) / sizeof(int);
	for(size_t i=0, element=10;i<50;i++, element+=10) {
		printf("adding element: %zu\n", element);
		add_element(arr, element, &size);
	}
	puts("");
	printf("Array after adding elements:\n");
	print_array(arr, size);
	puts("");
	
	for(size_t i=0;i<removal_count;i++) {
		printf("removing element: %d\n", removal_list[i]);
		remove_element(arr, removal_list[i], &size);
	}
	puts("");
	printf("Array after removing elements:\n");	
	print_array(arr, size);
	puts("");

	size_t shift_indices_list[][2] = {
		{2, 5},
		{3, 2},
		{0, 50},
		{1, 10},
		{2, 15}
	};
	size_t shift_count = sizeof(shift_indices_list)/sizeof(size_t[2]);
	for(size_t i=0;i<shift_count;i++) {
		size_t shift_index = shift_indices_list[i][0], shift_places = shift_indices_list[i][1];
		printf("Gonna shift the element %d at index %zu, %zu places to the right\n", arr[shift_index],
				shift_index, shift_places);
		printf("Array after shifting element %d to the right:\n", arr[shift_index]);
		shift_element_toright(arr, shift_index, shift_places, size);	
		print_array(arr, size);
		if(i != shift_count-1) {
			puts("");
		}
	}
	return 0;
}
