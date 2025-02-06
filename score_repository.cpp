#include <map>
#include <string>
#include "file_interactor.h"

std::map<std::string, int> scores;

void print_sore_table() {
    if (scores.size() == 0) {
        scores = get_score_table();
    }
    printf( "\n" );
    printf( "%-30s : %10s\n", "Player Name", "Score" );
    printf( "-------------------------------------------\n" );
    for(std::map<std::string, int>::const_iterator it = scores.begin(); it != scores.end(); ++it) {
        printf( "%-30s : %10d\n", it->first.c_str(), it->second );
    }
    printf( "\n" );
}

void save_score(std::string name, int score) {
    if (scores.size() == 0) {
        scores = get_score_table();
    }
    if (scores.find(name) == scores.end()) {
        scores[name] = score;
    } else if (scores[name] > score){
        scores[name] = score;
    }
    save_score_table(scores);
    print_sore_table();
}
