#ifndef LABS_MAINS_H
#define LABS_MAINS_H


#include <iostream>
#include <iostream>
#include <ctime>
#include "lab.h"
#include "readAndParse.h"
#include "FilesStorage.h"

class Mains {
private:
    uint8_t lab;
    static int lab1(int argc, char* argv[]);
    static int lab2(int argc, char* argv[]);
    static int lab3(int argc, char* argv[]);
    static int lab4(int argc, char* argv[]);
    static int lab5(int argc, char* argv[]);
    static int lab6(int argc, char* argv[]);
    static int lab7(int argc, char* argv[]);
    static int lab8(int argc, char* argv[]);
    static int lab9(int argc, char* argv[]);
    static int lab10(int argc, char* argv[]);
public:
    explicit Mains(uint8_t labNumber);
    Mains(const Mains& other) = delete;

    Mains(Mains&& other) = delete;
    Mains& operator =(const Mains& other) = delete;

    Mains& operator =(Mains&& other) = delete;

    ~Mains() = default;

    int execute(int argc, char **argv) const;
};


#endif //LABS_MAINS_H
