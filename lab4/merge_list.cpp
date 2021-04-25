#include <iostream>
using namespace std;

struct Cells
{
	int value;
	Cells* next_ptr;
};

struct List
{
	int length;
	Cells* first;
	Cells* last;
};







List append(List list, int value)
{
	Cells* cell = new Cells;
	(*cell).value = value;
	(*cell).next_ptr = nullptr;
	if (list.length == 0)
	{
		list.first = cell;
	}
	else
	{
		if (list.length == 1)
		{
			list.last = list.first;
			(*list.first).next_ptr = cell;
		}
		(*list.last).next_ptr = cell;
		list.last = cell;
	}
	list.length += 1;
	return list;
}


List merge(List first_list, List second_list)
{
	Cells* cell;
	if (second_list.length != 0)
	{
		cell = second_list.first;
		while ((*cell).next_ptr != nullptr)
		{
			first_list = append(first_list, (*cell).value);
			cell = (*cell).next_ptr;
		}
		first_list = append(first_list, (*cell).value);
	}
	return first_list;
}

