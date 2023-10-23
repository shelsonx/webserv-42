#ifndef HTTP_STATUS_HPP
#define HTTP_STATUS_HPP

#include <iostream>

struct StatusCode {
    const int code;
    const std::string description;
    const std::string details;

    StatusCode(int cd, std::string desc, std::string dt) : 
        code(cd), description(desc), details(dt) {
    }
    friend std::ostream& operator<<(std::ostream& os, const StatusCode& status);
};

class HTTPStatus {
    public:
        HTTPStatus();
        StatusCode OK;
        StatusCode NOT_FOUND;
};

#endif