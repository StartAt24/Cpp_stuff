#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Graph{
public:
    Graph(int n){
        _main_list.resize(n);
    };
    ~ Graph(){
        
    };

    int addDegree(int m, int relvent){
        _main_list[m].push_back(relvent);
        _main_list[m].sort();
    }

    void print(){
        for(const auto& i: _main_list){
            cout << "+++ sub list: +++" << endl;
            for(const auto&j: i){
                cout << j << ' ,';
            }
            cout << endl;
        }
    }

private:
    vector<list<int>> _main_list;
};

int main(int argc, char** argv){
    

}