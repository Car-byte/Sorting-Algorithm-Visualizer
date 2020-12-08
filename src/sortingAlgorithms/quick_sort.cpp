


#include <iostream> 
#include "ui.h"
#include "visualizer.h"
#include <SFML/Graphics.hpp>
#include <ctime> 


//note to everyone NEVER use unsigned numbers for quick sort 
void Visualizer::quickSort() {

	//scramble the rectangles
	scramble();

	ui.setAlgorithm("Quick Sort");

	ui.setBigO("O(n log(n))", "O(log(n))");

	//keep track of comparisons and swaps
	unsigned long  comparisons = 0;
	unsigned long  swaps = 0;


	//reset swap and comparisons count on the display
	ui.setComparisons(comparisons);
	ui.setSwaps(swaps);

	std::clock_t time = std::clock();

	ui.setTime(time);

	render();

	bool exit = false;

	quickSort(0, rectangles.size() - 1, swaps, comparisons, time, exit);

	render();

	std::cout << "Quick sort algorithm ended" << std::endl;
}



void Visualizer::quickSort(long long low, long long high, unsigned long& swaps, unsigned long& comparisons, std::clock_t& time, bool& exit) {

	//if the user pressed escape or exited the window
	if (exit == true) return;

	if (low < high) {

		long long pivot = partition(low, high, swaps, comparisons, time, exit);

		quickSort(low, pivot - 1, swaps, comparisons, time, exit);
		quickSort(pivot + 1, high, swaps, comparisons, time, exit);

	}
}


long long Visualizer::partition(long long low, long long high, unsigned long& swaps, unsigned long& comparisons, std::clock_t& time, bool& exit) {

	//std::cout << "High: " << high << std::endl;
	sf::Vector2f pivot = rectangles[high].getSize();

	long long i = low - 1;

	for (long long j = low; j < high; j++) {

		comparisons++;
		ui.setComparisons(comparisons);

		ui.setTime(time);

		highlight(rectangles[j], rectangles[high]);

		render();

		//if we need to swap
		if (rectangles[j].getSize().y <= pivot.y) {

			i++;
			swap(rectangles[i], rectangles[j]);
			swaps++;
			ui.setSwaps(swaps);
		}

		unHighlight(rectangles[j], rectangles[high]);

		sf::Event event;

		while (ui.event(event)) {

			if (event.type == sf::Event::Closed) {

				//exit loop and set exit to true to exit algorithm
				//closing ui will exit the main loop and terminate the program
				ui.close();
				j = high - 1;
				exit = true;
			}
			else if (event.key.code == sf::Keyboard::Escape) {

				//exit loop and set exit to true to exit algorithm
				j = high - 1;
				exit = true;
				std::cout << "Quick sort algorithm stopped" << std::endl;
			}
		}
	}

	swap(rectangles[i + 1], rectangles[high]);
	swaps++;
	ui.setSwaps(swaps);

	return i + 1;
}