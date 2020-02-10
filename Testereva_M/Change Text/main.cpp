#include <iostream>
#include "string"
 
using namespace std;

void to_change_small_on_big (string &text){
    for (unsigned int i = 0; i <= text.length(); i++){
        //МЕТОД 1 (примитивный, пример)
        //if (text[i] == 'a'){text[i] = 'A';}
        //etc

        //МЕТОД 2 (использование функций библиотек с++)
        //if(islower(text[i])){text[i] = toupper(text[i]);}

        //МЕТОД 3 (использование таблицы кодирования символов ASCII)
        if ((unsigned int)text[i] >= 97 &&  (unsigned int)text[i] <= 122) {text[i]=(unsigned int)text[i]-32;}
    }
}

int main() {
    string text;

    cout << "Write a text:" << endl;
    cin >> text;

    to_change_small_on_big (text);

    cout << text << endl;
    return 0;
}
