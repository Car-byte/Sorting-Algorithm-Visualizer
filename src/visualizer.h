


#ifndef VISUALIZER_H
#define VISUALIZER_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ui.h"


class Visualizer {
public:

	Visualizer();//sets the array of rectangles
	
	void test();//delete before post

	void start();//starts the main loop and displays the options menu

	void render();//renders the current state and displays it

	void scramble();//scrambles the position of the rectangles

	void highlight(sf::RectangleShape&, sf::RectangleShape&); //highlights two rectangles in red

	void unHighlight(sf::RectangleShape&, sf::RectangleShape&);//sets two rectangles back to the default color white

	void displayOptions();//displays the options menu

	void swap(sf::RectangleShape&, sf::RectangleShape&);//swaps the position of two rectangles //helper function

private:

	//quick sorts
	void quickSort(long long, long long, unsigned long&, unsigned long&, std::clock_t&, bool&); 
	void quickSort();//starts the quicksort algorithm
	long long partition(long long, long long, unsigned long&, unsigned long&, std::clock_t&, bool&);


	void insertionSort();//insertion sort algorithm
	void selectionSort();//selection sort algorithm
	void bubbleSort();//bubble sort algorithm

	//void radixSort();
	//sf::Vector2f getMax();
	//void countingSort(long long, unsigned long&, unsigned long&, std::clock_t&, bool&);

	//merge sort
	void mergeSort();//starts the merge sort algorithm
	void mergeSort(size_t, size_t, unsigned long&, unsigned long&, std::clock_t&, bool&);
	void merge(size_t, size_t, size_t, unsigned long&, unsigned long&, std::clock_t&, bool&);

	UI ui; //user interface
	std::vector<sf::RectangleShape> rectangles; //the ractangles being sorted and displayed
};



#endif // !VISUALIZER_H