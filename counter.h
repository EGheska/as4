//
// Created by Dima Taras on 06.04.2023.
//

#ifndef UNTITLED33_COUNTER_H
#define UNTITLED33_COUNTER_H
#include "file_counts.h"

class counter {
public:
    counter(const std::string& file_name, file_counts& fule);
    void process(const options& opts,  file_counts& fule);
    const file_counts& counts() const;
    void byte_count(const options &opts,  file_counts& fileCounts);
private:
    std::string file;
    file_counts& _file;
    bool is_invoked = false;
};


#endif //UNTITLED33_COUNTER_H
