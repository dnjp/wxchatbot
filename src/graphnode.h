#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include "chatbot.h"
#include <string>
#include <vector>

class GraphEdge;

class GraphNode {
private:
    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>>
        _childEdges; // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge*> _parentEdges; // edges to preceding nodes
    ChatBot _chatBot;

    int _id;
    std::vector<std::string> _answers;

public:
    GraphNode(int id);
    ~GraphNode();

    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge* GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge* edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);
    void MoveChatbotHere(ChatBot chatbot);
    void MoveChatbotToNewNode(GraphNode* newNode);
};

#endif /* GRAPHNODE_H_ */