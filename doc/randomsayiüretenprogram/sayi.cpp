#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    int random_integer = 0;

    ofstream dosya;
    dosya.open("deneme.txt");
    for (int i = 0; i < 10000; i++)
    {
        for (int i = 0; i < 16; i++)
        {
            random_integer = rand() % 10;
            dosya << random_integer;
        }
        dosya << endl;
    }

    dosya.close();

    return 0;
}