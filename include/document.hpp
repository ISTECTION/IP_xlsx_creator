#pragma once
#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include "date.hpp"

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
        bool set_receipt   () const { return _is_checked_receipt;  }
        bool set_signature () const { return _is_checed_signature; }
    };


    class Document {
    private:
        unsigned int _id;
        std::string _name;
        DateOnly _date;
        Checked _sent;

    public:
        Document () { }
    };

}
#endif