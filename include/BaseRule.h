#ifndef BASERULE_H
#define BASERULE_H

#include <string>
#include <vector>
#include "KetMap.h"

class Ket;
class Superposition;
class Sequence;
class ContextList;

class BaseRule {
    private:

    public:
        virtual int type() const = 0;
        virtual const std::string to_string() const = 0;
        virtual const ulong size() const = 0;
        virtual Ket to_ket() const = 0;
        virtual Superposition to_sp() const = 0;
        virtual Sequence to_seq() const = 0;
        virtual BaseRule* b_add(BaseRule* brule) = 0;
        virtual BaseRule* b_append(BaseRule* brule) = 0;
        virtual Sequence Compile(ContextList& context) = 0;
        virtual Sequence Compile(ContextList& context, const ulong label_idx) = 0;
        virtual Sequence Compile(ContextList& context, std::vector<Sequence>& args) = 0;
};

#endif
