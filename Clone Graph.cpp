/*Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        if(hash.find(node)==hash.end()){
            hash[node]=new UndirectedGraphNode(node->label);
            for(auto it:node->neighbors){
                hash[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return hash[node];
    }
};
