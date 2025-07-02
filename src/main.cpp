#include <iostream>
#include "utils.h"
#include "AVLTree.h"
#include "RBTree.h"

int main() {
    std::vector<User> users = readUsersFromJSON("data/users.json");
    shuffleUsers(users);

    AVLTree avl;
    RBTree rb;

    for (const auto& user : users) {
        avl.insert(user);
        rb.insert(user);
    }

    std::cout << "\nAVL Tree:\n";
    avl.printTree();

    std::cout << "\nRed-Black Tree:\n";
    rb.printTree();

    for (const auto& user : users) {
        if (isPrime(user.userid)) {
            avl.remove(user.userid);
            rb.remove(user.userid);
        }
    }

    std::cout << "\nAVL Tree after removal of primes:\n";
    avl.printTree();

    std::cout << "\nRed-Black Tree after removal of primes:\n";
    rb.printTree();

    return 0;
}
