#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;
    treenode(T data){
    this->data=data;
    }
};
//creating input func. for taking tree as input
treenode<int>* takeinput(){
    cout<<"enter the data: ";
    int rdata;
    cin>>rdata;
    treenode<int>* root = new treenode<int>(rdata);
    int n;
    cout<<"enter no. of children of "<<rdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        treenode<int>* child = takeinput();
        root->children.push_back(child);
    } 
    return root;
}
//creating display function for displaying tree
void display(treenode<int>* root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        display(root->children[i]);
    }
}
int main()
{
    treenode<int> *root = takeinput();
    display(root);
    return 0;
}
