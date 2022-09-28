#include <functional>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace CommandLineParser
{
    struct my_settings
    {
        bool help{false};
        bool verbose{false};
        std::optional<std::string> infile;
        std::optional<std::string> outfile;
        std::optional<int> value;
    };

    void print_settings(my_settings &s);

    my_settings parse_settings(int argc, char const *argv[]);

    bool operator==(my_settings &, my_settings &);
    bool operator!=(my_settings &, my_settings &);
}