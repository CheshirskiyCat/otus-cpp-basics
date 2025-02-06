#include <iostream>
#include <ctime>
#include "score_repository.h"

const int THIRD_LEVEL_TOP_BORDER = 100;

const int SECOND_LEVEL_TOP_BORDER = 50;

const int FIRST_LEVEL_TOP_BORDER = 10;

int top_border = THIRD_LEVEL_TOP_BORDER;

std::string player_name;

void game(int number) {
	std::string input;
	std::string result;
	int step;
	int attempts = 0;

	std::cout << "New Game!!" << std::endl;
	std::cout << "Enter your guess: ";
	for(;;attempts++){
		std::cin >> input;
		step = std::stoi( input );

		if ( step == number ) { 
			std::cout << "you win! attempts = " << attempts << std::endl;
			save_score(player_name, attempts);
			break;
		} else if ( step < number ){
			result = "greater than ";
		} else if ( step > number ){
			result = "less than ";
		}

		std::cout << result << step << std::endl;
	}
}

int main(int argc, const char * argv[]) {

	bool isMaxArg = false;
	bool isLevelArg = false;
	std::string arg;

	int i = 1;
    while ( i < argc ) {
		arg = argv[i];
		std::cout << "arg" << argv[i] << std::endl;
		if (arg == "-max"){
			std::cout << "max" << std::endl;
			isMaxArg = true;
			top_border = std::stoi(argv[i+1]);
			i++;
		} else if (arg == "-list") {
			print_sore_table();
		} else if (arg == "-level") {
			isLevelArg = true;
			int level = std::stoi(argv[i+1]);
			switch (level){
				case 1:
					top_border = FIRST_LEVEL_TOP_BORDER;
					break;

				case 2:
					top_border = SECOND_LEVEL_TOP_BORDER;
					break;
				
				case 3:
				default:
					top_border = THIRD_LEVEL_TOP_BORDER;
					break;
			}
			i++;
		}
		i++;
    }

	if (isMaxArg && isLevelArg) {
		std::cout << "Args -max and -level can't be used together" << std::endl;
		return 1;
	}

	std::string input;
	std::srand(std::time(nullptr));
	std::cout << "Guess Number Game" << std::endl;
	std::cout << "Enter your name, pleas: ";
	std::cin >> player_name;
	for(;;){
		std::cout << "type [exit] to exit or any word to start new game: ";
		std::cin >> input;
		if (input == "exit") {
			break;
		} else {
			game(rand() % top_border);
		}
	}
	return 0;
}
