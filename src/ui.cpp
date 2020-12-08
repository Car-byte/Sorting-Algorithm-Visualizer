



#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "ui.h"


UI::UI(){

	window.create(sf::VideoMode(800, 600), "Sorting Visualizer"); //create display window
	
	window.setFramerateLimit(60); //limit frame limit so that the visualization is not too fast

	setIcon(); //set icon

	//sets default strings
	swaps.setString("Swaps: 0");
	algorithm_selected.setString("None");
	comparisons.setString("Comparisons: 0");
	time.setString("Timer: 0");
	bigO.setString("Time: O() Space: ()");

	//set the fill color
	swaps.setFillColor(sf::Color::Red);
	algorithm_selected.setFillColor(sf::Color::Red);
	comparisons.setFillColor(sf::Color::Red);
	time.setFillColor(sf::Color::Red);
	bigO.setFillColor(sf::Color::Red);

	//sets the character size
	swaps.setCharacterSize(15);
	algorithm_selected.setCharacterSize(15);
	comparisons.setCharacterSize(15);
	time.setCharacterSize(15);
	bigO.setCharacterSize(15);

	//sets the position
	algorithm_selected.setPosition(250, 10);
	swaps.setPosition(10, 10);
	comparisons.setPosition(100, 10);
	time.setPosition(220, 40);
	bigO.setPosition(10, 40);

	setFont(); //set font
}


//renders all the text elements
void UI::renderText() {

	window.draw(comparisons);
	window.draw(algorithm_selected);
	window.draw(swaps);
	window.draw(time);
	window.draw(bigO);
}


//sets the current algorithm string
void UI::setAlgorithm(std::string s) {

	this->algorithm_selected.setString("Algorithm: " + s);
}


//sets the comparisons string
void UI::setComparisons(unsigned long &comp) {

	this->comparisons.setString("Comparisons: " + std::to_string(comp));
}


//sets the current swaps string
void UI::setSwaps(unsigned long &swaps) {

	this->swaps.setString("Swaps: " + std::to_string(swaps));
}


//sets the bigO notation string
void UI::setBigO(std::string time, std::string space) {

	this->bigO.setString("Time: " + time + " Space: " + space);
}



//loads the icon and sets it for the window
void UI::setIcon() {

	if (!icon.loadFromFile("icon.png")) {
		std::cout << "FAILED TO LOAD ICON" << std::endl;
		return;
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}


//loads the font and sets all the text elements to that font
void UI::setFont() {

	if (!font.loadFromFile("roboto.ttf")) {
		std::cout << "FAILED TO LOAD FONT" << std::endl;
		return;
	}

	comparisons.setFont(font);
	swaps.setFont(font);
	algorithm_selected.setFont(font);
	time.setFont(font);
	bigO.setFont(font);
}


//checks if the window is open
bool UI::isOpen() {

	if (window.isOpen()) return true;

	return false;
}


//closes the window
void UI::close() {
	window.close();
}


//polls the current event if any
bool UI::event(sf::Event &e) {
	return window.pollEvent(e);
}


//renders all the rectangles
void UI::renderRectangles(std::vector<sf::RectangleShape> &rectangles) {
	
	for (int i = 0; i < rectangles.size(); i++) {
		window.draw(rectangles[i]);
	}
}


//clears every element that has been rendered
void UI::clear() {
	window.clear();
}


//displays the current renders
void UI::display() {
	window.display();
}


//sets the current time of the algorith,
void UI::setTime(std::clock_t& time) {

	this->time.setString("Time: " + std::to_string(float(std::clock() - time) / CLOCKS_PER_SEC) + " Sec");
}

