#include "Ket.h"
#include "Superposition.h"
#include "Functions.h"


Superposition Ket::operator+(Ket& a) {
    Superposition tmp;
    tmp.add(*this);
    tmp.add(a);
    return tmp;
}


ulong Ket::label_idx() {
    return ket_label_idx;
}

std::string Ket::label() {
    std::string result = ket_map.get_str(ket_label_idx);
    return result;
}

double Ket::value() {
    return ket_value;
}

ulong Ket::size() {
    ulong result;
    if (ket_map.get_idx("") == ket_label_idx) {
        result = 0;
    }
    else {
        result = 1;
    }
    return result;
}

std::string Ket::to_string() {
    std::string s;
    if ( double_eq(ket_value, 1.0) ) {
        s = "|" + ket_map.get_str(ket_label_idx) + ">";
    }
    else {
        s = std::to_string(ket_value) + "|" + ket_map.get_str(ket_label_idx) + ">";
    }
    return s;
}

std::vector<ulong> Ket::label_split_idx() {
    std::vector<ulong> result = ket_map.get_split_idx(ket_label_idx);
    return result;
}

Ket Ket::multiply(const double d) {
    Ket tmp(*this);
    tmp.ket_value *= d;
    return tmp;
}

