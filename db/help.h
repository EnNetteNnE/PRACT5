#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>

#include "hash.h"
#include "arr.h"


using namespace std;



string getCurrentTime() {
    // Получаем текущее время
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now);

    // Используем строковый поток для форматирования времени
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S"); // Формат: ГГГГ-ММ-ДД ЧЧ:ММ:СС

    return oss.str();
}

string inverse(string a) {
    if (a == "sell") {return "buy";}
    return "sell";
}

vector<string> splitProbel(const string &input) {
    vector<string> tokens;
    size_t start = 0; // Начальная позиция для поиска
    size_t end;

    while ((end = input.find(' ', start)) != string::npos) {
        // Извлекаем подстроку и добавляем ее в вектор
        string token = input.substr(start, end - start);
        if (!token.empty()) { // Проверка на пустую строку
            tokens.push_back(token);
        }
        start = end + 1; // Обновляем начальную позицию
    }
    
    // Добавляем последнее слово, если оно существует
    string lastToken = input.substr(start);
    if (!lastToken.empty()) {
        tokens.push_back(lastToken);
    }

    return tokens; // Возвращаем вектор строк
}


vector<string> splitPerenos(const string &input) {
    vector<string> tokens;
    size_t start = 0; // Начальная позиция для поиска
    size_t end;

    while ((end = input.find('\n', start)) != string::npos) {
        // Извлекаем подстроку и добавляем ее в вектор
        string token = input.substr(start, end - start);
        if (!token.empty()) { // Проверка на пустую строку
            tokens.push_back(token);
        }
        start = end + 1; // Обновляем начальную позицию
    }
    
    // Добавляем последнее слово, если оно существует
    string lastToken = input.substr(start);
    if (!lastToken.empty()) {
        tokens.push_back(lastToken);
    }

    return tokens; // Возвращаем вектор строк
}


vector<string> splitZap(const string &input) {
    vector<string> tokens;
    size_t start = 0; // Начальная позиция для поиска
    size_t end;

    while ((end = input.find(',', start)) != string::npos) {
        // Извлекаем подстроку и добавляем ее в вектор
        string token = input.substr(start, end - start);
        if (!token.empty()) { // Проверка на пустую строку
            tokens.push_back(token);
        }
        start = end + 1; // Обновляем начальную позицию
    }
    
    // Добавляем последнее слово, если оно существует
    string lastToken = input.substr(start);
    if (!lastToken.empty()) {
        tokens.push_back(lastToken);
    }

    return tokens; // Возвращаем вектор строк
}


string SizeIndex(string str, int begin, int end) {
    if (str.size() < end) {
        //cout << "Попробуйте ввести запрос ещё раз)";
        return str;
    }
    string strcut;
    for (int i = begin; i < end; i++) {
        strcut.push_back(str[i]);
    }
    return strcut;
}



MyArr<MyArr<string>> ReadCSV(string filename) {
    MyArr<MyArr<string>>* data = MCREATE<MyArr<string>>(10);
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        MyArr<string>* row = MCREATE<string>(10);
        stringstream lineStream(line);
        string cell;

        while (getline(lineStream, cell, ',')) {
            MSET(*row, cell);
        }

        MSET(*data, *row);
    }

    file.close();
    return *data;
}




int AddInFile(string filename, string addstr) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 0;
    }

    string line;
    string allstr;
    while (getline(file, line)) {
        allstr += line;
        allstr.push_back('\n');
    }
    file.close();
    allstr += addstr;

    ofstream file2(filename);
    file2 << allstr;
    file2.close();
  
    return 0;
}


int getPair(int pair, int& lot1, int& lot2) {
    switch(pair) {
        case (1): lot1 = 1; lot2 = 2;
        case (2): lot1 = 1; lot2 = 3;
        case (3): lot1 = 1; lot2 = 4;
        case (4): lot1 = 1; lot2 = 5;
        case (5): lot1 = 2; lot2 = 3;
        case (6): lot1 = 2; lot2 = 4;
        case (7): lot1 = 2; lot2 = 5;
        case (8): lot1 = 3; lot2 = 4;
        case (9): lot1 = 3; lot2 = 5;
        case (10): lot1 = 4; lot2 = 5;
    }
    return 0;
}

int getu(vector<vector<string>>& abba) {
    MyArr<MyArr<string>> data = ReadCSV("Birga/user_lot/1.csv");
    //vector<vector<string>> abba;
    for (int i = 0; i < data.len; i++) {
        MyArr<string> fuy = data.data[i];
        vector<string> ab;
        for (int j = 0; j < fuy.len; j++) {
            ab.push_back(fuy.data[j]);
        }
        abba.push_back(ab);
    }

    return 0;
}

int get(vector<vector<string>>& abba) {
    MyArr<MyArr<string>> data = ReadCSV("Birga/order/1.csv");
    //vector<vector<string>> abba;
    for (int i = 0; i < data.len; i++) {
        MyArr<string> fuy = data.data[i];
        vector<string> ab;
        for (int j = 0; j < fuy.len; j++) {
            ab.push_back(fuy.data[j]);
        }
        abba.push_back(ab);
    }

    return 0;
}