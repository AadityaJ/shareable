#include "includes/mClient.h"
#define VNAME(x) #x
/*class share{
    string str;
public:
    share(string str){this->str=str;}
    string to_str(){
        return str;
    }
};*/
int main(int argc, char const *argv[]) {
    Client c(8000);
    int a=5;
    double b=15.00;
    string snd(VNAME(a));
    snd+=(","+to_string(a));
    c.Send(snd);
    string snd2(VNAME(b));
    snd2+=(","+to_string(b));
    Client c2(8000);
    c2.Send(snd2);
    Client c3(8000);
    c3.Send(snd2);
    return 0;
}
