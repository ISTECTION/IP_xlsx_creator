#pragma once
#pragma warning(disable : 4996) /// _CRT_SECURE_NO_WARNINGS
#ifndef _DATE_HPP_
#define _DATE_HPP_
#include "document.hpp"

/// : standart template library (STL)
#include <cstdint>
#include <sstream>
#include <string>
#include <ctime>

namespace function {
    std::vector<std::string> split (const std::string &str, const char _delim) {
        std::vector<std::string> _result;
        std::stringstream _ss (str);
        std::string _item;

        while (std::getline(_ss, _item, _delim)) { _result.push_back(_item); }
        return _result;
    }
}

namespace xlsx_ip {
    class DateOnly
    {
    private:
        uint32_t _day;
        uint32_t _mon;
        uint32_t _year;

    public:
        DateOnly () {
            time_t _time = std::time(nullptr);
            tm *_tm = std::localtime(&_time);

            _day  = _tm->tm_mday;
            _mon  = _tm->tm_mon;
            _year = 1900 + _tm->tm_year;
        }

        DateOnly (uint32_t _d, uint32_t _m, uint32_t _y) :
            _day(_d),
            _mon(_m),
            _year(_y) { };

        DateOnly (const std::string& _str_date) {
            auto _split_date = function::split(_str_date, '.');
            _day  = std::stoul(_split_date[0]);
            _mon  = std::stoul(_split_date[1]);
            _year = std::stoul(_split_date[2]);
        }

        std::string get_str_date () const {
            std::ostringstream _oss;
            _oss << _day << '.' << _mon << '.' << _year;
            return _oss.str();
        }
    };
}
#endif