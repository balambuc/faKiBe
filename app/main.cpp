#include "../src/Tree.h"
#include <iostream>


using namespace std;

int main(int arc, char** argv) {
    cout << "------ Bináris fa kiíró és beolvasó demonstráló környezet -----"
         << endl
         << "Kilépéshez írja be a bemenetre az 'e' betűt!";

    string str;
    do
    {
        cout << endl << Tree(move(str)).to_string() << endl;
        cout << "Fa zárójeles módon: ";
        cin >> str;
    }
    while (str != "e" && str != "E");
    return 0;
}