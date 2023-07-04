#include<iostream>
#include"hash.h"
#include<string>
#include"studentsStruct.h"
using namespace std;

Hash::Hash(int size)
{
	seat_number = 0;
	capacity = size;
	seat_table = new hash_group[capacity];
}

Hash::~Hash()
{
	delete[] seat_table;
}

int Hash::hash_fun(seqlist::Student stu)
{
	string name = stu.name;
	int index = 0;
	for (char c : name) {
		index = index * 31 + c;
	}
	return index% capacity;
}

void Hash::insert(seqlist::Student stu,int seat)
{
	if (seat_number * 2 > capacity)update();
	int index = hash_fun(stu);
	hash_group temp;
	temp.stu = stu;
	temp.seat_num = seat;
	
	if (index < 0)index = -index;
	while (seat_table[index].flag)
	{
		index++;
		if (index == capacity)index = 0;
	}
	seat_table[index] = temp;
	seat_table[index].flag = 1;
	seat_number++;
	
}

hash_group Hash::search_seat(seqlist::Student stu)
{
	int index = hash_fun(stu);
	if (index < 0)index = -index;
	
	while (seat_table[index].stu.id != stu.id)
	{
		index++;
		if (index == capacity)index = 0;
	}
	return seat_table[index];
}

void Hash::update()
{
	cout << "进入更新函数" << endl;
	int size = capacity;
	capacity = capacity * 2;
	hash_group* temp = new hash_group[capacity];
	for (int i = 0; i < size; i++)
	{
		if (seat_table[i].flag)
		{
			int index = hash_fun(seat_table[i].stu);
			if (index < 0)index = -index;
			cout << index << endl;
			while (temp[index].flag)
			{
				index++;
				if (index == capacity)index = 0;
			}
			hash_group new_temp;
			new_temp.stu = seat_table[i].stu;
			new_temp.flag = 1;
			new_temp.seat_num = seat_table[i].seat_num;
			temp[index] = new_temp;
		}
	}
	delete[]seat_table;
	seat_table = nullptr;
	seat_table = new hash_group[capacity];
	for (int i = 0; i < capacity; i++)
	{
		seat_table[i] = temp[i];
	}
	delete[]temp; 
	temp = nullptr;
}
