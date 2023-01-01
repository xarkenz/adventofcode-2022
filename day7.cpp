//
// Created by xarkenz on 12/07/22.
//

#include "adventofcode.h"

struct D7File {
    std::string name;
    int size;
    bool isDir;
    D7File* parent;
    std::vector<D7File*> files;
};

int d7SizeSum(D7File* dir) {
    int sizeSum = 0;
    for (D7File* file : dir->files) {
        if (file->isDir) {
            sizeSum += (file->size <= 100000 ? file->size : 0) + d7SizeSum(file);
        }
    }
    return sizeSum;
}

int d7SmallestSpace(D7File* dir, int space) {
    int smallest = dir->size;
    for (D7File* file : dir->files) {
        if (file->isDir && file->size >= space) {
            int wouldFree = d7SmallestSpace(file, space);
            if (wouldFree < smallest) {
                smallest = wouldFree;
            }
        }
    }
    return smallest;
}

void day7() {
    std::ifstream input("day7.txt");
    if (!input.is_open()) {
        std::cerr << "Unable to open file\n";
        return;
    }
    D7File root{"/", 0, true, nullptr};
    D7File* location = &root;
    std::string arg;
    std::getline(input, arg, ' ');
    while (input.good()) {
        std::getline(input, arg);
        if (arg == "ls") {
            while (input.good()) {
                std::getline(input, arg, ' ');
                if (!input.good() || arg == "$") {
                    break;
                } else if (arg == "dir") {
                    std::getline(input, arg);
                    bool exists = false;
                    for (D7File* file : location->files) {
                        if (file->name == arg) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        location->files.push_back(new D7File{arg, 0, true, location});
                    }
                } else {
                    int size = std::stoi(arg);
                    std::getline(input, arg);
                    bool exists = false;
                    for (D7File* file : location->files) {
                        if (file->name == arg) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        location->files.push_back(new D7File{arg, size, false, nullptr});
                        D7File* dir = location;
                        while (dir) {
                            dir->size += size;
                            dir = dir->parent;
                        }
                    }
                }
            }
        } else {
            arg = arg.substr(3);
            if (arg == "/") {
                location = &root;
            } else if (arg == "..") {
                if (location->parent) {
                    location = location->parent;
                }
            } else {
                for (D7File* file : location->files) {
                    if (file->name == arg && file->isDir) {
                        location = file;
                        break;
                    }
                }
            }
            if (input.good()) {
                std::getline(input, arg, ' ');
            }
        }
    }
    input.close();
    std::cout << "Sum of sizes <= 100000: " << d7SizeSum(&root) << std::endl;
    std::cout << "Smallest directory free: " << d7SmallestSpace(&root, root.size - 40000000) << std::endl;
}