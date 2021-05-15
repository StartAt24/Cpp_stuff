#include <iostream>
#include <string>
using namespace std;

class Backup{
public:
    Backup(){};
};

class Note{
public:
    Backup createBackup(){
        return Backup();
    }

    void restore(Backup b){

    }
};

int main(){


    return 0;
}