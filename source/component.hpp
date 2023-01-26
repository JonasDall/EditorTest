#include <vector>

#include "../libs/cereal/cereal.hpp"
#include "../libs/cereal/archives/binary.hpp"
#include "../libs/cereal/types/vector.hpp"
#include "../libs/cereal/types/memory.hpp"

namespace node{

class Node{
public:
    int     m_id;
    int     m_child_id;

    Node() = default;
    Node(int id, int child_id);

    template<class Archive>
    void serialize(Archive & ar){
    ar(m_id, m_child_id);
}
};

class NodeTree{
    std::vector<std::unique_ptr<Node>> m_nodes;

public:
    NodeTree() = default;
    void AddNode(int id, int child_id);
    void PrintNodes();

    template<class Archive>
    void serialize(Archive & ar){
    ar(m_nodes);
    }
};
}