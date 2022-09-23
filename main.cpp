#include "CommandLineParser.h"

int main(int argc, char const *argv[])
{
    CommandLineParser::my_settings settings = CommandLineParser::parse_settings(argc, argv);

    CommandLineParser::print_settings(settings);
}