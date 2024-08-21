/// : submodule git
#include "../vendor/tabulate/single_include/tabulate/tabulate.hpp"

/// : headers
#include "../include/document.hpp"

/// : standart template library (STL)
#include <iostream>
#include <locale>
#include <filesystem>
#include <regex>

std::vector<std::string> split (const std::string &str, const char _delim) {
    std::vector<std::string> _result;
    std::stringstream _ss (str);
    std::string _item;

    while (std::getline(_ss, _item, _delim)) { _result.push_back(_item); }
    return _result;
}

int main (int argc, const char* argv[]) {
    ::setlocale(LC_ALL, "ru_RU.UTF8");

    std::string _path("../../test");
    std::string ext(".xlsx");

    std::vector<std::string> _docs;
    for (auto &p : std::filesystem::recursive_directory_iterator(_path)) {
        if (p.path().extension() == ext)
            _docs.push_back(p.path().stem().string());
    }

    tabulate::Table _table;
    _table.format().locale("ru_RU.UTF-8");
    _table.format().multi_byte_characters(true);
    _table.add_row({"ID", "КОМПАНИЯ", "ДАТА", "E-MAIL", "ЧЕКИ", "ПОДПИСЬ"});

    std::size_t i = 1;
    for (const auto& _item : _docs) {
        auto _result = split(_item, '_');
        _table.add_row({});

        for (std::size_t j = 0; j < _result.size(); j++)
            _table[i][j].set_text(_result[j]);
        i++;
    }

    std::cout << _table << std::endl;


    xlsx_ip::Date _date1 = xlsx_ip::get_cur_date();
    std::cout << _date1.get_str_date() << std::endl;

    return 0;
}