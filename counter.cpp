//
// Created by Dima Taras on 06.04.2023.
//

#include <fstream>
#include <iostream>
#include "counter.h"
#include <exception>


counter::counter(const std::string &file_name, file_counts& fule) : _file{fule}, file{file_name} {

}

void counter::process(const options &opts,  file_counts& fileCounts) {
    std::ifstream iFile("anna_karenina.txt");
    std::string buffer,line;
    int char_counter{0};
    while (std::getline(iFile,buffer)){
        line = buffer;
        fileCounts.lines ++;
        fileCounts.characters = fileCounts.characters + line.size();
        if (char_counter < line.size()){
            fileCounts.maximum_line_length = line.size();
        }
        for (char i : line) {
            if(i == ' '){
                fileCounts.words++;
            }}
        byte_count(opts, fileCounts);
        line.clear();
    }
    is_invoked = true;
}

const file_counts &counter::counts() const {
       if (is_invoked){
           throw std::logic_error("File already has been processed");
       }
}
void counter::byte_count(const options &opts,  file_counts& fileCounts){
    std::ifstream iFile("anna_karenina.txt", std::ios::binary);
    std::string buffer,line;
    while (std::getline(iFile,buffer)){
        iFile.seekg(0, std::ios::end);
        fileCounts.bytes = iFile.tellg();
    }
}










