#include "includes/shareable.h"
#define VNAME(x) #x
class intShare: public shareDS{
    int val;
public:
    intShare(int val){this->val=val;}
    string to_str(){
        return to_string(val);
    }
};
class stringShare: public shareDS{
    string val;
public:
    stringShare(string val){this->val=val;}
    string to_str(){
        return val;
    }
};
int main(int argc, char const *argv[]) {
    intShare a(10);
    stringShare b("Hello world");
    Share s(8000);
    s.add<intShare>(a,VNAME(a));
    s.add<stringShare>(b,VNAME(b));
    return 0;
}
