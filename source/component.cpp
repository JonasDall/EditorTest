#include "component.hpp"

// ?------------------------------------------
// ?NODE
// ?------------------------------------------

node::Node::Node(int id, int child_id) : m_id{id}, m_child_id{child_id}{}

// ?------------------------------------------
// ?NODE_TREE
// ?------------------------------------------

void node::NodeTree::AddNode(int id, int child_id){
    m_nodes.push_back(std::make_unique<Node>(id, child_id));
    // if (m_root.get() == nullptr) m_root = std::make_unique<Node>(id, child_id);
    // else m_root.reset(new Node(id, child_id));
}

void node::NodeTree::PrintNodes(){
    std::cout << "Found " << m_nodes.size() << " nodes\n";
    for (int i{}; i <m_nodes.size(); ++i)
    {
        std::cout << "Node " << i << " with ID " << m_nodes[i].get()->m_id << '\n';
    }

    // if (m_root.get() == nullptr) std::cout << "NULL!\n";
    // else std::cout << m_root.get()->m_id << '\n';

    return;
}