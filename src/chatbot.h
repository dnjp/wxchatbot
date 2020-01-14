#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <memory>
#include <string>
#include <wx/bitmap.h>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

/*
 * TODO 2:
 * Make changes to this class such that it compiles with the Rule of Five. Make
 * sure to properly allocate/deallocate memory resources on the heap and also
 * copy member data where it makes sense to you. In each of the methods (e.g.
 * the copy constructor), print a string of the type "ChatBot Copy Constructor"
 * to the console so that you can see which method is called in later examples.
 */
class ChatBot {
private:
    // data handles (owned)
    wxBitmap* _image; // avatar image

    // data handles (not owned)
    GraphNode* _currentNode;
    GraphNode* _rootNode;
    ChatLogic* _chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot(); // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode* node);
    void SetRootNode(GraphNode* rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic* chatLogic) { _chatLogic = chatLogic; }
    wxBitmap* GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */