/// : headers
#include "../include/document.hpp"

/// : standart template library (STL)
#include <iostream>
#include <locale>
#include <filesystem>
#include <regex>

int main (int argc, const char* argv[]) {
    ::setlocale(LC_ALL, "ru_RU.UTF8");

    std::string _path("../../test");
    std::string ext(".xlsx");

    std::vector<std::string> _docs;
    for (auto &p : std::filesystem::recursive_directory_iterator(_path)) {
        if (p.path().extension() == ext)
            _docs.push_back(p.path().stem().string());
    }

    std::vector<xlsx_ip::Document> _doc_list;

    for (const auto& _item : _docs) {
        auto _result = function::split(_item, '_');
        _doc_list.push_back(
            xlsx_ip::Document {
                std::stoul(_result[0]),
                _result[1],
                xlsx_ip::DateOnly { _result[2] },
                xlsx_ip::Checked { }
            }
        );
    }

    function::print_table(_doc_list);
    return 0;
}