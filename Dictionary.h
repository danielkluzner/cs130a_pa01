#include <string>
#include <vector>
using namespace std;

class Dictionary {
    
 public:
    // Insert an input set of n keys to the dictionary. This method should print out the following information:
    // 1. The hash functions comprising the perfect hash (both levels)
    // 2. The sum of squares of the number of keys mapped to each bin of the first level hash function, and
    // 3. The number of trials needed to generate each hash function.
    void bulkInsert(int n, string *keys);

    // Insert a key to the dictionary.
    // Print out whether the insertion caused a collision in the second level hash.
    // Handle collision with separate chaining.
    void insert(string key);

    // Remove a key from the dictionary, if it exists.
    void remove(string key);

    // Return whether a key is found in the dictionary.
    // Print the buckets (both first and second level) accessed during the operation.
    bool find(string key);
    
    // The hash function.
    // Generates an index value where the element should be inserted.
    int hash1Func(string key);
    int hash2Func(string key, int level2length);
    
    // Print out hash table.
    string to_String();
    
private:
    
    int items;
    vector< vector<string> > data;
    
    //vector< vector<int> > hash1;
    //vector< vector<int> > hash2;
    int hash1_1;
    int hash1_2;
    int hash2_1;
    int hash2_2;
    
    // Initialize the special hash function values that are stored in hash1 and hash2.
    // They correspond to the hashes executed in LEVEL1 and LEVEL2
    // of perfect hashing, respectively.
    void initHashFunc1();
    void initHashFunc2(/*int rows, int cols*/);
    
    //string convertToBinary(int decimal, int bits);
    //int convertToDecimal(string binary);
    
    //void printHash1();
    //void printHash2();
    
};
