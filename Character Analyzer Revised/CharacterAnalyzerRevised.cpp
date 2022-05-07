#include <iostream>
#include <string>
#include <vector>

// Program will take user input of a word, store in a string and then use a for loop to check for any consecutive
// characters, reporting said characters. All uppercase letters will be converted to lowercase to check to ensure
// they are not skipped.

int main()
{
	std::string word_to_analyze;
	
	std::cout << "Please enter a word:";
	std::cin >> word_to_analyze;
	
	for (int i = 0; i < word_to_analyze.size(); ++i)
	{
		const int uppercase_lowercase_gap = 32;
		const int first_lowercase_letter = 97;

		// skip first iteration of loop as there is nothing to compare against.
		if (i == 0)
		{
			continue;
		}

		// convert all uppercase characters to lowercase
		if (word_to_analyze[i] < first_lowercase_letter)
		{
			word_to_analyze[i] += uppercase_lowercase_gap;
		}

		// report if there is a duplicate character
		if (word_to_analyze[i] == word_to_analyze[i - 1])
		{
			std::cout << word_to_analyze << " has a duplicate consecutive character of " << word_to_analyze[i] << ". \n";
		}
	}

}