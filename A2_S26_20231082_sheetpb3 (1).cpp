#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "bits/stdc++.h"
using namespace std ;

string format_word(string word) { // I did this function to handle hyphen and alpha_digit words
    if (any_of(word.begin(), word.end(), ::isalpha)){
    for (int i = 0; i < word.size() - 1; i++) {
        while ( i < word.size() -1 && word[i] == '-' && word[i + 1] == '-') {
            word.erase(i, 1); 
        }
    }
    for (int i = 0; i < word.size() - 2; i++) {
     if (isdigit(word[i])) {
      word.erase(i, 1); 
      i--;  
      }
     }
     if (!word.empty() && word.front() == '-') word.erase(0, 1);
     if (!word.empty() && word.back() == '-') word.pop_back();
    
    return word;
    }
}
map<string, int> display_frequency_table(const string& file_name)
{
    string word;
    char c;
    map<string, int> word_count;
    ifstream file(file_name);

    if (!file)
    {
        cout << "Incorrect file name!" << endl;
        return word_count;
    }

    stringstream ss;
    while (file.get(c))
    {
        if (isalpha(c) || c == '-' || isspace(c) || isdigit(c))
        {
            ss.put(tolower(c));
        }
    }

    while (ss >> word)
    {
        string wordv2 = format_word(word) ;
        if (!wordv2.empty())
        {
            word_count[wordv2]++;
        }
    }
    if (word_count.empty()) 
    {
        cout << "(" << file_name << ") is an empty file or contains no valid words!" << endl;
    } 
    else 
    {
        cout << "(Word) " << "=============" << " (Freq.)\n\n";
    }

    return word_count;
}

ostream& operator<<(ostream& output, const map<string, int>& word_count)
{
    for (const auto& entry : word_count)
    {
        output << left << setw(20) << entry.first << " = " << entry.second << endl;
    }
    return output;
}

void small_menu()
{
    string file_name;
    cout << "Enter the file name: ";
    cin >> file_name;
    cout << "\n";
    cout << display_frequency_table(file_name) << endl;
}

int main()
{
    small_menu();  
    return 0;
}
