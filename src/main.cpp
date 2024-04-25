#include <iostream>
#include <fstream>
#include <string>
#include "coder.h"
#include "decoder.h"
#include <vector>

int main(int argc, char **argv)
{
    if (argc == 8)
    {
        std::string mode;
        std::string input_file;
        std::string output_path;
        long g;

        if (std::string(argv[1]) == "-d" || std::string(argv[1]) == "-c" || std::string(argv[1]) == "-a")
        {
            mode = std::string(argv[1]);
        }
        if (std::string(argv[2]) == "-i")
        {
            input_file = std::string(argv[3]);
        }
        if (std::string(argv[4]) == "-g")
        {
            g = std::stol(argv[5]);
        }
        if (std::string(argv[6]) == "-o")
        {
            output_path = std::string(argv[7]);
        }

        // std::cout << "MODE: " << mode << std::endl;
        // std::cout << "INPUT: " << input_file << std::endl;
        // std::cout << "OUTPUT: " << output_path << std::endl;

        std::ifstream input(input_file);
        if (!input.is_open())
        {
            std::cout << "Error: Unable to open input file.\n";
            return 1;
        }

        long m;
        std::vector<long> numbers;
        while (input >> m)
        {
            numbers.push_back(m);
        }
        input.close();

        std::ofstream output(output_path);
        if (!output.is_open())
        {
            std::cout << "Error: Unable to open output file.\n";
            return 1;
        }

        long E;
        std::string line;
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            long m = *it;
            if (mode == "-c")
            {
                long a = cyclic_coder_32(g, m);
                output << a << std::endl;
            }
            else if (mode == "-d")
            {
                long d = cyclic_default_decoder_32(g, m, &E);
                output << d << ", " << E << std::endl;
            }
            else if (mode == "-a")
            {
                long d = cyclic_alter_decoder_32(g, m, &E);
                output << d << ", " << E << std::endl;
            }
        }

        output.close();
        return 0;
    }
    else if (argc == 4)
    {
        std::string mode = argv[1];
        long g = std::stol(argv[2]);
        long m = std::stol(argv[3]);
        long E;

        if (mode == "-c")
        {
            long a = cyclic_coder_32(g, m);
            std::cout << g << ", " << m << ", " << a;
        }
        else if (mode == "-d")
        {
            // Testing default decoder
            long d = cyclic_default_decoder_32(g, m, &E);
            std::cout << d << ", " << E;
        }
        else if (mode == "-a")
        {
            // Testing alter decoder
            long d1 = cyclic_alter_decoder_32(g, m, &E);
            std::cout << d1 << ", " << E;
        }
        else
        {
            std::cout << "Invalid mode\n";
            return 1;
        }

        return 0;
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " <mode> <g> <m>\n";
        std::cout << "or: " << argv[0] << " -d|-c|-a -i <input_file> -g <g> -o <output_path>\n";
        return 1;
    }
}
