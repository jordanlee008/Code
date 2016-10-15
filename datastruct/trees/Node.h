using namespace std;

template<class T>
class Node {
 public:
  Node(const T& data, Node* l = 0, Node* r = 0);
  Node* insert(const T& x) {
    if (x == data)
      return this;
    if (x < data)
      return (l? l->insert(x) : l = new Node(x));
    else
      return (r? r->insert(x) : r = new Node(x));
  }
  Node* l;
  Node* r;
  T data;
};
