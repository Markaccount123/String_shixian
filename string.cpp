////实现一个简单的string，这个string只有基本的构造，析构，拷贝构造，operator[]等功能
//#include<iostream>
//using namespace std;
//namespace wzy
//{
//	class string
//	{
//	public:
//		//这个是调用无参的对象
//		//string(const char* str)
//		//	:_str(new char[1])
//		//{
//		//	_str[0] = '\0';
//		//}
//		//①建议写一个全缺省的构造函数
//		//②对于任意的一个字符串即使是空字符串""里面也有一个默认的‘\0’
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//s3(s1)
//		//拷贝构造
//		string(const string& s)
//			//对于拷贝构造函数来说，如果只是实现简单的浅拷贝，那么就会在析构的时候出错，所以需要深拷贝
//			//什么是深拷贝呢：自己重新开辟一个空间，然后在指向他
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		//在写这个的时候要想清楚，你的operator[]到底想要什么
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		//如果只是简单的浅拷贝，也会出现程序崩的情况
//		//赋值运算符（这两个对象都已经被创建出来了） s3 = s1
//		//此时你的s3对象需要和你的s1对象一样大，但是我哪知道他们两个哪个大，所以我直接把s3的空间释放掉，然后和s1对象开一样大就好了
//		//但是此时还需要考虑是否你自己会给自己赋值呢?
//		//那么为什么会考虑这种情况呢：是因为你如果自己给自己赋值的话，代码一上来就已经把你的这段空间给释放了
//		//
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//			return *this;
//		}
//
//		//返回C格式字符串
//		const char* c_str()
//		{
//			return _str;//再次说明，对于成员变量来说，成员函数可以随意的调用
//		}
//	private:
//		char* _str;
//	};
//};
//
//int main()
//{
//	wzy::string s1;//无参调用
//	wzy::string s2("hello");//有参调用
//	wzy::string s3(s2);//拷贝构造
//	wzy::string s4("hello world!");
//	s2 = s4; //赋值
//
//
//	std::cout << s1.c_str() << std::endl;
//	std::cout << s2.c_str() << std::endl;
//	std::cout << s3.c_str() << std::endl;
//	std::cout << s4.c_str() << std::endl;
//
//	return 0;
//}
//对于上面简单的string有一个debug还没有找到，等会需要重新回来找到他


//不是为了造更好的轮子，只是要我们去能够更好的去理解

#include"string.h"

void Print(const wzy::string& s)
{
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	wzy::string s("1234");

	//for (size_t i = 0; i < s.size(); i++)
	//{
	//	cout << s[i] << " ";
	//}
	//cout << endl;

	Print(s);

	wzy::string::iterator it = s.begin();
	//auto it = s.begin(); 可以使用auto去推类型，但是你不知道他返回的具体类型，其实并不是很好
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for的原理就是迭代器
	for (auto& e : s)
	{
		e += 1;  
	}
	Print(s);

	return 0;
}