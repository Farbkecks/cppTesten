#include <Python.h>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include "iostream"
#include <vector>

//using namespace std;


std::string
file_contents(const std::filesystem::path& path)
{
    // Sanity check
    if (!std::filesystem::is_regular_file(path))
        return { };

    // Open the file
    // Note that we have to use binary mode as we want to return a string
    // representing matching the bytes of the file on the file system.
    std::ifstream file(path, std::ios::in | std::ios::binary);
    if (!file.is_open())
        return { };

    // Read contents
    std::string content{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    // Close the file
    file.close();

    return content;
}

void print_container(const std::vector<int>& c)
{
    for (int i : c)
        std::cout << i << " ";
    std::cout << '\n';
}

int
main(int argc, char *argv[])
{

    std::vector<int> x = {1,2};
    print_container(x);

    x.insert(x.begin()+x.size(), 3);
    x.insert(x.begin()+x.size(), 3);
    x.insert(x.begin()+x.size(), 3);

    print_container(x);

    return 0;
    auto generatePairs = [](int const MAX = 8){
        int row = 0;
        int colume = 0;
        std::vector<std::pair<int,int>> resulte;
        resulte.resize(MAX);
        for(auto & i: resulte){
            if((int) MAX / 2 == colume){
                row++;
                colume = 0;
            }
            i = std::pair<int,int>(row,colume++);
        }
        return resulte;
    };


    for(auto [x,y] : generatePairs()){
        std::cout << x << "   " << y << std::endl;
    }



    return 0;
}