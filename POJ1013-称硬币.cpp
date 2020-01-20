#include<iostream>
#include<cstring>
using namespace std;

char Left[3][7];
char Right[3][7];
char result[3][7];

bool Isfake(char c, bool weight){
    int i = 0;
    char *pright, *pleft, *presult;
    for (i = 0; i < 3; i++){
        if (weight)
        {
            pright = Right[i];
            pleft = Left[i];
        }
        else if(!weight){
            pright = Left[i];
            pleft = Right[i];
        }
        switch (result[i][0])
        {
            case 'u':
                if(strchr(pleft, c) == NULL){
                    return false;
                }
                break;

            case 'd':
                if(strchr(pright, c) == NULL){
                    return false;
                }
                break;

            case 'e':
                if(strchr(pright, c) || strchr(pleft, c)){
                    return false;
                }
        }
        return true;
    }
}

int main(){
    int n = 0, i = 0;
    char c;
    cin >> n;
    while(n--){
        for (; i < 3; i++){
            cin >> Left[i] >> Right[i] >> result[i];
        }
        for (c = 'A'; c <= 'L'; c++){
            if(Isfake(c, true)){
                cout << c << " " << "is the counterfeit coin and it is light.";
            }
            else if(Isfake(c, false)){
                cout << c << " " << "is the counterfeit coin and it is weight.";
            }
        }
    }
}