#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

void hexDump(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile) {
        std::cerr << "error opening file" << "\n";
        return;
    }

    std::string outputFilename = filename + "_dump";
    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "error creating file" << "\n";
        return;
    }

    outputFile << "Offset    ";
    for (int i = 0; i < 16; ++i) {
        outputFile << std::hex << std::setw(2) << std::setfill('0') << i << " ";
    }
    outputFile << "\n";

    unsigned char buffer[16];
    std::streamsize bytesRead;
    int offset = 0;
    while ((bytesRead = inputFile.read(reinterpret_cast<char*>(buffer), sizeof(buffer)).gcount()) > 0) {
        outputFile << std::hex << std::setw(8) << std::setfill('0') << offset << "  ";

        for (int i = 0; i < bytesRead; ++i) {
            outputFile << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buffer[i]) << " ";
        }

        if (bytesRead < 16) {
            for (int i = bytesRead; i < 16; ++i) {
                outputFile << "   ";
            }
        }

        outputFile << "\n";
        offset += 16;
    }

    std::cout << "hex dumped in: " << outputFilename << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    hexDump(argv[1]);
    return 0;
}
