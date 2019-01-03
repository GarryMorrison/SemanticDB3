#ifndef NEWCONTEXT_H
#define NEWCONTEXT_H

#include <string>
#include <map>
#include "Superposition.h"

class NewContext {
    private:
        std::string name;
        std::map<std::pair<ulong, ulong>, Superposition> rules_dict;
        std::vector<std::pair<ulong, ulong> > sort_order;

    public:
        NewContext(const std::string& s);
        void learn(const std::string& op, const std::string& label, const std::string& rule);
        Superposition recall(const std::string& op, const std::string& label);
        void print_universe();
};

#endif
