namespace myLibrary{
	template <typename typeInElement> struct myListElement{ // struct, that will be used as element of stack
		myListElement<typeInElement>* back;
		typeInElement value;
		myListElement<typeInElement>* front;
	};
 
	template <typename type> class list{
		private:
			myListElement<type>* firstElement;
			myListElement<type>* lastElement;
			long long int size;
		public:
			list(); // constructor
			~list(); // destructor
            void clear();
			void pushFront(type x); // add new element to the start of list
			void popFront(); // delete first element
			void pushBack(type x); // add new element to the end of list
			void popBack(); // delete last element
			type front(); // return value of first element
			type back(); // return value of last element
			long long int getSize(); // return size
			bool empty(); // check if list is empty
	};
 
	template <typename type> list<type>::list(){
		size = 0;
		firstElement = nullptr;
		lastElement = nullptr;
	}
 
	template <typename type> list<type>::~list(){
		while (!empty()){
			popBack();
		}
	}

    template <typename type> void list<type>::clear(){
		while (!empty()){
			popBack();
		}
	}
 
	template <typename type> void list<type>::pushFront(type x){
		if (size == 0){ // if size == 0 firstElement and lastElement have to be the same
			myListElement<type> *cur = new myListElement<type>; // allocate memory for new element
			(*cur).value = x;
			(*cur).front = nullptr;
			(*cur).back = nullptr;
			firstElement = cur;
			lastElement = cur;
			size = size + 1;
		}else{
			myListElement<type> *cur = new myListElement<type>; // allocate memory for new element
			(*cur).value = x;
			(*cur).front = nullptr;
			(*cur).back = firstElement;
			(*firstElement).front = cur;
			firstElement = cur;
			size = size + 1;
		}
	}
 
	template <typename type> void list<type>::popFront(){
		if (size <= 0){ // if size == 0 return
			return;
		}else if (size == 1){ // if size == 1 queue becomes empty
			firstElement = nullptr;
			lastElement = nullptr;
			size = size - 1;
		}else{
			myListElement<type> *cur = firstElement;
			firstElement = (*cur).back;
			delete cur; //deallocate memory of first element
			size = size - 1;
		}
	}
 
	template <typename type> void list<type>::pushBack(type x){
		if (size == 0){ // if size == 0 firstElement and lastElement have to be the same
			myListElement<type> *cur = new myListElement<type>; // allocate memory for new element
			(*cur).value = x;
			(*cur).front = nullptr;
			(*cur).back = nullptr;
			firstElement = cur;
			lastElement = cur;
			size = size + 1;
		}else{
			myListElement<type> *cur = new myListElement<type>; // allocate memory for new element
			(*cur).value = x;
			(*cur).front = lastElement;
			(*cur).back = nullptr;
			(*lastElement).back = cur;
			lastElement = cur;
			size = size + 1;
		}
	}
 
	template <typename type> void list<type>::popBack(){
		if (size <= 0){ // if size == 0 return
			return;
		}else if (size == 1){ // if size == 1 queue becomes empty
			firstElement = nullptr;
			lastElement = nullptr;
			size = size - 1;
		}else{
			myListElement<type> *cur = lastElement;
			lastElement = (*cur).front;
			delete cur; // deallocate memory of last element
			size = size - 1;
		}
	}
 
	template <typename type> type list<type>::front(){
		if (size > 0){
			return (*firstElement).value;
		}else{
			return 0;
		}
	}
 
	template <typename type> type list<type>::back(){
		if (size > 0){
			return (*lastElement).value;
		}else{
			return 0;
		}
	}
 
	template <typename type> long long int list<type>::getSize(){
		return size;
	}
 
	template <typename type> bool list<type>::empty(){
		if (size == 0){
			return 1;
		}else{
			return 0;
		}
	}
}
