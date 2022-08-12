#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int);
};
Node::Node(int value) 
{
    data = value;
    next = prev = NULL;
}
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert_front(int);
    void insert_back(int);
    int delete_front();
    int delete_back();
    bool is_empty();
    void display();
    int length();
    void search(int);
 
private:
    Node* head;
    Node* tail;
    int size;
 
};

// Constructor 
DoublyLinkedList::DoublyLinkedList()
{
    head = tail = NULL;
    size = 0;
}

// Destructor 
DoublyLinkedList::~DoublyLinkedList(){}
 
void DoublyLinkedList::insert_front(int value)
{
    Node* temp = new Node(value);
 
    if (head == NULL)
        head = tail = temp;
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}
 
void DoublyLinkedList::insert_back(int value)
{
    Node* temp = new Node(value);
 
    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}
    return 0;
}
 
bool DoublyLinkedList::is_empty()
{
    if (size <= 0)
    {
        return true;
    }
 
    return false;
}
 
void DoublyLinkedList::display()
{
    Node* temp = head;
 
    cout << "\n\nDisplay in forward order\n";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL";
}
 
int DoublyLinkedList::length()
{
    return size;
}
 
void DoublyLinkedList::search(int value)
{
    if (!is_empty())
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->data == value)
            {
                cout << "YES! got it." << endl;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}


class BinaryMinHeap{
    private:
    int *heap;
    int heap_size;
    int array_size;
    
    void swap( int i, int j){
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp; } 
    
    public:
    
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
  int code[11], codes_from_string[2];
  

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
//	  
//	  	for(j=0;j<=1;j++){
//			cout<<x[j]<<endl;
//			if(x[j]!=0){
//			cout<<x[j]<< "  ";
//			bt.insert_front(x[j]);
//				}
//			else
//			continue;
//				}
	  
//	heap.printHeap();
  ReadFile.close();
}

int* getting_input_from_user(){
	int i,j,codes[3];
	int *x;
	string user_input;
	for(i=0;i<=2;i++){
		cin>>user_input;
		x=get_Number_From_String(user_input, codes);
		codes[i]=*x;
	}	
	return codes;
}

int check_courses(int* studied, int*  want_to_study, BinaryMinHeap heap){
	
	int i,j;
	DoublyLinkedList ok_to_study,cannot_be_taken;
	for(i=0;i<sizeof(heap);i++){
		for (j=0;j<sizeof(want_to_study);j++){
			if (==want_to_study[j]){
				if (heap.getParent(i)==(studied[0]||studied[1]||studied[2])){
					ok_to_study.insert_front(heap[i]);
				}
				else
				cannot_be_taken.insert_front(heap[i]);
		}
		}
		cout<<"The following courses are OK to take: "<<endl;
		cout<< ok_to_study.display();
		cout<<"The following courses are CANNOT be taken: "<<endl;
		cout<<cannot_be_taken.display();
	}
	
}




int main(){
	BinaryMinHeap heap(11);
	file_operation(heap);
	int* studied, want_to_study;
	
	cout<<"Enter the courses which you already studied:"<<endl;
	studied=getting_input_from_user();
	cout<<"Enter the courses that you want to study: "<<endl;
	want_to_study=getting_input_from_user();
	
	
	cout<<"Processing… "<<endl;
	
	
	


return 0;
}
