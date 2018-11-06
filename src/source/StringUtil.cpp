
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithms/StringUtil.h>

#include <algorithm>
#include <cstring>

///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
	Assume table is int[256]
*/
void BoyerMooreStringFinder::CreateTable(int* table, char* needle, int length)
{
	for(int index=0; index < strlen(needle); ++index)
	{
		char* current = &needle[index];
		int value = std::max(1, length - 1 - index);
		table[*current] = value;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

int BoyerMooreStringFinder::Find(char* needle, char* haystack)
{
	int table[256];
	memset(table, 0, sizeof(table));
	CreateTable(table, needle, strlen(needle));

	int offset = 0;
	bool done = false;

	while (!done) {
		for (int i=strlen(needle)-1; i >= 0; --i) { // iterate right to left
			if (offset + i > strlen(haystack) - 1) { // haystack index is beyond haystack, we have reached past end with no cigar
				done = true;
				break;
			}

			if (needle[i] != haystack[offset + i]) { // try to fail early
				int value = table[haystack[offset + i]]; // fetch number of steps to skip from B-M table
				if (value == 0) {
					value = strlen(needle); // character not in needle, thus we can skip an entire needle length
				}
				offset += value;
				break;
			}

			if (i == 0) { // we reached the beginning of the needle, thus all characters match
				return offset;
			}
		}
	}
	return -1; // there is no needle!
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
