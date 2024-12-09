#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <vector>
using namespace std;
using boost::asio::ip::tcp;

class HttpClient {
public:
    HttpClient(const std::string& server, const std::string& port)
        : server_(server), port_(port) {}

    std::string sendRequest(const std::string& resource) {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(server_, port_);
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Формируем HTTP-запрос
        std::string request = "GET / HTTP/1.1\r\n"
                              "Host: " + server_ + "\r\n"
                              "Connection: close\r\n\r\n";
        request += resource;

        boost::asio::write(socket, boost::asio::buffer(request));

        // Читаем ответ от сервера
        std::string response;
        boost::asio::streambuf response_buffer;
        boost::asio::read_until(socket, response_buffer, "\r\n\r\n");

        std::istream response_stream(&response_buffer);
        std::string header;
        while (std::getline(response_stream, header) && header != "\r")
            response += header + "\n";

        // Читаем тело ответа
        if (response_buffer.size() > 0) {
            response = std::string(std::istreambuf_iterator<char>(&response_buffer), {});
        }

        return response; // Возвращаем весь ответ сервера
    }

private:
    std::string server_;
    std::string port_;
};



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