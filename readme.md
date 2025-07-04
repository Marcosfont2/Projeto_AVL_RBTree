# Árvores AVL e Rubro-Negra em C++

Projeto em C++ para demonstrar o uso de árvores balanceadas (AVL e Rubro-Negra) com dados carregados de um arquivo JSON.

O programa lê usuários de um arquivo JSON, embaralha a ordem, insere em duas árvores balanceadas (AVL e Rubro-Negra), imprime a estrutura resultante e remove usuários cujo `userid` seja número primo.

---

## 📂 Organização de Pastas
``` bash
Projeto_AVL_RBTree/
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

## 📌 Como interpretar a saída das árvores no terminal

Este programa imprime a estrutura das árvores AVL e Rubro-Negra diretamente no terminal, em formato de diagrama de texto. 

A saída serve para entender a hierarquia e o balanceamento das árvores de forma visual.

### ✅ Exemplo de saída para uma Árvore Rubro-Negra:

```bash
└── joao(20)[B]
├── maria(10)[R]
│ ├── ana(5)[B]
│ └── pedro(15)[B]
└── lucas(30)[B]
├── bruno(25)[R]
└── carla(35)[R]
```
### ✅ Como ler a saída:

- Cada linha representa **um nó da árvore**.
- O **texto entre parênteses** mostra o `userid` do usuário.
- Os **colchetes** indicam a **cor** do nó na Árvore Rubro-Negra:
  - `[R]` = Vermelho
  - `[B]` = Preto
- As linhas e símbolos:
  - `└──` ou `├──` mostram a ligação de pai para filho.
  - A **indentação** indica o nível de profundidade na árvore.

### ✅ Diferença entre AVL e Rubro-Negra:

- **AVL Tree**: não exibe cor. A estrutura é impressa do mesmo jeito, mas sem os `[R]` ou `[B]`.
- **Rubro-Negra**: exibe a cor de cada nó, ajudando a visualizar as propriedades de balanceamento específicas desta árvore.

---

## ⚙️ Dependências

- Compilador com suporte a C++17 ou superior (g++, clang++, MSVC)
- [nlohmann/json.hpp](https://github.com/nlohmann/json) (já incluso em `external/`)

---

## 🛠️ Como Compilar

Abra o terminal na raiz do projeto (onde está este README.md) e execute:

```bash
g++ src/*.cpp -Iinclude -Iexternal -std=c++17 -o arvore
```
Caso prefira, pode usar Makefile:
```bash
make
```
Em ambos os casos, depois use para executar:
```bash
./arvore
```
Para eliminar os executáveis gerados no processo de compilação, use:
``` bash
make clean
```


## 👨‍💻 Sobre o Autor

Nome: Marcos Antônio Fontes Leite

Disciplina: Estrutura de Dados Básicas II.

