#pragma once

namespace caverneer {

struct Error;
struct StringView;

StringView getParentDir(const StringView& path);

Error setWorkingDir(const char* path);
Error setWorkingDir(const StringView& path);

} // namespace caverneer
