#include "Dictionary.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

void Dictionary::bulkInsert(int n, string *keys) {
    items = n;
    vector< vector<string> > level1;
    vector< vector<string> > level2;
    vector<string> empty(0);
    int hashCounter1 = 0;
    int hashCounter2 = 0;
    
    // LEVEL 1
    int sum = 2 * n;
    while(sum >= 2 * n){
        level1.resize(0);
        for(int i = 0; i < n; i++) level1.push_back(empty);
        initHashFunc1();
        hashCounter1++;
        
        for(int i = 0; i < n; i++){
            level1[hash1Func(*(keys + i))].push_back(*(keys + i));
        }
        
        sum = 0;
        for(int i = 0; i < level1.size(); i++){
            sum += pow(level1[i].size(), 2);
        }
    }
    
    sum = 0;
    cout << "\nSum of squares of the number of keys mapped to each bin of LEVEL1: ";
    for(int i = 0; i < level1.size(); i++){
        sum += pow(level1[i].size(), 2);
    }
    cout << sum << endl;

    // LEVEL 2
    bool collision = true;
    int rows, cols, index2;
    while(collision){
        initHashFunc2(rows, cols);
        hashCounter2++;
        
        cout << hashCounter2 << " | here\n";
        printHash2();
        
        collision = false;
        level2.resize(0);
        for(int i = 0; i < n; i++) level2.push_back(empty);
        for(int i = 0; i < level1.size(); i++){
            if(level1[i].size() > 1){
                vector<string> v2(pow(level1[i].size(),2));
                level2[i] = v2;
                rows = ceil( 2 * log(level1[i].size()) / log(2) );
                //cols = ceil( log(level1[i].size()) / log(2) );
                cols = rows;
                
                
                for(int j = 0; j < level1[i].size(); j++){
                    index2 = hash2Func(level1[i][j], level1[i].size());
                    if(level2[i][index2] == "") level2[i][index2] = level1[i][j];
                    else collision = true; /*level2[i][index2 + 1] = level1[i][j];*/
                }
            }
            else{
                level2[i] = level1[i];
            }
        }
    }
    
    data = level2;
    
    cout << endl << "HASH FUNCTION 1\n----------------" << endl;
    cout << "Generation attempts: " << hashCounter1 << endl << endl;
    printHash1();
    cout << endl;
    
    /*cout << endl << "HASH FUNCTION 2\n----------------" << endl;
    cout << "Generation attempts: " << hashCounter2 << endl << endl;
    printHash2();
    cout << endl;*/
    
       string result = "level1:\n";
       for(int i = 0; i < level1.size(); i++){
           result += to_string(i) + " |\t";
           for(int j = 0; j < level1[i].size(); j++){
               if((level1[i])[j] == "") result += "*";
               result += ((level1[i])[j] + " | ");
           }
           result += "\n";
       }
       cout << result << endl << "level2:\n";
}

void Dictionary::insert(string key) {
  // TODO:: Write this.

}

void Dictionary::remove(string key) {
  // TODO:: Write this.

}

bool Dictionary::find(string key) {
    /*int index1 = hash1Func(key);
    if(data[index1][0] == key) return true;
    int index2 = hash2Func(key);
    if(data[index1][index2] == key) return true;*/
    return false;
}

void Dictionary::initHashFunc1(){
    srand(rand() ^ time(NULL));
    hash1.resize(0);
    vector<int> empty(0);
    int dim = ceil(log(items) / log(2));
    for(int i = 0; i < dim; i ++){
        hash1.push_back(empty);
        for(int j = 0; j < dim; j++){
            (hash1[i]).push_back(rand() % 2);
        }
    }
}

void Dictionary::initHashFunc2(int rows, int cols){
    srand(rand() ^ time(NULL));
    hash2.resize(0);
    vector<int> empty(0);
    for(int i = 0; i < rows; i ++){
        hash2.push_back(empty);
        for(int j = 0; j < cols; j++){
            (hash2[i]).push_back(rand() % 2);
        }
    }
}

