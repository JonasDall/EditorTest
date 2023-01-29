#include <iostream>
#include <string>
#include <fstream>

#include "../libs/cereal/cereal.hpp"
#include "../libs/cereal/archives/binary.hpp"
#include "../libs/cereal/types/vector.hpp"
#include "../libs/cereal/types/memory.hpp"
#include "../libs/pge/olcPGE.hpp"
#include "../source/component.hpp"
#include "../source/core.hpp"

int main()
{
    pgeEditor edit;
    if (edit.Construct(256, 240, 4, 4)) edit.Start();

    return 0;
    /*
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
    */
}