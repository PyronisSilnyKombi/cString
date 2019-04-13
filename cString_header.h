#pragma once
#include<iostream>
#include<vector>
#include<fstream>
class cNapis
{
	char *ptr_cNapis;
	int capacity;
public:
	//constructors
	cNapis();
	cNapis(int size): ptr_cNapis(new char[size]), capacity(size){ptr_cNapis[0] = '\0';}
	cNapis(const char* tab);
	cNapis(const cNapis& s);
	//operators
	cNapis& operator=(cNapis s);
	cNapis operator+(const cNapis& s);
	//methods
	bool empty() const;
	int size() const;
	char* get_ptr() const;
	void tolower();
	//friends
	friend std::ostream& operator<<(std::ostream & out, const cNapis & s);
	//friend std::istream& operator>>(std::istream & in, cNapis& s);
	friend std::istream& operator>>(std::istream & in, cNapis& s);

	~cNapis();
};