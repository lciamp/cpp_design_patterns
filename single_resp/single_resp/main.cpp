//
//  main.cpp
//  single_resp
//
//  Created by Lou on 11/11/18.
//  Copyright © 2018 Lou. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string cwd = "/Users/lou/dropbox/cpp_design/single_resp/single_resp/";

struct Journal
{
    string title;
    vector<string> entries;
    
    Journal(const string& title) : title(title){}
    
    void add_entry(const string& entry)
    {
        entries.push_back(entry);
    }
};

struct PersistanceManager
{
    static void save(const Journal& j, const string& filename)
    {
        ofstream ofs(cwd + filename);
        for (auto& e : j.entries)
            ofs << e << endl;
        ofs.close();
    }
    
};

int main(int argc, const char * argv[]) {

    Journal journal("dear diary");
    journal.add_entry("i ate a bug");
    journal.add_entry("i cried today");
    journal.add_entry("it worked");
    
    PersistanceManager pm;
    
    pm.save(journal, "journal.txt");
    
    return 0;
}
