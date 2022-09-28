#include "CommandLineParser.h"
#include <string.h>
#include "CppUTest/TestHarness.h"

using CommandLineParser::my_settings;
using CommandLineParser::parse_settings;

TEST_GROUP(TestCommandLineParser){};

// CHECK usage
TEST(TestCommandLineParser, EmptyInput)
{
    my_settings expected = {
        .help{false},
        .verbose{false},
        .infile{},
        .outfile{},
        .value{}};

    int argc = 1;
    char const *argv[] = {"./file"};

    my_settings actual = parse_settings(argc, argv);
    CHECK(actual == expected);
}

// CHECK_FALSE usage
TEST(TestCommandLineParser, Input_h)
{
    my_settings expected = {
        .help{false},
        .verbose{false},
        .infile{},
        .outfile{},
        .value{}};

    int argc_test = 2;
    char const *argv_test[] = {"./file", "-h"};

    my_settings actual = parse_settings(argc_test, argv_test);
    CHECK_FALSE(actual == expected);
}

// CHECK_COMPARE usage
TEST(TestCommandLineParser, Input_h_help)
{
    my_settings expected = {
        .help{true},
        .verbose{false},
        .infile{},
        .outfile{},
        .value{}};

    int argc_test = 2;
    char const *argv_test[] = {"./file", "--help", "-h"};

    my_settings actual = parse_settings(argc_test, argv_test);
    CHECK(actual == expected);
}

// STRCMP_EQUAL usage
TEST(TestCommandLineParser, Input_infile)
{
    my_settings expected = {
        .help{false},
        .verbose{false},
        .infile{"teste"},
        .outfile{},
        .value{}};

    int argc_test = 2;
    char const *argv_test[] = {"./file", "teste"};

    my_settings actual = parse_settings(argc_test, argv_test);
    STRCMP_EQUAL(expected.infile->c_str(), actual.infile->c_str());
}

// LONGS_EQUAL usage
TEST(TestCommandLineParser, Input_value)
{
    my_settings expected = {
        .help{false},
        .verbose{false},
        .infile{},
        .outfile{},
        .value{12}};

    int argc_test = 3;
    char const *argv_test[] = {"./file", "--value", "12"};

    my_settings actual = parse_settings(argc_test, argv_test);
    LONGS_EQUAL(expected.value.value_or(1), actual.value.value_or(0));
}

// MEMCMP_EQUAL usage
TEST(TestCommandLineParser, Input_full)
{
    my_settings expected = {
        .help{true},
        .verbose{false},
        .infile{"in_file"},
        .outfile{"out_file"},
        .value{42}};

    int argc_test = 7;
    char const *argv_test[] = {"./file", "in_file", "--output", "out_file", "--help", "--value", "42"};

    auto actual = parse_settings(argc_test, argv_test);
    MEMCMP_EQUAL(expected.infile->c_str(), actual.infile->c_str(), strlen(actual.infile->c_str()));
    MEMCMP_EQUAL(expected.outfile->c_str(), actual.outfile->c_str(), strlen(actual.outfile->c_str()));
    CHECK_FALSE(actual.verbose);
    CHECK(actual.help);
    LONGS_EQUAL(expected.value.value_or(1), expected.value.value_or(0));
}
