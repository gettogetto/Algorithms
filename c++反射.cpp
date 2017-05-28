#include<bits/stdc++.h>
using namespace std;

using Functype=function<void*()>;
class Factory{
public:
    ~Factory(){}
    static Factory& getinstance(){
        static Factory res;
        return res;
    }
    void reg(string classname,Functype func){

        m[classname]=func;

    }
    void* getClassbyname(string classname){
        auto it=m.find(classname);
        if(it==m.end()){
            return NULL;
        }else{
            Functype func=it->second;//调用回调函数
            func();
        }
    }
private:
    Factory(){}
    map<string,Functype> m;
};
class Register{
public:
    Register(string classname,Functype func){
        Factory::getinstance().reg(classname,func);
    }

};

#define REGISTER(classname)\
classname* create##classname(){\
    return new classname();\
}\
Register g_register##classname(#classname,(Functype)create##classname)


class A{
public:
    A(){
        cout<<"A()"<<endl;
    }
};
class B{
public:
    B(){
        cout<<"B()"<<endl;
    }
};
REGISTER(A);
REGISTER(B);
int main(){
    A* a=(A*)Factory::getinstance().getClassbyname("A");
    B* b=(B*)Factory::getinstance().getClassbyname("B");
}
