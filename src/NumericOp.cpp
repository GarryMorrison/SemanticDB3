#include <string>

#include "NumericOp.h"
#include "ContextList.h"
#include "Sequence.h"

Sequence NumericOp::Compile(ContextList& context, Sequence& seq) {
    Sequence result(seq);
    result.multiply(value);
    return result;
}

const std::string NumericOp::to_string() const {
    return std::string(std::to_string(value));
}
