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

List create_empty()
{
	List list;
	list.length = 0;
	list.first = nullptr;
	list.last = nullptr;
	return list;
}

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

List copy_list(List list)
{
	Cells* cell;
	List copy;
	copy = create_empty();
	cell = list.first;
	while ((*cell).next_ptr != nullptr)
	{
		copy = append(copy, (*cell).value);
		cell = (*cell).next_ptr;
	}
	copy = append(copy, (*cell).value);
	return copy;
}
