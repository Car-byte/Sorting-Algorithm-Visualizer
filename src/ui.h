



#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class UI {
public:

	/*default constructor for the UI class
	calls the font and icon functions
	sets the color of all the text
	sets the size of the text elements
	sets the position of the text element
	sets the default text*/
	UI();

	void setAlgorithm(std::string);//sets the algorithm text element

	void setComparisons(unsigned long&);//sets the comparisons text element

	void setSwaps(unsigned long&);//sets the swaps text element
	
	void setIcon();//sets the icon

	void setFont();//setst the font of all the text

	bool isOpen();//checks if the display window is currently open

	void close();//closes the display window

	bool event(sf::Event&); //polls the event to get the event that has occured

	void renderText();//renders all the text elements

	void renderRectangles(std::vector<sf::RectangleShape>&); //renders the array of rectangles

	void clear();//clears everything that has been rendered

	void display();//displays everthing that has been rendered

	void setTime(std::clock_t&); //sets the time for display

	void setBigO(std::string time, std::string space); //sets the bigO notation for display

private:

	sf::Font font; //font must be in memory the whole time

	sf::Image icon; //the icon must be in memory the whole time

	sf::RenderWindow window; //the display window


	//text elements
	sf::Text comparisons; 
	sf::Text algorithm_selected;
	sf::Text swaps;
	sf::Text time;
	sf::Text bigO;
};





#endif // !UI_H