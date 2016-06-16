#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

namespace CP {
template <typename T>
class queue {
protected:
  vector<T> mVect;
  size_t mStart = 0;

public:
    void push(T element){
        mVect.push_back(element);
    }
    void pop(){
        mStart++;
    }
    bool empty(){
        return mVect.size() == 0;
    }
    T front(){
        return mVect.at(mStart);
    }
    T back(){
        return mVect.at(mVect.size()-1);
    }
    size_t size(){
        return mVect.size() - mStart;
    }

};
}

void test1(){
  CP::queue<int> q;
  assert(q.empty() == true);
  q.push(1);
  q.push(2);
  q.push(3);
  assert(q.size() == 3);
  assert(q.size() != 4);
  assert(q.front() == 1);



  assert(q.back() == 3);
  q.pop();
  assert(q.front() == 2);//1
  assert(q.size() == 2);
  assert(q.back() == 3);
  q.push(27);
  assert(q.back() == 27);
  assert(q.size() == 3);

  CP::queue<int> q1;
  q1 = q;
  assert(q1.size() == 3);
  assert(q1.front() == 2);
  assert(q1.back() == 27);
}

void test2(){

  CP::queue<vector<int>> q;
  vector<int> v1;
  vector<int> v2;
  for(int i = 1 ; i <= 10 ; i++){
    v1.push_back(i*10);
  }
  q.push(v1);
  q.push(v2);
  assert(q.size() == 2);
  assert(q.front()[0] == 10);
  assert(q.back().empty() == true);
}

void test3(){
  CP::queue<string> q;
  size_t n = 1e6;
  for(size_t i = 0 ; i < n ; i++){
    string a = "a";
    q.push(a);
  }

  assert(q.size() == n);
  assert(q.front() == "a");
  assert(q.back() == "a");
  for (size_t i = q.size(); i > 1 ; i --){
    q.pop();
  }
  assert(q.size() == 1);
  assert(q.front() == "a");
}

void test4(){


}

void test5(){
    //map<int,queue<int>> m;
    //vector<queue<string>> v;
    //pair<queue<pair>,pair<string,int> > p;
    //m[78].push(55)


}

void test56(){
    queue<int> q;
    //Test Push
    q.push(5);
    q.push(6);
    q.push(9);
    assert(q.size() == 3);

    //Test Pop
    q.pop();
    q.pop();
    assert(q.size() == 1);

    //Test Front
    assert(q.front() == 9);
    q.push(7);

    //Test Back
    assert(q.back() == 7);

    //Test empty()
    assert(!q.empty());
    q.pop();
    q.pop();
    assert(q.empty());

    //Test size()
    for(size_t i = 0;i<100000000;i++)
    {
        assert(i == q.size());
        q.push(i);
        if(i%10000000 == 0)
            cout<< i << " ";
    }



    queue<queue<int>> bigq;
    for(size_t i = 0;i<2;i++)
    {
        assert(i == bigq.size());
        bigq.push(q);
        cout<< i << " ";
    }

    bigq.front().pop();
    bigq.front().pop();
    bigq.front().pop();
    bigq.front().pop();
    bigq.front().pop();
    assert(bigq.front().front() == 5);

    queue<queue<int>> bigq2(bigq);


    bigq2.front().pop();
    assert(bigq2.front().front() == 6);
    assert(bigq.front().front() == 5);
}

int main() {
  test1(); cout << "test1 OK " << endl;
  test2(); cout << "test2 OK " << endl;
  test3(); cout << "test3 OK " << endl;
  test4(); cout << "test4 OK " << endl;
  test56(); cout << "test5&6 OK " << endl;
}