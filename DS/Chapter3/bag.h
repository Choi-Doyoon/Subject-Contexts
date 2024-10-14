#ifndef BAG_H
#include<cstdlib>
#include<iostream>
#include<cassert>
using namespace std;

namespace BAG{
    class bag{
        public:
        bag(){
            //Precondition: bag가 생성되고 비어있는 상태이다.
            used=0;
        }
        typedef int value_type;
		typedef size_t size_type;
		static const size_type CAPACITY = 20;
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
        bool erase_one(const value_type& target){
            while((index<used)&&(data[index]!=target)){++index;}
            if(index==used){return false;}
            --used;
            data[index]=data[used];
            return true;
        }
        void insert(const value_type& entry){
            //Precondition: Bag != full
            //Postcondition: 새로 복사 된 new_entry가 bag에 추가된다.
            assert(size()<CAPACITY);
            data[used++]=entry;
        }
        void operator +=(const bag& addend)
		{
			assert(size() + addend.size() <= CAPACITY);
			used += addend.used;
		}
        size_type size() const{
            //Postcondition: 반환값은 가방 안에 있는 항목들이다.
            return used;
        }
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
        int data[CAPACITY];
        size_type index;
        size_t used;
    };
    bag operator +(const bag& b1, const bag& b2)
	{
		bag answer;
		assert(b1.size() + b2.size() <= bag::CAPACITY);
		answer += b1;
		answer += b2;
		return answer;
	}
}
#endif