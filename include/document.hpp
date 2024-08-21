#pragma once
#ifndef _DOCUMENT_HPP_
#define _DOCUMENT_HPP_
#include "date.hpp"

#include <string>

namespace xlsx_ip {

    class Document {
    private:
        unsigned int _id;
        std::string _name;

    public:
        Document();
    };

    Document::Document() { }
}
#endif