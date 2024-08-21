#pragma once
#ifndef _FUNCTION_HPP_
#define _FUNCTION_HPP_

#include <vector>
#include <string>
#include <sstream>

namespace function {
    std::vector<std::string> split (const std::string &str, const char _delim) {
        std::vector<std::string> _result;
        std::stringstream _ss (str);
        std::string _item;

        while (std::getline(_ss, _item, _delim)) { _result.push_back(_item); }
        return _result;
    }
}
#endif