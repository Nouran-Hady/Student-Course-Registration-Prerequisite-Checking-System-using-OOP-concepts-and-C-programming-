#include <iostream>
#include <fstream>
#include <typeinfo>
#include<string>
#include<sstream>
#include<vector>
#include <bits/stdc++.h>
#include <cstdlib>
//#include <graphics.h>
//#include <math.h>
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
//	if (right < total_elements) {
//		line(x, y, x + y / (index + 1), y + 50);
//	}
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
//	            inOrder(root);
	 ReadFile.close();
	 return root;}
//searchNode() will search for the particular node in the binary tree  

int searchNode(Node* temp, int value, int x,  string ok_to_study[], string cannot_be_taken[], string want_to_study){  
	bool flag = false;
	Node* cmpr=temp->left;
	Node* compr=temp->right;
        //If value is found in the given binary tree then, set the flag to true  
        if(temp->data == value){
		cout<< "value" <<value<<endl;
	    flag = true;
		int i=0;
		int data=cmpr->data;
		int right_data=compr->data;
			
		if(data == value || right_data==value) { 
		cout<<"heeeeeerrrrreeeeeeee"<<endl;
		while(ok_to_study[i]!="null"){i++;}
		ok_to_study[i]=want_to_study;
		ok_to_study[i+1]="null";
		 }
		else{	

		while(cannot_be_taken[i]!="null"){i++;}
			cannot_be_taken[i]=want_to_study;
			cannot_be_taken[i+1]="null";	
		}	
			  }
	        //Search in left subtree  
	        if(flag == false && temp->left != NULL){  
	        searchNode(temp->left, value, x, ok_to_study,cannot_be_taken, want_to_study);  }  
	        
	        //Search in right subtree  
	        if(flag == false && temp->right != NULL){  
	        searchNode(temp->right, value, x, ok_to_study,cannot_be_taken, want_to_study); 
  } 
	        return 0;
	    }

void check_courses(int x , string studied[],Node* ptr, string ok_to_study[], string cannot_be_taken[], string want_to_study){
//	int i=0,j=0; int xcodes[3]; 
	int j=0;
	int ycodes[1];
//	int *x;
	int *y;
	
//	for (i=0;want_to_study[i+1]!="mm";i++){
//		x=get_Number_From_String(want_to_study[i],xcodes);
//		j=0;
		while (studied[j]!="mm"){
			cout<<studied[j]<<endl;
			y=get_Number_From_String(studied[j],ycodes);
			searchNode(ptr,*y, x, ok_to_study, cannot_be_taken, want_to_study );
			j++;
			}
//		}
//		i++;


//i=0;
//int flag=0;
//while(want_to_study[i]!="mm"){	
//j=0;
//flag=0;
//while(children_of_studied[j]!=0){
//	x=get_Number_From_String(want_to_study[i],xcodes);
//		if (*x==children_of_studied[j]){
//			cout<<"heeeeeeereeee"<<endl;
//			while(ok_to_study[flag]!="null"){ flag++; }
//			ok_to_study[flag]=want_to_study[i];
//			ok_to_study[flag+1]=="null";
//		}
//		else{
//		while(ok_to_study[flag]!="null"){ flag++; }	
//		cannot_be_taken[flag]==want_to_study[i];
//		cannot_be_taken[flag+1]=="null";
//			}
//		j++;
//	}
//i++;
//}

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
string  ok_to_study[100]={"null"};
string cannot_be_taken[100]={"null"};
int i;

cout<<"\nEnter the courses which you already studied: "<<endl;
getting_input_from_user(studied);

cout<<"\nEnter the courses that you want to study: "<<endl;
getting_input_from_user(want_to_study);


cout<<"\nProcessing,,, "<<endl;

//////////
//
//int *x;
//int xcodes[3];
//i=0;
//while (want_to_study[i]!="mm"){
//	x=get_Number_From_String(want_to_study[i],xcodes);
//	check_courses(*x,studied,ptr,ok_to_study,cannot_be_taken, want_to_study[i] );
//	i++;
//	}
//	
//i=0;
//while (ok_to_study[i] !="null"){
//cout<<"ok to study"<<ok_to_study[i]<<endl;
//i++;
//}
//////////////





//i=0;
//int j=0;
//string s1,s2;
//while(ok_to_study[i+1]!="null"){
//	s1=ok_to_study[i];
//	j=0;
//	while(cannot_be_taken[j+1]!="null"){
//		s2=cannot_be_taken[j];
//		
//		if((s1.compare(s2))){
//			cout<<cannot_be_taken[j]<<endl;
//			cout<<(s1.compare(s2))<<endl;
//			cannot_be_taken[j]="null";
//			cout<<cannot_be_taken[j]<<endl;}
//		j++;
//	}	
//	i++;		
//}


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



// Initialize graphic driver
//	int gd = DETECT, gm;
//	
//	initgraph(&gd, &gm,"None");

	// Consider the tree as represented
	/*
			1
		/	 \
		2	 3
	/ \	 / \
	4 5 6 7
	/ \ /
	8 9 10
	*/

	// Given array arr[]

//	int array[10] = { 101, 207, 311, 217, 313, 415, 304, 419, 315, 404};
//
//	// Function Call
//	printTree(300, 100, array, 0, 10);
//	getch();

	// closegraph function closes the
	// graphics mode and deallocates
	// all memory allocated by
	// graphics system
//	closegraph();	        
}
