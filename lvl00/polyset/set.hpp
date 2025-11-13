#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

/** A reference in C++ must always be initialized when the object is created.
 * Once it’s bound to an object, it can never be changed to refer to something else.
 *
 * The set class doesn’t own the bag — it just refers to it.
 * We shouldn’t copy, assign, or delete it. We only use it through the reference.
 * So the copy constructor (sharing the same reference) makes sense,
 * but the assignment operator doesn’t
 */

class set {
    private:
        searchable_bag &bag;
    public:
        set(searchable_bag &_bag);
        set(const set &copy);
        set &operator=(const set &copy) = delete;   
        ~set();

        void insert(int value);
        void insert(int *arr, int size);
        void print() const;
        void clear();

        bool has(int value) const;

        const searchable_bag &get_bag() const;
};

#endif