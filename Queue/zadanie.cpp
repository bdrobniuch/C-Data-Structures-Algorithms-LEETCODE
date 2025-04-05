#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "aabcafadf";
    
    int n = 9;
    int prefixCount = 0, suffixCount = 0;
    
    // Liczymy maksymalny prefix: kolejne znaki od początku takie, jak pierwszy znak
    for (auto a : s) {
        if(a == s[0]) prefixCount++;
        
    }
    
    // Liczymy maksymalny suffix: kolejne znaki od końca takie, jak ostatni znak
    for (auto a : s) {
        if(a == s[n-1]) suffixCount++;
        
    }
    cout << prefixCount << " " <<  suffixCount << endl;
    
    cout << prefixCount * suffixCount << endl;
    return 0;
}