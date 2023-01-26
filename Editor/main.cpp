#include <iostream>
#include <string>
#include <fstream>

#include "../libs/cereal/cereal.hpp"
#include "../libs/cereal/archives/binary.hpp"
#include "../libs/cereal/types/vector.hpp"
#include "../libs/cereal/types/memory.hpp"
#include "../source/component.hpp"

int main()
{
    {
    std::cout << "How many nodes?: ";
    int nodes;
    std::cin >> nodes;

    node::NodeTree tree;
    for (int i{}; i < nodes; ++i)
    {
        tree.AddNode(i, i + 1);
    }

    tree.PrintNodes();

    std::string cont;
    std::cin >> cont;

    std::ofstream outf{"../assets/nodes.bin", std::ios::binary};
    if (!outf) return 1;

    cereal::BinaryOutputArchive outb(outf);

    outb(tree);

    }
    return 0;
}