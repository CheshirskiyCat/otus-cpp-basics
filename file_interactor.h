#pragma once
#include <map>

void save_score_table(std::map<std::string, int> score_table);

std::map<std::string, int> get_score_table();