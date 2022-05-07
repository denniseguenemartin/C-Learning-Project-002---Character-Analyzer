// Program analyzes a word and reports if there are duplicate consecutive letters and reports
#include <iostream>
#include <string>
using namespace std;


int main() {

	string word_holder;

	cout << "Please enter a word: \n";
	cin >> word_holder;

	for (int i = 0; i < word_holder.size(); ++i) {
		if (word_holder[i] > 96) {
			word_holder[i] -= 32;
		}
		
		if (i == 0) {
			continue;
		}
			else if (word_holder[i] == word_holder[i - 1]){
			cout << word_holder << " has a duplicate consecutive character of " << word_holder[i] << ".\n";
			}
			
		
			
	}
}