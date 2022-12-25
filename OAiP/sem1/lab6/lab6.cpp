#include <iostream>
using namespace std;
int main()
{
    char* p = (char*)"0000011110001111110001100000000";
    int min = strlen(p);   //min group
    char* pos = p;         //position
    int kol_vo;

    while (*p) {
        kol_vo = 0;
        do {
            kol_vo++; p++;
        } while (*p == *(p - 1));

        if (kol_vo < min)
            pos = p - (min = kol_vo);
    }

    for (int i = 0; i < min; i++) cout<< pos[i];
    
    return 0;
}
