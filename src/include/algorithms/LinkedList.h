
#pragma once

template<class T>
class LinkedList
{
public:
	struct SLink
	{
		SLink()
			: mNext(nullptr)
			, data(nullptr) {}

		SLink(SLink* next, T data)
			: mNext(next)
			, mData(data) {}

		SLink* mNext;
		T mData;
	};

public:
	LinkedList()
		: mRoot(nullptr)
		, mTail(nullptr)
		, mLength(0)
	{
	}

	void Insert(T data);
	int Length() const;

	T GetFirstValue();
	T GetLastValue();

	T PopLast();
	T PopFirst();

	T Get(int index);

private:
	SLink* mRoot;
	SLink* mTail;

	int mLength;
};

template<class T>
void LinkedList<T>::Insert(T data)
{
	if (mRoot == nullptr)
	{
		// List is empty
		mTail = new SLink(nullptr, data);
		mRoot = mTail;
	}
	else
	{
		// If list contains (at least) one item
		mTail->mNext = new SLink(nullptr, data);
		mTail = mTail->mNext;
	}

	// If successfully inserted
	mLength++;
}

template<class T>
int LinkedList<T>::Length() const
{
	return mLength;
}

template<class T>
T LinkedList<T>::GetFirstValue()
{
	assert(mRoot);
	return mRoot->mData;
}

template<class T>
T LinkedList<T>::GetLastValue()
{
	assert(mTail);
	return mTail->mData;
}

template<class T>
T LinkedList<T>::PopFirst()
{
	assert(mRoot);
	SLink* first = mRoot; // save old root node
	mRoot = mRoot->mNext; // step root node forward

	T data = first->mData; // save data
	delete first;

	mLength--;

	return data;
}

template<class T>
T LinkedList<T>::PopLast()
{
	assert(mTail);

	T data = mTail->mData; // save data

	if (mRoot == mTail)
	{
		delete mRoot;
		mTail = mRoot = nullptr;
	}
	else
	{
		SLink* current = mRoot;
		while(current != mTail)
		{
			if (current->mNext == mTail)
			{
				current->mNext = mTail->mNext;
			}
			current = current->mNext;
		}
	}

	mLength--;

	return data;
}

template<class T>
T LinkedList<T>::Get(int index)
{
	assert(mRoot);
	assert(index >= 0 && index < mLength);

	int i=0;
	SLink* current = mRoot;
	while(current)
	{
		if (i == index)
		{
			return current->mData;
		}

		current = current->mNext;
		i++;
	}

	assert(false);
}