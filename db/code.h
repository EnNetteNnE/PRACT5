#include <iostream>
#include <fstream>

#include "hash.h"
#include "arr.h"

#include "data.h"
//#include "lock.h"
//#include "help.h"
#include "select_.h"
#include <future>

using namespace std;


string fileName = "schems.json";
string schemaName = "";
int tuplesLimit = 0;
MyHash<string, MyArr<string>*>* jsonStructure = HCREATE<string, MyArr<string>*>(10);
MyArr<string>* keys = MCREATE<string>(10);
    


int code(string& str, string sql) {

    if (SizeIndex(sql, 0, 12) == "INSERT INTO ") {
        int a = Insert(sql, *jsonStructure, schemaName, tuplesLimit, *keys);
        if (a > 0) {
            str = to_string(a);
        }
    }
    else if (SizeIndex(sql, 0, 12) == "DELETE FROM ") {
        int a = Delet(sql, *jsonStructure, schemaName, *keys);
    }
    else if (SizeIndex(sql, 0, 7) == "SELECT ") {
        Select(sql, *jsonStructure, schemaName, *keys, str);
    }
    else {
        str = "Попробуйте ввести запрос ещё раз)";
    }

    return 1;
}

void pushInfo() {
    MyArr<string>* info = MCREATE<string>(10);
    MSET<string>(*info, "INSERT INTO lot VALUES ('1', 'RUB')");
    MSET<string>(*info, "INSERT INTO lot VALUES ('2', 'ВТС')");
    MSET<string>(*info, "INSERT INTO lot VALUES ('3', 'ETH')");
    MSET<string>(*info, "INSERT INTO lot VALUES ('4', 'USDT')");
    MSET<string>(*info, "INSERT INTO lot VALUES ('5', 'USDC')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('1', '1', '2')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('2', '1', '3')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('3', '1', '4')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('4', '1', '5')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('5', '2', '3')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('6', '2', '4')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('7', '2', '5')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('8', '3', '4')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('9', '3', '5')");
    MSET<string>(*info, "INSERT INTO pair VALUES ('10', '4', '5')");
    string str = "0";

    for (int i = 0; i < info->len; i++) {
        string sql = info->data[i];
        code(str, sql);
    }
}


