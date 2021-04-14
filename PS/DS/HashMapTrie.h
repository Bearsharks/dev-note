#pragma once
#include <vector>
#include <list>
using namespace std;

template <class T1, class T2>
class HashMap {
public:
	HashMap(){}
	
	T2 get(T1 _key) {
		unsigned int key = getKey(_key);
		HashMap<T1, T2>* node = find(key);
		if (node->isValid()) {
			for (pair<T1, T2> p : node->bucket) {
				if (p.first == _key) {
					return p.second;
				}
			}
		}
		set(_key, NULL);
		return NULL;
	}
	void set(T1 _key, T2 _val) {
		unsigned int key = getKey(_key);
		HashMap<T1, T2>* node = find(key);
		if (!node->isValid()) {			
			int nextdigit = getNextDigit(key, node->depth);
			node->next[nextdigit] = new HashMap<T1, T2>(node);
			node = node->next[nextdigit];
		}
		node->bucket.push_back({ _key, _val });
		node->handleOverflow();
	}
	void erase(T1 _key) {
		unsigned int key = getKey(_key);
		HashMap<T1, T2>* node = find(key);
		if (node->isValid()) {
			for (auto iter = node->bucket.begin(); iter != node->bucket.end(); iter++) {
				if (iter->first == _key) {
					node->bucket.erase(iter);
					break;
				}
			}
			while (node->depth > 0 && !node->isValid()) {
				node = node->parent;
				node->eraseNotValidNode();
				
			}
		}
	}
	~HashMap() {
		for (int i = 0; i < 2; i++) {
			if (next[i] != nullptr) delete next[i];
		}
	}
private:
	int depth = 0;
	const int MAX_BUCKET_SIZE = 5;
	list<pair<T1, T2>> bucket;
	HashMap<T1, T2>* parent;
	HashMap<T1, T2>* next[2] = { nullptr, nullptr };

	HashMap(HashMap<T1, T2>* _parent) : parent(_parent), depth(_parent->depth + 1) {}

	HashMap<T1, T2>* find(unsigned int key) {
		return findRecur(key, 0);
	}
	HashMap<T1, T2>* findRecur(unsigned int key, int cur) {		
		unsigned int digit = getNextDigit(key, depth);
		return (next[digit] != nullptr) ? next[digit]->findRecur(key, cur + 1) : this;
	}
	bool isValid() {
		return !bucket.empty() || next[0] != nullptr || next[1] != nullptr;
	}
	void eraseNotValidNode() {
		for (int i = 0; i < 2; i++) {
			if (next[i] != nullptr && !next[i]->isValid()) {
				delete next[i];
				next[i] = nullptr;
			}
		}
	}
	unsigned int getKey(T1 _name) {
		return std::hash<T1>{}(_name);
	}
	
	void handleOverflow() {
		if (bucket.size() > MAX_BUCKET_SIZE) {
			next[0] = new HashMap<T1, T2>(this);
			next[1] = new HashMap<T1, T2>(this);
			for (pair<T1, T2> p : bucket) {
				next[getNextDigit(getKey(p.first), depth)]->bucket.push_back(p);
			}
			bucket.clear();
			next[0]->handleOverflow();
			next[1]->handleOverflow();
			eraseNotValidNode();		
		}
	}
	int getNextDigit(unsigned int key, int depth) {
		return !!(key & (1 << depth));
	}
};