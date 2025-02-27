#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <vector>

using namespace std;

enum class NodeType {
    NUMBER,
    VARIABLE,
    OPERATOR,
    FUNCTION
};

class Node {
public:
    NodeType type;
    string value;
    vector<shared_ptr<Node>> children;

    static shared_ptr<Node> createNumber(const string& value) {
        return make_shared<Node>(NodeType::NUMBER, value);
    }

    static shared_ptr<Node> createVariable(const string& value) {
        return make_shared<Node>(NodeType::VARIABLE, value);
    }

    static shared_ptr<Node> createOperator(const string& value) {
        return make_shared<Node>(NodeType::OPERATOR, value);
    }

    void addChild(shared_ptr<Node> child) {
        children.push_back(child);
    }

    bool removeChild(const shared_ptr<Node>& child) {
        auto it = find(children.begin(), children.end(), child);
        if (it != children.end()) {
            children.erase(it);
            return true;
        }
        return false;
    }

    void replaceChild(const shared_ptr<Node>& oldChild, const shared_ptr<Node>& newChild) {
        auto it = find(children.begin(), children.end(), oldChild);
        if (it != children.end()) {
            *it = newChild;
        }
    }

private:
    Node(NodeType t, const string& v) : type(t), value(v) {}
};
#endif