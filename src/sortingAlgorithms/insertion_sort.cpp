




#include "ui.h"
#include "visualizer.h"
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>


void Visualizer::insertionSort() {

	//scramble the rectangles
	scramble();

	ui.setAlgorithm("Insertion Sort");

	ui.setBigO("O(n^2)", "O(1)");

	//keep track of comparisons and swaps
	unsigned long  comparisons = 0;
	unsigned long  swaps = 0;


	//reset swap and comparisons count on the display
	ui.setComparisons(comparisons);
	ui.setSwaps(swaps);

	std::clock_t time = std::clock();

	ui.setTime(time);

	render();

	//use vector2f the size of the rectangle instead of the rectangle itself
	sf::Vector2f key;

	size_t j = 0;

	for (size_t i = 1; i < rectangles.size(); i++) {

		//geting the size instead the of whole rectangle increases efficiency
		key = rectangles[i].getSize();

		j = i;


		while (j > 0 && (rectangles[j - 1].getSize().y > key.y)) {
			
			comparisons++;
			ui.setComparisons(comparisons);

			highlight(rectangles[i], rectangles[j - 1]);

			ui.setTime(time);

			render();

			rectangles[j].setSize(rectangles[j - 1].getSize());
			swaps++;
			ui.setSwaps(swaps);

			unHighlight(rectangles[i], rectangles[j - 1]);

			sf::Event event;

			//check for events
			while (ui.event(event)) {

				//close the window and end the loops
				if (event.type == sf::Event::Closed) {

					ui.close();

					j = 1;
					i = rectangles.size() - 1;
				}
				//end the loops
				else if (event.key.code == sf::Keyboard::Escape) {

					j = 1;
					i = rectangles.size() - 1;
					std::cout << "Insertion sort stopped" << std::endl;
				}

			}

			j--;
		}


		rectangles[j].setSize(key);

		swaps++;
		ui.setSwaps(swaps);

	}


	//final render
	render();
	std::cout << "Insertion sort algorithm done" << std::endl;

}




