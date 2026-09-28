#include <stdexcept>
namespace myLibrary{
    template <typename type, long long int setSize> class array{
        private:
            type* elements;
            long long int size;
        public:
            array();
            array(type x);
            ~array();
			void resize(long long int n = 0); // the same as base constructor
			void resize(long long int n, type x); // the same as overloaded constructor
            type& operator[](long long int pos);
            type& at(long long int pos);
            long long int getSize();
            type* begin();
            type* end();
			long long int find(type x); // find element in array or return -1
			long long int find(type x, long long int st, long long int fin); // overloaded find with start and finish
			long long int count(type x);  // count how many elements array contains
			long long int count(type x, long long int st, long long int fin); // overloaded find with start and finish

    };
    template <typename type, long long int setSize> array<type,setSize>::array(){
        size = setSize;
        elements = new type[size];
    }
    template <typename type, long long int setSize> array<type,setSize>::array(type x){
        size = setSize;
        elements = new type[size];
        for (int i = 0; i <size; i++){
            elements[i] = x;
        }
    }
    template <typename type, long long int setSize> array<type,setSize>::~array(){
        delete [] elements;
    }
    template <typename type, long long int setSize> void array<type,setSize>::resize(long long int n){
        delete [] elements;
        size = n;
        elements = new type[n];
    }
    template <typename type, long long int setSize> void array<type,setSize>::resize(long long int n, type x){
        resize(n);
        for (int i = 0; i < size; i++){
            elements[i] = x;
        }
    }
    template <typename type, long long int setSize> type& array<type,setSize>::operator[](long long int pos){
        return elements[pos];
    }
    template <typename type, long long int setSize> type& array<type,setSize>::at(long long int pos){
        if (pos >= size){
            throw std::out_of_range("Position in at method >= size");
        }else{
            return elements[pos];
        }
    }
    template <typename type, long long int setSize> long long int array<type,setSize>::getSize(){
        return size;
    }
    template <typename type, long long int setSize> type* array<type,setSize>::begin(){
        return elements;
    }
    template <typename type, long long int setSize> type* array<type,setSize>::end(){
        return elements + size;
    }
    template <typename type, long long int setSize> long long int array<type,setSize>::find(type x){
        for (int i = 0; i < size; i++){
            if (elements[i] == x){
                return i;
            }
        }
        return -1;
    }
    template <typename type, long long int setSize> long long int array<type,setSize>::find(type x, long long int st, long long int fin){
        for (int i = st; i < fin; i++){
            if (elements[i] == x){
                return i;
            }
        }
        return -1;
    }
    template <typename type, long long int setSize> long long int array<type,setSize>::count(type x){
        long long int count = 0;
        for (int i = 0; i < size; i++){
            if (elements[i] == x){
                count++;
            }
        }
        return count;
    }
    template <typename type, long long int setSize> long long int array<type,setSize>::count(type x, long long int st, long long int fin){
        long long int count = 0;
        for (int i = st; i < fin; i++){
            if (elements[i] == x){
                count++;
            }
        }
        return count;
    }
}
