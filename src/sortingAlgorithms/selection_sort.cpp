




#include <iostream>
#include "ui.h"
#include "visualizer.h"
#include <ctime>
#include <SFML/Graphics.hpp>


void Visualizer::selectionSort() {

	//scramble the rectangles
	scramble();

	ui.setAlgorithm("Selection Sort");

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

	size_t minimum_index = 0;

	for (size_t i = 0; i < rectangles.size(); i++) {

		minimum_index = i;

		for (size_t j = i + 1; j < rectangles.size(); j++) {

			ui.setTime(time);

			comparisons++;
			ui.setComparisons(comparisons);

			highlight(rectangles[j], rectangles[minimum_index]);

			render();

			unHighlight(rectangles[j], rectangles[minimum_index]);

			if (rectangles[j].getSize().y < rectangles[minimum_index].getSize().y) {
				minimum_index = j;
			}


			sf::Event event;
			//track events
			while (ui.event(event)) {

					//close window and stop loops
				if (event.type == sf::Event::Closed) {

					ui.close();

					i = rectangles.size() - 1;
					j = rectangles.size() - 1;

				}
					//stop loops and return to main loop
				else if (event.key.code == sf::Keyboard::Escape) {

					std::cout << "Exiting Selection Sort" << std::endl;

					i = rectangles.size() - 1;
					j = rectangles.size() - 1;
				}
			}
		}

		swaps++;
		ui.setSwaps(swaps);
		swap(rectangles[i], rectangles[minimum_index]);

	}

	render();
	std::cout << "Selection sort ended" << std::endl;
}




