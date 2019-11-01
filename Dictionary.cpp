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
    while(sum >= (2 * n)){
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
    int index2 = 0;
    while(collision){
        initHashFunc2();
        hashCounter2++;
        collision = false;
        level2.resize(0);
        for(int i = 0; i < n; i++) level2.push_back(empty);
        for(int i = 0; i < level1.size(); i++){
            if(level1[i].size() > 1){
                vector<string> v2(pow(level1[i].size(),2));
                level2[i] = v2;
                for(int j = 0; j < level1[i].size(); j++){
		    index2 = hash2Func(level1[i][j], pow(level1[i].size(), 2));
                    if((level2[i])[index2] == "") level2[i][index2] = level1[i][j];
                    else collision = true;
                }
            }
            else{
                level2[i] = level1[i];
            }
        }
	}
    
    data = level2;
    
    cout << endl << "HASH FUNCTION LEVEL 1\n---------------------" << endl;
    cout << "Generation attempts: " << hashCounter1 << endl << endl;
    cout << "Hash function = SUM( (key[i] + hash1_1) * (i * hash1_2) + hash1_2 * key[i] + hash1_1 ) % n\n\t\ti being each of the last <= 8 characters of the string\n\t\tn items in the hash table\n";
    cout << "hash1_1: " << hash1_1 << "\nhash1_2: " << hash1_2 << endl;
    //cout << "key[i] + (i * " << hash1_1 << ") + " << hash1_2 << " * key[i]";
    cout << endl;
    
    cout << endl << "HASH FUNCTION LEVEL 2\n---------------------" << endl;
    cout << "Generation attempts: " << hashCounter2 << endl << endl;
    cout << "Hash function = ( SUM(key[i] * hash2_1 + i * key[i]) % hash2_2 ) % level2length\n\t\ti being each of the last <= 8 characters of the string\n\t\tlevel2length = size of items hashed to same index squared\n";
    cout << "hash2_1: " << hash2_1 << "\nhash2_2: " << hash2_2 << endl;
    //cout << "key[i] + (i * " << hash2_1 << ") + " << hash2_2 << " * key[i]";
    cout << endl;
    
}

void Dictionary::insert(string key) {
    int index1 = hash1Func(key);
    if(data[index1].size() > 1){
        int index2 = hash2Func(key, data[index1].size());
        if(data[index1][index2] != ""){
            cout << "\nTHERE HAS BEEN A COLLISION WHEN INSERTING \"" << key << "\"\n@ index " << index2 << " of level " << index1 << "\n\n";
            // HOW IN THE FREAKING HELL AM I SUPPOSED TO IMPLEMENT SEPARATE CHAINING RIGHT NOW. BUNK THIS.
            data[index1].push_back(key);
        }
        else data[index1][index2] = key;
    }
    else if(data[index1].size() == 1 && data[index1][0] != ""){
        data[index1].push_back(key);
        cout << "\nTHERE HAS BEEN A COLLISION WHEN INSERTING \"" << key << "\"\n@ index 0 of level " << index1 << "\n\n";
    }
    else if(data[index1].size() == 1 && data[index1][0] == ""){
        data[index1][0] = key;
    }
    else{
        data[index1].push_back(key);
    }
}

void Dictionary::remove(string key) {
    int index1 = hash1Func(key);
    if(data[index1].size() <= 0) return;
    if(data[index1][0] == key){
        data[index1][0] = "";
        return;
    }
    int index2 = hash2Func(key, data[index1].size());
    if(index2 >= 0 && data[index1].size() > index2 && data[index1][index2] == key) data[index1][index2] = "";
    if(data[index1][data[index1].size() - 1] == key) data[index1][data[index1].size() - 1] = "";
}

bool Dictionary::find(string key) {
    cout << "\nBUCKETS accessed during find operation:\n";
    int index1 = hash1Func(key);
    cout << "index1 = " << index1 << endl;
    if(data[index1].size() <= 0) return false;
    if(data[index1][0] == key) return true;
    int index2 = hash2Func(key, data[index1].size());
    cout << "index2 = " << index2 << endl;
    if(index2 >= 0 && data[index1].size() > index2 && data[index1][index2] == key) return true;
    cout << "last effort index = " << data[index1].size() - 1 << endl;
    if(data[index1][data[index1].size() - 1] == key) return true;
    return false;
}

void Dictionary::initHashFunc1(){
    srand(rand() ^ time(NULL));
    hash1_1 = rand() % 1000 + 1;
    srand(rand() ^ time(NULL));
    hash1_2 = rand() % 1000 + 1;
}

void Dictionary::initHashFunc2(){
    srand(rand() ^ time(NULL));
    hash2_1 = rand() % 1000 + 1;
    srand(rand() ^ time(NULL));
    hash2_2 = rand() % 50 + 1;
}

int Dictionary::hash2Func(string key, int level2length){
    if(level2length < 1) return -1;
    
    int inclIndex;
    if(key.length() < 8) inclIndex = 0;
    else inclIndex = key.length() - 8;
    
    int sum = 0;
    for(int i = key.length() - 1; i >= inclIndex; i--){
        
        // ACTUAL HASHING FUNCTION
        sum += key[i] * hash2_1 + i * key[i];
        // **********************
    }
    sum %= hash2_2;
    
    
    return sum % level2length;
}


int Dictionary::hash1Func(string key) {
    int inclIndex;
    if(key.length() < 8) inclIndex = 0;
    else inclIndex = key.length() - 8;
    
    int sum = 0;
    for(int i = key.length() - 1; i >= inclIndex; i--){
        
        // ACTUAL HASHING FUNCTION
        sum += (key[i] + hash1_1) * (i * hash1_2) + hash1_2 * key[i] + hash1_1;
        // **********************
    }
    
    return sum % items;
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
