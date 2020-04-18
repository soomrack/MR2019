#pragma once
#include "B_Tree.h"
// Класс представляет из себя инструмент дял красивого вывода дерева в консоль

class BTreePrinter
{
    struct NodeInfo
    {
        std::string text{ "" };
        unsigned text_pos{ 0 }, text_end{ 0 };
    };

    using LevelInfo = std::vector<NodeInfo>;

    std::vector<LevelInfo> levels;

    std::string node_text(std::vector < std::pair<int, void*>> const keys, unsigned key_count);

    void before_traversal()
    {
        levels.resize(0);
        levels.reserve(10);
    }

    void visit(B_Node const* node, unsigned level = 0, unsigned child_index = 0);

    void after_traversal();

public:
    void print(B_Tree const& tree)
    {
        before_traversal();
        visit(tree.root);
        after_traversal();
    }
}; 