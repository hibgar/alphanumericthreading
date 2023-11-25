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
/*
void* alpha_func(void* arg) {
    while (iter < inputString.size()) {
        if (isalpha(inputString[iter])) {
            cout << "alpha: ";
            while (inputString[iter] != ' ' && inputString[iter] != '\0') {
                cout << inputString[iter];
                iter++;
            }
            cout << endl;
        } else {
            switchn = true;
            break;
        }
        iter++;
    }
    pthread_exit(0);
}

void* numeric_func(void* arg) {
    while (iter < inputString.size()) {
        if (isdigit(inputString[iter])) {
            cout << "numeric: ";
            while (inputString[iter] != ' ' && inputString[iter] != '\0') {
                cout << inputString[iter];
                iter++;
            }
            cout << endl;
        } else {
            switchn = false;
            if (switcha) {
                switcha = false;
                break;
            }
            switcha = true;
        }
        iter++;
    }
    pthread_exit(0);
}
*/
// Both alpha and numeric get the whole string, I didn't add break just made it so if not bool or bool depending then print otherwise it doesn't do anything and kinda gets stuck at that index until the other thread changes it
// No breaking it will get stuck at index index should be global anfld manually updated in the if statements

void* alpha_func(void* arg) {
    while (iter < inputString.size()) {
        if (isalpha(inputString[iter])) {
            cout << "alpha: ";
            while (inputString[iter] != ' ' && inputString[iter] != '\0') {
                cout << inputString[iter];
                iter++;
            }
            cout << endl;
        } else {
            switchn = true;
            break;
        }
        iter++;
    }
    pthread_exit(0);
}

void* numeric_func(void* arg) {
    while (iter < inputString.size()) {
        if (isdigit(inputString[iter])) {
            cout << "numeric: ";
            while (inputString[iter] != ' ' && inputString[iter] != '\0') {
                cout << inputString[iter];
                iter++;
            }
            cout << endl;
        } else {
            switchn = false;
            if (switcha) {
                switcha = false;
                break;
            }
            switcha = true;
        }
        iter++;
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
