//palindrome = a word, phrase, or sequence that reads the same backwards as forwards, e.g. madam or nursesrun.

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

// function to convert a non-palindromic string to a palindrome
string Converting_into_Palindrome(string str) {
    
    string rev = str;
    reverse(rev.begin(), rev.end());
    if(str == rev){
        return str;
    }else{
    return str + rev;
    }

}

int main() {
    string str;
    cout << "enter a sentence: ";
    getline(cin, str);
    stringstream str_s(str);
    string word;
    while (str_s >> word) {
            word = Converting_into_Palindrome(word);
        cout << word << " ";
    }
    return 0;
}