#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
using namespace std;


class DoublyLinkedList
{
	private:
	struct Node{
		int data;
		Node* left;
		Node* right;
		Node(int value){
			data = value;
//			left = right = NULL;
		}
	};
	Node* root = NULL;
    
    void inOrder(Node* temp);
    int size;
	Node* root = new Node (101);
	
	public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(int*);
    bool is_empty();
    void display_inOrder();
    int length();
    Node* right_search(int value, Node* temp){
    	    	cout<<"hi"<<endl;
    	
//        Node* left_temp = root;
//        Node* right_temp=root;
	if(value==temp->data){
		return temp;
	}
	else{
		return right_search(value, temp->right)
	}

        
	}
  
};

// Constructor 
DoublyLinkedList::DoublyLinkedList()
{
    root  = NULL;
    size = 0;
}

// Destructor 
DoublyLinkedList::~DoublyLinkedList(){}
//
//Node* DoublyLinkedList:: search(int value, Node* temp){
//    	cout<<"hi"<<endl;
//    	
////        Node* left_temp = root;
////        Node* right_temp=root;
//
//        search(value,temp->left);
//     		if (temp->data==value){
//			return temp;
//			}
//			else{
//				return search(value,temp->right);
//			}
//}

void DoublyLinkedList::inOrder(Node* temp){
	
   	if (temp == NULL)
			return;

		inOrder(temp->left);
		cout << temp->data << " ";
		inOrder(temp->right);
}
 
void DoublyLinkedList::insert(int *value){
	Node* left_temp = new Node(value[0]);
	Node* right_temp = new Node(value[2]);
	Node* root_temp= new Node(value[1]);
	Node* searched;


    if (root == NULL){
        root = root_temp;
        cout<<"if here"<<endl;
}
	else
    {
    	searched= search(value[1], root);
    	searched->left= left_temp;
//    	left_temp->prev=searched;
    	searched-= right_temp;
//    	right_temp->prev-searched;
    	
	cout<<"else here"<<endl;
        
    }
    size++;
	
}
 
bool DoublyLinkedList::is_empty(){
    if (size <= 0){ return true; }
    return false;
}
 
 
void DoublyLinkedList::display_inOrder(){
		if (root != NULL)
			inOrder(root);

		cout << endl;
	}
 

 
int DoublyLinkedList::length()
{
    return size;
}
 
//Node* DoublyLinkedList::

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
void file_operation(DoublyLinkedList bt){  
  string Text;
  int j,i;
  int *x;
  int codes_from_string[2],codes[3];
  

  // Read from the text file
  ifstream ReadFile("dependency tree.csv");

  // Use a while loop together with the getline() function to read the file line by line
  for(i=0;i<4;i++){
  	
  	getline (ReadFile, Text);
//  	int from string function call
  	x=get_Number_From_String(Text, codes_from_string);
	cout<<x[0]<<" "<<x[1]<<endl;
	codes[0]=x[0];
	codes[1]=x[1];
	getline (ReadFile, Text);
	x=get_Number_From_String(Text, codes_from_string);
	cout<<x[0]<<" "<<x[1]<<endl;
	if(x[1]==codes[1]){
		codes[2]==x[0];
	}
	else{
		codes[2]=9;
	}
	bt.insert(codes);
bt.display_inOrder();
	  }  
bt.display_inOrder();
  ReadFile.close();
}

int* getting_input_from_user(){
//	int i,j;
//	int *codes[3];
//	int *x;
//	string user_input;
//	for(i=0;i<=2;i++){
//		cin>>user_input;
//		x=get_Number_From_String(user_input, codes);
//		codes[i]=*x;
//	}	
//	return codes;
}

int check_courses(int* studied, int*  want_to_study, DoublyLinkedList bt){
	
//	int i,j;
//	DoublyLinkedList ok_to_study,cannot_be_taken;
//	for(i=0;i<sizeof(heap);i++){
//		for (j=0;j<sizeof(want_to_study);j++){
//			if (==want_to_study[j]){
//				if (heap.getParent(i)==(studied[0]||studied[1]||studied[2])){
//					ok_to_study.insert_front(heap[i]);
//				}
//				else
//				cannot_be_taken.insert_front(heap[i]);
//		}
//		}
//		cout<<"The following courses are OK to take: "<<endl;
//		cout<< ok_to_study.display();
//		cout<<"The following courses are CANNOT be taken: "<<endl;
//		cout<<cannot_be_taken.display();
//	}
//	
}




int main(){
	DoublyLinkedList bt;
	file_operation(bt);
	int *studied, *want_to_study;
	
	cout<<"\nEnter the courses which you already studied:"<<endl;
	studied=getting_input_from_user();
	cout<<"Enter the courses that you want to study: "<<endl;
	want_to_study=getting_input_from_user();

//	cout<<"Processing… "<<endl;
	
return 0;
}
