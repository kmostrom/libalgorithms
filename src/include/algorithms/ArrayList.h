
#pragma once

template<class T>
class ArrayList
{
public:
	ArrayList(int size=0);
	virtual ~ArrayList();

	void Insert(T data);
	T Get(int index);
	void Remove(int index); // Fast remove by replacing with last item

	int Length() const;

private:
	void Alloc(int size);
	void Free();

private:
	T* mArray;
	int mSize;

	int mLength;
};

template<class T>
ArrayList<T>::ArrayList(int size)
	: mArray(nullptr)
	, mSize(0)
	, mLength(0)
{
	Alloc(size);
}

template<class T>
ArrayList<T>::~ArrayList()
{
	Free();
}

template<class T>
void ArrayList<T>::Alloc(int size)
{
	assert(size > 0);

	if (mArray && mSize > 0)
	{
		Free();
	}

	mArray = new T[size];
	if (mArray)
	{
		mSize = size;
	}
}

template<class T>
void ArrayList<T>::Free()
{
	assert(mArray);

	delete [] mArray;
	mArray = nullptr;
	mSize = 0;
	mLength = 0;
}

template<class T>
void ArrayList<T>::Insert(T data)
{
	assert(mLength < mSize);
	mArray[mLength++] = data;
}

template<class T>
T ArrayList<T>::Get(int index)
{
	assert(index >= 0 && index < mLength);
	return mArray[index];
}

template<class T>
void ArrayList<T>::Remove(int index)
{
	assert(index >= 0 && index < mLength);

	mArray[index] = mArray[mLength - 1];
	mLength--;
}

template<class T>
int ArrayList<T>::Length() const
{
	return mLength;
}
