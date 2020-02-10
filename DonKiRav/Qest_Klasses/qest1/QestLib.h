#include <iostream>
#include <string>
using namespace std;

class Quuestion {
public:
    string question;
    string var1 ;
    string var2 ;
    string var3 ;
    void body() {
        cout << endl << question << "\n" << var1 << "\n" << var2 << "\n" << var3 << "\n";
    };
    string user_answer ;
    string right_answer ;

    Quuestion();

    void scan_answer() {
        cin >> user_answer;
    };

    void verdict() {
        if (user_answer == right_answer) {
            cout << "Right" << endl;
        }
        else {
            cout << "False" << endl;
        }
    };
};
