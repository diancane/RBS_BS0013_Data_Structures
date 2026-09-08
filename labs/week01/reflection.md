# Week 1 reflection

Write concise answers in your own words.

## 1. Source and executable

What is the difference between `src/hello.cpp` and `build/manual/hello` after compilation?

Answer: The first one is a source code that I can easily read, write, or edit, but the computer can not run it directly. The second one is already an executable program, it is the actual file the computer can run.

## 2. Compiler warnings

What is the purpose of `-Wall -Wextra -Wpedantic`?

Answer: They turn on warnings and imply stricts control of all c++ rules in syntaxis, so even if the code technically works, these flags point out things that might be bugs or bad habits.

## 3. Value and reference parameters

What is the difference between these declarations?

```cpp
void f(std::vector<int> values);
void f(std::vector<int>& values);
```

Answer: The first one makes an exact copy, while the second one only provides a reference to the value and no copy is made.

## 4. Const reference

Why can this parameter form be useful?

```cpp
void print(const std::vector<int>& values);
```

Answer: Its perfect for functions where you only need to read the data and not modify it, bcause it uses a reference.

## 5. Linux navigation

Which command shows the current working directory?

Answer: pwd

## 6. Git state

Which command shows modified files?

Answer: git status

