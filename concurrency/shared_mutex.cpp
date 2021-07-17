#include <memory>
#include <shared_mutex>
#include <map>
#include <string>
using namespace std;

class dns_entry{
    public:
    dns_entry(){}
};

class dns_cache{
    std::map<string, dns_entry> entries;
    mutable std::shared_mutex entry_mutex;
public:
    dns_entry find_entry(string const& domain) const{
        shared_lock<shared_mutex> _(entry_mutex);
        auto target = entries.find(domain);
        return (target==entries.end())? dns_entry():target->second;
    }
    void update_or_add_entry(const string& domain, const dns_entry& dns_details){
        // 注意写的时候和读取的时候调用的函数方法其实不同
        lock_guard<shared_mutex> _(entry_mutex);
        entries[domain] = dns_details;
    }
};
