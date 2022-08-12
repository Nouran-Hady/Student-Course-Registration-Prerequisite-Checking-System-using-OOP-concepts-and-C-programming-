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

void printTree(int x, int y, int* array,
			int index,
			int total_elements)
{

	// Base Case
	if (index >= total_elements)
		return;

	// Convert int value into string
	ostringstream str1;
	str1 << array[index];

	string str2 = str1.str();
	char* str = &str2[0u];

	// Set color of the boundary of
	// circle as green
	setcolor(GREEN);

	// Draw the circle of radius 15
	// that represent node of Tree
	circle(x, y, 15);
	floodfill(x, y, GREEN);

	// Print the values of the node
	// in the circle
	outtextxy(x - 2, y - 3, str);

	// Set the color of the line
	// from parent to child as green
	setcolor(BLUE);

	// Evaluating left and right child
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	// Recursively draw the left subtree
	// and the right subtree
	printTree(x - y / (index + 1), y + 50,
			array, left, total_elements);

	printTree(x + y / (index + 1), y + 50,
			array, right, total_elements);

	// Draw the line (or link) when the
	// node is not the leaf node
	if (left < total_elements) {
		line(x, y, x - y / (index + 1), y + 50);
	}

	if (right < total_elements) {
		line(x, y, x + y / (index + 1), y + 50);
	}

	return;
}

int main() {
//	/ Initialize graphic driver
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"None");
	
	int array[2] = { 207, 217};
//	// Function Call
	printTree(300, 100, array, 0, 2);
	getch();
	int array1[3]={311,313,415};
	printTree(300, 100, array1, 0, 3);
	getch();

	// closegraph function closes the
	// graphics mode and deallocates
	// all memory allocated by
	// graphics system
	closegraph();	       
	return 0;
}
