#include <iostream>
#include "vector.h"

int main(){
    vector<std::string> vec(5,"abc");
    vec[15] = "jab";
    vec.push_back("this is pushed back");
    for(int i=0;i<vec.size();i++){
        std::cout << vec[i] << "\n";
    }
    std::cout << "back = " << vec.back()<<"\n";
    vec.pop_back();
    std::cout << "back = " << vec.back()<<"\n";
    vector<int>vec2;
    vec2.push_back(5);
    std::cout << "this is push back = "<<vec2[0]<<"\n";
    vector<int> t= {1,2,3};
    int n = t.size();
    for(int i =0;i<n;i++){
        std::cout << t[i]<<"\n";
    }
    for(auto it = t.begin(); it < t.end();it++){
        std::cout << *it << std::endl;
    }
}