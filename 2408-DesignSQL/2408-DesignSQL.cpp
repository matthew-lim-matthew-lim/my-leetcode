class Table {
public:
    string tableName;
    map<int, vector<string>> rows;
    int columns;
    int currRow = 1;

    void insert_row(vector<string> &row) {
        rows[currRow] = row;
        currRow++;
    }

    void remove_row(int rowId) {
        rows.erase(rowId);
    }

    vector<string> exp() {
        vector<string> res;
        for (auto pair : rows) {
            string expRow;
            expRow += to_string(pair.first);
            for (string s : pair.second) {
                expRow += ',' + s;
            }
            res.push_back(expRow);
        }

        return res;
    }
};

class SQL {
private:
    unordered_map<string, Table> tables;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < names.size(); i++) {
            tables[names[i]] = Table(names[i], {}, columns[i]);
        }
    }
    
    bool ins(string name, vector<string> row) {
        if (!tables.contains(name)) {
            return false;
        }
        if (tables[name].columns != row.size()) {
            return false;
        }

        tables[name].insert_row(row);
        return true;
    }
    
    void rmv(string name, int rowId) {
        if (!tables.contains(name)) {
            return;
        }
        if (!tables[name].rows.contains(rowId)) {
            return;
        }
        tables[name].remove_row(rowId);
    }
    
    string sel(string name, int rowId, int columnId) {
        if (!tables.contains(name)) {
            return "<null>";
        }
        if (!tables[name].rows.contains(rowId)) {
            return "<null>";
        }
        if (!(columnId - 1 < tables[name].columns)) {
            return "<null>"; 
        }
        return tables[name].rows[rowId][columnId - 1];
    }
    
    vector<string> exp(string name) {
        if (!tables.contains(name)) {
            return {};
        }
        return tables[name].exp();
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */