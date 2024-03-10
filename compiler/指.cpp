#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string name;
    std::cout << "FILE:";
    std::cin >> name;;
    std::ifstream file(name.c_str(), std::ios::binary);

    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        std::streampos fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<char> buffer(static_cast<size_t>(fileSize));
        file.read(buffer.data(), fileSize);

        std::cout << "RAM read:";
        for (size_t i = 0; i < buffer.size(); ++i) {
            std::cout << buffer[i];
        }

        file.close();
    } else {
        std::cout << "ERROR" << std::endl;
    }
	return 0;
}
