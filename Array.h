#ifndef __ARRAY__
#define __ARRAY__
#include <cstdlib>
#include<iostream>
using namespace std;
template <typename T> //template�� ����Ͽ� �ڷ����� ����� �ʿ���� ���ش�.
class Array{
	protected:
		T *data; // template ���
		int len;
	public:
			Array<T>(int size);
			~Array<T>();
			int length() const;
			T& operator[](int i); // template ���
			T operator[](int i)const; // template ���
			void print();
};
template <typename T>
Array<T>::Array(int size)
{
	//����� Ȯ���ϰ� ����̸� new�� ����Ͽ� �迭 data�� �Ҵ�, len�� �ʱ�ȭ
	if( size <= 0 )
	{
		cout << " Error!" << endl;
		return ;
	}
	data = new T[size];
	int i;
	for(i=0;i<size;i++)
		data[i]=0;
	len = size;
}
template <typename T>
Array<T>::~Array()
{
	delete [] data;
}
template <typename T>
int Array<T>::length() const
{
	return len;
}
template <typename T>
T& Array<T>::operator[](int i) // �迭�� ���� ����
{
	static T tmp=0;
	// �迭�� �ε����� ���� ���� ������ �� ����, �׷��� ������ �����޼��� ���
	if(i >= 0 && i < len)
	{
		return data[i];
	}else{
		cout<<"Array bound error!"<<endl;
		return tmp;
	}
}
template <typename T>
T Array<T>::operator[](int i) const // �迭�� ���Ұ� ��ȯ
{
	//�迭�� �ε����� ���� ���� ������ ���� ����, �׷��� ������ �����޼��� ����ϰ� 0�� ����
	if(i >= 0 && i<len)
	{	
		return data[i];
	}
	else
	{
		cout<<"Array bound error!"<<endl;
		return 0;		
	}
}
template<typename T>
void Array<T>::print() //�迭�� ��� ������ ������ִ� �Լ�
{
	int i;
	cout<<"[ ";
	for(i=0;i<len;i++)
		cout<<data[i]<<" ";
	cout<<"]"<<endl;
}
#endif
