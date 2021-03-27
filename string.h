#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>

//ģ��ʵ��һ��������string
namespace wzy  //����ͬһ�������ռ䣬��������ǻ�ϲ���
{
	class string
	{
	public:
		//����������ָ��һ�������ͣ�����һ����ָ�룬�������ǵġ��÷�����඼һ��
		//��������Ϊ�ĵ������ǳ��ĸߴ��ϣ���ʵ��Ȼ������һ�ֺܺõķ�װ���ϲ������˾�����Ϣ
		typedef char* iterator;//Ŀǰ��string����Ϳ��Լ򵥵���Ϊ����������char*��ָ��
		typedef const char* const_iterator;

		iterator begin() 
		{
			return _str;
		}

		iterator end() //�������Ϊ���end����ָ��ġ�\0����λ��
		{
			return _str + _size;
		}

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const //�������Ϊ���end����ָ��ġ�\0����λ��
		{
			return _str + _size;
		}

		string(const char* str)
		{
			//��ᷢ�֣������ʹ�ó�ʼ���б���ô��Ҫ��ε�дstrlen(str),��������������ʵд���ڲ�����
			//��ʾ����ʼ���б��˳�򲢲������˳��������˳����ǳ�ʼ���б����ʵ˳��
			_size = strlen(str);
			_capacity = _size;//��������������ܴ���ٸ�Ч�ַ��� ��\0���Ǳ�ʶ��
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
			assert(i < _size);//Խ���ֱ�ӱ���
			return _str[i];
		}

		size_t size()
		{
			return _size;
		}
		
		//��ֵ
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

		//�������κ�ʱ������ʱ��Ҫ���ǿռ��Ƿ��㹻������
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//���ﲻҪֱ�ӵ���������Ҫ���ǳ�ԶһЩ��ӦΪ����Ҫʵ��һ��reserve()�ӿ�
			}
		}

		void append(const char* str)
		{

		}

		void reverse()
		{

		}
	private:
		//��ᷢ����windows������ĳ�Ա��������һ��char buff[16]����ʵ�������ʹ����һ�ֿռ任ʱ��ķ�ʽ���������ַ����Ƚ϶�
		//�ͻ�ֱ�ӵĴ洢��buff���棬�������ڽ�������Ŀ��ռ䲽���ˣ���������ַ����Ƚϳ�����ô������buff�ռ��ֱ���˷ѵ�
		char* _str;
		int _size;
		int _capacity;
	};
};