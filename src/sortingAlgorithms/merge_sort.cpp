





#include <iostream>
#include <ctime>
#include "ui.h"
#include "visualizer.h"
#include <SFML/Graphics.hpp>
#include <vector>


void Visualizer::mergeSort() {

	//scramble the rectangles
	scramble();

	ui.setAlgorithm("Merge Sort");

	ui.setBigO("O(n log(n))", "O(n)");

	//keep track of comparisons and swaps
	unsigned long  comparisons = 0;
	unsigned long  swaps = 0;


	//reset swap and comparisons count on the display
	ui.setComparisons(comparisons);
	ui.setSwaps(swaps);

	std::clock_t time = std::clock();

	ui.setTime(time);

	render();

	//to track if the user exites the program or presses escape to exit the algorithm
	bool exit = false;

	mergeSort(0, rectangles.size() - 1, swaps, comparisons, time, exit);
	
	std::cout << "Merge Sort ended" << std::endl;

	render();
}



void Visualizer::mergeSort(size_t left_index, size_t right_index, unsigned long& swaps, unsigned long& comparisons, std::clock_t& time, bool& exit) {

	if (left_index >= right_index || exit == true) return;

	size_t middle_index = (left_index + right_index) / 2;

	mergeSort(left_index, middle_index, swaps, comparisons, time, exit);
	mergeSort(middle_index + 1, right_index, swaps, comparisons, time, exit);
	merge(left_index, middle_index, right_index, swaps, comparisons, time, exit);

}



void Visualizer::merge(size_t left_index, size_t middle_index, size_t right_index, unsigned long& swaps, unsigned long& comparisons, std::clock_t& time, bool& exit) {

	//if user exits
	if (exit == true) return;

	size_t i = left_index;
	size_t j = middle_index + 1;
	size_t k = left_index;

	//temp array
	std::vector<sf::Vector2f> temp;
	temp.resize(right_index + 1);

	while (i <= middle_index && j <= right_index) {

		swaps++;
		comparisons++;
		ui.setComparisons(comparisons);
		ui.setSwaps(swaps);
		ui.setTime(time);

		highlight(rectangles[i], rectangles[j]);

		render();

		unHighlight(rectangles[i], rectangles[j]);


		if (rectangles[i].getSize().y < rectangles[j].getSize().y) {
			
			temp[k] = rectangles[i].getSize();
			k++;
			i++;
		}
		else {
			temp[k] = rectangles[j].getSize();
			k++;
			j++;
		}

		sf::Event event;

		//check events
		while (ui.event(event)) {

			//close the window and set exit to true
			if (event.type == sf::Event::Closed) {

				exit = true;
				ui.close();
			}
			//set exit to true
			else if (event.key.code == sf::Keyboard::Escape) {

				exit = true;
				std::cout << "Merge sort exited" << std::endl;
			}
		}
	}


	while (i <= middle_index) {
		
		swaps++;
		ui.setSwaps(swaps);
		ui.setTime(time);

		temp[k] = rectangles[i].getSize();
		k++;
		i++;
	}
	while (j <= right_index) {

		swaps++;
		ui.setSwaps(swaps);
		ui.setTime(time);

		temp[k] = rectangles[j].getSize();
		k++;
		j++;
	}

	for (i = left_index; i < k; i++) {

		rectangles[i].setSize(temp[i]);
		swaps++;
		ui.setSwaps(swaps);
		ui.setTime(time);

		sf::Event event;


		//chek for events
		while (ui.event(event)) {

			if (event.type == sf::Event::Closed) {

				exit = true;
				ui.close();
			}
			else if (event.key.code == sf::Keyboard::Escape) {

				exit = true;
				std::cout << "Merge sort exited" << std::endl;
			}
		}

		//stop if the user exits
		if (exit == true) return;

		render();

	}

}