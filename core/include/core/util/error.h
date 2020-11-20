#pragma once

namespace caverneer {

struct Error
{
    const char* message;
};

Error makeError(const char* message);
Error makeSuccess();

bool isError(const Error& error);
bool isSuccess(const Error& error);

} // namespace caverneer
