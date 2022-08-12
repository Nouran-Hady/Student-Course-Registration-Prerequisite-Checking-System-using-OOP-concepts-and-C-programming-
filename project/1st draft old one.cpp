#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
using namespace std;

class node{
	public:
		string v;
		node *next;
		node(){
			next = NULL;
		}
};

class LinkedList{
	node *head;
	public:
		
		LinkedList(){
			head = NULL;
		}
		
		void insert(string v){
			node *temp = new node();
			temp->v = v;
			if (head == NULL){
				// if linked list is empty
				// make temp the new head
				head = temp;
			}
			else{
				// if linked list is not empty
				// go to the last node of the linked list
				node *ptr = head;
				// the loop sets ptr to last node of the linked list
				while (ptr->next != NULL){
					ptr = ptr->next;
				}
				// ptr now points to the last node of the linked list
				// store temp in the next of ptr  
				ptr->next = temp;
			}
		}
		
		node* return_next(node* temp){
			return temp->next;
		}
	
		void print(){
			if (head == NULL){
				cout<<"List is empty"<<endl;
			}
			else{
				node *temp = head;
				cout<<"Linked List: ";
				while (temp != NULL){
					cout<<temp->v<<"->";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}		
};


class BinaryMinHeap{
    private:
    int *heap;
    int array_size;
    
    void swap( int i, int j){
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp; } 
    	int heap_size;
    public:
    
    int size(){
    	return heap_size;
	}
    BinaryMinHeap(int size){
        heap = new int[size];
        heap_size = 0;
        array_size = size;
    }
    int getParent(int index){  return (index-1)/2;  }
    void insert(int data){
        if(heap_size == array_size)
            return; 
        else {
            heap_size++;
            heap[heap_size-1] = data;
            heapUp(heap_size -1);
            }
			}
			  
    void heapUp(int index){
        if(index!= 0){
            int parent = getParent(index);

        if(heap[parent] > heap[index]){
            swap(parent,index);
            heapUp(parent);
        }
        }
    }
    void printHeap(){
    	int i;
    	for(i=0;i<heap_size;i++){
    		cout<<heap[i]<<"   ";
		}
	}
        
	};

// function to get int from string
int* get_Number_From_String(string course, int *codes) {
   stringstream course_stream;
   int temp_intger,i=0;
   string temp_string;
   
   course_stream << course; //convert the string s into stringstream
   
   while(!course_stream.eof()) {
   	
      course_stream >> temp_string; //take words into temp_str one by one
      
      if(stringstream(temp_string) >> temp_intger) { //try to convert string to int
			codes[i]=temp_intger;
			i++;
			 }
      temp_string = ""; //to clear temp string
   }
   return codes;
}

//function to operate on file
void file_operation(BinaryMinHeap heap){  
  string Text;
  int i,j;
  int *x;
  int codes_from_string[2];
  

  // Read from the text file
  ifstream ReadFile("dependency tree.csv");

  // Use a while loop together with the getline() function to read the file line by line
  for (i=0;i<6;i++) {
  	getline (ReadFile, Text);
//  	int from string function call
  	x=get_Number_From_String(Text, codes_from_string);
		for(j=0;j<=1;j++){
			cout<<x[j]<< endl;
			heap.insert(x[j]);	}
	  }  
	heap.printHeap();
  ReadFile.close();
}


LinkedList getting_input_from_user(LinkedList courses){
	string user_input;
	int choice;
	do {
		cout<<"1) insert 0)exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cin>>user_input;
				courses.insert(user_input);	
		}
	} while (choice != 0);
	
		return courses;
}


//int check_courses(LinkedList studied, LinkedList  want_to_study, BinaryMinHeap heap){
//	
//	int i,j,codes[3];
//	int* want;
//	int* int_studied;
//	LinkedList ok_to_study;
//	LinkedList cannot_be_taken;
//	cout<<typeid(want_to_study).name()<<endl;
//
//	for(i=0;i<heap.size();i++){
////		want_to_study !=NULL
//		while(true ){
//			
//			want=get_Number_From_String(want_to_study->v, codes)
//		if( heap[i]==want){
//			while(studied->next!=NULL){
//				if(heap[i].getParent(i)==studied->v){
//			    ok_to_study.insert(want_to_study->v);
//				}
//				else{
//				studied=studied->next;
//				}
//			}
//		
//		}
//		else{
//			want_to_study=want_to_study->next;
//		}
//		}
//	}
//	
//}




int main(){
	BinaryMinHeap heap(10);
	file_operation(heap);
	LinkedList studied, want_to_study;
	
	cout<<"Enter the courses which you already studied: i.e when done press 0"<<endl;
	studied=getting_input_from_user(studied);
studied.print();
	cout<<"Enter the courses that you want to study: "<<endl;
	want_to_study=getting_input_from_user(want_to_study);
	
//	check_courses(studied, want_to_study, heap);
	
	want_to_study.print();
	
	cout<<"Processing… "<<endl;
	


return 0;
}
