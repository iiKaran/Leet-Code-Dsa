class BrowserHistory {
public:
    class node {
    public:
        node* prev;
        string data;
        node* next;
        node(string value)
        { 
            prev = NULL; 
            data = value; 
            next = NULL; 
        }
    };
    node* pos = new node("");
    BrowserHistory(string homepage) {
       pos->data = homepage;
    }
   
    void visit(string url) {
        node* temp = new node(url);
        pos->next = temp;
        temp->prev = pos;
        pos = pos->next;
    }
    
    string back(int steps) {
        while(steps-- && pos->prev != NULL)
        {
            pos = pos->prev;
        }
        return pos->data;
    }
    
    string forward(int steps) {
        while(steps-- && pos->next != NULL)
        {
            pos = pos->next;
        }
        return pos->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */