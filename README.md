
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