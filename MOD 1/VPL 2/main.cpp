#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra;
    cin >> palavra;
    string str ("aeiou");
    int numVogais[5];
    for(int i = 0; i < 5; ++i)
    {
        numVogais[i] = 0;
    }
    for (int i=0; i<palavra.length(); ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(palavra[i] == str[j]){
              numVogais[j]++;
            };
        }
    }
    for (int i=0; i< 5; ++i)
    {
        if(numVogais[i] > 0){
            cout << str[i] << " " << numVogais[i] << endl;
        };
    }
}