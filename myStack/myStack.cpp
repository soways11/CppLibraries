namespace myLibrary{
    template <typename typeInElement> struct myStackElement{ // struct, that will be used as element of stack
        typeInElement value;
        myStackElement* pointer;
    };
    template <typename type> class stack{
        private:
            myStackElement<type>* lastElement;
            long long int size;
        public:
            stack(); // constructor
            ~stack(); // destructor
            void clear();
            void push(type x); // add new element to the stack
            void pop(); // delete last element
            type top(); // return value of last element
            long long int getSize(); // return size
            bool empty(); // check if stack is empty
    };
    template <typename type> stack<type>::stack(){
        size = 0;
        lastElement = nullptr;
    }
    template <typename type> stack<type>::~stack(){
        while (!empty()){
            pop();
        }
    }
    template <typename type> void stack<type>::clear(){
        while (!empty()){
            pop();
        }
    }
    template <typename type> void stack<type>::push(type x){    
        myStackElement<type>* cur = new myStackElement<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).pointer = lastElement;
        lastElement = cur;
        size = size + 1;
    }
    template <typename type> void stack<type>::pop(){
      if (size <= 0){ // check if stack has elements
          return;
      }else{
           size = size - 1;
           myStackElement<type>* cur = lastElement;
           lastElement = (*cur).pointer;
            delete cur; // deallocate memory of last element
        }
    }
    template <typename type> type stack<type>::top(){
        if (size > 0){
            return (*lastElement).value;
        }else{
            return 0;
        }
    }
    template <typename type> long long int stack<type>::getSize(){
        return size;
    }
    template <typename type> bool stack<type>::empty(){
        if (size <= 0){
            return 1;
        }else{
            return 0;
        }
    }
}
