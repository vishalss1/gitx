
# File Structure
```
gitx/
├── CMakeLists.txt
├── README.md
│
├── include/
│   ├── lexer/
│   │   ├── Token.hpp
│   │   └── Lexer.hpp
│   │
│   ├── parser/
│   │   ├── AST.hpp
│   │   └── Parser.hpp
│   │
│   ├── runtime/
│   │   ├── Executor.hpp
│   │   └── Context.hpp
│   │
│   ├── core/
│   │   ├── Repository.hpp
│   │   ├── ObjectDatabase.hpp
│   │   ├── Index.hpp
│   │   ├── Commit.hpp
│   │   ├── Tree.hpp
│   │   ├── Blob.hpp
│   │   └── RefStore.hpp
│   │
│   ├── fs/
│   │   └── FileReader.hpp
│   │
│   └── common/
│       └── Error.hpp
│
├── src/
│   ├── main.cpp
│   │
│   ├── lexer/
│   │   ├── Lexer.cpp
│   │   └── Token.cpp
│   │
│   ├── parser/
│   │   ├── Parser.cpp
│   │   └── AST.cpp
│   │
│   ├── runtime/
│   │   ├── Executor.cpp
│   │   └── Context.cpp
│   │
│   ├── core/
│   │   ├── Repository.cpp
│   │   ├── ObjectDatabase.cpp
│   │   ├── Index.cpp
│   │   ├── Commit.cpp
│   │   ├── Tree.cpp
│   │   ├── Blob.cpp
│   │   └── RefStore.cpp
│   │
│   ├── fs/
│   │   └── FileReader.cpp
│   │
│   └── common/
│       └── Error.cpp
│
├── examples/
│   └── hello.gitx
│
└── tests/
```