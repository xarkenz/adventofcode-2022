//
// Created by xarkenz on 12/01/22.
//

#include "adventofcode.h"

void day1() {
    std::ifstream input("day1.txt");
    if (!input.is_open()) {
        std::cerr << "Unable to open file\n";
        return;
    }
    std::string line;
    long int currentElfCalories = 0, elf1Calories = 0, elf2Calories = 0, elf3Calories = 0;
    while (input.good()) {
        std::getline(input, line);
        if (line.empty()) {
            if (currentElfCalories > elf1Calories) {
                elf3Calories = elf2Calories;
                elf2Calories = elf1Calories;
                elf1Calories = currentElfCalories;
            } else if (currentElfCalories > elf2Calories) {
                elf3Calories = elf2Calories;
                elf2Calories = currentElfCalories;
            } else if (currentElfCalories > elf3Calories) {
                elf3Calories = currentElfCalories;
            }
            currentElfCalories = 0;
        } else {
            currentElfCalories += std::strtol(line.c_str(), nullptr, 10);
        }
    }
    input.close();
    std::cout << "Max: " << elf1Calories << std::endl;
    std::cout << "Top 3: " << (elf1Calories + elf2Calories + elf3Calories) << std::endl;
}