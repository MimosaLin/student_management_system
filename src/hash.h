#pragma once
#include<iostream>
#include<vector>
#include"studentsStruct.h"

struct hash_group
{
	seqlist::Student stu;
	int seat_num;
	bool flag=0;
};

class Hash
{
public:
	Hash(int size);
	~Hash();
	int hash_fun(seqlist::Student stu);
	void insert(seqlist::Student stu, int seat);
	hash_group search_seat(seqlist::Student);
	void update();
private:
	int seat_number;
	hash_group* seat_table;
	int capacity;
};