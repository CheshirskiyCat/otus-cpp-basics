#include <map>
#include <iostream>
#include <cstring>
#include "file_interactor.h"

const std::string FILE_NAME = "map.data";


void save_score_table(std::map<std::string, int> score_table){
    FILE *fp = fopen(FILE_NAME.c_str(), "w+b");
    if (fp == nullptr) {
      std::cout << "Faled to create data file" << std::endl;
    } else {
        for (std::map<std::string, int>::const_iterator iter = score_table.begin(); iter!=score_table.end(); ++iter) {
            fprintf(fp, "%s|%d\n", iter->first.c_str(), iter->second );
        }
        fclose(fp);
    }
}

std::map<std::string, int> get_score_table(){
    std::map<std::string, int> scores = {};
    char line[256];
    std::string string;

    if (FILE *file = fopen(FILE_NAME.c_str(), "r")) {
        while (fgets(line, sizeof(line), file)) {
            string = std::string(line);
            int delimeter_index = string.find("|");
            std::string name = string.substr(0, delimeter_index);
            std::string score = string.substr(delimeter_index + 1, string.length());
            scores[name] = std::stoi(score);
        }
        fclose(file);
    } else {
        std::cout << "file is not exist" << std::endl;
    }  
    return scores;
}
