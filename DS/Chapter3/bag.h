#include<cassert>
#include<iostream>
using namespace std;
class bag
	{
	public:
		bag() { used = 0; }
		//TYPEDEFS and MEMBER CONSTANTS
		typedef int value_type;
		typedef size_t size_type;
		static const size_type CAPACITY = 30;
		size_type erase(const value_type& target)
		{
			size_type index = 0;
			size_type many_removed = 0;
			while (index < used)
			{
				if (data[index] == target)
				{
					--used;
					data[index] = data[used];
					++many_removed;
				}
				else
				{
					++index;
				}
			}
			return many_removed;
		}
		bool erase_one(const value_type& target)
		{
			size_type index = 0;
			while ((index < used) && (data[index] != target))
			{
				++index;
			}
			if (index == used)
			{
				return false;
			}
			--used;
			data[index] = data[used];
			return true;
		}
		void insert(const value_type& entry)
		{
			assert(size() < CAPACITY);
			data[used++] = entry;
		}
		void operator +=(const bag& addend)
		{
			assert(size() + addend.size() <= CAPACITY);
			used += addend.used;
		}
		size_type size() const { return used; }
		size_type count(const value_type& target) const
		{
			size_type answer;
			size_type i;
			answer = 0;
			for (i = 0; i < used; ++i)
			{
				if (target == data[i])
				{
					++answer;
				}
			}
			return answer;
		}
	private:
		value_type data[CAPACITY];
		size_type used;
	};
	bag operator +(const bag& b1, const bag& b2)
	{
		bag answer;
		assert(b1.size() + b2.size() <= bag::CAPACITY);
		answer += b1;
		answer += b2;
		return answer;
	}