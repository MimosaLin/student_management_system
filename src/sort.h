#pragma once
#ifndef SORT_H
#define SORT_H
#include <iostream>
#include"studentsStruct.h"
#include"seqList.h"

void insert_sort(SeqList& list)
{
	int n = list.get_length();
	for (int i = 1; i < n; i++)
	{
		seqlist::Student stu = list[i];
		int grade = stu.grade;
		int j = i - 1;
		int flag = 0;
		for (; j >= 0; j--)
		{
			if (grade > list[j].grade)
			{
				list[j + 1] = list[j];
				flag = 1;
			}
			else break;
		}
		if (flag) list[j+1] = stu;
	}
}

void swap(SeqList& list, int i, int j)
{
	seqlist::Student temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}


void quick_sort(SeqList& list, int begin, int end)
{
    if (begin >= end) return;
    int pivot = list[begin].grade;
    int i = begin + 1;
    int j = end;
    while (i <= j) {
        while (i <= j && list[i].grade > pivot) {
            i++;
        }
        while (i <= j && list[j].grade < pivot) {
            j--;
        }
        if (i <= j) {
            swap(list, i, j);
            i++;
            j--;
        }
    }
    int pivotIndex = j;
    while (pivotIndex > begin && list[pivotIndex].grade == pivot) {
        pivotIndex--;
    }
    swap(list, begin, pivotIndex);
    quick_sort(list, begin, pivotIndex - 1);
    quick_sort(list, pivotIndex + 1, end);
}



void heap_adjust(SeqList& list,int k)
{
    int max_index = k;
    int right = 2 * k + 2;
    int left = 2 * k + 1;
    if (k > list.get_length() / 2 - 1)return;
    if (2 * k + 2 < list.get_length() && list[k].grade < list[2 * k + 2].grade)max_index = right;
    if (list[max_index].grade < list[2 * k + 1].grade)max_index = left;
    if (max_index != k)swap(list, max_index, k);
    heap_adjust(list, 2 * k + 2);
    heap_adjust(list, 2 * k + 1);
}

void heapify(SeqList& list)
{
    int mid = list.get_length() / 2 - 1;
    for (int i = mid; i >= 0; i--)
    {
        heap_adjust(list, i);
    }
}

void heap_sort(SeqList& list)
{
    SeqList heap_list = list;
    heapify(heap_list);
    for (int i = 0; i < heap_list.get_length(); i++)
    {
        
        seqlist::Student maximum = heap_list[0];
        for (int j = 1; j <heap_list.get_length(); j++)
        {
            heap_list[j - 1] = heap_list[j];
        }
        seqlist::Student temp;
        temp.grade = 0;
        heap_list[heap_list.get_length() - 1] = temp;
        heapify(heap_list);
        list[i] = maximum;
    }
}

#endif
