#include <iostream>
#include "KetMap.h"
#include "Superposition.h"
#include "Frame.h"


std::vector<ulong> Frame::supported_ops() {
    std::vector<ulong> result;
    result = supported_operators;
    return result;
}

void Frame::learn(const ulong op_idx, BaseRule* brule) {
    if (rules.find(op_idx) == rules.end()) {
        supported_operators.push_back(op_idx);
    }
    rules[op_idx] = brule;
    return;
}

BaseRule* Frame::recall(const ulong op_idx) {
    BaseRule* result;
    Superposition *sp = new Superposition();
    ulong supported_ops_idx = ket_map.get_idx("op: supported-ops");
    if (op_idx == supported_ops_idx) {
        for (const ulong op_idx2: supported_operators) {
            sp->add(op_idx2);
        }
        result = sp;
        return result;
    }
    if (rules.find(op_idx) == rules.end()) {
        result = sp;
        return result;
    }
    result = rules[op_idx];
    return result;
}

void Frame::print() {
    std::cout << "supported_operators:" << std::endl;
    for (const ulong op_idx: supported_operators) {
        std::cout << "    " << op_idx << " " << ket_map.get_str(op_idx) << std::endl;
    }
    std::cout << "rules:" << std::endl;
    for (auto pair: rules) {
        std::cout << "    " << pair.first << " " << pair.second->to_string() << std::endl;
    }
}