int Dictionary::hash2Func(string key, int level2length){
    int inclIndex;
    if(key.length() < 8) inclIndex = 0;
    else inclIndex = key.length() - 8;
    
    int sum = 0;
    for(int i = key.length() - 1; i >= inclIndex; i--){
        
        // ACTUAL HASHING FUNCTION
        // sum += i + key[i] * i + key[i];
        sum += key[i] + key.length() - i;
        // **********************
    }
    
    sum = sum % (int)pow(level2length, 2);
    string binary = convertToBinary(sum, ceil( 2 * log(level2length) / log(2) ));
    reverse(binary.begin(), binary.end());
    
    string result = "";
    int inter = 0;
    string curr = "";
    for(int i = 0; i < hash2.size(); i++){
        inter = 0;
        for(int j = 0; j < hash2[i].size(); j++){
            curr = binary[j];
            inter = inter || (stoi(curr) *  (hash2[i])[j]);
        }
        result += to_string(inter);
    }
    reverse(result.begin(), result.end());
    
    return convertToDecimal(result) % (int)pow(level2length, 2);
    return 1;
}

int Dictionary::hash1Func(string key) {
    
    int inclIndex;
    if(key.length() < 8) inclIndex = 0;
    else inclIndex = key.length() - 8;
    
    int sum = 0;
    for(int i = key.length() - 1; i >= inclIndex; i--){
        
        // ACTUAL HASHING FUNCTION
        if(items > 80){
            
        }
        else if(items > 40){
            
        }
        else if(items > 20){
            //sum += (key[i] - i) + i * (key[i] + i - 1);
            //sum += i + key[i] * i + key[i];
            sum += key[i] + key.length() - i;
        }
        else if(items > 9){
            sum += key[i] + key.length() - i;
        }
        else{
            sum += key[i] * i + key[i];
            //sum += key[i] + key.length() - i;
        }
        // **********************
    }
    
    //return sum % items;
    
    sum = sum % items;
    string binary = convertToBinary(sum, ceil(log(items) / log(2)));
    reverse(binary.begin(), binary.end());
    
    string result;
    int inter = 0;
    string curr = "";
    for(int i = 0; i < hash1.size(); i++){
        inter = 0;
        for(int j = 0; j < hash1[i].size(); j++){
            curr = binary[j];
            inter = inter || (stoi(curr) *  (hash1[i])[j]);
        }
        result += to_string(inter);
    }
    reverse(result.begin(), result.end());
    
    return convertToDecimal(result) % items;
}

string Dictionary::convertToBinary(int decimal, int bits){
    int num = decimal;
    string bin = "";
    for(int i = 0; i < bits; i++){
        if(num == 0) bin += "0";
        else{
            bin += to_string(num % 2);
            num /= 2;
        }
    }
    return bin;
}

int Dictionary::convertToDecimal(string binary){
    int decimal = 0;
    string curr = "";
    for(int i = 0; i < binary.length(); i++){
        curr = binary[i];
        decimal += pow(2, i) * stoi(curr);
    }
    return decimal;
}

string Dictionary::to_String(){
    string result = "";
    for(int i = 0; i < data.size(); i++){
        result += to_string(i) + " |\t";
        for(int j = 0; j < data[i].size(); j++){
            if((data[i])[j] == "") result += "*";
            result += ((data[i])[j] + " | ");
        }
        result += "\n";
    }
    return result;
}

void Dictionary::printHash1(){
    for(int i = 0; i < hash1.size(); i++){
        for(int j = 0; j < hash1[i].size(); j++){
            cout << hash1[i][j] << " ";
        }
        cout << endl;
    }
}

void Dictionary::printHash2(){
    for(int i = 0; i < hash2.size(); i++){
        for(int j = 0; j < hash2[i].size(); j++){
            cout << hash2[i][j] << " ";
        }
        cout << endl;
    }
}
