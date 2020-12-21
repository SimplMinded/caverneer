#include "core/util/filesystem.h"

#include <cerrno>
#include <cstddef>
#include <unistd.h>

#include "core/debug/assert.h"
#include "core/util/error.h"
#include "core/util/string_view.h"
#include "core/util/unreachable.h"

namespace caverneer {

StringView getParentDir(const StringView& path)
{
    const size_t index = lastIndexOf(path, '/');
    return index < path.length ?
        substring(path, 0, index) :
        StringView();
}

Error setWorkingDir(const char* path)
{
    ASSERT(path != nullptr);

    if (chdir(path) == -1)
    {
        switch (errno)
        {
            case EACCES:
                return makeError("Search permission denied");
            case ELOOP:
                return makeError("Loop in symbolic links found");
            case ENAMETOOLONG:
                return makeError("Path or directory name too long");
            case ENOENT:
                return makeError("Directory does not exist");
            case ENOTDIR:
                return makeError("Not a directory");
            default:
                UNREACHABLE("Unknown chdir error");
        }
    }

    return makeSuccess();
}

Error setWorkingDir(const StringView& path)
{
    ASSERT(path.length < 1024);

    char buffer[1024] = {};
    for (size_t i = 0; i < path.length; i++)
    {
        buffer[i] = path[i];
    }

    return setWorkingDir(buffer);
}

} // namespace caverneer
