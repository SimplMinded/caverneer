#include <catch.hpp>
#include <core/util/error.h>

using namespace caverneer;

SCENARIO("Create and verify the different error types")
{
    GIVEN("An error with a descriptive message")
    {
        const char* message = "Something went wrong!";
        const Error error = makeError(message);

        WHEN("The error is tested for an error")
        {
            const bool result = isError(error);

            THEN("The result is true")
            {
                CHECK(result == true);
            }

            THEN("The message equals the given message")
            {
                CHECK(error.message == message);
            }
        }

        WHEN("The error is tested for a success")
        {
            const bool result = isSuccess(error);

            THEN("The result is false")
            {
                CHECK(result == false);
            }
        }
    }

    GIVEN("A success")
    {
        const Error error = makeSuccess();

        WHEN("The error is tested for an error")
        {
            const bool result = isError(error);

            THEN("The result is false")
            {
                CHECK(result == false);
            }
        }

        WHEN("the error is tested for a success")
        {
            const bool result = isSuccess(error);

            THEN("The result is true")
            {
                CHECK(result == true);
            }

            THEN("the message is not set")
            {
                CHECK(error.message == nullptr);
            }
        }
    }
}
