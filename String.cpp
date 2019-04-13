#include"cString_header.h"


cNapis::cNapis() {
	ptr_cNapis = NULL;
	capacity = 0;
}

cNapis::cNapis(const char *tab)
{
	if (tab)
	{
		int size = strlen(tab) + 1;
		ptr_cNapis = new char[size];
		memset(ptr_cNapis, 0, size);
		capacity = size;
		memcpy(ptr_cNapis, tab, strlen(tab));
	}
}

cNapis::cNapis(const cNapis &s)
{
	if (!s.empty())
	{
		this->ptr_cNapis = new char[s.size() + 1];
		this->capacity = s.size() + 1;
		memset(this->ptr_cNapis, 0, this->capacity);
		memcpy(this->ptr_cNapis, s.get_ptr(), this->capacity);
	}
}

bool cNapis::empty() const
{
	if (this->ptr_cNapis){
		if (memcmp(this->ptr_cNapis, "", strlen(this->ptr_cNapis)) == 0)
			return true;
		else
			return false;
	}
	return true;
}

void cNapis::tolower() {
	for (int i = 0; ptr_cNapis[i] != 0; i++)
	{
		if (ptr_cNapis[i] > 64 && ptr_cNapis[i] < 90) {
			ptr_cNapis[i] += 32;
		}
	}
}

cNapis& cNapis::operator=(cNapis s)
{
	std::swap(s.ptr_cNapis, ptr_cNapis);
	this->capacity = s.capacity;
	return *this;
}

cNapis cNapis::operator+(cNapis const& s)
{
	cNapis  result(size() + s.size() + 1);

	std::copy(ptr_cNapis, ptr_cNapis + size(), result.ptr_cNapis);
	std::copy(s.ptr_cNapis, s.ptr_cNapis + s.size(), result.ptr_cNapis + size());
	result.ptr_cNapis[size() + s.size()] = '\0';

	return result;
}

int cNapis::size() const
{
	if (this->ptr_cNapis)
	{
		return strlen(this->ptr_cNapis);
	}
	else
	{
		return 0;
	}
}

char * cNapis::get_ptr() const
{
	if (this->ptr_cNapis)
	{
		return this->ptr_cNapis;
	}
	else
	{
		return NULL;
	}
}

std::ostream & operator<<(std::ostream & out, const cNapis & a)
{
	for (int i = 0; a.ptr_cNapis[i] != 0; i++) {
		std::cout << a.ptr_cNapis[i];
	}
	return out;
}
//
//std::istream& operator >>(std::istream & in, cNapis& s)
//{
//	char* input = new char[100];
//	in.getline(input, 100);
//
//	int i = 0;
//	while (input[i] != '\0')
//	{
//		i++;
//	}
//	s.capacity = i + 1;
//	delete[]s.ptr_cNapis;
//	s.ptr_cNapis = new char[(i + 1)];
//	for (int j = 0; j < (i); j++)
//	{
//		s.ptr_cNapis[j] = input[j];
//	}
//	s.ptr_cNapis[i] = '\0';
//	delete[]input;
//	return in;
//}

std::istream& operator>>(std::istream & in, cNapis& s) {
	char* input = new char[100];
	in.getline(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
		if (input[i] == '/') break;	
	}
	s.capacity = i + 1;
	delete[] s.ptr_cNapis;
	s.ptr_cNapis = new char[(i + 1)];
	int k=0;
	for (int j = 0; j < (i); j++)
	{
		if (input[j] != '-') {
			s.ptr_cNapis[k] = input[j];
			k++;
		}

	}
	s.ptr_cNapis[k] = '\0';
	delete[]input;
	return in;
}

cNapis::~cNapis()
{
	delete[] this->ptr_cNapis;
}