# PRACT5

**Для запуска программы необходимо ввести в консоль команду**
* docker compose up --build

**Для остановки программы необходимо ввести в консоль команду**
* docker compose down

**Команды для ввода**
* curl -d "POST /user Eva" http://localhost:81
* curl -d "POST /user Sasha" http://localhost:81
* curl -d "GET /balance 1804289383" http://localhost:81
* curl -d "GET /pair" http://localhost:81
* curl -d "GET /lot" http://localhost:81
* curl -d "POST /order 846930886 1 200 0.015 buy" http://localhost:81
* curl -d "POST /order 1804289383 1 300 0.01 sell" http://localhost:81
* curl -d "GET /order" http://localhost:81
* curl -d "DELETE /order 1804289383 3" http://localhost:81
