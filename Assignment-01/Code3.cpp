// Postfix to Infix
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOp(char c){ return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

string postToInfix(const string& s){
    stack<string> st;
    for(char c: s){
        if(c==' ') continue;
        if(!isOp(c)) st.push(string(1,c));
    else {
        string op2=st.top(); st.pop();
        string op1=st.top(); st.pop();
        st.push("("+op1+" "+c+" "+op2+")");}}
    return st.top(); }

int main(){
string s = "A B C * D + E F G * + ^ H I / -";
cout << postToInfix(s) << "\n";
return 0;
}