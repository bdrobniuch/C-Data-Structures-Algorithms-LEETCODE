#include<iostream>
//#include<exeption>

using namespace std;

class custom_exeption : public exception {
     const char* what() const noexcept  override {
        return "Custom Exeption";
    }
};

int main() {
    try
    {
        throw custom_exeption();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
