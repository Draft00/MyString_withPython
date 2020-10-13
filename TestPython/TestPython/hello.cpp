#include "hello.h"
#include <iostream>

	/*
		Constructors
	*/
	//ndr3w: always initialize a default fields values	(1?)
	MyString::MyString() :
		_length(0),
		_capacity(0),
		_str(nullptr)
	{
		_setCapacity(0);
		_setLength(0);
	}
	MyString::MyString(const MyString& other)
	{
		_append(other._str, other._length);
	}
	MyString::MyString(const char* cchar_arr)
	{
		_append(cchar_arr);
	}
	MyString::MyString(const std::string& std_string)
	{
		_append(std_string.c_str());
	}
	MyString::MyString(const char* other, size_t count)
	{
		_append(other, count);
	}
	MyString::MyString(size_t count, char c)
	{
		append(count, c);
	}
	MyString::MyString(const std::initializer_list<char>& list)
	{
		size_t list_size = list.size();
		_increaseCapacity(list_size);
		_setLength(list_size);
		size_t i = 0;

		//ndr3w: this copy code repeats many times! it needs a separate function!
		for (auto& element : list)
			operator[](i++) = element;
		operator[](_length) = '\0';
	}

	/*
		Element access for PYTHON
	*/
	void MyString::__setitem__(size_t i, char c)
	{
		operator[](i) = c; 
	}
	const char MyString::__getitem__(size_t i)
	{
		return (*this)[i];
	}

	/*
	Element access
*/
	char& MyString::operator[](size_t i)
	{
		return *(_str + i);
	}
	const char& MyString::operator[](size_t i) const
	{
		return *(_str + i);
	}

	/*
		Dectructor
	*/
	MyString::~MyString()
	{
		delete[] this->_str;
		this->_str = nullptr;
		_length = 0;
		_capacity = 0;
	}


	/*
		operator =
	*/
	MyString& MyString::operator=(const MyString & other)
	{
		if (this != &other)
		{
			_setLength(0);
			_append(other._str, other._length);
		}
		return *this;
	}

	MyString& MyString::operator=(const char* cchar_array)
	{
		if (cchar_array != NULL)
		{
			_setLength(0);
			_append(cchar_array);
		}
		return *this;
	}
	MyString& MyString::operator=(const std::string & std_string)
	{
		if (&std_string != NULL)
		{
			_setLength(0);
			_append(std_string.c_str());
		}
		return *this;
	}
	MyString& MyString::operator=(char c)
	{
		_setLength(0);
		_append(&c, 1);
		return *this;
	}

	void MyString::equall_char_array(const char* cchar_array)
	{
		if (cchar_array != NULL)
		{
			_setLength(0);
			_append(cchar_array);
		}
		//return *this;
	}
	void MyString::equall_c(char c)
	{
		_setLength(0);
		_append(&c, 1);
		//return *this;
	}
	void MyString::equall_std_string(const std::string& std_string)
	{
		if (&std_string != NULL)
		{
			_setLength(0);
			_append(std_string.c_str());
		}
		//return *this;
	}


	/*
		operator +=
	*/
	MyString& MyString::operator+=(const MyString & other)
	{
		_append(other._str, other._length);
		return *this;
	}
	MyString& MyString::operator+=(const char* cchar_array)
	{
		_append(cchar_array);
		return *this;
	}
	MyString& MyString::operator+=(const std::string & std_string)
	{
		_append(std_string.c_str());
		return *this;
	}


	/*
		comparison operator
	*/
	/*bool operator==(const MyString & left, const MyString & right)
	{
		const char* buffer = right.c_str();
		return left._compare(right._str) == 0;
	}*/
	bool MyString::operator==(const MyString& left) const
	{
		size_t res = (*this)._compare(left.c_str());
		return res == 0;
	}

	/*bool operator!=(const MyString & left, const MyString & right)
	{
		return left._compare(right._str) != 0;
	}*/
	bool MyString::operator!=(const MyString& left) const
	{
		return (*this)._compare(left.c_str()) != 0;
	}
	bool MyString::operator<(const MyString& left) const
	{
		return (*this)._compare(left.c_str()) < 0;
	}
	bool MyString::operator<=(const MyString& left) const
	{
		return (*this)._compare(left.c_str()) <= 0;
	}
	bool MyString::operator>(const MyString& left) const
	{
		return (*this)._compare(left.c_str()) > 0;
	}
	bool MyString::operator>=(const MyString& left) const
	{
		return (*this)._compare(left.c_str()) >= 0;
	}

	/*
		iostream
	*/
	std::ostream& operator<<(std::ostream & os, const MyString & str)
	{
		size_t length = str.length();
		for (size_t i = 0; i < length; ++i)
		{
			os << str[i];
		}
		return os;
	}
	std::istream& operator>>(std::istream & is, MyString & str)
	{
		str.clear();
		char c;
		do {
			c = is.get();
			if (c == ' ' || c == '\n')
				break;
			str.append(1, c);
		} while (true);
		//str.append(1, '\0');
		return is;
	}


	/*
	operator +
	*/
	MyString MyString::operator+(const MyString& left_other) const
	{
		MyString result = (*this);
		result += left_other;
		return result;
	}
	MyString MyString::operator+(const char* cchar_array) const
	{
		MyString result = (*this);
		result += cchar_array;
		return result;
	}
	MyString MyString::operator+(const std::string& std_string) const
	{
		MyString result = (*this);
		result += std_string;
		return result;
	}

	/*MyString operator+(const MyString & left_other, const MyString & right_other)
	{
		MyString result = left_other;
		result += right_other;
		return result;
	}
	/*MyString operator+(const MyString & left_other, const char* cchar_array)
	{
		MyString result = left_other;
		result += cchar_array;
		return result;
	}
	MyString operator+(const MyString & left_other, const std::string & std_string)
	{
		MyString result = left_other;
		result += std_string;
		return result;
	}*/

	//class methods
	size_t MyString::length() const
	{
		return _length;
	}
	size_t MyString::size() const
	{
		return  length(); 
	}
	size_t MyString::capacity() const
	{
		return _capacity;
	}
	bool MyString::empty() const
	{
		return size() == 0; 
	}
	void MyString::shrink_to_fit(size_t cap)
	{
		_decreaseCapacity(_length);
	}
	void MyString::clear()
	{
		_clear_str(0);
	}
	const char* MyString::c_str() const
	{
		return data();
	}

	const char* MyString::data() const
	{
		return _str;
	}
	size_t MyString::find(const char* cchar_array, size_t pos) const
	{
		return _find(cchar_array, pos, strlen(cchar_array));
	}
	size_t MyString::find(const char* cchar_array) const
	{
		return _find(cchar_array, 0, strlen(cchar_array));
	}
	size_t MyString::find(const std::string & std_string, size_t pos) const
	{
		return _find(std_string.c_str(), pos, std_string.length());
	}
	size_t MyString::find(const std::string & std_string) const
	{
		return _find(std_string.c_str(), 0, std_string.length());
	}

	/*
		append
	*/
	MyString& MyString::append(const char* cchar_array)
	{
		_append(cchar_array);
		return *this;
	}
	MyString& MyString::append(const char* cchar_array, size_t index, size_t count)
	{
		if (index + count > strlen(cchar_array))
			throw;
		char* buffer = _substr(cchar_array, index, count);
		_append(buffer);
		_dealloc_cstring(buffer);
		return *this;
	}
	MyString& MyString::append(const std::string & std_string, size_t index, size_t count)
	{
		size_t std_string_length = std_string.length();
		if (index + count > std_string_length)
			throw;
		char* buffer = _substr(std_string.c_str(), index, count);
		_append(buffer);
		_dealloc_cstring(buffer);
		return *this;
	}
	MyString& MyString::append(const std::string & std_string)
	{
		_append(std_string.c_str());
		return *this;
	}
	MyString& MyString::append(size_t count, char c)
	{
		char* buffer = _alloc_cstring(count, c); 
		_append(buffer, count);
		_dealloc_cstring(buffer);
		return *this;
	}


	/*
		insert
	*/
	MyString& MyString::insert(size_t index, const char* cchar_array)
	{
		_insert(index, cchar_array, strlen(cchar_array));
		return *this;
	}
	MyString& MyString::insert(size_t index, const char* cchar_array, size_t count)
	{
		_insert(index, cchar_array, count);
		return *this;
	}
	MyString& MyString::insert(size_t index, size_t count, char c)
	{
		char* buffer = _alloc_cstring(count, c);
		_insert(index, buffer, count);
		_dealloc_cstring(buffer);
		return *this;
	}
	MyString& MyString::insert(size_t index, const std::string & std_string)
	{
		_insert(index, std_string.c_str(), strlen(std_string.c_str()));
		return *this;
	}
	MyString& MyString::insert(size_t index, const std::string & std_string, size_t count)
	{
		_insert(index, std_string.c_str(), count);
		return *this;
	}

	/*
		erase
	*/
	MyString& MyString::erase(size_t index, size_t count)
	{
		_erase(index, count);
		return *this;
	}

	/*
		replace
	*/
	MyString& MyString::replace(size_t index, size_t count, const char* cchar_array)
	{
		_replace(index, count, cchar_array);
		return *this;
	}
	MyString& MyString::replace(size_t index, size_t count, const std::string & std_string)
	{
		_replace(index, count, std_string.c_str());
		return *this;
	}

	/*
		substr
	*/
	MyString MyString::substr(size_t index, size_t count) const
	{
		if (index + count > _length)
			throw;

		char* buffer = nullptr;
		buffer = _substr(_str, index, count);

		MyString result(buffer);
		delete[] buffer;
		buffer = nullptr; 
		//_dealloc_cstring(buffer);
		return result;
	}

	MyString MyString::substr(size_t index) const
	{
		if (index > _length)
			throw;
		size_t count = strlen(_str) - index;
		char* buffer = _substr(_str, index, count); 
		MyString result(buffer);
		delete[] buffer;
		buffer = nullptr;
		//_dealloc_cstring(buffer);
		return result;
	}

	void MyString::_setLength(const size_t len)
	{
		if (_length > len)
			_clear_str(len);
		else if (_capacity < len)
			_increaseCapacity(len);
		_length = len;
	}
	void MyString::_clear_str(const size_t pos)
	{
		_fill_str(_str, _length, pos, '\0');
		_length = pos;
	}

	void MyString::_increaseCapacity(const size_t new_cap)
	{
		if (_capacity > new_cap && _str)
			return;
		size_t cap = _capacity;
		while (cap <= new_cap)
			cap += _increaseBy;

		_setCapacity(cap);
	}

	
	char* MyString::_alloc_cstring(const size_t count) const
	{
		char* buffer = nullptr;
		buffer = new char[count + 1](); //the default constructor will fill the array with 0
		return buffer;
	}
	void MyString::_fill_str(char* cchar_array, const size_t len, size_t pos, char c) const
	{
		size_t begin = pos;
		while (begin != len)
			cchar_array[begin++] = c;
		cchar_array[begin] = '\0';
	}

	void MyString::_dealloc_cstring(char*& buffer)
	{
		delete[] buffer;
		buffer = nullptr;
	}

	void MyString::_setCapacity(const size_t cap)
	{
		if (_capacity == cap && _str)
			return;
		if (cap < _length)
			return;

		_capacity = cap;

		char* buffer = _str;
		_str = _alloc_cstring(_capacity);
		//_str = nullptr; 
		//_alloc_cstring(_str, _capacity);
		if (buffer) {
			for (size_t i = 0; i < _length; ++i)
				operator[](i) = buffer[i];
			operator[](_length) = '\0';

			_dealloc_cstring(buffer); //delete only not null-terminated
		}

	}

	size_t MyString::_strlen(const char* cchar_array)
	{
		size_t i = 0;
		while (cchar_array[i] != 0) i++;
		return i;
	}

	void MyString::_append(const char* cchar_array, size_t n)
	{
		_increaseCapacity(_length + n);
		size_t i = 0;
		for (; i < n; ++i)
			operator[](_length + i) = cchar_array[i];
		operator[](_length + i) = '\0';
		_setLength(_length + n);
	}
	void MyString::_append(const char* cchar_array)
	{
		_append(cchar_array, strlen(cchar_array));
	}
	void MyString::_decreaseCapacity(const size_t cap)
	{
		if (_capacity < cap)
			return;

		_setCapacity(cap);
	}

	int MyString::_compare(const MyString & other) const
	{
		if (_length < other._length)
			return -1;
		else if (_length > other._length)
			return 1;
		return strcmp(_str, other._str);
	}
	char* MyString::_substr(const char* cchar_array, size_t pos, size_t len) const
	{
		if (cchar_array == nullptr)
			throw;
		char* buffer = _alloc_cstring(len);
		for (size_t i = 0; i < len; ++i)
			buffer[i] = cchar_array[pos + i];
		return buffer;
	}

	bool MyString::_find_compare(const char* cchar_array, size_t len, size_t pos) const
	{
		for (size_t i = 1; i < len; ++i)
		{
			if (operator[](pos + i) != *(cchar_array + i))
				return false;
		}
		return true;
	}
	char* MyString::_alloc_cstring(const size_t count, char c) const
	{
		char* buffer = nullptr;
		buffer = _alloc_cstring(count);
		_fill_str(buffer, count, 0, c);
		return buffer;
	}
	size_t MyString::_find(const char* cchar_array, size_t pos, size_t len) const
	{
		size_t ResultPos = npos;
		if (pos == npos)
			pos = _length - 1;
		if (len == 0)
			return 0;
		//return ResultPos;
		for (; pos <= _length - len; ++pos)
		{
			if (operator[](pos) == *cchar_array && _find_compare(cchar_array, len, pos))
			{
				ResultPos = pos;
				break;
			}
		}
		return ResultPos;
	}
	void MyString::_insert(size_t pos, const char* cchar_array, size_t count)
	{
		if (count == 0 || cchar_array == nullptr)
			return;
		if (pos == _length)
			return _append(cchar_array, count);
		if (pos > _length)
			throw;

		_increaseCapacity(_length + count);

		if (_str == nullptr)
			return _append(cchar_array, count);

		char* buffer = _substr(_str, pos, _length - pos);
		_clear_str(pos);
		_append(cchar_array, count);
		_append(buffer, strlen(buffer));
		_dealloc_cstring(buffer);

	}
	void MyString::_erase(size_t pos, size_t count)
	{
		if (pos + count > _length)
			throw;
		if (_str == nullptr)
			throw;

		for (size_t i = pos + count; i < _length; ++i)
			operator[](i - count) = operator[](i);
		_clear_str(_length - count); 
	}
	void MyString::_replace(size_t pos, size_t count, const char* cchar_array)
	{
		char* third_buffer = _substr(_str, pos + count, _length);
		_clear_str(pos);
		char* second_buffer = _substr(cchar_array, 0, strlen(cchar_array));
		_append(second_buffer);
		_append(third_buffer);
		_dealloc_cstring(third_buffer);
		_dealloc_cstring(second_buffer);
	}
