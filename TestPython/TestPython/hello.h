#ifndef MY_STRING_H
#define MY_STRING_H

#include <string> 
#include <initializer_list>

class MyString
{

public:
	static constexpr const size_t npos = -1;


public:
	MyString();							
	MyString(const MyString& other);			

	MyString(const char* const cchar_array);				
	MyString(const std::string& std_string);				

	MyString(const size_t count, const char c); 
	MyString(const std::initializer_list<char>& list);
	MyString(const char* const cchar_array, const size_t count);


	~MyString();

	//=
	MyString& operator = (const MyString& other);
	MyString& operator = (const char* cchar_array);
	MyString& operator = (const std::string& std_string);
	MyString& operator = (char c);

	//=  for Python
	void equall_c(char c);
	void equall_std_string(const std::string& std_string);
	void equall_char_array(const char* cchar_array);
	//MyString& equall_c(char std_string);

	//__str__ for Python
	const char* __str__()
	{
		return this->c_str();
	}

	// +=
	MyString& operator += (const MyString& other);
	MyString& operator += (const char* cchar_array);
	MyString& operator += (const std::string& std_string);

	//+
	//friend MyString operator+ (const MyString& left_other, const MyString& right_other); //friend???? friend.
	//friend MyString operator+ (const MyString& other, const char* cchar_array);
	//friend MyString operator+ (const MyString& left_other, const std::string& std_string);

	MyString operator+ (const MyString& left_other) const;
	MyString operator+ (const char* cchar_array) const;
	MyString operator+ (const std::string& std_string) const;

	//friend bool operator == (const MyString& left, const MyString& right);

	bool operator == (const MyString& left) const;
	bool operator != (const MyString& left) const;
	bool operator <  (const MyString& left) const;
	bool operator >  (const MyString& left) const;
	bool operator <= (const MyString& left) const;
	bool operator >= (const MyString& left) const;

	//for Python
	void __setitem__(size_t i, char c);
	const char __getitem__(size_t i);

	//	Element access 
	const char& operator [] (size_t) const;
	char& operator [] (size_t);

	const char* c_str() const;
	const char* data() const;

	size_t length() const;
	size_t size() const;
	bool empty() const;

	size_t capacity() const; // return the current amount of allocated memory for array
	void shrink_to_fit(size_t cap); // reduce the capacity to size 
	void clear();


	size_t find(const char* cchar_array, size_t pos) const;
	size_t find(const char* cchar_array) const;
	size_t find(const std::string& std_string, size_t pos) const;
	size_t find(const std::string& std_string) const;

	MyString& append(const char* cchar_array);
	MyString& append(const char* cchar_array, size_t index, size_t count);
	MyString& append(const std::string& std_string);
	MyString& append(const std::string& std_string, size_t index, size_t count);
	MyString& append(size_t count, char c);

	MyString& insert(size_t index, const char* cchar_array);
	MyString& insert(size_t index, const char* cchar_array, size_t count);
	MyString& insert(size_t index, size_t count, char c);
	MyString& insert(size_t index, const std::string& std_string);
	MyString& insert(size_t index, const std::string& std_string, size_t count);

	MyString& erase(size_t index, size_t count);

	MyString& replace(size_t index, size_t count, const char* cchar_array);
	MyString& replace(size_t index, size_t count, const std::string& std_string);

	MyString substr(size_t index, size_t count) const;
	MyString substr(size_t index) const;


private:
	void _dealloc_cstring(char*& buffer);
	void _setLength(const size_t len);
	void _clear_str(const size_t pos);
	void _setCapacity(const size_t cap);
	void _increaseCapacity(const size_t cap);
	void _decreaseCapacity(const size_t cap);
	char* _alloc_cstring(const size_t count) const;
	void _fill_str(char* cchar_array, const size_t len, size_t pos, char c) const;
	void _append(const char* cchar_array, size_t n);
	void _append(const char* cchar_array);
	size_t _strlen(const char* cchar_array);
	bool _find_compare(const char* cchar_array, size_t len, size_t pos) const;
	int _compare(const MyString& other) const; //strcoll - it should be lexicographically comparing. maybe i should use classic strcmp?
	char* _substr(const char* cchar_array, size_t pos, size_t len) const;
	char* _alloc_cstring(const size_t count, char c) const;
	size_t _find(const char* cchar_array, size_t pos, size_t len) const;
	void _insert(size_t pos, const char* cchar_array, size_t count);
	void _erase(size_t pos, size_t count);
	void _replace(size_t pos, size_t count, const char* cchar_array);

private:
	size_t _length = 0;				// length
	size_t _capacity = 0;			// capacity
	char* _str = nullptr;			// c-string

	static constexpr const size_t _increaseBy = 1;
};

//iostream
std::ostream& operator<< (std::ostream& os, const MyString& str);
std::istream& operator>> (std::istream& is, MyString& str);

#endif MY_STRING_H // MY_STRING_H