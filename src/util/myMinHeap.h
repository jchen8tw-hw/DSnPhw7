/****************************************************************************
  FileName     [ myMinHeap.h ]
  PackageName  [ util ]
  Synopsis     [ Define MinHeap ADT ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2014-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef MY_MIN_HEAP_H
#define MY_MIN_HEAP_H

#include <algorithm>
#include <vector>

template <class Data>
class MinHeap {
   public:
    MinHeap(size_t s = 0) {
        if (s != 0) _data.reserve(s);
    }
    ~MinHeap() {}

    void clear() { _data.clear(); }

    // For the following member functions,
    // We don't respond for the case vector "_data" is empty!
    const Data& operator[](size_t i) const { return _data[i]; }
    Data& operator[](size_t i) { return _data[i]; }

    size_t size() const { return _data.size(); }

    // TODO
    const Data& min() const { return _data[0]; }
    void insert(const Data& d) {
        _data.push_back(d);
        size_t t = _data.size();
        while (t > 1) {
            size_t p = t / 2;
            if (_data[t - 1] < _data[p - 1]) {
                swap(_data[t - 1], _data[p - 1]);
            } else
                break;
            t = p;
        }
        return;
    }
    void delMin() {
        delData(0);
        return;
    }
    void delData(size_t i) {
        _data[i] = _data[_data.size() - 1];
        _data.resize(_data.size() - 1);
        size_t p = i + 1, t = p * 2;
        if (p == 1 || _data[p / 2 - 1] < _data[p - 1]) {
            while (t <= _data.size()) {
                if (t < _data.size()) {  // right child exist
                    if (_data[t - 1] < _data[t]) {
                        if (_data[t - 1] < _data[p - 1]) {
                            swap(_data[p - 1], _data[t - 1]);
                            p = t;
                            t = p * 2;
                        } else
                            break;
                    } else {
                        if (_data[t] < _data[p - 1]) {
                            swap(_data[p - 1], _data[t]);
                            p = t + 1;
                            t = p * 2;
                        } else
                            break;
                    }
                } else if (t == _data.size()) {  // only left child
                    if (_data[t - 1] < _data[p - 1]) {
                        swap(_data[t - 1], _data[p - 1]);
                        p = t;
                        t = p * 2;
                    } else
                        break;
                }
            }
        } else {
            while (p > 1) {
                if (_data[p - 1] < _data[p / 2 - 1]) {
                    swap(_data[p - 1], _data[p / 2 - 1]);
                    t = p;
                    p = p / 2;
                } else
                    break;
            }
        }
    }

   private:
    // DO NOT add or change data members
    vector<Data> _data;
};

#endif  // MY_MIN_HEAP_H
