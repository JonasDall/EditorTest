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
    std::ifstream inf{"../assets/nodes.bin", std::ios::binary};
    if(!inf) return 1;

    node::NodeTree tree;
    tree.PrintNodes();

    cereal::BinaryInputArchive inb(inf);

    inb(tree);

    tree.PrintNodes();

    std::string cont;
    std::cin >> cont;
    }

    return 0;
}