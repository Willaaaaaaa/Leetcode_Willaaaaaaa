// This cpp file is used to record my learning on string.
// URL: https://www.youtube.com/playlist?list=PLqjW-ORyj-hLKFq_ESmFpXDnaLKaTCMio

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removal(string s){
    string ns;
    for (int i = 0; i < s.length(); i++){
        if (s.at(i) >= '0' && s.at(i) <= '9')
            ns += s.at(i);
    }
    return ns;
}

int main(){
    string text = "some text";

    // 1. the length function returns the number of characters in the string
    cout << "\n1.\n";
    cout << "the length of the string: " << text.length() << endl;

    // 2. the resize function(1)
    cout << "\n2.\n";
    text.resize(8);
    cout << "resize to 8 characters: " << text << endl;
    text.resize(20);

    // 3. locate the char in the string: be caucious of the index, keep it in range
    cout << "\n3.\n";
    cout << "text[4]: " << text[4] << endl;
    cout << "text.at(4): " << (int)text.at(4) <<endl;  // the ascii value of a space
    cout << "text[10]: " << text[10] << endl;
    cout << "text.at(10): " << (int)text.at(10) <<endl;  // the ascii value of NULL

    // 4. continue: rezise(2)
    cout << "\n4.\n";
    text = "some text";  // revalue the string
    text.resize(15, '*');  // resize to 15 and replace "NULL" to "*"
    cout << text << endl;
    text.resize(20, '-');  // resize to 20 and replace "NULL" to "-"
    cout << text << endl;

    // practice
    // cout << "\n*practice\n";
    // string line;
    // cout << "Enter a line: ";
    // getline(cin, line);
    // line.resize(line.length()+3, '!');
    // cout << line;

    // 5. remove characters
    cout << "\n5.\n";
    string numLetter = "123abc";
    cout << "after removal: " << removal(numLetter) << endl;

    // 6. string substr
    cout << "\n6.\n";
    string s = "hello world";
    string ns = s.substr(6, 2);  // the 1st parameter: the beginning index, the 2nd one: the length
    cout << "substr begins at 6 and has 2 characters: " << ns << endl;

    // 7. find and find_first_of
    cout << "\n7.\n";
    string s1 = "abc abc abc";
    int found = s1.find("abc", 3);  // the 1st parameter: the char/string you try to find, the 2nd one: begins at 
    cout << "found abc at: " << found << endl;  

    // 8. insert
    cout << "\n8.\n";
    string words = "one two three four six";
    string word = "five";
    int foundSpace = -1;
    int lastSpace = 0;
    do{
        foundSpace = words.find(" ", foundSpace + 1);
        if (foundSpace != -1){
            lastSpace = foundSpace;
        }
    } while (foundSpace != -1);
    words = words.substr(0, lastSpace) + " " + word + words.substr(lastSpace);
    cout << words << endl;

    // 9. remove certain texts from a string
    cout << "\n9.\n";
    string ums = "I um want to um stop talking um like um this.";
    string target = "um ";
    int foundT = -1;
    do{
        foundT = ums.find(target, foundT + 1);
        if (foundT != -1){
            ums = ums.substr(0, foundT) + ums.substr(foundT + target.length());
        }
    } while (foundT != -1);
    cout << ums << endl;

    // 10. begin and end function
    cout << "\n10.\n";
    string str = "test string";
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    // 11. reverse the string: rbegin and rend function
    cout << "\n11.\n";
    string s11 = "hello";
    cout << string(s11.rbegin(), s11.rend()) << endl;

    // 12. reverse the string: reverse function
    cout << "\n12.\n";
    string s12 = "abcd";
    reverse(s12.begin(), s12.end());  // #include<algorithm>
    cout << s12 << endl;

    // 13. push_back
}