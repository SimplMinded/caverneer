#include "core/util/error.h"

#include "core/debug/assert.h"

namespace caverneer {

Error makeError(const char* message)
{
    ASSERT(message != nullptr);

    return Error{ message };
}

Error makeSuccess()
{
    return Error{ nullptr };
}

bool isError(const Error& error)
{
    return error.message != nullptr;
}

bool isSuccess(const Error& error)
{
    return error.message == nullptr;
}

} // namespace caverneer
