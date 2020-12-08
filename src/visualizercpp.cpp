




#include <iostream>
#include "visualizer.h"
#include <SFML/Graphics.hpp>

//swaps two rectangles positions
void Visualizer::swap(sf::RectangleShape& rectangle1, sf::RectangleShape& rectangle2) {

	sf::Vector2f i = rectangle1.getSize();
	sf::Vector2f j = rectangle2.getSize();
	rectangle1.setSize(j);
	rectangle2.setSize(i);
}

//creates an array of rectangles of random value
Visualizer::Visualizer(){

	float j = 6;

	for (int i = 0; i < 114; i++) {

		sf::RectangleShape temp;

		temp.setFillColor(sf::Color::White);
		temp.setSize(sf::Vector2f(3, float(std::rand() % 550)));
		temp.setRotation(temp.getRotation() + 180);
		temp.setPosition(j, 600);
		
		rectangles.push_back(temp);

		j = j + float(7);
	}
}


//renders all the shapes and text and displays them
void Visualizer::render() {

	ui.clear();

	ui.renderText();

	ui.renderRectangles(this->rectangles);

	ui.display();
}


//delete before upload
void Visualizer::test() {

	while (ui.isOpen()) {

		sf::Event event;

		while (ui.event(event)) {

			if (event.type == sf::Event::Closed) {
				ui.close();
			}

		}

		scramble();
		render();
	}
}


//scrambels the data set
void Visualizer::scramble() {

	for (int i = 0; i < rectangles.size(); i++) {

		swap(rectangles[i], rectangles[std::rand() % rectangles.size()]);
	}	
}


//sets the color of two rectangles to red
void Visualizer::highlight(sf::RectangleShape& rectangle1, sf::RectangleShape& rectangle2) {

	rectangle1.setFillColor(sf::Color::Red);
	rectangle2.setFillColor(sf::Color::Red);
}


//sets the color of two rectangles to white(default color)
void Visualizer::unHighlight(sf::RectangleShape& rectangle1, sf::RectangleShape& rectangle2) {
	
	rectangle1.setFillColor(sf::Color::White);
	rectangle2.setFillColor(sf::Color::White);
}



//starts everthing
void Visualizer::start() {

	displayOptions();

	//while the user has not closed out
	while (ui.isOpen()) {

		sf::Event event;

		//if the user does an action
		while (ui.event(event)) {

			if (event.type == sf::Event::Closed) {
				ui.close();
			}
			else if (event.type == sf::Event::KeyPressed) {

				switch (event.key.code) {

				case sf::Keyboard::Q:
					std::cout << "Quick sort selected" << std::endl;
					quickSort();
					break;

				case sf::Keyboard::I:
					std::cout << "Insertion sort selected" << std::endl;
					insertionSort();
					break;

				case sf::Keyboard::B:
					std::cout << "Bubble sort selected" << std::endl;
					bubbleSort();
					break;

				case sf::Keyboard::S:
					std::cout << "Selection sort selected" << std::endl;
					selectionSort();
					break;

				case sf::Keyboard::M:
					std::cout << "Merge sort selected" << std::endl;
					mergeSort();
					break;

				/*case sf::Keyboard::R:
					std::cout << "Radix sort selected" << std::endl;
					radixSort();
					break;*/

				case sf::Keyboard::Escape:
					std::cout << "No algorithm selected" << std::endl;
					break;

				}
			}
		}
	}
}


//displays all the options
void Visualizer::displayOptions() {

	std::cout << "*************************************************************************" << std::endl;
	std::cout << "Press key q for the quick sort algorithm" << std::endl;
	std::cout << "Press key i for insertion sort algorithm" << std::endl;
	std::cout << "Press key s for selection sort algorithm" << std::endl;
	std::cout << "Press key b for bubble sort algorithm" << std::endl;
	std::cout << "Press key m for merge sort algorithm" << std::endl;
	//std::cout << "Press key r for radix sort algorithm" << std::endl;
	std::cout << std::endl;
	std::cout << "Press the escape key at anytime through the sort to cancel current algorithm and pick a new one" << std::endl;
	std::cout << "*************************************************************************" << std::endl;
	std::cout << std::endl << std::endl;
}

