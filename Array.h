#ifndef __ARRAY__
#define __ARRAY__
#include <cstdlib>
#include<iostream>
using namespace std;
template <typename T> //template을 사용하여 자료형을 고려할 필요없게 해준다.
class Array{
	protected:
		T *data; // template 사용
		int len;
	public:
			Array<T>(int size);
			~Array<T>();
			int length() const;
			T& operator[](int i); // template 사용
			T operator[](int i)const; // template 사용
			void print();
};
template <typename T>
Array<T>::Array(int size)
{
	//사이즈를 확인하고 양수이면 new를 사용하여 배열 data를 할당, len값 초기화
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
T& Array<T>::operator[](int i) // 배열에 원소 삽입
{
	static T tmp=0;
	// 배열의 인덱스가 범위 내에 있으면 값 리턴, 그렇지 않으면 에러메세지 출력
	if(i >= 0 && i < len)
	{
		return data[i];
	}else{
		cout<<"Array bound error!"<<endl;
		return tmp;
	}
}
template <typename T>
T Array<T>::operator[](int i) const // 배열의 원소값 반환
{
	//배열의 인덱스가 범위 내에 잇으면 값을 리턴, 그렇지 않으면 에러메세지 출력하고 0을 리턴
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
void Array<T>::print() //배열의 모든 내용을 출력해주는 함수
{
	int i;
	cout<<"[ ";
	for(i=0;i<len;i++)
		cout<<data[i]<<" ";
	cout<<"]"<<endl;
}
#endif
