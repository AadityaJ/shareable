#include "includes/shareable.h"
class intShare: public shareDS{
public:
    int val;
    intShare(int val){this->val=val;}
    string to_str(){
        return to_string(val);
    }
};
class stringShare: public shareDS{
public:
    string val;
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
    a.val++;
    s.add<intShare>(a,VNAME(a));
    a.val++;
    s.add<intShare>(a,VNAME(a));
    b.val="hello";
    s.add<stringShare>(b,VNAME(b));
    return 0;
}
