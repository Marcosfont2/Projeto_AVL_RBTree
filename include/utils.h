#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "user.h"

bool isPrime(int n);
void shuffleUsers(std::vector<User>& users);
std::vector<User> readUsersFromJSON(const std::string& filename);

#endif
