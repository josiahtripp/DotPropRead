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
        int findValueEntries(int index);
        std::string find(int keyIndex, int index);//Used for multiple values

    public:
        bool loadFile(std::string file);//Loads a file into dynamic memory
        std::string find(std::string key);//Returns the value associated with a key (dynamic array)
        int findValueEntries(std::string key);
        std::string find(std::string key, int index);//Used for multiple values
};

int main(){
    
    DotPropRead settings;

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
        return true;
    }
}

int DotPropRead::keyIndex(string key){

    /*Searches through the array of Keys.
    Returns the index of the key, -1 if not found*/
    for (int i = 0; i < keysRead; i++){

        if(key == keys[i]){

            return i;
        }
    }
    return -1;
}

string DotPropRead::find(string key){

    //Finds initial index of key
    int index;
    index = keyIndex(key);

    //keyIndex() returned -1, meaning no key was located
    if(index == -1){

        return "404";
    }

    //Finds the number of values associated with key
    int valueEntries;
    valueEntries = findValueEntries(index);

    //No value exists for the given key
    if(valueEntries < 1){

        return "173";
    }
    //There is more than one value associated with the key (returns first value by default).
    if(valueEntries > 1){

        return find(index, 1);
    }
    //There is only one value associated with the key. (returns sole value)
    else{

        return values[index];
    }
}