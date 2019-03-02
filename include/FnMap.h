#ifndef FNMAP_H
#define FNMAP_H

#include <unordered_map>
#include <functional>
#include "ContextList.h"
#include "Sequence.h"


class FnMap {
    private:
    public:
        FnMap();  // this is where we register our functions and operators.

        std::unordered_map<ulong, std::function<Sequence(const Sequence&, const Sequence&)> > whitelist_1;
        std::unordered_map<ulong, std::function<Sequence(const Sequence&, const Sequence&, const Sequence&)> > whitelist_2;
        std::unordered_map<ulong, std::function<Sequence(const Sequence&, const Sequence&, const Sequence&, const Sequence&)> > whitelist_3;
        std::unordered_map<ulong, std::function<Sequence(const Sequence&, const Sequence&, const Sequence&, const Sequence&, const Sequence&)> > whitelist_4;

        std::unordered_map<ulong, std::function<Sequence(ContextList&, const Sequence&, const Sequence&)> > context_whitelist_1;
        std::unordered_map<ulong, std::function<Sequence(ContextList&, const Sequence&, const Sequence&, const Sequence&)> > context_whitelist_2;
        std::unordered_map<ulong, std::function<Sequence(ContextList&, const Sequence&, const Sequence&, const Sequence&, const Sequence&)> > context_whitelist_3;
        std::unordered_map<ulong, std::function<Sequence(ContextList&, const Sequence&, const Sequence&, const Sequence&, const Sequence&, const Sequence&)> > context_whitelist_4;

        void print() const;
};

extern FnMap fn_map;

#endif