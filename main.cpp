#include <Python.h>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include "iostream"
#include <vector>

//using namespace std;

struct Test{
        int eins;
        int zwei = 123;
        bool ok;
       };

int main(int argc, char *argv[])
{
    Test x{
        .eins = 2,
        .zwei = 5,
        .ok = true
    };

    Test x2{
        .eins = 2,
        .ok = true
    };


    return 0;
}