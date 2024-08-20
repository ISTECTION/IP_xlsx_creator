/// : standart template library (STL)

#include <iostream>
#include <locale>
#include <filesystem>

int main (int argc, const char* argv[]) {
    ::setlocale(LC_ALL, "ru_RU.UTF8");


    std::string _path("test");
    std::string ext(".xlsx");

    for (auto &p : std::filesystem::recursive_directory_iterator(_path)) {
        if (p.path().extension() == ext)
            std::wcout << p.path().stem().wstring() << '\n';
    }

    return 0;
}