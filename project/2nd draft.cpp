#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
using namespace std;

class BST{
private:
	struct Node{
		int data;
		Node* left;
		Node* right;

		Node(int value){
			data = value;
			left = right = NULL;
		}
	};

	Node* root = NULL;

	void addHelper(Node* temp, int value){
		
		if (value <= temp->data){
			if (temp->left == NULL){
				temp->left = new Node(value);
			}
			else{
				addHelper(temp->left, value);
			}
		}
		else{
			if (temp->right == NULL){
				temp->right = new Node(value);
			}
			else{
				addHelper(temp->right, value);
			}
		}
	}
	
    void inOrder(Node* temp){
		if (temp == NULL)
			return;

		inOrder(temp->left);
		cout << temp->data << " ";
		inOrder(temp->right);
		
	}

	Node* removeHelper(Node* root, int data){
		if (root == NULL) return root;
		else if (data < root->data)
			root->left = removeHelper(root->left, data);
		else if (data > root->data)
			root->right = removeHelper(root->right, data);
		else{
			if (root->left == NULL){
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL){
				Node* temp = root->left;
				delete root;
				return temp;
			}
			else{
				int maxValue = this->getMaxHelper(root->left);
				root->data = maxValue;
				root->left = removeHelper(root->left, maxValue);
			}
			
		}
		return root;
	}
	
	void create_node(value) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
	}
	

public:
	
	void insert_left(struct Node* root, int value) {
    root->left = create_node(value);
    return root->left;
	}
	void insert_right(struct Node* root, int value) {
    root->right = create_node(value);
    return root->right;
	}

	void add(int value){
		if (root == NULL){
			root = new Node(value);
		}
		else{
			addHelper(root, value);
		}
	}

    void display_inOrder(){
		if (root != NULL)
			inOrder(root);

		cout << endl;
	}

	void remove(int data){
		root = removeHelper(root, data);
	}
};


// while (true)
//        {
//            if ((right_temp->data )== value)
//            {
//                cout << "YES! got it." << endl;
//                return right_temp;
//                break;
//            }
//            else if(left_temp->data==value){
//            	 cout << "YES! got it." << endl;
//                return left_temp;
//                break;
//			}
//			else{
//				right_temp = right_temp->right;
//            left_temp = left_temp->left;
//			}
//        }

 
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
void file_operation(BST bt){  
  string Text;
  int i,j;
  int *x;
  int code[11], codes_from_string[2];
  

  // Read from the text file
  ifstream ReadFile("dependency tree.csv");
  while(ReadFile)
    
  // Use a while loop together with the getline() function to read the file line by line
  for (i=0;i<6;i++) {
  	getline (ReadFile, Text);
//  	int from string function call
  	x=get_Number_From_String(Text, codes_from_string);
		for(j=0;j<=1;j++){
			
			if(x[j]==0)
			continue;
			else{
			cout<<x[j]<< endl;
			 bt.add(x[j]);
			 }	}
	  }  
	  
	  
bt.display_inOrder();
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

int check_courses(int* studied, int*  want_to_study, BST bt){
	
//	int i,j,Ok_to_study[999];
//	for(i=0;i<sizeof(heap);i++){
//		for (j=0;j<sizeof(want_to_study);j++){
//			if (heap[i]==want_to_study[j]){
//				if (heap.getParent(i)==(studied[0]||studied[1]||studied[2])){
//					
//				}
//			}
//		}
//		
//	}
	
}




int main(){
	BST bt;
	file_operation(bt);
	int* studied, want_to_study;
	
	cout<<"Enter the courses which you already studied:"<<endl;
	studied=getting_input_from_user();
	cout<<"Enter the courses that you want to study: "<<endl;
//	want_to_study=getting_input_from_user();
	
	
	cout<<"Processing…"<<endl;
	


return 0;
}
