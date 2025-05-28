/*
 * bincraft2json.cpp
 *
 * Author: @aymene69
 * License: MIT
 * Example usage for bincraft2json.hpp
 *
 * Compile with:
 *   g++ -std=c++17 -o bincraft2json bincraft2json.cpp -lzstd
 *
 * This program decodes a BinCraft binary file and prints the aircraft data as JSON.
 */
 
#include "bincraft2json.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <flight_data.bin> [zstd_compressed (true/false)]" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    bool zstd_compressed = false;
    if (argc > 2) {
        std::string arg = argv[2];
        if (arg == "true" || arg == "1") zstd_compressed = true;
    }
    try {
        nlohmann::json result = decodeBinCraftToJson(filename, zstd_compressed);
        std::cout << result.dump(2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}