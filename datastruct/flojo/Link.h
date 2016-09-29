template<class T>
struct Link {
  explicit Link(const T& info, Link *next=0) : info(info), next(next) { }
  
  ~Link() {
    Link *p = next;
    while (p) {
      Link *q = p->next;
      p->next = 0;
      delete p;
      p = q;
    }
  }

  T info;
  Link *next;
};
