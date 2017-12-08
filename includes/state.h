#include <string>
#include <map>
template <typename T1,typename T2>
class state{
	map<string,T2> mp;
public:
	void add(T1&,T2&);
	T2 seek(T1);
};
template <typename T1, typename T2>
void state<T1,T2>::add(T1 &t1,T2 &t2){
	mp.insert(make_pair(t1.to_str(),t2));
}
template <typename T1, typename T2>
T2 state<T1,T2>::seek(T1 t1){
	typename::map<string,T2>::iterator it;
	it=mp.find(t1.to_str());
	if(it!=mp.end()){
		return it->second;
	}else{
		return NULL;
	}
}
