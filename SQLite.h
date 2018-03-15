#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <vector>
#include <string>
#include <map>

#include "sqlite3.h"

using namespace std;

class SQLite {

    public:
        SQLite(string filename="");
        ~SQLite();

        bool open(string filename);
        vector< map<string, string> > query(string query);
        void close();

    private:
        sqlite3 *database;

};

#endif
