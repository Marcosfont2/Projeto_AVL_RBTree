#include "utils.h"
#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>
#include "json.hpp"

using json = nlohmann::json;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void shuffleUsers(std::vector<User>& users) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(users.begin(), users.end(), g);
}

std::vector<User> readUsersFromJSON(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo JSON.\n";
        return {};
    }
    json j;
    file >> j;

    std::vector<User> users;
    for (auto& item : j) {
        User u;
        u.login = item["login"];
        u.userid = item["userid"];
        u.region = item["region"];
        u.password = item["password"];
        users.push_back(u);
    }
    return users;
}
