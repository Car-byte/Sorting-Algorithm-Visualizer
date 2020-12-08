


#include <iostream> 
#include "ui.h"
#include "visualizer.h"
#include <SFML/Graphics.hpp>
#include <ctime>
 

void Visualizer::bubbleSort() {

	//scramble the data set
	scramble();

	//set the algorithm name to be displayed
	ui.setAlgorithm("Bubble Sort");

	ui.setBigO("O(n^2)", "O(1)");

	//keep track of the comparisons and swaps performed
	unsigned long  comparisons = 0;
	unsigned long  swaps = 0;

	//reset swap and comparisons count on the display
	ui.setComparisons(comparisons);
	ui.setSwaps(swaps);

	std::clock_t time = std::clock();

	ui.setTime(time);

	render();


	//bubble sort algorithm
	for (size_t i = 0; i < rectangles.size(); i++) {
		for (size_t j = 0; j < (rectangles.size() - 1 - i); j++) {

			//highlight the two rectangled being compared in red
			highlight(rectangles[j], rectangles[j + 1]);

			ui.setTime(time);

			//display with the highlight
			render();

			comparisons++;
			ui.setComparisons(comparisons);

			//if we need to swap
			if (rectangles[j].getSize().y > rectangles[j + 1].getSize().y) {
				
				swap(rectangles[j], rectangles[j + 1]);
				swaps++;
				ui.setSwaps(swaps);
			}

			//remove the red highlight
			unHighlight(rectangles[j], rectangles[j + 1]);


			sf::Event event;

			//if we have input			
			if (ui.event(event)) {

				
				
				//pressed the x on the window
				if (event.type == sf::Event::Closed) {

					ui.close();
						
					//exit loop
					i = rectangles.size() - 1;
					j = rectangles.size() - i - 2;
				}
				//if the user presses escape we exit the current algorithm
				else if (event.key.code == sf::Keyboard::Escape){
						
					std::cout << "Exited Bubble sort"  << std::endl;

					//exit loop
					i = rectangles.size() - 1;
					j = rectangles.size() - i - 2;
				}
			}
		}
	}

	//shows the final results of the algorithm
	render();

	std::cout << "Bubble sort ended" << std::endl; 
}