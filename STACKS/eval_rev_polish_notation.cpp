// problem: 150. Evaluate Reverse Polish Notation
// difficulty: medium 
// topic: array, math, stack
// approach: in this problem, we will use stack, and in array - tokens, we will iterate through each element, one by one, and if that element is a number, we will covert it to integer and push it to the stack,
// and if that element is one of the four operators then we will save and pop out the last two nodes of stack and operate them in order - second element opr first element, and store the result and push it again
// in the stack and repeat these steps until we are done with all elemnts in tokens.
// aty last we will return st.top();
// time: O(n)
// sapce:  O(n)
// link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(string c:tokens)
        {
            if(c=="+"||c=="-"||c=="/"||c=="*")
            {
                int result;
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();
                if(c=="+")  result = a+b;
                 else if(c=="-")  result = a-b;
                 else if(c=="/")  result = a/b;
                 else if(c=="*")  result = a*b;
                st.push(result);
            }
            else
            st.push(stoi(c));
        }
        return st.top();

    }
};

