////ʵ��һ���򵥵�string�����stringֻ�л����Ĺ��죬�������������죬operator[]�ȹ���
//#include<iostream>
//using namespace std;
//namespace wzy
//{
//	class string
//	{
//	public:
//		//����ǵ����޲εĶ���
//		//string(const char* str)
//		//	:_str(new char[1])
//		//{
//		//	_str[0] = '\0';
//		//}
//		//�ٽ���дһ��ȫȱʡ�Ĺ��캯��
//		//�ڶ��������һ���ַ�����ʹ�ǿ��ַ���""����Ҳ��һ��Ĭ�ϵġ�\0��
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
//		//��������
//		string(const string& s)
//			//���ڿ������캯����˵�����ֻ��ʵ�ּ򵥵�ǳ��������ô�ͻ���������ʱ�����������Ҫ���
//			//ʲô������أ��Լ����¿���һ���ռ䣬Ȼ����ָ����
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		//��д�����ʱ��Ҫ����������operator[]������Ҫʲô
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		//���ֻ�Ǽ򵥵�ǳ������Ҳ����ֳ���������
//		//��ֵ������������������Ѿ������������ˣ� s3 = s1
//		//��ʱ���s3������Ҫ�����s1����һ���󣬵�������֪�����������ĸ���������ֱ�Ӱ�s3�Ŀռ��ͷŵ���Ȼ���s1����һ����ͺ���
//		//���Ǵ�ʱ����Ҫ�����Ƿ����Լ�����Լ���ֵ��?
//		//��ôΪʲô�ῼ����������أ�����Ϊ������Լ����Լ���ֵ�Ļ�������һ�������Ѿ��������οռ���ͷ���
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
//		//����C��ʽ�ַ���
//		const char* c_str()
//		{
//			return _str;//�ٴ�˵�������ڳ�Ա������˵����Ա������������ĵ���
//		}
//	private:
//		char* _str;
//	};
//};
//
//int main()
//{
//	wzy::string s1;//�޲ε���
//	wzy::string s2("hello");//�вε���
//	wzy::string s3(s2);//��������
//	wzy::string s4("hello world!");
//	s2 = s4; //��ֵ
//
//
//	std::cout << s1.c_str() << std::endl;
//	std::cout << s2.c_str() << std::endl;
//	std::cout << s3.c_str() << std::endl;
//	std::cout << s4.c_str() << std::endl;
//
//	return 0;
//}
//��������򵥵�string��һ��debug��û���ҵ����Ȼ���Ҫ���»����ҵ���


//����Ϊ������õ����ӣ�ֻ��Ҫ����ȥ�ܹ����õ�ȥ���

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
	//auto it = s.begin(); ����ʹ��autoȥ�����ͣ������㲻֪�������صľ������ͣ���ʵ�����Ǻܺ�
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor��ԭ����ǵ�����
	for (auto& e : s)
	{
		e += 1;  
	}
	Print(s);

	return 0;
}