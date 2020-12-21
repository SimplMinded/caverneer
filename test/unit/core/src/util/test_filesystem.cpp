#include <catch.hpp>
#include <core/util/filesystem.h>

#include <cstddef>
#include <iostream>

#include <core/util/string_view.h>

using namespace caverneer;

namespace caverneer {

static std::ostream& operator <<(std::ostream& os, const StringView& stringView)
{
    for (size_t i = 0; i < stringView.length; i++)
    {
        os << stringView[i];
    }

    return os;
}

} // namespace caverneer

SCENARIO("You can request the parent of a path")
{
    GIVEN("A path with a parent")
    {
        const StringView path("this/is/a/path/file");

        WHEN("The parent directory of the path is requested")
        {
            const StringView parent = getParentDir(path);

            THEN("The result is \"this/is/a/path\"")
            {
                CHECK(parent == "this/is/a/path");
            }
        }
    }

    GIVEN("A path without a parent")
    {
        const StringView path("file");

        WHEN("The parent directory of the path is requested")
        {
            const StringView parent = getParentDir(path);

            THEN("The result is empty")
            {
                CHECK(parent == StringView());
            }
        }
    }
}
