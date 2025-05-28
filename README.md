# BinCraft2JSON

A simple C++ header and example to decode binary BinCraft files (optionally ZSTD-compressed) and convert aircraft data to JSON using [nlohmann::json](https://github.com/nlohmann/json).

## Features
- Header-only: just include `bincraft2json.hpp` in your project
- Supports ZSTD-compressed and uncompressed BinCraft files
- Outputs a JSON array of aircraft objects

## Requirements
- C++17 or later
- [nlohmann::json](https://github.com/nlohmann/json) (single header)
- [ZSTD library](https://github.com/facebook/zstd) (`libzstd`)

## Usage

### 1. Include the header
```cpp
#include "bincraft2json.hpp"
```

### 2. Decode a file and get JSON
```cpp
nlohmann::json result = decodeBinCraftToJson("flight_data.bin", /*zstd_compressed=*/true);
```

### 3. Example main
See `bincraft2json.cpp` for a ready-to-use example:
```cpp
#include "bincraft2json.hpp"
#include <iostream>

int main() {
    nlohmann::json result = decodeBinCraftToJson("flight_data.bin", true);
    std::cout << result.dump(2) << std::endl;
    return 0;
}
```

### 4. Compile
On Linux or WSL:
```
g++ -std=c++17 -o bincraft2json bincraft2json.cpp -lzstd
```
On Windows (MinGW):
```
g++ -std=c++17 -o bincraft2json.exe bincraft2json.cpp -lzstd
```

## License
MIT (see LICENSE file)

## Author
Alexandre D. and contributors
