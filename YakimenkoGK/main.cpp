#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string name, otvet;
    int flagA=0, rez=0;
    int n=0;
    cout << "Welcome to IQ test Pied-Piper!\n";
    A:
    if (flagA == 0) {cout << "What is your name?\n";}
    else cout << "HELLO AGAIN! What is your name now?\n";
    cin >> name;
    cout << "Nice to meet you, " << name << "!\n";
    cout << "Lets start!\n" << "First question: 4+4=?\n";
    cin >> otvet;
    if (otvet == "8" || otvet == "eight") {
        rez++;
        cout<< "Wow, " << name << "You are so smart!\n"<< "Score: " << rez<< "\n";
    }
    else cout  << "Lol, " << name << ", be carefully.\n" << "Score: " << rez << "\n";
    cout << "Second question: What is rhe capital of Russia?\n";
    cin >> otvet;
    if (otvet == "Moscow" || otvet == "moscow"){
        rez++;
        cout << "Good job! " << name << ", you are state of my heart!\n"<< "Score: " << rez <<"\n";
    }
    else cout << "Wtf, " << name << "!!!!!????\n" << "Score: " << rez <<"\n";
    cout << "Next question:\n" << "Nanana or Lalala?\n";
    cin >> otvet;
    if (otvet == "Nanana" || otvet == "nanana") {
        rez++;
        cout << "SUCH A GOOD VOICE!!!\n " << "Score: " << rez <<"\n";
    }
    else {
        cout << "Its a trap, " << name << "! Go to start and then choose other answer))0\n";
        rez =0;
        flagA = 1;
        goto A;

    }
    cout << "AND LAST VERY HARD QUESTION!!!!!!!!!!!:\n"<< "WRITE ONE YOUR FAVORITE WORD OR I KILL YOU!\n";
    cin >> otvet;
    while (n!=20) { cout << "%)&@!@)(*@)!#**!@#)(*#@"; n++;}
    cout << name << ", " << otvet << " eto tvoya sudba";
    while (n!=40) { cout << "!%)&@!@)(*@)!#**!@#)(*#@"; n++;};
    cout << "\n"; cout << "\n"; cout << "\n";
    cout << "NAIDI I NAPISHI FRAZU KOTORUU YA OSTAVIL V ETOM TEKSTE\n"<< "\n";
    cin >> otvet;
    cout << "\n"<<"Ti otvetil: " << otvet << " No tak to mne nevazhno \n";
    rez= rez+10000000000000;
    cout << "Tvoi rezultat " << rez << " Iz 100. \n";
    cout << "Diagnoz - "<< name <<   ", ti robototehnik.";

    getchar();getchar();getchar();getchar();getchar();getchar();getchar();getchar();
    getchar();











}