#include "Dictionary.h"
#include <iostream>
using namespace std;

// Driver program
int main()
{
    
    // Initialize the dictionary.
    Dictionary dict;

    // BulkInsert the keys into the dictionary.
    string strs[] = {"Lauren Bacall", "Brigitte Bardot", "John Belushi", "Ingmar Bergman", "Emma Ember", "Fred Alstaire", "Olivia Rosalie", "Ava Journee", "Isabella Presley", "Sophia Amy", "Charlotte Catherine", "Mia Mckenzie", "Amelia Alaina", "Harper Brooke", "Evelyn Alana", "Abigail Summer", "Emily Rachel", "Elizabeth Mya", "Mila Everleigh", "Ella Daniela", "Avery Jocelyn", "Sofia Amara", "Camila Josie", "Aria Gracie", "Scarlett Callie", "Victoria Ayla", "Madison Londyn", "Luna Elliana", "Grace Sienna", "Chloe Juliette", "Penelope Diana", "Layla Lucia", "Riley Laila", "Zoey Sloane", "Nora London", "Lily Alexis", "Eleanor Teagan", "Hannah Remi", "Lillian Elise", "Addison Harmony", "Aubrey Arabella", "Ellie Sara", "Stella Genevieve", "Natalie Lauren", "Zoe Kimberly", "Leah ", "Hazel Daisy", "Violet Trinity", "Aurora Eloise", "Savannah Jordyn", "Audrey Sydney", "Brooklyn Morgan", "Bella Finley", "Claire Parker", "Skylar Lilly", "Lucy Aliyah", "Paisley Reese", "Everly Molly", "Anna Alina", "Caroline Valerie", "Nova Cecilia", "Genesis Ariel", "Emilia Esther", "Kennedy Charlie", "Samantha Juliana", "Maya Alyssa", "Willow Kayla", "Kinsley Anastasia", "Naomi Emersyn", "Aaliyah Eden", "Elena Ryleigh", "Sarah Adalyn", "Ariana Emerson", "Allison Valeria", "Gabriella Annabelle", "Alice Norah", "Madelyn Isabel", "Cora Iris", "Ruby Melody", "Eva Jasmine", "Serenity Khloe", "Autumn Andrea", "Adeline Bailey", "Hailey Brianna", "Gianna Eliza", "Valentina Amaya", "Isla Ashley", "Eliana Lyla", "Quinn Margaret", "Nevaeh Mary", "Ivy Alexandra", "Sadie Kylie", "Piper Rose", "Lydia Faith", "Alexa Taylor", "Josephine Leilani", "Emery Arya", "Julia Ximena", "Delilah Athena", "Arianna Maria", "Vivian Raelynn", "Kaylee Natalia", "Sophie Isabelle", "Brielle Katherine", "Madeline Jade", "Peyton Aubree", "Rylee Liliana", "Clara Adalynn", "Hadley Reagan", "Melanie Mackenzie", "Mackenzie Melanie", "Reagan Hadley", "Adalynn Clara", "Liliana Rylee", "Aubree Peyton", "Jade Madeline", "Katherine Brielle", "Isabelle Sophie", "Natalia Kaylee", "Raelynn Vivian", "Maria Arianna", "Athena Delilah", "Ximena Julia", "Arya Emery", "Leilani Josephine", "Taylor Alexa", "Faith Lydia", "Rose Piper", "Kylie Sadie", "Alexandra Ivy", "Mary Nevaeh", "Margaret Quinn", "Lyla Eliana", "Ashley Isla", "Amaya Valentina", "Eliza Gianna", "Brianna Hailey", "Bailey Adeline", "Andrea Autumn", "Khloe Serenity", "Jasmine Eva", "Melody Ruby", "Iris Cora", "Isabel Madelyn", "Norah Alice", "Annabelle Gabriella", "Valeria Allison", "Emerson Ariana", "Adalyn Sarah", "Ryleigh Elena", "Eden Aaliyah", "Emersyn Naomi", "Anastasia Kinsley", "Kayla Willow", "Alyssa Maya", "Juliana Samantha", "Charlie Kennedy", "Esther Emilia", "Ariel Genesis", "Cecilia Nova", "Valerie Caroline", "Alina Anna", "Molly Everly", "Reese Paisley", "Aliyah Lucy", "Lilly Skylar", "Parker Claire", "Finley Bella", "Morgan Brooklyn", "Sydney Audrey", "Jordyn Savannah", "Eloise Aurora", "Trinity Violet", "Daisy Hazel", " Leah", "Kimberly Zoe", "Lauren Natalie", "Genevieve Stella", "Sara Ellie", "Arabella Aubrey", "Harmony Addison", "Elise Lillian", "Remi Hannah", "Teagan Eleanor", "Alexis Lily", "London Nora", "Sloane Zoey", "Laila Riley", "Lucia Layla", "Diana Penelope", "Juliette Chloe", "Sienna Grace", "Elliana Luna", "Londyn Madison", "Ayla Victoria", "Callie Scarlett", "Gracie Aria", "Josie Camila", "Amara Sofia", "Jocelyn Avery", "Daniela Ella", "Everleigh Mila", "Mya Elizabeth", "Rachel Emily", "Summer Abigail", "Alana Evelyn", "Brooke Harper", "Alaina Amelia", "Mckenzie Mia", "Catherine Charlotte", "Amy Sophia", "Presley Isabella", "Journee Ava", "Rosalie Olivia", "Ember Emma"};
    int n = 15;
    dict.bulkInsert(n, strs);
    cout << dict.to_String();
    //cout << dict.find("beth Mya") << endl << endl;
    //dict.remove("beth Mya");
    dict.insert("Sophhie Lauren");
    cout << dict.to_String();
    dict.find("Sophhie Lauren");
    dict.remove("Sophhie Lauren");
    cout << endl<< dict.to_String();
    dict.insert("Sophhie Lauren");
    cout << dict.to_String();

    // Insert "Humphrey Bogart" into the dictionary.
    //dict.insert("Humphrey Bogart");

    // Remove "Lauren Bacall" from the dictionary.
    //dict.remove("Lauren Bacall");

    // Find "Fred Astaire" in the dictionary.
    // cout << endl << dict.find("Fred Astaire") << endl;

    // Find "Lauren Bacall" in the dictionary.
    //cout << dict.find("Lauren Bacall") << endl;

    return 0;
}
