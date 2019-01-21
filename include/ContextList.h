#ifndef CONTEXTLIST_H
#define CONTEXTLIST_H

#include <string>
#include <vector>

#include "NewContext.h"
#include "BaseRule.h"


class ContextList {
    private:
        std::string name;
        ulong index;
        ulong max_index;
        std::vector<NewContext> data;

    public:
        ContextList(const std::string& s);
        void set(const std::string& s);
        void learn(const std::string& op, const std::string& label, BaseRule* brule);
        void learn(const std::string& op, const std::string& label, const std::string& rule);
        BaseRule* recall(const std::string& op, const std::string& label);
        BaseRule* recall(const ulong op_idx, const ulong label_idx);
        void print_multiverse();
};

#endif