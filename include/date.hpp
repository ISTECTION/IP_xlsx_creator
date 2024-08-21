#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#ifndef _DATE_HPP_
#define _DATE_HPP_
#include <cstdint>
#include <string>
#include <ctime>
#include <sstream>
#include <chrono>

namespace xlsx_ip {

    class Date
    {
    private:
        uint32_t _day;
        uint32_t _mon;
        uint32_t _year;

    public:
        Date(uint32_t _d, uint32_t _m, uint32_t _y) :
            _day(_d),
            _mon(_m),
            _year(_y) { };

        std::string get_str_date () const {
            std::ostringstream _oss;
            _oss << _day << '.' << _mon << '.' << _year;
            return _oss.str();
        }
    };

    Date get_cur_date () {
        time_t _time = std::time(nullptr);
        tm *_tm = std::localtime(&_time);

        return Date {
            static_cast<uint32_t>(_tm->tm_mday),
            static_cast<uint32_t>(_tm->tm_mon),
            static_cast<uint32_t>(_tm->tm_year)
        };
    }
}
#endif