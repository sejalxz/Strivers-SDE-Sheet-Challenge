
class LRUCache
{
public:
    class Node{
        public: 
            int key;
            int val;
            Node *prev;
            Node *next;

            Node(int key, int val) : key(key), val(val),prev(NULL),next(NULL) {}
    };
    
private:
        int capacity;
        Node *head;
        Node *tail;
        unordered_map<int, Node*>mp;
    
public:
    
    LRUCache(int capacity_)
    {
        capacity = capacity_;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *newNode)
    {
        Node *headNext = head->next;
        newNode->next = headNext;
        newNode->prev = head;
        headNext->prev = newNode;
        head->next = newNode;
    }
    
    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_)
    {
        if(mp.find(key_) != mp.end())
        {
            Node *resNode = mp[key_];
            int value_ = resNode->val;
            mp.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            mp[key_] = head->next;
            return value_;
        }
        return -1;
    }

    void set(int key_, int value_)
    {
        if(mp.find(key_) != mp.end())
        {
            Node *existingNode = mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        if(mp.size() == capacity)
        {
                Node *delNode = tail->prev;
                mp.erase(delNode->key);
                deleteNode(delNode);                
        }
        addNode(new Node(key_,value_));
        mp[key_] = head->next;
    }
};
