#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
#include<vector>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

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

//searchNode() will search for the particular node in the binary tree  
	void searchNode(Node* temp, int value, int x,  string ok_to_study[], string cannot_be_taken[], string want_to_study){  
	static bool flag = false;
	static int v=value;
	Node* cmpr=temp->left;
	Node* compr=temp->right;
        //If value is found in the given binary tree then, set the flag to true  
        if(temp->data == value){
//		cout<< "value" <<value<<endl;
	    flag = true;
		int i=0;
		int data=cmpr->data;
		int right_data=compr->data;
//		cout<<"data = "<<data<<endl;
//		cout<<"right_data = "<<right_data<<endl;
			
		if(data == value || right_data==value) { 
		if(ok_to_study[i].empty()){
			ok_to_study[i]=want_to_study;
		ok_to_study[i+1]="null";
		}
		else{
			while(ok_to_study[i]!="null" ){i++;}
		ok_to_study[i]=want_to_study;
		ok_to_study[i+1]="null";
		}
		
		 }
		else{	
		if(cannot_be_taken[i].empty()){
		cannot_be_taken[i]=want_to_study;
		cannot_be_taken[i+1]="null";
		}
		else{
		while(cannot_be_taken[i]!="null"){i++;}
			cannot_be_taken[i]=want_to_study;
			cannot_be_taken[i+1]="null";	
		}
		}	
			  }
	        //Search in left subtree  
	        if(flag == false && temp->left != NULL){  
	        searchNode(temp->left, v, x, ok_to_study,cannot_be_taken, want_to_study);  }  
	        //Search in right subtree  
	        if(flag == false && temp->right != NULL){  
	        searchNode(temp->right, v, x, ok_to_study,cannot_be_taken, want_to_study);   } 
}  


void check_courses(string studied[], string want_to_study[],Node* ptr, string ok_to_study[], string cannot_be_taken[]){

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
string  ok_to_study[100];
string cannot_be_taken[100];

cout<<"\nEnter the courses which you already studied: "<<endl;
getting_input_from_user(studied);

cout<<"\nEnter the courses that you want to study: "<<endl;
getting_input_from_user(want_to_study);


cout<<"\nProcessing,,, "<<endl;
int i=0,j=0; int xcodes[3]; int ycodes[1];
int *x;
int *y;

	while (want_to_study[i+1]!="mm"){
		j=0;
		x=get_Number_From_String(want_to_study[i],xcodes);
			searchNode(ptr,*(get_Number_From_String(studied[j],ycodes)), *(get_Number_From_String(want_to_study[i],xcodes)), ok_to_study, cannot_be_taken, want_to_study[i]);
			cout<<endl<< studied[j]<<endl;
			
			y=get_Number_From_String(studied[j+1],ycodes);
			cout<<*y<<endl;
			searchNode(ptr,*(get_Number_From_String(studied[j+1],ycodes)), *x, ok_to_study, cannot_be_taken, want_to_study[i] );
			
			cout<<endl<< studied[j+1]<<endl;
//			y=get_Number_From_String(studied[j+2],ycodes);
			searchNode(ptr,*(get_Number_From_String(studied[j+2],ycodes)), *x, ok_to_study, cannot_be_taken, want_to_study[i] );
			cout<<endl<< studied[j+2]<<endl;
			i++;
	}


check_courses(studied,want_to_study,ptr,ok_to_study,cannot_be_taken);

//cout<<"ok_to_study"<<endl;
//cout<<ok_to_study[0]<<endl;	
//cout<<ok_to_study[1]<<endl;	
//cout<<ok_to_study[2]<<endl;	
//cout<<"cannot_be_taken"<<endl;
//cout<<cannot_be_taken[0]<<endl;
//cout<<cannot_be_taken[1]<<endl;
//cout<<cannot_be_taken[2]<<endl<<endl;


	i=0;
	j=0;
	string s1,s2;
	while(ok_to_study[i+1]!="null"){
		s1=ok_to_study[i];
		j=0;
		while(cannot_be_taken[j+1]!="null"){
			s2=cannot_be_taken[j];
			
			if((s1.compare(s2))){
				cout<<cannot_be_taken[j]<<endl;
				cout<<(s1.compare(s2))<<endl;
				cannot_be_taken[j]="null";
				cout<<cannot_be_taken[j]<<endl;}
			j++;
		}	
		i++;		
	}
	

//cout<<"ok_to_study"<<endl;
//cout<<ok_to_study[0]<<endl;	
//cout<<ok_to_study[1]<<endl;	
//cout<<ok_to_study[2]<<endl;	
//cout<<"cannot_be_taken"<<endl;
//cout<<cannot_be_taken[0]<<endl;
//cout<<cannot_be_taken[1]<<endl;
//cout<<cannot_be_taken[2]<<endl;

cout<<"\nThe following courses are OK to take: "<<endl;
//i=0;
//while(ok_to_study[i]!="null"){
//cout<<ok_to_study[i];
//i++;
//}
cout<<"\nThe following courses CANNOT be taken: "<<endl;
//i=0;
//while(cannot_be_taken[i]!="null"){
//cout<<cannot_be_taken[i];
//i++;
//}
//bool flag=searchNode(ptr, 404);	        
}
