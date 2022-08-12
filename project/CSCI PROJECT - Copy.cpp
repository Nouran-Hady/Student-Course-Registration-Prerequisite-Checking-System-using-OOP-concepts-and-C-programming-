#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
#include<vector>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;


//
//class node{
//	public:
//		int v;
//		node *next;
//		node(){
//			next = NULL;
//		}
//};
//
//class LinkedList{
//	node *head;
//	public:
//		node* return_head_data(){
//			node* x;
//			if (head->next == NULL){
//				cout<<"if here";
//				return head; 
//				}
//			else{
//				cout<<"else here";
//				head=head->next;
//				return head;
//				}
//		}
//		void insert_at_end(int v){
//			node *temp = new node();
//			temp->v = v;
//			if (head == NULL){ head = temp;	}
//			else{
//				node *ptr = head;
//				while (ptr->next != NULL){
//					ptr = ptr->next;	}
//				ptr->next = temp;	}
//		}
//		};



struct Node
{
	int data;
	Node* left, * right;
};

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Function to insert nodes in level order
Node* insertLevelOrder(int arr[], Node* root,
					int i, int n)
{
	// Base case for recursion
	if (i < n)
	{
		Node* temp = newNode(arr[i]);
		root = temp;
		
		// insert left child
		root->left = insertLevelOrder(arr,
				root->left, 2 * i + 1, n);

		// insert right child
		root->right = insertLevelOrder(arr,
				root->right, 2 * i + 2, n);
	}
	return root;
}

void inOrder(Node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->data <<" ";
		inOrder(root->right);
	}
}


// function to get int from string
int* get_Number_From_String(string course, int* code) {
   stringstream course_stream;  
   int temp_intger,i=0;
   string temp_string;  
   
   course_stream << course; //convert the string s into stringstream
   
   while(!course_stream.eof()) {
   	
      course_stream >> temp_string; //take words into temp_str one by one
      
      if(stringstream(temp_string) >> temp_intger) { //try to convert string to int

        	code[i]=temp_intger;
	 }
   }
   return code;
}

//function to operate on file
Node *file_operation(){  
  string Text;
  int i=0;
  int *x;
  int code[10], codes[2];
  
   //Read from the text file
  ifstream ReadFile("dependency tree.csv");

string Course[10];
  // Use a while loop together with the getline() function to read the file line by line
  ifstream inFile("dependency tree.csv");
    if (inFile.is_open())
    {
        string line;
        while( getline(inFile,line) )
        {
            stringstream ss(line);
            getline(ss,Course[i],','); 
            i++;
        }
}

string course_string = "";
     for(i=0;i<10;i++){
    course_string =Course[i];
		 x = get_Number_From_String(course_string, codes);	
		 code[i] = *x;
		 }
		 
Node* root = insertLevelOrder(code, root, 0, 10);
	            inOrder(root);
	 ReadFile.close();
	 return root;
}

//int search_result(int result ,int i){
//	
//	int data[6];
//	data[i]=result;	
////	cout<<"     "<<data[2]<<endl;
//	cout<<data[i]<<endl;
//	
////	return data[];
//}

bool compare_values(Node* cmpr, Node* compr, int value){
	bool flag=false;
	int data=cmpr->data;
	int right_data=compr->data;
	cout<<data<<endl;
	cout<<right_data<<endl;
	cout<<"value = "<<value<<endl;
	if(data == value) {cout<<"ok to take"<<endl; flag =true; }
	else if(right_data==value) {cout<<"ok to take"<<endl; flag =true; }	
	return flag;
}

//searchNode() will search for the particular node in the binary tree  

bool searchNode(Node* temp, int value, int x){  
	static bool flag = false;
	static bool cmpr_flag=false;
	Node* pre_temp;
        //If value is found in the given binary tree then, set the flag to true  
        if(temp->data == value){  
            flag = true;
			cmpr_flag=compare_values(temp->left, temp->right, x); 
            return cmpr_flag;
		  }
        //Search in left subtree  
        if(flag == false && temp->left != NULL){  
        searchNode(temp->left, value, x);  }  
        //Search in right subtree  
        if(flag == false && temp->right != NULL){  
        searchNode(temp->right, value, x);   } 
}  

void check_courses(string studied[], string want_to_study[],Node* ptr){
	int i=0,j=0; int xcodes[3]; int ycodes[3];
	int* x;
	int* y;
	bool obj=false;
	while (want_to_study[i+1]!="mm"){
		x=get_Number_From_String(want_to_study[i],xcodes);
		
		while (studied[j+1]!="mm"){
			y=get_Number_From_String(studied[j],ycodes);
			obj = searchNode(ptr,*y, *x);
			j++;
			cout<<obj<<endl;
			if(obj){
				cout<<"ok to take"<<endl;
			}
			else continue;
				
				}
		i++;
	}
}

void getting_input_from_user(string user_input[]){
	
	int choice,i=0;
	do {
		cout<<"\n1)insert \n0)exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cin>>user_input[i];	
				i++;
		}
	} while (choice != 0);
	user_input[i+1]="mm";

}

int main()
{
Node* ptr=file_operation();
string studied[100];
string want_to_study[100];

cout<<"\nEnter the courses which you already studied: "<<endl;
getting_input_from_user(studied);

cout<<"\n  fffEnter the courses that you want to study: "<<endl;
getting_input_from_user(want_to_study);

check_courses(studied,want_to_study,ptr);

//bool flag=searchNode(ptr, 404);

	        
}

