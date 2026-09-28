namespace myLibrary{
    template <typename typeInElement> struct myQueueElement{ // struct, that will be used as element of stack
        myQueueElement* pointer;
        typeInElement value;
    };
    template <typename type> class queue{
        private:
            myQueueElement<type>* firstElement;
            myQueueElement<type>* lastElement;
            long long int size;
        public:
            queue(); // constructor
            ~queue(); // destructor
            void clear();
            void push(type x ); // add new element to the end of the queue
            void pop(); // delete first element
            type front(); // return first element of queue
            type back(); // return last element of queue
            long long int getSize(); // return size
            bool empty(); // check if queue is empty
    };
    template <typename type> queue<type>::queue(){
        firstElement = nullptr;
        lastElement = nullptr;
        size = 0;
    }
    template <typename type> queue<type>::~queue(){ 
        while (!empty()){
            pop();
        }
    }
    template <typename type> void queue<type>::clear(){ 
        while (!empty()){
            pop();
        }
    }
    template <typename type> void  queue<type>::push(type x){   
       if (size <= 0){ // if size == 0, firstElement and lastElement have to be the same
           myQueueElement<type>* cur = new myQueueElement<type>; // allocate memory for new element
           (*cur).value = x;
            (*cur).pointer = nullptr;
            firstElement = cur;
           lastElement = cur;
           size++;
        }else{
           myQueueElement<type>* cur = new myQueueElement<type>; // allocate memory for new element
           (*cur).value = x;
           (*cur).pointer = nullptr;
            (*lastElement).pointer = cur;
            lastElement = cur;
            size++;
        }
    }
    template <typename type> void queue<type>::pop(){
        if (size <= 0){ // if size == 0 return
            return;
       }else if (size == 1){ // if size == 1, queue becomes empty
            delete firstElement; // deallocate memory of first element
            firstElement = nullptr;
            lastElement = nullptr;
            size = 0;
        }else{
            myQueueElement<type>* cur = firstElement;
            firstElement = (*cur).pointer;
            delete cur; // deallocate memory of first element
            size = size - 1;
        }
    }
    template <typename type> type queue<type>::front(){
        if (size > 0){
            return (*firstElement).value;
        }else{
            return 0;
        }
    }
    template <typename type> type queue<type>::back(){  
        if (size > 0){
            return (*lastElement).value;
        }else{
            return 0;
        }
    }
    template <typename type> long long int queue<type>::getSize(){
        return size;
    }
    template <typename type> bool queue<type>::empty(){
        if (size == 0){
            return 1;
        }else{
            return 0;
        }
    } 
}
