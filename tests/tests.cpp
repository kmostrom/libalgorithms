
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <gtestutil/TestUtil.h>

#include <algorithms/LinkedList.h>
#include <algorithms/ArrayList.h>

#include <algorithms/StringUtil.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(AlgorithmsTest, LinkedListTest)
{
	LinkedList<int> list;
	list.Insert(1);
	list.Insert(91);
	list.Insert(116);
	EXPECT_EQ(3, list.Length());

	EXPECT_EQ(116, list.GetLastValue());
	EXPECT_EQ(1, list.GetFirstValue());

	EXPECT_EQ(1, list.PopFirst());
	EXPECT_EQ(2, list.Length());

	EXPECT_EQ(91, list.PopFirst());
	EXPECT_EQ(1, list.Length());

	EXPECT_EQ(116, list.PopLast());
	EXPECT_EQ(0, list.Length());

	list.Insert(777);
	list.Insert(64);
	list.Insert(12);
	EXPECT_EQ(64, list.Get(1));
}

TEST(AlgorithmsTest, ArrayListTest)
{
	ArrayList<int> list(10);
	list.Insert(1);
	list.Insert(116);
	list.Insert(576);
	EXPECT_EQ(3, list.Length());

	EXPECT_EQ(1, list.Get(0));
	EXPECT_EQ(116, list.Get(1));
	EXPECT_EQ(576, list.Get(2));

	list.Remove(0);
	EXPECT_EQ(2, list.Length());
	list.Remove(1);
	EXPECT_EQ(1, list.Length());
	list.Remove(0);
	EXPECT_EQ(0, list.Length());
}

template<typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T (&expected)[size], const T (&actual)[size])
{
	for (size_t i(0); i < size; ++i) {
		if (expected[i] != actual[i]) {
			return ::testing::AssertionFailure() << "array[" << i << "] (" << actual[i] << ") != expected[" << i << "] (" << expected[i] << ")";
		}
	}

	return ::testing::AssertionSuccess();
}

TEST(BoyerMoore, FindStringTest)
{
	BoyerMooreStringFinder finder;
	EXPECT_EQ(17, finder.Find("example", "this is a simple example"));
	EXPECT_EQ(-1, finder.Find("ff", "abcdefgh"));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
