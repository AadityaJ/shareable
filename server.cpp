#include "includes/mServer.h"
#include "includes/state.h"
#include "includes/shareable.h"
class stringShare: public shareDS{
    string val;
public:
    stringShare(string val){this->val=val;}
    string to_str(){
        return val;
    }
};
pair<string,string> split(string a){
	string temp1="",temp2="";
	int i=0;
	for(;a[i]!=',';i++){temp1.push_back(a[i]);}
	i++;
	for(;i!=a.length();i++){temp2.push_back(a[i]);}
	return make_pair(temp1,temp2);
}
int main(int argc, char const *argv[]) {
    Server s;
    s.listen_(8000);
    state<stringShare ,string> st;
    while(1){
        string recv=s.receive();
        //cout<<recv<<endl;
        pair<string,string>prv=split(recv);
        freqVar[prv.first]++;
        stringShare obj(prv.first);
        cout<<"ADDED: "<<obj.to_str()<<" "<<prv.second<<endl;
        cout<<"FREQ OF: "<<obj.to_str()<<" "<<freqVar[prv.first]<<endl;
        st.add(obj,prv.second);
        cout<<st.seek(obj)<<endl;
    }
    return 0;
}
