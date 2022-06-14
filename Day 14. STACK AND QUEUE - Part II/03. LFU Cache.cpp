struct Node
{
    int val,key,cnt;
    Node *prev;
    Node *next;
    
    Node(int key_, int val_)
    {
        val = val_;
        key = key_;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

struct List
{
    Node *head;
    Node *tail;
    int size;
    
    List()
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void removeNode(Node *remNode)
    {
        Node *remPrev = remNode->prev;
        Node *remNext = remNode->next;
        remPrev->next = remNext;
        remNext->prev = remPrev;
        size--;
    }
    
    void addNode(Node *newNode)
    {
        Node *headNext = head->next;
        newNode->next = headNext;
        newNode->prev = head;
        head->next = newNode;
        headNext->prev = newNode;
        size++;
    }
    
};

class LFUCache {
private:
    int maxSize;
    int currSize;
    int minFreq;
    unordered_map<int, List*>freqListMap;
    unordered_map<int, Node*>keyNodeMap;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0; 
    }
    
    void updateFreqList(Node *existingNode)
    {
        keyNodeMap.erase(existingNode->key);
        freqListMap[existingNode->cnt]->removeNode(existingNode);
        if(existingNode->cnt == minFreq && freqListMap[existingNode->cnt]->size == 0)
        {
            minFreq++;
        }
        List* newList = new List();
        if(freqListMap.find(existingNode->cnt + 1) != freqListMap.end())
        {
            newList = freqListMap[existingNode->cnt+1];
        }
        existingNode->cnt +=1;
        newList->addNode(existingNode);
        freqListMap[existingNode->cnt] = newList;
        keyNodeMap[existingNode->key] = existingNode;
    }
    
    int get(int key_) {
        if(keyNodeMap.find(key_) != keyNodeMap.end())
        {
            Node *existingNode = keyNodeMap[key_];
            int value_ = existingNode->val;
            updateFreqList(existingNode);
            return value_;
        }
        return -1;
    }
    
    void put(int key_, int value_) {
        if(maxSize == 0)
        {
            return;
        }
        if(keyNodeMap.find(key_) != keyNodeMap.end())
        {
            Node *existingNode = keyNodeMap[key_];
            existingNode->val = value_;
            updateFreqList(existingNode);
        }
        else
        {
            if(maxSize == currSize)
            {
                List* existingList = freqListMap[minFreq];
                keyNodeMap.erase(existingList->tail->prev->key);
                freqListMap[minFreq]->removeNode(existingList->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *newList = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                newList = freqListMap[minFreq];
            }
            Node *newNode = new Node(key_,value_);
            newList->addNode(newNode);
            keyNodeMap[key_] = newNode;
            freqListMap[minFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
