#include<iostream>
#include<vector>

using namespace std;

//0
//1 - 1
//2 - 2 11 2
//3 - 3 111 12 21 
//4 - 5 1111 112 121 211 22
//5 - 8 11111 1112 1121 1211 2111 122 212 221
//6 -   111111 11112 11121 11211 12111 21111 1122 1212 2112 2121 2211 ...

int returnPossibilitiesDynamic(int remaningSteps, vector<int> & dynamic){

    if (remaningSteps==0) return 0;
    if (remaningSteps==1) return 1;
    if (remaningSteps==2) return 2;

    int r1, r2;
    if (dynamic[remaningSteps-1] != 0) r1= dynamic[remaningSteps-1];
    else {
        r1 = returnPossibilitiesDynamic(remaningSteps-1, dynamic);
        dynamic[remaningSteps-1] = r1;
    }

    if (dynamic[remaningSteps-2] != 0) r2= dynamic[remaningSteps-2];
    else {
        r2 = returnPossibilitiesDynamic(remaningSteps-2, dynamic);
        dynamic[remaningSteps-2] = r2;
    }
    return r1 + r2;

    
}

int returnPossibilities(int steps){
    std::vector<int> vec(steps, 0); 

    
    int out = returnPossibilitiesDynamic(steps, vec);
    for (auto i : vec) {
        cout << i << ", ";
        
    }
    cout << endl;
    return out;
}



int main() {
    cout<< returnPossibilities(1) <<endl;
    cout<< returnPossibilities(2) <<endl;
    cout<< returnPossibilities(3) <<endl;
    cout<< returnPossibilities(4) <<endl;
    cout<< returnPossibilities(5) <<endl;
    cout<< returnPossibilities(6) <<endl;



}