//
// Created by Dima Taras on 06.04.2023.
//

#ifndef UNTITLED33_OPTIONS_H
#define UNTITLED33_OPTIONS_H


#include <iostream>
#include <vector>
#include <string>

class options {
public:
    /* Constructors */
    options(int argc, char * argv[]);
    options();  // default constructor

    /* Accessors */
    bool lines() const;
    bool words() const;
    bool characters() const;
    bool bytes() const;
    bool longest_line() const;

    bool help() const;
    bool version() const;

    const std::vector<std::string> file_names() const;

    /* Modifiers */
    void parse(int argc, char * argv[]);

    /* Debug/ helper functions */
    bool verbose() const;
    void print(std::ostream& out) const;

    void parse_options(const std::string& option);

private:
    /* TODO: you fill this part */
    int argc;
    bool _lines;
    bool _words;
    bool _char;
    bool _byte;
    bool _longline;
    bool _help{false};
    bool _version;
    bool _verbose;
    std::vector<std::string> _file_names;
    char * argv[];
};



#endif //UNTITLED33_OPTIONS_H
