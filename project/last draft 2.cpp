#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
#include<vector>
#include <bits/stdc++.h>
#include <cstdlib>
#include <graphics.h>
#include <math.h>
using namespace std;

//void printTree(int x, int y, int* array,
//			int index,
//			int total_elements)
//{
//
//	// Base Case
//	if (index >= total_elements)
//		return;
//
//	// Convert int value into string
//	ostringstream str1;
//	str1 << array[index];
//
//	string str2 = str1.str();
//	char* str = &str2[0u];
//
//	// Set color of the boundary of
//	// circle as green
//	setcolor(GREEN);
//
//	// Draw the circle of radius 15
//	// that represent node of Tree
//	circle(x, y, 15);
//	floodfill(x, y, GREEN);
//
//	// Print the values of the node
//	// in the circle
//	outtextxy(x - 2, y - 3, str);
//
//	// Set the color of the line
//	// from parent to child as green
//	setcolor(BLUE);
//
//	// Evaluating left and right child
//	int left = 2 * index + 1;
//	int right = 2 * index + 2;
//
//	// Recursively draw the left subtree
//	// and the right subtree
//	printTree(x - y / (index + 1), y + 50,
//			array, left, total_elements);
//
//	printTree(x + y / (index + 1), y + 50,
//			array, right, total_elements);
//
//	// Draw the line (or link) when the
//	// node is not the leaf node
//	if (left < total_elements) {
//		line(x, y, x - y / (index + 1), y + 50);
//	}
//
//	if (right < total_elements) { line(x, y, x + y / (index + 1), y + 50); }
//
//	return;
//}


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
Node* insertLevelOrder(int arr[], Node* root, int i, int n){
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
        while( getline(inFile,line) )  {
            stringstream ss(line);
            getline(ss,Course[i],','); 
            i++;
        }}
string course_string = "";
     for(i=0;i<10;i++){
    course_string =Course[i];
		 x = get_Number_From_String(course_string, codes);	
		 code[i] = *x;
		 }
		 
Node* root = insertLevelOrder(code, root, 0, 10);
	 ReadFile.close();
	 return root;}
	 
//searchNode() will search for the particular node in the binary tree  

int searchNode(Node* temp,  int value,  int children_of_studied[]){  
	bool flag = false;
	Node* cmpr=temp->left;
	Node* compr=temp->right;
	
        //If value is found in the given binary tree then, set the flag to true  
        if(temp->data == value){
	    flag = true;
		int i=0;
		int data=cmpr->data;
		int right_data=compr->data;
	
			while(children_of_studied[i]!=0 ){i++;}
		children_of_studied[i]=data;
		children_of_studied[i+1]=right_data;
		children_of_studied[i+2]=0;
		 return 0 ;
	}
	 //Search in left subtree  
	        if(flag == false && temp->left != NULL){  
	        searchNode(temp->left,   value,  children_of_studied);  }  
	        
	        //Search in right subtree  
	        if(flag == false && temp->right != NULL){  
	        searchNode(temp->right,   value,  children_of_studied); } 
	        
	        return 0;
	    }


void sort_courses (int children_of_studied[] , string want_to_study[] , 
	string ok_to_study[], string cannot_be_taken[] ){
	int xcodes[1];
	int *x;
	int i=0, j=0,k=0;
	bool flag=false;
//	
	while(want_to_study[i]!="null"){
		
		x=get_Number_From_String(want_to_study[i],xcodes);
		j=0;
		flag=false;
		while(children_of_studied[j]!=0){
			k=0;
			if (*x==children_of_studied[j]){
			while (ok_to_study[k]!="null"){ k++; }
				ok_to_study[k]=want_to_study[i];
				ok_to_study[k+1]="null";
				flag=true;
				break;}
				j++;
		}
		if  (flag==false){
			while (cannot_be_taken[k]!="null"){ k++; }
				cannot_be_taken[k]=want_to_study[i];
				cannot_be_taken[k+1]="null";
				}
			i++;	}
			}
	
void courses_to_be_searched( string studied[],Node* ptr, int children_of_studied[]){
int xcodes[1];
int *x;
int i=0;
while ( studied[i]!="null" ){	
	x=get_Number_From_String(studied[i],xcodes);
	searchNode(ptr,*x, children_of_studied );
	i++;}
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
	user_input[i+1]="null";	
}

void print_courses(string ok_to_study[], string cannot_be_taken[]){
	int i=0;
cout<<"\nThe following courses are OK to take: "<<endl;

i=0;
while(ok_to_study[i+1] != "null"){
	cout<<ok_to_study[i]<<endl;
	i++;
	}
	cout<<ok_to_study[i]<<endl;
	
cout<<"\nThe following courses CANNOT be taken: "<<endl;
i=0;
while(cannot_be_taken[i+1] != "null"){
	cout<<cannot_be_taken[i]<<endl;
	i++;
	}
	cout<<cannot_be_taken[i]<<endl;
}

int main()
{
Node* ptr=file_operation();
string studied[4];

int children_of_studied[7]={0};
string want_to_study[4];

string  ok_to_study[4]={"null"};
string cannot_be_taken[4]={"null"};
int i;

cout<<"\nEnter the courses which you already studied: "<<endl;
getting_input_from_user(studied);

cout<<"\nEnter the courses that you want to study: "<<endl;
getting_input_from_user(want_to_study);

cout<<"\nProcessing,,, "<<endl;
courses_to_be_searched(studied,ptr,children_of_studied);
sort_courses(children_of_studied, want_to_study , ok_to_study, cannot_be_taken );
print_courses(ok_to_study, cannot_be_taken);



//// Initialize graphic driver
//	int gd = DETECT, gm;
//	initgraph(&gd, &gm,"None");

////	// Function Call
//	printTree(300, 100, ok_to_study, 0, 10);
//	getch();

//	// closegraph function closes the
//	// graphics mode and deallocates
//	// all memory allocated by
//	// graphics system
//	closegraph();	        
}
