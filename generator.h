#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

enum enumGenType // Try to correspond with area.h
{
    GEN_SKY = 0,
    GEN_EMPTY = 1,
    GEN_WALL = 2,
    GEN_DOOR = 3,
    GEN_VARIABLE = 4,
    GEN_BARS = 5
};

class Generator
{
    std::vector<int>prefabs7x7;
    std::vector<int>prefabs9x9;
    std::vector<int>prefabs11x11;

    std::vector<int>generation;

public:
    Generator();
    ~Generator();

    void LoadPrefabs(std::string filename, std::vector<int> &v);

    int TranslateFileChar(char c);

    void GenerateFloor(int genW, int genH, std::vector<int>&result);

};


#endif // GENERATOR_H_INCLUDED
