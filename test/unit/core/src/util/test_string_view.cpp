#include <catch.hpp>
#include <core/util/string_view.h>

#include <cstddef>
#include <cstdio>

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

SCENARIO("StringViews can be constructed")
{
    GIVEN("A char array and its length")
    {
        constexpr size_t length = 13;
        const char array[length] = {
            'H', 'e', 'l', 'l', 'o', ',', ' ', 'W' , 'o', 'r', 'l', 'd', '!'
        };

        WHEN("The char array and length are passed to the StringView "
             "constructor")
        {
            const StringView stringView(array, length);

            THEN("The constructed StringView points to the array and has the "
                 "given length")
            {
                CHECK(stringView.ptr == array);
                CHECK(stringView.length == length);
            }
        }
    }

    GIVEN("A null-terminated string")
    {
        const char* string = "Hello, World!";

        WHEN("The string is passed to the StringView constructor")
        {
            const StringView stringView(string);

            THEN("The constructed StringView points to the string and has its "
                 "length")
            {
                CHECK(stringView.ptr == string);
                CHECK(stringView.length == 13);
            }
        }
    }

    GIVEN("Absolutely nothing")
    {
        WHEN("A StringView is constructed")
        {
            const StringView stringView;

            THEN("The constructed StringView points to nothing and has a "
                 "length of 0")
            {
                CHECK(stringView.ptr == nullptr);
                CHECK(stringView.length == 0);
            }
        }
    }
}

SCENARIO("StringViews can be indexed into")
{
    GIVEN("A StringView")
    {
        const StringView stringView("Hello, World!");

        WHEN("The 0th index is queried")
        {
            THEN("The returned value is 'H'")
            {
                CHECK(stringView[0] == 'H');
            }
        }
    
        WHEN("The 7th index is queried")
        {
            THEN("The returned value is 'W'")
            {
                CHECK(stringView[7] == 'W');
            }
        }

        WHEN("The 12th index is queried")
        {
            THEN("The returned value is '!'")
            {
                CHECK(stringView[12] == '!');
            }
        }
    }
}

SCENARIO("StringViews can be compared for equality")
{
    GIVEN("2 equal StringViews, but different locations in memory")
    {
        const char array1[14] = {
            'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'
        };
        const char array2[14] = {
            'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'
        };

        const StringView sv1(array1);
        const StringView sv2(array2);

        WHEN("They are compared for equality")
        {
            THEN("The result is true")
            {
                CHECK(sv1 == sv2);
            }
        }

        WHEN("They are compared for inequality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(sv1 != sv2);
            }
        }
    }

    GIVEN("2 different StringViews")
    {
        const StringView sv1("Hello, World!");
        const StringView sv2("Dadaa, World?");

        WHEN("They are compared for equality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(sv1 == sv2);
            }
        }

        WHEN("They are compared for inequality")
        {
            THEN("The result is true")
            {
                CHECK(sv1 != sv2);
            }
        }
    }

    GIVEN("1 initialized and 1 empty StringView")
    {
        const StringView sv1("Hello, World!");
        const StringView sv2;

        WHEN("They are compared for equality")
        {
            THEN("The result is false")
            {
                CHECK_FALSE(sv1 == sv2);
            }
        }

        WHEN("They are compared for inequality")
        {
            THEN("The result is true")
            {
                CHECK(sv1 != sv2);
            }
        }
    }
}

SCENARIO("You can find the index of a character in a StringView")
{
    GIVEN("A StringView")
    {
        const StringView stringView("Hello, World!");

        WHEN("The index of 'l' is requested")
        {
            THEN("The first index is 2")
            {
                CHECK(indexOf(stringView, 'l') == 2);
            }

            THEN("The last index is 10")
            {
                CHECK(lastIndexOf(stringView, 'l') == 10);
            }
        }

        WHEN("The index of 'W' is requested")
        {
            THEN("The first index is 7")
            {
                CHECK(indexOf(stringView, 'W') == 7);
            }

            THEN("The last index is 7")
            {
                CHECK(lastIndexOf(stringView, 'W') == 7);
            }
        }

        WHEN("The index of 'a' is requested")
        {
            THEN("The first index is 13")
            {
                CHECK(indexOf(stringView, 'a') == 13);
            }

            THEN("The last index is 13")
            {
                CHECK(lastIndexOf(stringView, 'a') == 13);
            }
        }
    }
}

SCENARIO("You can obtain substrings from StringViews")
{
    GIVEN("A StringView")
    {
        const StringView stringView("Hello, World!");

        WHEN("The substring from 0 to 5 is requested")
        {
            const StringView result = substring(stringView, 0, 5);

            THEN("The result is \"Hello\"")
            {
                CHECK(result == "Hello");
            }
        }

        WHEN("The substring from 7 to 12 is requested")
        {
            const StringView result = substring(stringView, 7, 12);

            THEN("The result is \"World\"")
            {
                CHECK(result == "World");
            }
        }

        WHEN("The substring from 0 to length is requested")
        {
            const StringView result =
                substring(stringView, 0, stringView.length);

            THEN("The result is the original StringView")
            {
                CHECK(result == stringView);
            }
        }
    }
}
