#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include "chatgui.h"
#include <memory>
#include <string>
#include <vector>

class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic {
private:
    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode>> _nodes;

    // data handles (not owned)
    GraphNode* _currentNode;
    ChatBot* _chatBot;
    ChatBotPanelDialog* _panelDialog;

    typedef std::vector<std::pair<std::string, std::string>> tokenlist;
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist& tokens,
        T& element);

public:
    ChatLogic();
    ~ChatLogic();

    void SetPanelDialogHandle(ChatBotPanelDialog* panelDialog);
    void SetChatbotHandle(ChatBot* chatbot);

    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap* GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */