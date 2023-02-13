# BASE64 Library for C++

This C++ Library offers an implementation of BASE64 encoding and decoding. You may refer to the source code for a deeper understanding. The compiled binary files are available in the GitHub release.

## Usage

```cpp
BASE64 base64;

std::string data = base64.encode("Hello World");
std::cout << data << std::endl; // Result: "SGVsbG8gV29ybGQ="

data = base64.decode(data);
std::cout << data << std::endl; // Result: "Hello World"

Or with a streaming option:

while (dataflow) {
  base64.add("DATA");
}

data = base64.encode(); // base64.decode() also work
std::cout << data << std::endl;
```
