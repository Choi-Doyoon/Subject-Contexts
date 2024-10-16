#ifndef DynamicBag_H
#include<iostream>
#include<cstdlib>
using namespace std;

namespace DB{
    class bag{
        public:
        typedef int value_type;
		typedef size_t size_type;
		static const size_type DEFAULT_CAPACITY = 30;
        //constructor
        bag(size_type init_capacity){
            data=new value_type[init_capacity];
            capacity=init_capacity;
            used=0;
        }

        //copy constructor
        bag(const bag& source){
            data=new value_type[source.capacity];
            capacity=source.capacity;
            used=source.used;
            copy(source.data,source.data+used,data);
        }

        //Destructor
        ~bag(){delete[] data;}

        void operator =(const bag& source){
            value_type *new_data;
            if(this==&source){return;} //self-assignment check
            if(capacity!=source.capacity){//capacity matching
                new_data=new value_type[source.capacity];
                delete[] data;
                data=new_data;
                capacity=source.capacity;
            }
            used=source.used;
            copy(source.data,source.data+used,data);

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
				return many_removed;
			}
		}

        void reserve(size_type new_capacity){
            value_type *larger_array;
            if(new_capacity==capacity){return;}
            if(new_capacity<used){new_capacity=used;}
            larger_array=new value_type[new_capacity];
            copy(data,data+used,larger_array);
            data=larger_array;
            capacity=new_capacity;
        }

        void insert(const value_type& entry){
            if(used==capacity){reserve(used+1);}
            data[used]=entry;
            ++used;
        }

        void operator +=(const bag& addend){
            if(used+addend.used>capacity){reserve(used+addend.used);}
            copy(addend.data,addend.data+addend.used,data+used);
            used+=addend.used;
        }

        size_type size() const
		{
			return used;
		}

		size_type count(const value_type& target)
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
				return answer;
			}
		}
        private:
        value_type* data;
		size_type used;
		size_type capacity;
    };
    bag operator +(const bag& b1, const bag& b2){
        bag answer(b1.size()+b2.size());
        answer+=b1;
        answer+=b2;
        return answer;
    }
}
#endif