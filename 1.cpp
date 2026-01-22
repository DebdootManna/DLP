#include<iostream>
using namespace std;

int main() {
    cout<<"23CS043 Debdoot Manna "<<endl;
    cout << "Enter string :" << endl;
    string input;
    cin >> input;
    int length = input.length();
    for(int i = length - 1; i > length-3; i--) {
        if(input[i] != 'b'){
            cout<<"Invalid String "<<endl;
            return 0;
        }}
    for(int i=0; i<length-2; i++) {
        if(input[i] != 'a'){
            cout<<"Invalid String"<<endl;
            return 0;
        }
    }
    cout<<"Valid String"<<endl;
    return 0;
}