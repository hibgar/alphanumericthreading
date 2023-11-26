#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
using namespace std;

int iter = 0;
string inputString;
bool switchn = false;
bool switcha = false;

void* alpha_func(void* arg) {

    while (iter < inputString.size()) {
        if (switcha) {
            if (isalpha(inputString[iter])){
                cout << "alpha: ";
                while (inputString[iter] != ' ' && inputString[iter] != '\0') {
                    cout << inputString[iter];
                    iter++;
                }
                cout << endl;
                iter++;
            }
            
            else {
                if (isdigit(inputString[iter])) {
                    switcha = false;
                    switchn = true;
                }
                
            }
            
        }
        
    }
    pthread_exit(0);
}

void* numeric_func(void* arg) {
    
    while (iter < inputString.size()) {
        if (switchn) {

            if (isdigit(inputString[iter])) {
                cout << "numeric: ";
                while (inputString[iter] != ' ' && inputString[iter] != '\0') {
                    cout << inputString[iter];
                    iter++;
                }
                cout << endl;
                iter++;
            }
            
            else {
                if (isalpha(inputString[iter])){
                    switchn = false;
                    switcha = true;
                }
                
            }
            
        }
        
    }
    pthread_exit(0);
}

int main() {  

    cout << "Enter a phrase: ";
    getline(cin, inputString);
    
    if (isalpha(inputString[0])) {
        switcha = true;
    }
    if (isdigit(inputString[0])){
        switchn = true;
    }

    pthread_t alpha, numeric;

    pthread_create(&alpha, NULL, alpha_func, NULL);
    pthread_create(&numeric, NULL, numeric_func, NULL);
    pthread_join(alpha, NULL);
    pthread_join(numeric, NULL);

    return 0;
}
