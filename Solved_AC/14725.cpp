#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <map>


using namespace std;
typedef struct ant{
    map<string, int> antmap;
    vector<ant*> children;
}ant;

void add_step(ant* node, string S){
    node->antmap[S] = node->children.size();
    ant* new_node = new ant();
    node->children.push_back(new_node);
}
bool is_in(ant* node, string S){
    return (node->antmap).count(S);
}
void add(ant* root, const vector<string>& words){
    ant* temp = root;
    for(const auto& x : words){
        if(!is_in(temp, x)){
            add_step(temp, x);
        }
        temp = temp->children[temp->antmap[x]];
    }
}
void print_ant(ant* node, string prefix){
    for(const auto& x: node->antmap){
        string key = x.first;
        int value = x.second;
        cout << prefix << key <<"\n";
        print_ant(node->children[value], prefix + "--");
    }
}
int main(){
    int N;
    cin >> N;
    ant* root = new ant();
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        vector<string> words;
        for(int i=0;i<a;i++){
            string s;
            cin >> s;
            words.push_back(s);
        }
        add(root, words);
    }
    print_ant(root, "");

}