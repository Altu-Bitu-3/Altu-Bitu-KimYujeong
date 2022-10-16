#include <iostream>
#include <string>

using namespace std;

bool isCpp(string input) { // cpp 변수명인가
    if(input[0] == '_' || input[input.length()-1] == '_') return false; // 언더바가 맨 앞이나 맨 뒤에 오는 경우
    if(input.find("__") != string::npos) return false; // 언더바가 2개 연속으로 나온 경우

    for(int i = 0; i < input.length(); i++) {
        // 언더바나 소문자가 아닌 경우 cpp 변수명 아님
        if(input[i] != '_' && (input[i] < 'a' || input[i] > 'z'))
            return false;
    }
    return true;
}

bool isJava(string input) { // java 변수명인가
    if(input[0] < 'a' || input[0] > 'z') return false; // 첫문자가 소문자가 아닌 경우
    for(int i = 1; i < input.size(); i++) {
        if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) continue;
        return false; // 대소문자가 아닌 경우 java 변수명 아님
    }
    return true;
}

string cppToJava(string cpp) { // cpp 변수명 -> java 변수명
    string java = "";
    for(int i = 0; i < cpp.size(); i++) {
        if(cpp[i] == '_') {
            java += toupper(cpp[++i]);
        }
        else java += cpp[i];
    }
    return java;
}

string javaToCpp(string java) { // java 변수명 -> cpp 변수명
    string cpp = "";
    for(int i = 0; i < java.size(); i++) {
        if(java[i] >= 'A' && java[i] <= 'Z') {
            cpp += '_';
        }
        cpp += tolower(java[i]);
    }
    return cpp;
}

string swapCppJava(string input) {
    if(isCpp(input)) { // cpp 변수명인 경우 java 변수명으로 변환
        return cppToJava(input);
    }
    if(isJava(input)) { // java 변수명인 경우 cpp 변수명으로 변환
        return javaToCpp(input);
    }
    return "Error!"; // cpp 변수명도, java 변수명도 아닌 경우
}

int main() {
    string input;
    cin >> input;

    cout << swapCppJava(input);
    return 0;
}