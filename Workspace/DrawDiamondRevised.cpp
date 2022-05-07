#include <iostream>


// function will output certain amount of spaces depending on the height of the 
// triangle and the current line being drawn.

void draw_spaces(int triangle_height, int current_line)
{
	for (int i = 0; i < triangle_height - current_line; ++i)
	{
		std::cout << " ";
	}
}

// funtion will ouput a certain number of X's depending on the current line being drawn

void draw_stars(int current_line)
{
	for (int i = 0; i < current_line; ++i)
		{
			std::cout << "X";
		}
	
}

// when drawing the top of the triangle, function will first draw a right triangle
// with the right angle facing towards the middle of the diamond. It will then output a
// single X no matter which line is being worked on. It will then draw a second right 
// triangle with the right angle facing towards the middle of the triangle (in mirror)
// Number of Xs being drawn will increase each line and the spaces will decrease.

void draw_top(int triangle_height)
{
	for (int i = 0; i < triangle_height; ++i)
	{
		draw_spaces(triangle_height, i);
		std::cout << "X";
		draw_stars(i);
		draw_stars(i);
		draw_spaces(triangle_height, i);

		std::cout << "\n";
	}

}

// Similar to draw_top function but in inverse. If the triangle height is an odd number
// an extra line of Xs/spaces will be drawn at the beginning to accommodate this. Then
//  a right triangle will be drawn with the right angle facing towards the middle of
// the diamond. It will then output a single X no matter which line is being worked on.
// It will then draw a second right triangle with the right angle facing towards the
//  middle of the triangle (in mirror). Number of Xs being drawn will decrease each
// line and the spaces will increase.

void draw_bottom(int triangle_height, bool is_even)
{
	if (is_even == false)
	
	{
		draw_spaces(triangle_height, triangle_height);
		std::cout << "X";
		draw_stars(triangle_height);
		draw_stars(triangle_height);
		draw_spaces(triangle_height, triangle_height);

		std::cout << "\n";
	}

	for (int i = triangle_height; i > 0; --i)
	{
		draw_spaces(triangle_height, i-1);
		std::cout << "X";
		draw_stars(i - 1);
		draw_stars(i - 1);
		draw_spaces(triangle_height, i - 1);

		std::cout << "\n";
	}
}

// funtion asks user for a positive integer. If it receives bad input it will clear
// stream and ask again. The user input will be the total height of the diamond which
// will be composed of two equalateral triangles, therefore the user input gets divided
// in half and stored as the triangle height to be drawn. Function also checks if there
// is a remainder in division, which indicates and odd number and stores that in is_even.
void get_user_input(int &user_input, bool &is_even, int &triangle_height)
{
	std::cout << "Enter a positive integer:";
	std::cin >> user_input;
	while (!std::cin.good() || user_input < 1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter a positive integer:";
		std::cin >> user_input;
		
	}

	triangle_height = user_input / 2;

	if (user_input % 2 != 0)
	{
		is_even = false;
	}
}


// Ask user for diamond height, then draw top of diamond as a triangle pointing upwards
// then drawn a botttom as a triangle pointing downwards, completing diamond shape.
int main()
{
	int user_input;
	int triangle_height;
	bool is_even = true;

	get_user_input(user_input, is_even, triangle_height);
	draw_top(triangle_height);
	draw_bottom(triangle_height, is_even);
}
 