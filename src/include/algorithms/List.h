
#pragma once

template<class T>
class IList
{
public:
	virtual operator[] (int index);

	virtual void Push(T* item);
	virtual T* Pop();
};