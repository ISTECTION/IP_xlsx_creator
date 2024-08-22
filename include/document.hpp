#pragma once
#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
/// : submodule git
#include "../vendor/tabulate/single_include/tabulate/tabulate.hpp"

/// : headers
#include "date.hpp"

/// : standart template library (STL)
#include <vector>
#include <iomanip>




namespace xlsx_ip {
    class Checked {
    private:
        bool _is_checked_email;
        bool _is_checked_receipt;
        bool _is_checed_signature;
    public:
        Checked () : _is_checked_email(false), _is_checked_receipt(false), _is_checed_signature(false) { }
        Checked (bool _e, bool _r, bool _s) : _is_checked_email(_e), _is_checked_receipt(_r), _is_checed_signature(_s) { }

        void set_email     (bool _is) { _is_checked_email = _is;    }
        void set_receipt   (bool _is) { _is_checked_receipt = _is;  }
        void set_signature (bool _is) { _is_checed_signature = _is; }

        bool get_email     () const { return _is_checked_email;    }
        bool get_receipt   () const { return _is_checked_receipt;  }
        bool get_signature () const { return _is_checed_signature; }
    };


    class Document {
    private:
        unsigned int _id;
        std::string _name;
        DateOnly _date;
        Checked _sent;

    public:
        Document (unsigned int id, std::string name, DateOnly date, Checked sent) :
            _id(id),
            _name(name),
            _date(date),
            _sent(sent) { }

        unsigned int get_id  () const { return _id;   }
        std::string get_name () const { return _name; }
        DateOnly get_date    () const { return _date; }
        Checked get_checked  () const { return _sent; }

        std::string get_id_string_format (unsigned int _setw = 3) const {
            std::ostringstream ss;
            ss << std::setw(_setw) << std::setfill('0') << _id;
            return ss.str();
        }

    };
}


namespace function {
    void print_table (const std::vector<xlsx_ip::Document> &_document_list) {
        tabulate::Table _table;
        _table.format().locale("ru_RU.UTF-8");
        _table.format().multi_byte_characters(true);
        _table.add_row({"ID", "КОМПАНИЯ", "ДАТА", "E-MAIL", "ЧЕКИ", "ПОДПИСЬ"});

        for (size_t i = 0; i < _document_list.size(); i++) {
            _table.add_row( {
                _document_list[i].get_id_string_format(),
                _document_list[i].get_name(),
                _document_list[i].get_date().get_str_date()
            } );
        }
        std::cout << _table << std::endl;
    }
}
#endif