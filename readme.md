# Árvores AVL e Rubro-Negra em C++

Projeto em C++ para demonstrar o uso de árvores balanceadas (AVL e Rubro-Negra) com dados carregados de um arquivo JSON.

O programa lê usuários de um arquivo JSON, embaralha a ordem, insere em duas árvores balanceadas (AVL e Rubro-Negra), imprime a estrutura resultante e remove usuários cujo `userid` seja número primo.

---

## 📂 Organização de Pastas
``` bash
arvores-balanceadas/
│
├── src/ # Código-fonte (.cpp)
│ ├── main.cpp
│ ├── utils.cpp
│ ├── AVLTree.cpp
│ └── RBTree.cpp
│
├── include/ # Headers (.h)
│ ├── user.h
│ ├── utils.h
│ ├── AVLTree.h
│ └── RBTree.h
│
├── external/ # Bibliotecas externas
│ └── json.hpp
│
└── data/ # Dados de entrada
└── users.json

---
```

## ⚙️ Dependências

- Compilador com suporte a C++17 ou superior (g++, clang++, MSVC)
- [nlohmann/json.hpp](https://github.com/nlohmann/json) (já incluso em `external/`)

---

## 🛠️ Como Compilar

Abra o terminal na raiz do projeto (onde está este README.md) e execute:

```bash
g++ src/*.cpp -Iinclude -Iexternal -std=c++17 -o arvore
```

👨‍💻 Sobre o Autor
Nome: Marcos Antônio Fontes Leite

Disciplina: Linguagem de Programação II.