#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Graph{
public:
    // init  graph with a fixed size;
    Graph(int n){
        _main_list.resize(n);
        _is_visted.resize(n);
        _who_visted_me.resize(n);
        init();
    };
    ~ Graph(){
    };

    int addDegree(int m, int relvent){
        // 无向图，需要在两者都添加关系。
        _main_list[m].push_back(relvent);
        _main_list[m].sort();
        _main_list[relvent].push_back(m);
        _main_list[relvent].sort();
    }

    // from s -> t
    int breadthFirstSearch(int s, int t){
        if(s == t)
            return 0;
        init();

        // 需要浏览的节点
        _to_visit.push_back(s);

        while(_to_visit.size()>0){
            // 依次访问_to_visit里的 节点
            int node = _to_visit.front();
            _to_visit.pop_front();
            _is_visted[node] = true;

            if(node == t){
                // print search path
                print(s, t);
                return 1;
            }

            for(const auto i: _main_list[node]) {

                if(!_is_visted[i]){
                    _to_visit.push_back(i);
                    _who_visted_me[i] = node;
                }
            }
        }
        return -1;
    }

    int deepFirstSearch(int s, int t){
        if(s == t)
            return 0;
        init(); 

        dfsRecursive(s,t);
        print(s,t);
    }

    void dfsRecursive(int s, int t){
        if(_is_found)
            return;
        
        _is_visted[s] = true;
        if(s==t)
        {
            _is_found= true;
            return;
        }
        for(auto m: _main_list[s]){
            if(!_is_visted[m]){
                _who_visted_me[m] = s;
                dfsRecursive(m, t);
            }
        }
    }

    // print path s->t
    void print(int s, int t){
        if(_who_visted_me[t] != -1 && s != t) 
        {
            print(s, _who_visted_me[t]);
        }
        cout << t << " ";
    }

    void init(){
        std::fill(_is_visted.begin(), _is_visted.end(), 0);
        std::fill(_who_visted_me.begin(), _who_visted_me.end(), -1);
        _to_visit.clear();
        _is_found = false;
    }
private:
    vector<list<int>> _main_list;
    
    // 将要访问的客人
    list<int> _to_visit;
    // 是否访问过
    vector<bool> _is_visted;
    // 通过谁访问到了我
    vector<int> _who_visted_me;

    // 深度搜索是否已经找到
    bool _is_found;
};

int main(int argc, char** argv){
    Graph g(8);
    g.addDegree(0, 1);
    g.addDegree(0, 3);
    g.addDegree(1,2);
    g.addDegree(1, 4);
    g.addDegree(3, 4);
    g.addDegree(2, 5);
    g.addDegree(4, 5);
    g.addDegree(4, 6);
    g.addDegree(6, 7);
    g.addDegree(5, 7);
    // g.breadthFirstSearch(0, 6);
    g.deepFirstSearch(0,6);
    return 0;
    
}