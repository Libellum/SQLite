#include "SQLite.h"

SQLite::SQLite(string filename) {
	database = NULL;
	if(filename.length() > 0)
		open(filename.c_str());
}

SQLite::~SQLite() {

}

bool SQLite::open(string filename) {
	if(sqlite3_open(filename.c_str(), &database) == SQLITE_OK)
		return true;

	return false;
}

vector< map<string, string> > SQLite::query(string Query) {
	sqlite3_stmt *statement;

	vector< map<string, string> > results;

	if(sqlite3_prepare_v2(database, Query.c_str(), -1, &statement, 0) == SQLITE_OK){
		int cols = sqlite3_column_count(statement);
		int result = 0;


		while(true){
			result = sqlite3_step(statement);
			if(result == SQLITE_ROW){
				map<string, string> value;
				for(int col = 0; col < cols; col++){
					char * column_name = (char*)sqlite3_column_name(statement, col);
					char * column_value = (char*)sqlite3_column_text(statement, col);
				    value[column_name] = column_value;

				}
				results.push_back( value );
			}else{
				break;
			}
		}
		sqlite3_finalize(statement);
	}else{
        string error = sqlite3_errmsg(database);
        throw error;
    }

	return results;
}

void SQLite::close() {
	sqlite3_close(database);
}