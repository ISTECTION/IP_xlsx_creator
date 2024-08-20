/// : submodule git
#include "../vendor/tabulate/single_include/tabulate/tabulate.hpp"

/// : standart template library (STL)
#include <iostream>
#include <locale>
#include <filesystem>

int main (int argc, const char* argv[]) {
    ::setlocale(LC_ALL, "ru_RU.UTF8");


    std::string _path("../../test");
    std::string ext(".xlsx");

    for (auto &p : std::filesystem::recursive_directory_iterator(_path)) {
        if (p.path().extension() == ext)
            std::wcout << p.path().stem().wstring() << '\n';
    }


    tabulate::Table _table;
    _table.format().locale("ru_RU.UTF-8");
    _table.format().multi_byte_characters(true);

    _table.add_row({"ID", "КОМПАНИЯ", "ДАТА", "E-MAIL", "ЧЕКИ", "ПОДПИСЬ"});
    _table.add_row({"tt1979376", "Toy Story 4", "Josh Cooley", "$200,000,000", "21 June 2019", "23324"});

    std::cout << _table << std::endl;

    return 0;
}