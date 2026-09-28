#include <stdexcept>
namespace myLibrary{
	template <typename type> class vector{
		private:
			type* elements;
			long long int size;
			long long int capacity;
			void prResize(); // set capacity = 2 * size and relocate memory
		public:
			vector(long long int n = 0); // base constructor with set size or stardant size = 0
			vector(long long int n, type x); // overloaded constructor with set size and standart element
			~vector(); // destructor: deleting pointer to array
			void resize(long long int n = 0); // the same as base constructor
			void resize(long long int n, type x); // the same as overloaded constructor
            void clear(); // clear the vector
			type& operator[] (long long int pos);
        	type& at(long long int pos);
			long long int getSize(); // return size
			long long int getCapacity(); // return capacity
			type* begin(); //pointer to 1st element 
			type* end(); //pointer to (last + 1) element
			void pushFront(type x); // add new element to begin of array
			void popFront(); // delete element from begin of array
			void pushBack(type x); // add new element to end
			void popBack(); // delete element from end
			void insert(long long int pos, type x); // insert element on position pos
			void erase(long long int pos, long long int count = 1); // erase count elements from position pos
			long long int find(type x); // find element in array or return -1
			long long int find(type x, long long int st, long long int fin); // overloaded find with start and finish
			long long int count(type x);  // count how many elements array contains
			long long int count(type x, long long int st, long long int fin); // overloaded find with start and finish
	};
 
	template <typename type> void vector<type>::prResize(){
		type* xelements = elements; // change variable, that contains pointer for array
		elements = new type[size * 2]; // allocate memory for new array
		for (int i = 0; i < size - 1 ; i++){
			elements[i] = xelements[i];
		}
		delete [] xelements; // deallocate memory of old array
		capacity = 2 * size;
	}
 
	template <typename type> vector<type>::vector(long long int n){
		elements = new type[n]; // allocate memory
		size = n;
		capacity = n;
	}
 
	template <typename type> vector<type>::vector(long long int n, type x){
		elements = new type[n]; // allocate memory
		for (int i = 0; i < n; i++){
			elements[i] = x;
		}
		size = n;
		capacity = n;
	}
 
	template <typename type> vector<type>::~vector(){
		delete [] elements; // deallocate memory of array
	}
 
	template <typename type> type& vector<type>::operator[] (long long int pos){
		return elements[pos];
	}
    
    template <typename type> type& vector<type>::at(long long int pos){
		if (pos >= size){
            throw std::out_of_range("Position in at method >= size");
        }else{
            return elements[pos];
        }
	}
 
	template <typename type> void vector<type>::resize(long long int n){
		delete [] elements; // deallocate memory of old array
		elements = new type[n]; // allocate memory for new array
		size = n;
		capacity = n;
	}
 
	template <typename type> void vector<type>::resize(long long int n, type x){
		resize(n);
		for (int i = 0; i < n; i++){
			elements[i] = x;
		}
	}
	
    template <typename type> void vector<type>::clear(){
		resize();
	}

    template <typename type> long long int vector<type>::getSize(){
		return size;
	}
 
	template <typename type> long long int vector<type>::getCapacity(){
		return capacity;
	}
 
	template <typename type> type* vector<type>::begin(){
		return elements;
	}
 
	template <typename type> type* vector<type>::end(){
		return elements + size;
	}
 
	template <typename type> void vector<type>::pushFront(type x){
		size = size + 1;
		if (size >= capacity){
			prResize(); // resize if array can't save new variable
		}
		for (int i = size - 1; i > 0; i--){
			elements[i] = elements[i-1];
		}
		elements[0] = x;
	}
 
	template <typename type> void vector<type>::popFront(){
		size = size - 1;
		for (int i = 0; i < size; i++){
			elements[i] = elements[i+1];
		}
		if (size*4 <= capacity){
			prResize(); // resize if capacity >= 4 * size
		}
	}
 
	template <typename type> void vector<type>::pushBack(type x){
		size = size + 1;
		if (size >= capacity){
			prResize(); // resize if array cant save new variable
		}
		elements[size-1] = x;
	}
 
	template <typename type> void vector<type>::popBack(){
		size = size - 1;
		if (size*4 <= capacity){
			prResize(); // resize if capacity >= 4 * size
		}
	}
 
	template <typename type> void vector<type>::insert(long long int pos, type x){
		size = size + 1;
		if (size >= capacity){
			prResize(); // resize if array can't save new variable
		}
		for (int i = size - 1; i > pos; i--){
			elements[i] = elements[i-1];
		}
		elements[pos] = x;
	}
 
	template <typename type> void vector<type>::erase(long long int pos, long long int count){
		size = size - count;
		for (int i = pos; i < pos + count; i++){
			elements[i] = elements[i + count];
		}
		if (size*4 <= capacity){
			prResize(); // resize if capacity >= 4 * size
		}
	}
 
	template <typename type> long long int vector<type>::find(type x){
		for (int i = 0; i < size; i++){
			if (x == elements[i]){
				return i;
			}
		}
		return -1;
	}
 
	template <typename type> long long int vector<type>::find(type x, long long int st, long long int fin){
		for (int i = st; i < fin; i++){
			if (x == elements[i]){
				return i;
			}
		}
		return -1;
	}
 
	template <typename type> long long int vector<type>::count(type x){
		long long int count = 0;
		for (int i = 0; i < size; i++){
			if (elements[i] == x){
				count++;
			}
		}
		return count;
	}
 
	template <typename type> long long int vector<type>::count(type x, long long int st, long long int fin){
		long long int count = 0;
		for (int i = st; i < fin; i++){
			if (elements[i] == x){
				count++;
			}
		}
		return count;
	}
}
