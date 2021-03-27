#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>

//模拟实现一个完整的string
namespace wzy  //对于同一个命名空间，里面的类是会合并的
{
	class string
	{
	public:
		//迭代器是像指针一样的类型，但不一定是指针，但是他们的“用法”大多都一样
		//我们所认为的迭代器非常的高大上，其实不然，就是一种很好的封装，上层隐藏了具体信息
		typedef char* iterator;//目前在string里面就可以简单的认为迭代器就是char*的指针
		typedef const char* const_iterator;

		iterator begin() 
		{
			return _str;
		}

		iterator end() //可以理解为你的end就是指向的‘\0’的位置
		{
			return _str + _size;
		}

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const //可以理解为你的end就是指向的‘\0’的位置
		{
			return _str + _size;
		}

		string(const char* str)
		{
			//你会发现，如果你使用初始化列表，那么就要多次的写strlen(str),对于内置类型其实写在内部更好
			//提示：初始化列表的顺序并不是真的顺序，声明的顺序才是初始化列表的真实顺序
			_size = strlen(str);
			_capacity = _size;//这里的容量代表“能存多少个效字符” ‘\0’是标识符
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		char& operator[](size_t i)
		{
			assert(i < _size);//越界会直接崩掉
			return _str[i];
		}

		size_t size()
		{
			return _size;
		}
		
		//赋值
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		//不管在任何时候插入的时候都要考虑空间是否足够的问题
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//这里不要直接的扩二倍，要考虑长远一些，应为还需要实现一个reserve()接口
			}
		}

		void append(const char* str)
		{

		}

		void reverse()
		{

		}
	private:
		//你会发现在windows下这里的成员变量还有一个char buff[16]，其实这里就是使用了一种空间换时间的方式，如果你的字符串比较短
		//就会直接的存储在buff里面，而不用在进行下面的开空间步骤了，但是如果字符串比较长，那么你的这个buff空间就直接浪费掉
		char* _str;
		int _size;
		int _capacity;
	};
};