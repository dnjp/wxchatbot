#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include "chatgui.h"
#include <memory>
#include <string>
#include <vector>

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

/*
 * TODO 3:
 * Adapt the vector _nodes in a way that the instances of GraphNodes to which
 * the vector elements refer are exclusively owned by the class ChatLogic.
 *
 * Use an appropriate type of smart pointer to achieve this. Where required,
 * make changes to the code such that data structures and function parameters
 * reflect the changes. When passing the GraphNode instances to functions, make
 * sure to not transfer ownership and try to contain the changes ot class
 * ChatLogic where possible.
 *
 * TODO 4:
 * Change the ownership of all instances of GraphEdge in such a way that each
 * instance of GraphNode exclusively owns the outgoing GraphEdges and holds
 * non-owning references to incoming GraphEdges.
 *
 * When transferring ownership from class ChatLogic, where all instances of
 * GraphEdge are created, into instances of GraphNode, make sure to use move
 * semantics.
 *
 * TODO 5:
 * Create a local ChatBot instance on the stack at the bottom of the function
 * LoadAnswerGraphFromFile. Then use move semantics to pass the ChatBot instance
 * into the root node. Make sure that ChatLogic has no ownership relation to the
 * ChatBot instance and thus is no longer responsible for memory allocation and
 * deallocation.
 *
 * Note that the member _chatBot remains so it can be used as a communication
 * handle between GUI and ChatBot instance. Make all required changes in files
 * chatlogic and graphnode. When the program is executed, messages on which part
 * of the Rule of Five components of ChatBot is called should be printed to the
 * console.
 */
class ChatLogic {
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    //std::vector<GraphNode*> _nodes;
    std::vector<std::unique_ptr<GraphNode>> _nodes;
    std::vector<GraphEdge*> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode* _currentNode;
    ChatBot* _chatBot;
    ChatBotPanelDialog* _panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist& tokens,
        T& element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog* panelDialog);
    void SetChatbotHandle(ChatBot* chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap* GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */