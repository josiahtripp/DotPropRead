#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_KEYS = 32;

class DotPropRead{

    private:
        std::string filename;//File associated with file-fetching
        std::string * keys;//Used for dynamic array for holding keys
        std::string * values;//Used for dynamic array for holding values
        int keysRead;//The number of keys within the allocated array
        bool allocate(int keyNumber);//Allocates dynamic arrays
        int tabulate(std::string file);//Tabulates a file to determine size needed for allocation
        int keyIndex(std::string key);//Returns the index of a specific key within the dynamic array (returns -1 if not found);

    public:
        bool loadFile(std::string file);//Loads a file into dynamic memory
        bool setFile(std::string file);//Sets a specific filename for file-fetching
        std::string find(std::string key);//Returns the value associated with a key (dynamic array)
        std::string fetch(std::string key);//Returns the value associated with a key (file-fetching)
        int findValueEntries(std::string key);
        int fetchValueEntries(std::string key);//Finds the number of values within a 
        std::string find(std::string key, int index);//Used for multiple values
        std::string fetch(std::string key, int index);//Used for multiple values
};

int main(){


    return 0;
}

bool DotPropRead::allocate(int keyNumber){

    /*Returns false if the number of key-spaces to allocated is greater
    than the preset maximum, or is negative*/
    if(keyNumber > MAX_KEYS || keyNumber < 0){

        return false;
    }

    //keyNumber is within the valid allocation range
    else{

        //Relinquishes any previously allocated memory
        delete[] keys;
        delete[] values;

        //Allocates new memory
        keys = new string[keyNumber];
        values = new string[keyNumber];
    }
}