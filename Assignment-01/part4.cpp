// Postfix to Prefix
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOp(char c){ return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

string postToPre(const string& s){
stack<string> st;
for(char c: s){
    if(c==' ') continue;
    if(!isOp(c)) st.push(string(1,c));
    else {
        string b=st.top(); st.pop();
        string a=st.top(); st.pop();
        st.push(string(1,c) + string(" ") + a + string(" ") + b);
        }}
    return st.top(); }


int main(){
    string s = "A B C * D + E F G * + ^ H I / -";
    cout << postToPre(s) << "\n"; // - ^ A + + * B C D + E * F G / H I
    return 0; }