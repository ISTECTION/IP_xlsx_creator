#pragma once
#pragma warning(disable : 4996) /// _CRT_SECURE_NO_WARNINGS
#ifndef _DATE_HPP_
#define _DATE_HPP_
#include <cstdint>
#include <sstream>
#include <string>
#include <ctime>

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
            _year(1900 + _y) { };

        std::string get_str_date () const {
            std::ostringstream _oss;
            _oss << _day << '.' << _mon << '.' << _year;
            return _oss.str();
        }
    };
}
#endif