// Prefix to Infix
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
bool isOp(char c){ return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

string preToInfix(const string& s){
stack<string> st;
for(int i=(int)s.size()-1;i>=0;--i){
    char c=s[i];
    if(c==' ') continue;
    if(isOp(c)){
        string op1=st.top(); st.pop();
        string op2=st.top(); st.pop();
        string expr = "(" + op1 + " " + c + " " + op2 + ")";
        st.push(expr);
    } else {
    st.push(string(1,c));}}
return st.top(); }


int main(){
    string s = "- + * A B / C D ^ E F";
    cout << preToInfix(s) << "\n";
    return 0;
}