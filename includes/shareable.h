#include <string>
#include "mClient.h"
#define VNAME(x) #x
class shareDS{
public:
    virtual string to_str()=0;
};
class Share{
    int hostAddr;
public:
    Share(int hostAddr){
        this->hostAddr=hostAddr;
    }
    template <typename T1>
    void add(shareDS &var,string var_name){
        Client c(this->hostAddr);

        c.Send(var_name+","+var.to_str());
    }
};
