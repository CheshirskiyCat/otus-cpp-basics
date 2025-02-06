cmake_minimum_required(VERSION 3.12)

project(guess_the_number)

add_executable(guess_the_number
    guess_the_number.cpp
    file_interactor.h
    file_interactor.cpp
    score_repository.h
    score_repository.cpp
)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
